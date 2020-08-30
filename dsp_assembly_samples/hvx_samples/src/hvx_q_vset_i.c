#include "hvx_samples.h"

/*--------------------------------------------------------------*
 * Function: hvx_Q6_Q_vsetq_R
 * Notes:
 *    sets predication register to the number of bits as specified
 *    as argument
 *    supports three formats
 *        Q6_Q_vset_R -- takes in #bits to set as args and sets those
 *         # of bits to 1
 *        Q6_Q_vsetq2_R -- takes in #bits to set as args and sets those
 *         # of bits to 1
 *    The difference vset and vsetq2 is at the border case.
 *    Q6_Q_vsetq_R to set Q to 128 bits : 0x00000000|00000000|00000000|00000000
 *    Q6_Q_vsetq2_R to set Q to 127 bits: 0x7fffffff|ffffffff|ffffffff|ffffffff
 *-------------------------------------------------------------*/

void
hvx_Q6_Q_vsetq_R() {
    print_wrapper_start("Set Predication Register");

    HVX_VectorPred QPred;

    int num_bits = 4;
    printf("Using Q6_Q_vsetq_R to set Q to %d bits: ", num_bits);
    QPred = Q6_Q_vsetq_R(num_bits);
    qprintf_Q("%x\n", QPred);

    num_bits = 127;
    printf("Using Q6_Q_vsetq_R to set Q to %d bits: ", num_bits);
    QPred = Q6_Q_vsetq_R(num_bits);
    qprintf_Q("%x\n", QPred);

    num_bits = 128;
    printf("Using Q6_Q_vsetq_R to set Q to %d bits: ", num_bits);
    QPred = Q6_Q_vsetq_R(num_bits);
    qprintf_Q("%x\n", QPred);

    num_bits = 5;
    printf("Using Q6_Q_vsetq2_R to set Q to %d bits: ", num_bits);
    QPred = Q6_Q_vsetq2_R(num_bits);
    qprintf_Q("%x\n", QPred);

    num_bits = 127;
    printf("Using Q6_Q_vsetq2_R to set Q to %d bits: ", num_bits);
    QPred = Q6_Q_vsetq2_R(num_bits);
    qprintf_Q("%x\n", QPred);

    num_bits = 128;
    printf("Using Q6_Q_vsetq2_R to set Q to %d bits: ", num_bits);
    QPred = Q6_Q_vsetq2_R(num_bits);
    qprintf_Q("%x\n", QPred);
}

/*-------------------------------------------------------------*/
