#include "hvx_samples.h"

/*--------------------------------------------------------------*
 * Function: hvx_Q6_Vx_vsplat_R
 * Notes:
 *    Splats a hvx_vector with pattern that is passed as argument.
 *    supports three formats
 *        Q6_Q6_vsplat_R -- splats every word of hvx vector with
 *         the argument
 *        Q6_Q6_vsplat_R -- splats every word of hvx vector with
 *         the argument
 *        Q6_Q6_vsplat_R -- splats every word of hvx vector with
 *         the argument
 *		------------------------------------------
 *	    Int value ........|31-24|23-16|15-8| 7-0 |
 *		------------------------------------------
 *	    |127-120|.........|31-24|23-16|15-8| 7-0 |
 *		------------------------------------------
 *		|   12  |.........|  12 | 34  | 56 |  78 |
 *		------------------------------------------
 *-------------------------------------------------------------*/

void
hvx_Q6_Vx_vsplat_R() {
    print_wrapper_start("splat hvx vector with argument");

    HVX_Vector a;

    uint32_t splat_val = 0x12345678;
    a = Q6_V_vsplat_R(splat_val);
    printf("Splatting hvx vector with a word: %lx\n", splat_val);
    print_hvx_as_ui8_all(a, "V_vsplat_R", __FILE__, __LINE__, 1);

    splat_val = 0x1234;
    a = Q6_Vh_vsplat_R(splat_val);
    printf("Splatting hvx vector with a word: %lx\n", splat_val);
    print_hvx_as_ui8_all(a, "Vh_vsplat_R", __FILE__, __LINE__, 1);

    splat_val = 0x12;
    printf("Splatting hvx vector with a word: %lx\n", splat_val);
    a = Q6_Vb_vsplat_R(splat_val);
    print_hvx_as_ui8_all(a, "Vb_vsplat_R", __FILE__, __LINE__, 1);
}

/*-------------------------------------------------------------*/
