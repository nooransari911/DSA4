#include "header0.h"


void insert (struct btree * tr, struct record * data) {
	
	struct elle * te0, * te1, * te2, * te3;
	int i = 0, j = 0, k;
    volatile int flag0 = 0;
	int pos = 0;
	struct stack_elle * s1;
	

	if (tr -> root == NULL) {
		te0 = init_elle ();
		te0 -> data [0] = data;
		te0 -> count ++;
		tr -> root = te0;
		return;
	}


	te3 = tr -> root;
	k = data -> key;
	s1 = init_stack_elle ();



	te3 = search_3 (tr, data -> key);

	
	printf ("\nKey: %d; ", data -> key);

	// printf ("Target: %d; Count: %d", te3 -> data [0] -> key, te3 -> count);




	if (te3 -> count < M - 1) {
		flag0 = 1;
	}

	else {
		flag0 = 2;
	}

	

	
	if (flag0 == 1) {
		//non-overflow
		printf ("\nnon-overflow");
		pos = where (te3, k);
		ins_non_ov_3 (te3, data, pos);
	}


	else if (flag0 == 2) {
		//overflow
		printf ("\noverflow");
		//build stack of full elles from te3 -> root;
        te0 = te3;
		while (te0 != NULL) {
			if (te0 -> count == M - 1) {
				ins_st (s1, te0);
			}

			te0 = te0 -> pare;
		}


		//apply split on all elles in stack;
		while (s1 -> lastin > -1) {
			flag0 = split_3 (tr, acc_st(s1));
		}


		//insert as needed
		te3 = search_3 (tr, k);
		pos = where (te3, k);
		ins_non_ov_3 (te3, data, pos);
	}

}




void ins_non_ov_3 (struct elle * te3, struct record * data, int at) {
	
	//non-overflow

	int j = 0;


	j = M - 2;


	while (j > at) {
		te3 -> data [j] = te3 -> data [j - 1];
		te3 -> link [j + 1] = te3 -> link [j];
		j --;
	}

	te3 -> data [at] = data;
	te3 -> count ++;
}



