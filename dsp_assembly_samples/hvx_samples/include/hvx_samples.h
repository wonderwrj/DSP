#ifndef HVX_SAMPLES_H
#define HVX_SAMPLES_H
#include <stdio.h>

#include "qprintf.h"
#include <hexagon_types.h>
#include <hvx_hexagon_protos.h>

/*--------------------------------------------------------*
 * Prototypes
 *-------------------------------------------------------*/
void
print_pred_reg(HVX_VectorPred q,
               const char *reg_name,
               const char *file_name,
               const int line_num);
void
print_hvx_as_ui8_all(HVX_Vector vec,
                     const char *reg_name,
                     const char *file_name,
                     const int line_num,
                     int format);

void
print_hvx_as_ui32_all(HVX_Vector vec,
                     const char *reg_name,
                     const char *file_name,
                     const int line_num,
                     int format);
void
print_wrapper_start(const char *test_info);

void
hvx_Q6_Vx_vsplat_R();

void
hvx_Q6_V_vzero();

void
hvx_Q6_Q_vsetq_R();

void
hvx_Q6_V_vmux_QVV();

void
hvx_Q6_Vuw_vrmpyacc_VuwVubRub();

void
hvx_Q6_Vw_vrmpyacc_VwVbVb();

void
hvx_vmemu(uint8_t *buf, unsigned int SIZE);

void
hvx_Q6_bitwise_ops();

void
hvx_Q6_pack_ops();

void
hvx_Q6_int_multiply();

void
hvx_Q6_shuffle();

void
hvx_align();

void
hvx_shift();

 /*------------------------------------------------------*/
#endif 	//HVX_SAMPLES_H
