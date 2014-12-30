// hash.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rechner.h"
int hash_append(command* rootnode,command* newnode)
{
  command* nextnode = rootnode;
  while(nextnode->next != NULL)
    nextnode = nextnode->next;
  nextnode->next = newnode;
  
}

void print_hash(command* rootnode)
{
  command* nextnode = rootnode;
  while(nextnode->next != NULL)
  {
    nextnode = nextnode->next;
    printf("NODE %s %i \n",nextnode->command,nextnode->arg);
    
  }

}
void unload_hash(command *rootnode)
{
	command *tmp = rootnode;
	command *fwd;

	while(tmp != NULL) {
		fwd = tmp->next;
		free(tmp->command);
		free(tmp);	
		tmp = fwd;
	}
}
int count_nodes(command *rootnode)
{
  int i = 0;
  command* nextnode = rootnode;
  while(nextnode->next != NULL)
  {
    nextnode = nextnode->next;
    i++;
  }
  return i;
  
}
command* getnode(command *rootnode)
{
  
  
  
}