#include "header0.h"


int split_3(struct btree *tr, struct elle *over) {
    struct elle *te0, *te1, *te2;
    volatile int i = 0, j = 0;
    int ins;
    int median;


    i = (M - 2) / 2;
    te0 = init_elle();
    median = over->data[i]->key;


    if (over->pare == NULL) {
        te1 = init_elle();
        te1->data[0] = over->data[i];


        te1->link[0] = te0;
        te0->pare = te1;

        te1->link[1] = over;
        over->pare = te1;

        tr->root = te1;
        te1->count++;
    }

    else {
        ins = where (over->pare, over->data[ME]->key);

        ins_non_ov_3(over->pare, over->data[ME], ins);
        //over->pare->count++;

        over->pare->link[ins + 1] = over->pare->link[ins];
        over->pare->link[ins] = te0;
        te0->pare = over;
    }

    // else {
    //         ins = over->pare->count;
    //         over->pare->data[ins] = over->data[i];
    //         over->pare->count++;

    //         over->pare->link[ins + 1] = over->pare->link[ins];
    //         over->pare->link[ins] = te0;
    //         te0->pare = over;
    //  }   
    
    
     //inline mv_elle

    j = 0;
    for (i = 0; i < ME; i++) {
        te0->data[j] = over->data[i];
        te0->link[j] = over->link[i];
        j++;
    }

    te0->count = ME;
    over->count = ME;

    //rs_elle(te0, (i + 1), over->count);
    //inline rs_elle
    j = 0;
    for (i = (ME + 1); i < M - 1; i++) {
        over->data[j] = over->data[i];
        over->link[j] = over->link[i];

        over->data[i] = NULL;
        over->link[i] = NULL;
        j++;
    }

    over->link[over->count] = over->link[M - 2];
    over->data[ME + 1] = NULL;

    return median;
}




void mv_elle (struct elle *from, struct elle *to, int from_in, int to_in) {
    printf ("enters mvelle");
    int i, j;
    j = 0;
    for (i = from_in; i <= to_in; i++) {
        to->data[j] = from->data[i];
        to->link[j] = from->link[i];
        j++;
    }

    to->count = (to_in - from_in) + 1;
}




void rs_elle(struct elle *reset, int from, int count) {
    int i, j;
    j = 0;
    for (i = from; i < M - 1; i++) {
        reset->data[j] = reset->data[i];
        reset->link[j] = reset->link[i];

        reset->data[i] = NULL;
        reset->link[i] = NULL;
        j++;
    }

    reset->link[count] = reset->link[M - 2];
}
