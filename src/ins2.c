#include "header0.h"




struct elle * search_3 (struct btree * tr, int k) {
  struct elle * te3 = tr -> root;
  struct elle * te4 = NULL;
	int i = 0;


  while (te3 != NULL) {
    if (te3 -> data [0] -> key > k) {
      //left child
      // printf ("\n%s\n", "//left child");
      te4 = te3;
      te3 = te3 -> link [0];
    }
  
    else if (te3 -> data [(te3 -> count) - 1] -> key < k) {
      //right child
      // printf ("\n%s", "//assign right child");
      te4 = te3;
      te3 = te3 -> link [te3 -> count];
    }
  
    else {
			i = 0;

			while (i < te3 -> count) {
				if (te3 -> data [i] -> key > k) {
					break;
				}

				else {
					i ++;
				}
			}
      te4 = te3;
			te3 = te3 -> link [i];
    }

  }

  
  return te4;
}




int where (struct elle * in, int k) {
	int i = 0;


	while (i < in -> count) {
		if (in -> data [i] -> key > k) {
			break;
		}

		else {
			i ++;
		}
	}


	return i;
}




void BFS_iterative (struct btree* tr, struct  stack_elle * qu, struct  stack_elle * in) {

    struct elle* te0;
    int i;

    te0 = tr -> root;
    insert_master (qu, in, te0);

    while (qu -> size != 0) {
        te0 = access_queue_elle (qu);

        for (i = 0; i < M; i ++) {
            if (te0 -> link [i] != NULL) {
                insert_master (qu, in, te0 -> link [i]);
            }
        }
    }


}


