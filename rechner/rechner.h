#ifndef _INCL_GUARD
#define _INCL_GUARD

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
#endif