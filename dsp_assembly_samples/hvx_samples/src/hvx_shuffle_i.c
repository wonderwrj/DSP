#include "hvx_samples.h"

/*--------------------------------------------------------------*
 * Function: hvx_shuffle
 * Notes:
 *    Performs 32x16 multiply and take last 32 bits for the result
 *    It takes two hvx vectors
 *       - vector A: 0x01020304
 *       - vector B: 0x03030202
 *                Pair Low: 0x0E08
 *-------------------------------------------------------------*/

void
hvx_Q6_shuffle() {
    print_wrapper_start("Shuffle operations");

    HVX_Vector a;

    int splat_val = 0xaa55aa55;
    a = Q6_V_vsplat_R(splat_val);
    printf("Splatting hvx vector with a word: %x\n", splat_val);
    print_hvx_as_ui8_all(a, "V_vsplat_R", __FILE__, __LINE__, 1);

    HVX_Vector b;
    splat_val = 0xcc33cc33;
    b = Q6_V_vsplat_R(splat_val);
    printf("Splatting hvx vector with a word: %x\n", splat_val);
    print_hvx_as_ui8_all(b, "V_vsplat_R", __FILE__, __LINE__, 1);

    HVX_Vector c = Q6_Vb_vshuffe_VbVb(a, b);
    print_hvx_as_ui8_all(c, "Q6_Vb_vshuffe_VbVb", __FILE__, __LINE__, 1);

    c = Q6_Vh_vshuffe_VhVh(a, b);
    print_hvx_as_ui8_all(c, "Q6_Vh_vshuffe_VhVh", __FILE__, __LINE__, 1);

}

/*-------------------------------------------------------------*/
