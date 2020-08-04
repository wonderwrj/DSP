#include "hvx_samples.h"

/*--------------------------------------------------------------*
 * Function: hvx_Q6_Vx_vsplat_R
 * Notes:
 *    Splats a hvx_vector with pattern that is passed as argument.
 *    supports three formats
 *        Q6_Q6_vsplat_R -- splats every word of hvx vector with
 *         the argument
 *        Q6_Q6_vsplat_R -- splats every word of hvx vector with
 *         the argument
 *        Q6_Q6_vsplat_R -- splats every word of hvx vector with
 *         the argument
 *-------------------------------------------------------------*/
void
hvx_Q6_Vx_vsplat_R() {
    print_wrapper_start("splat hvx vector with argument");

    HVX_Vector a;

    uint32_t splat_val = 0x12345678;
    printf("Splatting hvx vector with a word: %lx\n", splat_val);
    a = Q6_V_vsplat_R(splat_val);
    qprintf_V("%x\n", a);

    splat_val = 0x1234;
    printf("Splatting hvx vector with a word: %lx\n", splat_val);
    a = Q6_Vh_vsplat_R(splat_val);
    qprintf_V("%x\n", a);

    splat_val = 0x12;
    printf("Splatting hvx vector with a word: %lx\n", splat_val);
    a = Q6_Vb_vsplat_R(splat_val);
    qprintf_V("%x\n", a);
}
