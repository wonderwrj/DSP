#include "hvx_samples.h"

/*--------------------------------------------------------------*
 * Function: hvx_align
 * Notes:
 *    Splats a hvx_vector with pattern that is passed as argument.
 *    supports three formats
 *        Q6_Q6_vsplat_R -- splats every word of hvx vector with
 *         the argument
 *-------------------------------------------------------------*/

void
hvx_align() {
    print_wrapper_start("align hvx vector");

    HVX_Vector Vu;
    HVX_Vector Vv;

    int splat_val = 0x12345678;
    Vu = Q6_V_vsplat_R(splat_val);
    printf("Splatting hvx vector with a word: %x\n", splat_val);
    print_hvx_as_ui8_all(Vu, "V_vsplat_R", __FILE__, __LINE__, 1);

    splat_val = 0x9abcdef0;
    Vv = Q6_V_vsplat_R(splat_val);
    printf("Splatting hvx vector with a word: %x\n", splat_val);
    print_hvx_as_ui8_all(Vv, "V_vsplat_R", __FILE__, __LINE__, 1);

    HVX_Vector Vx = Q6_V_valign_VVI(Vu, Vv, 2);
    print_hvx_as_ui8_all(Vx, "Q6_V_valign_VVI", __FILE__, __LINE__, 1);

    Vx = Q6_V_valign_VVI(Vu, Vv, 3);
    print_hvx_as_ui8_all(Vx, "Q6_V_valign_VVI", __FILE__, __LINE__, 1);

    Vx = Q6_V_valign_VVI(Vu, Vv, 5);
    print_hvx_as_ui8_all(Vx, "Q6_V_valign_VVI", __FILE__, __LINE__, 1);

    Vx = Q6_V_valign_VVI(Vu, Vv, 7);
    print_hvx_as_ui8_all(Vx, "Q6_V_valign_VVI", __FILE__, __LINE__, 1);

}

/*-------------------------------------------------------------*/
