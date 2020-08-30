#include "hvx_samples.h"

/*--------------------------------------------------------------*
 * Function: hvx_pack_ops.c
 * Notes:
 *    Bitwise operators supported in hvx
 *    supports
 *        Q6_V_vxor_VV -- xor two input hvx vectors
 *-------------------------------------------------------------*/

void
hvx_Q6_pack_ops() {
    print_wrapper_start("Pack operations between two hvx input vectors");

    HVX_Vector a;

    int splat_val = 0x55aa;
    a = Q6_Vh_vsplat_R(splat_val);
    printf("Splatting hvx vector with a word: %x\n", splat_val);
    print_hvx_as_ui8_all(a, "Vh_vsplat_R", __FILE__, __LINE__, 1);

    HVX_Vector b;
    splat_val = 0xcc33;
    b = Q6_Vh_vsplat_R(splat_val);
    printf("Splatting hvx vector with a word: %x\n", splat_val);
    print_hvx_as_ui8_all(b, "Vh_vsplat_R", __FILE__, __LINE__, 1);

    HVX_Vector c = Q6_Vb_vpacke_VhVh(a, b);
    print_hvx_as_ui8_all(c, "Vb_vpacke_VhVh", __FILE__, __LINE__, 1);

    c = Q6_Vb_vpacko_VhVh(a, b);
    print_hvx_as_ui8_all(c, "Vb_vpacko_VhVh", __FILE__, __LINE__, 1);

}

/*-------------------------------------------------------------*/
