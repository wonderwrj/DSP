#include "hvx_samples.h"

/*--------------------------------------------------------------*
 * Function: hvx_Q6_V_mux_QVV()
 * Notes:
 *    Implements mux select.
 *    Notes
 *        takes in two hvx vectors and a predicate register.
 *        Chooses b4etween either of two vectors depending on the
 *        predicate pattern.
 *-------------------------------------------------------------*/
void
hvx_Q6_V_vmux_QVV() {
    print_wrapper_start("mux that selects from either of two HVX Vectors");

    HVX_Vector a;
    HVX_Vector b;

    uint32_t splat_val = 0xaa55;
    printf("Splatting hvx vector with a word:a = %lx", splat_val);
    a = Q6_Vh_vsplat_R(splat_val);
    qprintf_V("%x\n", a);

    splat_val = 0xcc33;
    printf("Splatting hvx vector with a word: b = %lx", splat_val);
    b = Q6_Vh_vsplat_R(splat_val);
    qprintf_V("%x\n", b);

    uint32_t numSetBits = 64;
    printf("Setting predicate registers with half bits set: ");
    HVX_VectorPred QPred = Q6_Q_vsetq_R(numSetBits);
    qprintf_V("%x\n", QPred);

    HVX_Vector c = Q6_V_vmux_QVV(QPred, a, b);
    printf("After muxing as per QPred pattern: c = ");
    qprintf_V("%x\n", c);
}

/*-------------------------------------------------------------*/
