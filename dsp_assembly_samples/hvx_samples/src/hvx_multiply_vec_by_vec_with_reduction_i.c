#include "hvx_samples.h"

/*--------------------------------------------------------------*
* Function: hvx_Q6_Vw_vrmpyacc_VwVbVb
* Notes:
*    Implements multiplication between the elements in Vector Vu
*    and Vv(byte by byte) and sum them across word and add it to
*    output vector word Vx.
*    word1
*    B3    B2  B1  B0  x   <--- bytes in HVX Vector Vu
*    B3    B2  B1  B0      <--- bytes in HVX Vector Vv
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
hvx_Q6_Vw_vrmpyacc_VwVbVb() {
    print_wrapper_start("multply with reduction");

    HVX_Vector Vu;
    HVX_Vector Vv ;
    HVX_Vector Vx ;

    uint32_t splat_val = 0x04040404;
    printf("Splatting hvx vector with a word:a = %lx", splat_val);
    Vu = Q6_V_vsplat_R(splat_val);
    qprintf_V("%x\n", Vu);

    splat_val = 0x01010101;
    printf("Splatting hvx vector with a word:a = %lx", splat_val);
    Vv = Q6_V_vsplat_R(splat_val);
    qprintf_V("%x\n", Vv);

    splat_val = 0x00000010;
    printf("Splatting hvx vector with a word:a = %lx", splat_val);
    Vx = Q6_V_vsplat_R(splat_val);
    qprintf_V("%x\n", Vx);

    Vx = Q6_Vw_vrmpyacc_VwVbVb(Vx, Vu, Vv);
    printf("After multiply and accumulate: Vx =");
    qprintf_V("%x\n", Vx);
}
/*-------------------------------------------------------------*/
