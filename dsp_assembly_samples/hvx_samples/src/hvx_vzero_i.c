
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

	printf("HVX Vector before zeroing: a = ");
	qprintf_V("%x\n", a);

	printf("HVX Vector after zeroing: a = ");
	qprintf_V("%x\n", a);
}
