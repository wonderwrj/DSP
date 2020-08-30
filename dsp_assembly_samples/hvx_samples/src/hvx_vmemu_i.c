#include "hvx_samples.h"

/*--------------------------------------------------------------*
 * Function: hvx_vmemu
 * Notes:
 *    reads and writes data from external buffer to a hvx vector
 *-------------------------------------------------------------*/

#if defined(__hexagon__)
typedef long HVX_Vect_UN __attribute__((__vector_size__(128)))__attribute__((aligned(4)));
#define vmemu(A) *((HVX_Vect_UN*)(A))
#endif

void
hvx_vmemu(uint8_t *buf, unsigned int sz) {
    print_wrapper_start("vmemu example");

    HVX_Vector a = Q6_V_vzero();
    for(int i = 0; i < sz; i+=128) {
        a = vmemu(&buf[i]);
		print_hvx_as_ui8_all(a, "vmemu load:buf->HVX reg", __FILE__, __LINE__, 1);
		a = Q6_Vw_vadd_VwVw(a, a);
		print_hvx_as_ui8_all(a, "vmemu store:HVX reg->buf", __FILE__, __LINE__, 1);
        vmemu(&buf[i]) = a;
    }
}
