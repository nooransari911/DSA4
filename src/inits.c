#include "header0.h"


struct btree * init_btree () {
  struct btree * tr0;

  tr0 = (struct btree *) malloc (sizeof (struct btree));

  tr0 -> root = NULL;
  return tr0;
}




struct record * init_record () {
  struct record * te0;
  int i = 0;
  
  te0 = (struct record *) malloc (sizeof (struct record));

  for (; i < RECORD_SIZE; i++) {
    te0 -> field [i] = NULL;
  }
  
  return te0;
}




struct elle * init_elle () {
  struct elle * te0;
  int i = 0;

  te0 = (struct elle *) malloc (sizeof (struct elle));

  for (i = 0; i < M - 1; i++) {
    te0 -> data [i] = NULL;
    te0 -> link [i] = NULL;
  }

  te0 -> link [M - 1] = NULL;
  te0 -> pare = NULL;
  
  te0 -> count = 0;
  te0 -> mark = 0;
  return te0;
}

