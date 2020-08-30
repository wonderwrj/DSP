#include "hvx_samples.h"

/*--------------------------------------------------------------*
 * Function: hvx_Q6_V_vzero
 * Notes:
 *    Resets a HVX_Vector to zero
 *-------------------------------------------------------------*/

void
hvx_Q6_V_vzero() {
    print_wrapper_start("Reset HVX Vector to 0 - Vzero");
    HVX_Vector a = Q6_V_vsplat_R(0x12345678);

    print_hvx_as_ui8_all(a, "before vzero", __FILE__, __LINE__, 1);

    a = Q6_V_vzero();

    print_hvx_as_ui8_all(a, "after vzero", __FILE__, __LINE__, 1);
}

/*-------------------------------------------------------------*/
