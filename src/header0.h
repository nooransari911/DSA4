#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


#define M 16
//M-way BTree;
//M links; M - 1 records;
#define ME ((M -2) / 2)

#define RECORD_SIZE 20




typedef struct record {
  int key;  //primary key;
  void * field [RECORD_SIZE];
} record;

typedef struct elle {
  struct record * data [M - 1];
  struct elle * link [M];
  int count;
  int mark;

  struct elle * pare;
} elle;

typedef struct btree {
    struct elle * root;
} btree;

typedef struct stack_elle {
    struct elle * arr [RECORD_SIZE];
    int firstin;
    int lastin;
    int size;
} stack_elle;




//test0.c
void test0 ();




//stack_elle.c declartions;
struct stack_elle * init_stack_elle ();
void insert_in_stack_elle (struct stack_elle * s1, struct elle* s);
void ins_st (struct stack_elle * s1, struct elle* s);
void insert_master (struct stack_elle * qu,
                    struct stack_elle * in, struct elle * a);
struct elle * acc_st (struct stack_elle * s1);
struct elle * acc_qu (struct stack_elle * s1);

void * access_stack_elle (struct stack_elle * s1);
void * access_queue_elle (struct stack_elle * s1);
int searchinlinear (struct stack_elle * in, int
key);




//prints.c
void printall (struct stack_elle * in);
void print_time (struct timespec * initial, struct timespec * final, int op);
void print_one_elle (struct elle * te0);




//inits.c
struct btree * init_btree ();
struct record * init_record ();
struct elle * init_elle ();




//ins0.c
int split_3 (struct btree * tr, struct elle * over);
void mv_elle (struct elle * from, struct elle * to, int from_in, int to_in);
void rs_elle (struct elle * reset, int from, int count);




//ins1.c
void insert (struct btree * tr, struct record * data);
void ins_non_ov_3 (struct elle * te3, struct record * data, int at);



//ins2.c
struct elle * search_3 (struct btree * tr, int k);
int where (struct elle * in, int k);

void BFS_iterative (struct btree* tr, struct  stack_elle * qu, struct  stack_elle * in);
