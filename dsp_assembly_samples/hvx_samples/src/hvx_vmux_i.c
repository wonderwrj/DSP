#include "hvx_samples.h"

/*--------------------------------------------------------------*
 * Function: hvx_Q6_V_mux_QVV()
 * Notes:
 *    Implements mux select.
 *    Notes
 *        takes in two hvx vectors and a predicate register.
 *        Chooses between either of two vectors depending on the
 *        predicate pattern.
 *      
 *        If QPred bits set, it takes it from first hvx vector(a)
 *        else it takes it from second hvx vector(b)
 *-------------------------------------------------------------*/

void
hvx_Q6_V_vmux_QVV() {
    print_wrapper_start("mux that selects from either of two HVX Vectors");

    HVX_Vector a;
    HVX_Vector b;

    int splat_val = 0xaa55;
    a = Q6_Vh_vsplat_R(splat_val);
    print_hvx_as_ui8_all(a, "Vh_vsplat hvx register a:", __FILE__, __LINE__, 1);

    splat_val = 0xcc33;
    b = Q6_Vh_vsplat_R(splat_val);
    print_hvx_as_ui8_all(b, "Vh_vsplat hvx register b:", __FILE__, __LINE__, 1);

    int num_bits = 64;
    printf("Using Q6_Q_vsetq_R to set QPred to %d bits:", num_bits);
    HVX_VectorPred QPred = Q6_Q_vsetq_R(num_bits);
    qprintf_Q("%x\n", QPred);

    HVX_Vector c = Q6_V_vmux_QVV(QPred, a, b);
    print_hvx_as_ui8_all(c, "V_vmux of a and b with Qpred", __FILE__, __LINE__, 1);
}

/*-------------------------------------------------------------*/
