#include "hvx_samples.h"

/*--------------------------------------------------------------*
 * Function: hvx_bitwise_op.c
 * Notes:
 *    Bitwise operators supported in hvx
 *    supports
 *        Q6_V_vxor_VV -- xor two input hvx vectors
 *-------------------------------------------------------------*/

void
hvx_Q6_bitwise_ops() {
    print_wrapper_start("Bitwise operations between two hvx input vectors");

    HVX_Vector a;

    int splat_val = 0xaaaaaaaa;
    a = Q6_V_vsplat_R(splat_val);
    printf("Splatting hvx vector with a word: %x\n", splat_val);
    print_hvx_as_ui8_all(a, "V_vsplat_R", __FILE__, __LINE__, 1);

    HVX_Vector b;
    splat_val = 0x55555555;
    b = Q6_Vh_vsplat_R(splat_val);
    printf("Splatting hvx vector with a word: %x\n", splat_val);
    print_hvx_as_ui8_all(b, "V_vsplat_R", __FILE__, __LINE__, 1);

    HVX_Vector c = Q6_V_vxor_VV(a, b);
    print_hvx_as_ui8_all(c, "V_vxor_VV", __FILE__, __LINE__, 1);

    c = Q6_V_vor_VV(a, b);
    print_hvx_as_ui8_all(c, "V_vor_VV", __FILE__, __LINE__, 1);

    c = Q6_V_vand_VV(a, b);
    print_hvx_as_ui8_all(c, "V_vand_VV", __FILE__, __LINE__, 1);

    c = Q6_V_vnot_V(a);
    print_hvx_as_ui8_all(c, "V_vnot_V", __FILE__, __LINE__, 1);

}

/*-------------------------------------------------------------*/
