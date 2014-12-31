#ifndef _INCL_GUARD
#define _INCL_GUARD
#define pc_size 8
// rechner.h
struct command
{
  char* command;
  int arg;
  struct command* next;
};

typedef struct command command;
int main(int argc, char* argv[]);
int hash_append(command* rootnode,command* newnode);
void print_hash(command* rootnode);
void unload_hash(command* rootnode);
int count_nodes(command *rootnode);
command* getnode(command *rootnode,int nr);

void eval(command* rootnode);
int add(int a[pc_size],int b[pc_size]);
void negate(int array[pc_size]);
void printres(int array[pc_size]);
void subtract(int a[pc_size],int b[pc_size]);
void setnull(int a[pc_size]);
void printres(int array[pc_size]);
void converttobinary(int result[pc_size],int decimalno);

#endif