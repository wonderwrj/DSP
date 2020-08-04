#include "hvx_samples.h"

/*--------------------------------------------------------------*
 * Function: hvx_vmemu
 * Notes:
 *    Loads data from external buffer
 *-------------------------------------------------------------*/

#if defined(__hexagon__)
typedef long HVX_Vect_UN __attribute__((__vector_size__(128)))__attribute__((aligned(4)));
#define vmemu(A) *((HVX_Vect_UN*)(A))
#endif

void
hvx_vmemu(uint8_t * buf, unsigned int sz) {
    print_wrapper_start("vmemu example");

    HVX_Vector a;
    for(int i = 0; i < sz; i+=128) {
        a = vmemu(&buf[i]);
        printf("Reading from external buffer.........");
        qprintf_V("a = %x\n", a);
    }
}
