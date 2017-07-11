#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
#include<windows.h>
// MAIN FUNCTIONS:
void linkedlist();
void stackk();
void Queues();
void searching();

//single linked list
void  singlell();
struct node *create_list(struct node *);
void display(struct node *);
struct node *addatbeg(struct node *,int);
struct node *addatend(struct node *,int );
struct node *addafter(struct node *,int ,int );
struct node *addbefore(struct node *,int ,int );
struct node *addatpos(struct node *,int ,int );
struct node *del(struct node *,int );
struct node *reverse(struct node *);
struct node *addatbeg(struct node *,int );


//double linked list
void doublell();
struct node *createdll(struct node *);
void displaydll(struct node *);
struct node *insert_empty(struct node *,int );
struct node *add_at_beg(struct node *,int );
struct node *add_atend(struct node *,int );
struct node *add_after(struct node *,int ,int );
struct node *add_before(struct node *,int ,int );
struct node *delete(struct node *,int );
//circular linked list
void circularll();
struct node *createcll(struct node *);
void displaycll(struct node *);
struct node *addempty(struct node *,int);
struct node *insert_beg(struct node *,int);
struct node *insert_end(struct node *,int );
struct node *insert_after(struct node *,int ,int );
struct node *deletion(struct node *,int );

//linked stack
void llstack();
void push(int );
int pop();
int peek();
int isEmpty();
void displaylstack();

// Array stack
void arr_stack();
void push_item(int );
int pop_item();
int PEEK();
int isempty();
int isfull();
void displaystack();

//array queue
void aqueue();
void insert_it(int );
int del_it();
int Peek();
void displayaq();
int Full();
int Empty();

// Circular queue
void cirqueue();
void display_cq( );
void insert_cq(int);
int del_cq();
int PEEKQ();
int EMPTY();
int FULL();
// Dequeue
void de_que();
void insert_dfrontEnd(int );
void insert_drearEnd(int );
int delete_dfrontEnd();
int delete_drearEnd();
void display_dq();
int DQisEmpty();
int DQisFull();
 // Priority queue
 void priorqueue();
 void insert_data(int item, int item_priority);
int del_data();
void display_pq();
int PQisEmpty();
// Searching
void lisearch();
int Linearsearch(int arr[], int n, int item);
int bisearch();
int BinarySearch(int arr[], int size, int item);
int fibo_search();
int fibo(int [],int );
int fibonacci(int [],int ,int ,int [],int ,int ,int ,int ,int );

//heap sort
void heapsort();
void heap_sort(int arr[], int size);
void buildHeap(int arr[], int size);
int del_root(int arr[], int *size);
void restoreDown(int arr[], int i, int size );
void display_h(int arr[], int n);
//sorting
void Select_sort();
void Insert_sort();
void Bubble_sort();
void merge_sort();
void div_conq(int [],int ,int );
void merge(int [],int [],int ,int , int ,int );
void out_arr(int [],int [],int ,int );
// trees
void avltree();
void appstack();
void appqueue();
