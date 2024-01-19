#include "header0.h"





int split_3 (struct btree * tr, struct elle * over) {
	struct elle * te0, * te1, * te2;
	int i = 0;
	int ins;
  int median;


  i = (M - 2) / 2;
	te0 = init_elle ();
  median = over -> data [i] -> key;

	
	if (over -> pare == NULL) {
		te1 = init_elle ();
    te1 -> data [0] = over -> data [i];
    
    
    te1 -> link [0] = te0;
    te0 -> pare = te1;
    
    te1 -> link [1] = over;
    over -> pare = te1;
    
    te1 -> count++;
	} 

	else {
		ins = over -> pare -> count;
		over -> pare -> data [ins] = over -> data [i];
    
    over -> pare -> link [ins] = te0;
    te0 -> pare = over;
    over -> pare -> count++;
  } 

  mv_elle (over, te0, 0, (i - 1));
  over -> count = (M - 2) - (i + 1) + 1;
  rs_elle (te0, (i + 1), over -> count);

  
  return median;
}




void mv_elle (struct elle * from, struct elle * to, int from_in, int to_in) {
  
  int i, j;
  j = 0;
  for (i = from_in; i <= to_in; i++) {
    to -> data [j] = from -> data [i];
    to -> link [j] = from -> link [i];
    j ++;
  }

  to -> count = (to_in - from_in) + 1;
}




void rs_elle (struct elle * reset, int from, int count) {
  int i, j;
  j = 0;
  for (i = from; i < M - 1; i++) {
    reset -> data [j] = reset -> data [i];
    reset -> link [j] = reset -> link [i];
    j ++;
  }

  reset -> link [count] = reset -> link [M - 2];
}
