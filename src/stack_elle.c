
//
// Created by ansarimn on 12/11/23.
//

#ifndef TREES_AND_GRAPHS_STACK_ELLE_H
#define TREES_AND_GRAPHS_STACK_ELLE_H

#include <stdio.h>
#endif //TREES_AND_GRAPHS_STACK_ELLE_H


#include "header0.h"









struct stack_elle * init_stack_elle () {
    int i = 0;
    struct stack_elle * te0 = (struct stack_elle *) malloc (sizeof (struct stack_elle));

    while (i < RECORD_SIZE) {
        te0 -> arr [i] = init_elle ();
        i ++;
    }

    te0 -> lastin = -1;
    te0 -> firstin = 0;
    te0 -> size = 0;


    return te0;
}




void insert_in_stack_elle (struct stack_elle * s1, struct elle* s) {
    s1 -> lastin ++;
    s1 -> size ++;

    struct elle * s2 = (s1 -> arr [(s1 -> lastin)]);
    memcpy (s2, s, (sizeof (struct elle)));

    s -> mark ++;
}


void insert_master (struct stack_elle * qu, struct stack_elle * in, struct elle * a) {
    // inserts a into two given linears as a stack;

    insert_in_stack_elle (qu, a);
    insert_in_stack_elle (in, a);
}




void * access_stack_elle (struct stack_elle * s1) {
    struct elle * s2 = (s1 -> arr [(s1 -> lastin)]);
    struct elle * s3;

    s3 = malloc (sizeof (struct elle));
    memset (s3, 0, sizeof (struct elle));


    if ((s1 -> lastin) > -1) {
        memcpy(s3, s2, sizeof(struct elle));
        memset(s2, 0, sizeof(struct elle));
        s1->lastin--;
        s1->size--;
        s3->mark++;
        return s3;
    }

    else {
        printf ("Bad access;");
        return (void *) ("911");
    }
}


void * access_queue_elle (struct stack_elle * s1) {
    struct elle * s2 = (s1 -> arr [(s1 -> firstin)]);
    struct elle * s3;

    s3 = malloc (sizeof (struct elle));
    memset (s3, 0, sizeof (struct elle));


    if ((s1 -> lastin) > -1) {
        memcpy(s3, s2, sizeof(struct elle));
        memset(s2, 0, sizeof(struct elle));
        s1->firstin++;
        s1->size--;
        s3->mark++;
        return s3;
    }

    else {
        printf ("Bad access;");
        return (void *) ("911");
    }
}





void reset_tree (struct stack_elle * in) {
    int i = 0;

    for (i = 0; i <= in -> lastin; i++) {
        in -> arr [i] -> mark = 0;
    }
}
