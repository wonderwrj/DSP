#include "hvx_samples.h"

/*--------------------------------------------------------------*
 * Function: hvx_int_multiply.c
 * Notes:
 *    Performs 32x16 multiply and take last 32 bits for the result
 *    It takes two hvx vectors
 *       - vector A: 0x01020304
 *       - vector B: 0x03030202
 *       - Q6_Vw_vmpyie_VwVuh
 *                A= 0x01020304 x
 *                B= 0x0202 = 0x2060A0E08
 *                MSByte "2" get dropped and result is 0x060A0E08
 *       - Q6_Vw_vmpyio_VwVh
 *                A= 0x01020304 x
 *                B= 0x0303 = 0x3090F150C
 *                MSByte "3" get dropped and result is 0x090F150C
 *       - Q6_W_vmpye_VwVuh
 *                A= 0x01020304 x
 *                B= 0x0202 = 0x2060A0E08
 *                MSByte "2" get dropped and result is 
 *                0x0002_060A_0E08
 *                Pair high: 0x0002_060A
 *                Pair Low: 0x0E08
 *-------------------------------------------------------------*/

void
hvx_Q6_int_multiply() {
    print_wrapper_start("multiply operation between two hvx input vectors");

    HVX_Vector Vu;

    int splat_val = 0x01020304;
    Vu = Q6_V_vsplat_R(splat_val);
    printf("Splatting hvx vector with a word: %x\n", splat_val);
    print_hvx_as_ui8_all(Vu, "V_vsplat_R", __FILE__, __LINE__, 1);

    HVX_Vector Vv;
    splat_val = 0x03030202;
    Vv = Q6_V_vsplat_R(splat_val);
    printf("Splatting hvx vector with a word: %x\n", splat_val);
    print_hvx_as_ui8_all(Vv, "V_vsplat_R", __FILE__, __LINE__, 1);

    HVX_Vector c = Q6_Vw_vmpyie_VwVuh(Vu, Vv);
    print_hvx_as_ui8_all(c, "Vw_vmpyie_VwVuh", __FILE__, __LINE__, 1);

    c = Q6_Vw_vmpyio_VwVh(Vu, Vv); // takes lower 32 bits
    print_hvx_as_ui8_all(c, "Vw_vmpyio_VwVh", __FILE__, __LINE__, 1);

    c = Q6_Vw_vmpye_VwVuh(Vu, Vv); // takes lower 32 bits
    print_hvx_as_ui8_all(c, "Q6_Vw_vmpye_VwVuh", __FILE__, __LINE__, 1);

    c = Q6_Vw_vmpyo_VwVh_s1_rnd_sat(Vu, Vv); // takes upper 32 bits
    print_hvx_as_ui8_all(c, "Q6_Vw_vmpyo_VwVh_s1_rnd_sat", __FILE__, __LINE__, 1);

    HVX_VectorPair d = Q6_W_vmpye_VwVuh(Vu, Vv);
    print_hvx_as_ui8_all(Q6_V_hi_W(d), "Q6_W_vmpye_VwVuh", __FILE__, __LINE__, 1);
    print_hvx_as_ui8_all(Q6_V_lo_W(d), "Q6_W_vmpye_VwVuh", __FILE__, __LINE__, 1);

    HVX_Vector Vx;
    splat_val = 0x00000505; // takes upper 32 bits
    Vx = Q6_V_vsplat_R(splat_val);
    Vx = Q6_Vw_vmpyoacc_VwVwVh_s1_rnd_sat_shift(Vx, Vu, Vv);
    print_hvx_as_ui8_all(Vx, "Q6_Vw_vmpyoacc_VwVwVh_s1_rnd_sat_shift", __FILE__, __LINE__, 1);
}

/*-------------------------------------------------------------*/
