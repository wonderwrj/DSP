#include "hvx_samples.h"

/*--------------------------------------------------------------*
 * Function: hvx_Q6_Q_vsetq_R
 * Notes:
 *    sets predication register to the number of bits as specified
 *    as arg
 *    supports three formats
 *        Q6_Q_vset_R -- taks in #bits to set as args and sets those
 *         # of bits to 1
 *        Q6_Q_vsetq2_R -- taks in #bits to set as args and sets those
 *         # of bits to 1
 *-------------------------------------------------------------*/
void
hvx_Q6_Q_vsetq_R() {
    print_wrapper_start("Set Predication Register");

    HVX_VectorPred QPred;

    uint32_t num_bits = 4;
    printf("setting Pred register Q to %lu bits: ", num_bits);
    QPred = Q6_Q_vsetq_R(num_bits);
    qprintf_Q("%x\n", QPred);

    num_bits = 127;
    printf("setting Pred register Q to %lu bits: ", num_bits);
    QPred = Q6_Q_vsetq_R(num_bits);
    qprintf_Q("%x\n", QPred);

    num_bits = 5;
    printf("setting Pred register Q to %lu bits: ", num_bits);
    QPred = Q6_Q_vsetq2_R(num_bits);
    qprintf_Q("%x\n", QPred);

    num_bits = 128;
    printf("setting Pred register Q to %lu bits: ", num_bits);
    QPred = Q6_Q_vsetq2_R(num_bits);
    qprintf_Q("%x\n", QPred);
}
/*-------------------------------------------------------------*/
