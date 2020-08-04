#include <assert.h>

#include "scalar_abs_ex.h"
#include "qprintf.h"

#include <hexagon_types.h>
#include <hvx_hexagon_protos.h>

void
scalar_abs_ex(signed char *in_buf, 
			  signed char *out_buf,
			  unsigned int len) {
	int i;
	
	qprintf_R_all();
	qprintf_V_all();

	HVX_Vector x = Q6_V_vsplat_R(-1);
	qprintf_V("x = %d\n", x);

	HVX_VectorPred pred = Q6_Q_vand_VR(x, -1);
	qprintf_Q("pred = %x\n", pred);

	for(i = 0; i < len; ++i) {
		out_buf[i] = Q6_R_abs_R(in_buf[i]);
	}
}
