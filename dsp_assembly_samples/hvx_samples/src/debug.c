#include "hvx_samples.h"

void
print_pred_reg(HVX_VectorPred q,
               const char *reg_name,
               const char *file_name,
               const int line_num) {
	union {
		HVX_VectorPred as_q;
   		uint8_t    as_ui8[128];
   		unsigned   as_ui32[16];
	} qq = {q};

    printf("...RV HVX Dump: %s:%d - %s\n", file_name, line_num, reg_name);
    for(int i = 31; i >= 0; i-=4) {
            printf("%x%x|%x%x|",\
                qq.as_ui32[i], qq.as_ui32[i-1], qq.as_ui32[i-2], qq.as_ui32[i-3]);
    }
    printf("\n-------------------------------------------\n");
}

void
print_hvx_as_ui8_all(HVX_Vector vec,
                     const char *reg_name,
                     const char *file_name,
                     const int line_num,
                     int format) {

	union {
		HVX_Vector as_v;
   		uint8_t    as_ui8[128];
   		unsigned   as_ui32[16];
	} uu = {vec};

    printf("...RV HVX Dump: %s:%d - %s\n", file_name, line_num, reg_name);
    for(int i = 127; i >= 0; i-=8) {
        if(format == 1)
            printf("...%02x %02x %02x %02x %02x %02x %02x %02x\n", \
                uu.as_ui8[i], uu.as_ui8[i-1], uu.as_ui8[i-2], uu.as_ui8[i-3], \
                uu.as_ui8[i-4], uu.as_ui8[i-5], uu.as_ui8[i-6], uu.as_ui8[i-7]);
        else
            printf("...%4d %4d %4d %4d %4d %4d %4d %4d\n", \
                uu.as_ui8[i], uu.as_ui8[i-1], uu.as_ui8[i-2], uu.as_ui8[i-3], \
                uu.as_ui8[i-4], uu.as_ui8[i-5], uu.as_ui8[i-6], uu.as_ui8[i-7]);
    }
    printf("-------------------------------------------\n");
}

void
print_hvx_as_ui32_all(HVX_Vector vec,
                     const char *reg_name,
                     const char *file_name,
                     const int line_num,
                     int format) {

	union {
		HVX_Vector as_v;
   		uint8_t     as_ui8[128];
   		unsigned    as_ui32[16];
	} uu = {vec};

    printf("...RV HVX Dump: %s:%d - %s\n", file_name, line_num, reg_name);
    for(int i = 31; i >= 0; i-=4) {
        if(format == 1)
            printf("...%08x %08x %08x %08x \n", \
                uu.as_ui32[i], uu.as_ui32[i-1], uu.as_ui32[i-2], uu.as_ui32[i-3]);
        else
            printf("...%8d %8d %8d %8d \n", \
                uu.as_ui32[i], uu.as_ui32[i-1], uu.as_ui32[i-2], uu.as_ui32[i-3]);
    }
    printf("-------------------------------------------\n");
}
