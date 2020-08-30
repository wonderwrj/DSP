#include "hvx_samples.h"

/*--------------------------------------------------------------*
* Function: hvx_Q6_Vuw_vrmpyacc_VuwVubRub
* Notes:
*    Implements multiplication between the elements in Vector Vu
*    and Rt(byte by bit) and sum them across word and add it to
*    output vector word Vx.
*    word1
*    B3    B2  B1  B0  x   <--- bytes in HVX Vector Vu
*    b3    b2  b1  b0      <--- bits in scalar Rt
*    ----------------
*    S3    S2  S1  S0
*
*    Vx(Word) <- Vx(Word) + (S3 + S2 + S1 + S0)
*
*    Notes
*        takes in two hvx vectors and a predicate register.
*        Chooses b4etween either of two vectors depending on the
*        predicate pattern.
*-------------------------------------------------------------*/

void
hvx_Q6_Vuw_vrmpyacc_VuwVubRub() {
    print_wrapper_start("multply with reduction");

    HVX_Vector Vu;
    HVX_Vector Vx ;

    int splat_val = 0x04030201;
    Vu = Q6_V_vsplat_R(splat_val);
    print_hvx_as_ui8_all(Vu, "V_vsplat_R on Vu", __FILE__, __LINE__, 1);

    splat_val = 0x01020304;
    Vx = Q6_V_vsplat_R(splat_val);
    print_hvx_as_ui8_all(Vx, "V_vsplat_R on Vx", __FILE__, __LINE__, 1);

    Vx = Q6_Vuw_vrmpyacc_VuwVubRub(Vx, Vu, 0x04030201);
    printf("After multiply and accumulate: Vx =");
    print_hvx_as_ui8_all(Vx, "Q6_Vuw_vrmpyacc_VuwVubRub", __FILE__, __LINE__, 1);
}

/*-------------------------------------------------------------*/

