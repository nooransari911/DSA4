#include "header0.h"




void test0 () {
	struct timespec initial0, final0;
	struct timespec initial1, final1;

	timespec_get (&initial1, TIME_UTC);
	clock_gettime (CLOCK_PROCESS_CPUTIME_ID, &initial0);



	//actual function starts here;	
	struct btree * tr0;
	struct record * re [M - 1], * re1 [M - 1];
	struct elle tra [8];
	struct stack_elle * qu, * in;

	int i = 0;


	tr0 = init_btree();

	qu = init_stack_elle ();
	in = init_stack_elle ();

	
	for (; i < (M - 1); i++) {
		re [i] = init_record();
		re [i] -> key = i + 1;
	}


	//part1
	printf ("\n\n//Part1:\n");
	for (i = 0; i < (M - 1); i++) {
		//printf ("%d\t", re [i] -> key);
		insert (tr0, re[i]);
	}

	for (i = 0; i < 16; i++) {
		//printf ("%d\t", tr0 -> root -> data [i] -> key);
	}

	printf ("\n\n");



	
	//part2
	printf ("\n\n//Part2:\n");

	for (i = (M - 1); i < (2 * (M - 1)); i++) {
		re1 [i % (M - 1)] = init_record();
		re1 [i % (M - 1)] -> key = i + 1;
	}


	for (i = 0; i < (M - 1); i++) {
		//printf ("%d\t", re1 [i] -> key);
		insert (tr0, re1[i]);
	}

	printf ("\n\n//Root ::\n");

	for (i = 0; i < tr0 -> root -> count; i++) {
		printf ("pa%d\t", tr0 -> root -> data [i] -> key);
	}
	
	printf ("\n\n");

	printf ("\n\n//Child ::\n");
	
	for (i = 0; i < tr0 -> root -> link [(M - 1)] -> count; i++) {
		printf ("ch%d\t", tr0 -> root -> link [(M - 1)] -> data [i] -> key);
	}

	
	BFS_iterative(tr0, qu, in);
	printall (in);

	// printf ("\n\nPrint one: root;");
	// print_one_elle (tr0 -> root);
	// printf ("\n\nPrint one: root via root's child;");
	// print_one_elle (tr0 -> root -> link [M - 1] -> pare);

	//actual function ends here;



	timespec_get(&final1, TIME_UTC);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &final0);

	print_time (&initial0, &final0, 0);
	print_time (&initial1, &final1, 1);
}

