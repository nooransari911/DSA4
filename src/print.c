#include "header0.h"

void print_time (struct timespec * initial, struct timespec * final, int op) {
    double diff;

    diff = (final -> tv_sec - initial -> tv_sec) + ((final -> tv_nsec - initial -> tv_nsec)
                                                    / 1000.0);


    if (op == 0) {
        printf ("\n\nPROCESS TIME IS: %lf us\n\n", diff);
    }

    else if (op == 1) {
        printf ("\n\nWALL TIME IS: %lf us\n\n", diff);
    }
}


void print_one_elle (struct elle * te0) {
	int i = 0;

	
	printf ("\n\nKey: %d\n", te0 -> data [0] -> key);
	for (i = 0; i < te0 -> count; i ++) {
		printf("%d\t", (te0 -> data [i] -> key));
  }
}





void printall (struct stack_elle * in) {
    int i = 0, j = 0;

    printf ("\n");

    if ((in -> lastin) > -1) {
        for (i = 0; i <= in -> lastin; i++) {
            printf ("\n\nKey: %d\n", in -> arr [i] -> data [0] -> key);
            for (j = 0; j < M - 1; j ++) {
                printf("%d\t", (in -> arr[i] -> data [j] -> key));
            }
        }
    }

    // if (in -> lastin > -1) {
    //     for (i = 0; i <= in -> lastin; i++) {
    //         printf("%d\t", (in -> arr[i] -> data [0] -> key));
    //     }
    // }

    else {
        printf ("Bad access;");
    }
}
