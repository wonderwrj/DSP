#include <stdio.h>
#include "hvx_samples.h"

#define SIZE     128

void
printBuffer(const char *caption, const uint8_t *buf, const int size) {
    printf("%s:\n", caption);

    for(int i = size-1; i >= 0; --i) {
        printf("%02x ", buf[i]);
        if(i % 8 == 0)
            printf("\n");
     }

    printf("\n");
    printf("-------------------------------------\n");
}

int main() {
    uint8_t buf[SIZE] = {0};

	// Test shift
	hvx_shift();

	// Test align
	hvx_align();

    // Test shuffle
	hvx_Q6_shuffle();

    // Test integer multiply
    hvx_Q6_int_multiply();

    // Test Pack
    hvx_Q6_pack_ops();

    // Test Bitwise
    hvx_Q6_bitwise_ops();

    // Test vsplat
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

    // Test vemu
    for(int i = 0; i < SIZE; ++i)
        buf[i] = i;

    // print Input buffer
    printBuffer("Input", buf, SIZE);

    hvx_vmemu(buf, SIZE);

    // print Output buffer
    printBuffer("Output", buf, SIZE);

    return 0;
}
