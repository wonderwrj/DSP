#include <stdio.h>

#include "scalar_abs_ex.h"

#define SIZE 128
signed char buf_in[SIZE];
signed char buf_out[SIZE];

int main() {
	int i;
	for(i = 0; i < SIZE; ++i) {
		buf_in[i] = (i & 1) ? -i : i;
	}

	scalar_abs_ex(buf_in, buf_out, SIZE);

	for(i = 0; i < SIZE; ++i)  {
		printf("OUT:%04d: %04d ----- %04d \n", i, buf_in[i], buf_out[i]);
	}

	return 0;
}
