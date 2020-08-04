#include <stdio.h>
#include "hvx_samples.h"

#define SIZE 	512

int main() {
	uint8_t buf[SIZE];
	for(int i = 0; i < SIZE; ++i) 
		buf[i] = i;

    //Test vsplat
    hvx_Q6_Vx_vsplat_R();

	// Test zeroing HVX Vector
	hvx_Q6_V_vzero();

	// Test setting pred register
	hvx_Q6_Q_vsetq_R();
	
	// Test mux select
	hvx_Q6_V_vmux_QVV();

	// Test multiply bytes with 4-byte reduction
	hvx_Q6_Vuw_vrmpyacc_VuwVubRub();

	// Test multiply bytes of two HVX Vectors and accumulate to a word
	hvx_Q6_Vw_vrmpyacc_VwVbVb();

	hvx_vmemu(buf, SIZE);

    return 0;
}
