// Emulator des LOCAD RECHNER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rechner.h"

int main(int argc, char* argv[])
{
  if(argc != 2)
  {
    printf("The correct syntax would be ./rechner <filename>, %i arguments are not allowed.",argc-1);
    return 1;
  }
  
  FILE* f = fopen(argv[1],"r");
  command* firstcommand = malloc(sizeof(struct command)); 
  firstcommand->command = malloc(sizeof(char)*256);
  strcpy(firstcommand->command,(char *)"first");
  firstcommand->arg = 0;
  firstcommand->next = NULL;
  // Read the first line
  while(!feof(f))
  {
    char* first  = malloc(sizeof(char)*256);
    int second;
    fscanf(f,"%s %i",first,&second); // Read the 3 arguments
    command* toappend = malloc(sizeof(command));
    toappend->command = malloc(sizeof(char)*256);
    strcpy(toappend->command,"");
    strcpy(toappend->command,first);
    toappend->arg = 0;
    toappend->arg = second;
    toappend->next = NULL;
    hash_append(firstcommand,toappend);
    free(first);
  }
  print_hash(firstcommand);
  eval(firstcommand);
  // Everything is ready for execution
  unload_hash(firstcommand);
  
  fclose(f);
  return 0;
}

