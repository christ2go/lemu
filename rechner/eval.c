//eval.c
#include "rechner.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int acc[pc_size];
void setnull(int a[pc_size])
{
	for(int i = 0;i<pc_size;i++)
		a[i] = 0;
}
void eval(command* rootnode)
{
	int* ram = NULL;
	for(int i = 0;i<count_nodes(rootnode);i++)
	{

		// GETNODE
		command* node = getnode(rootnode,i);
		if(strcmp(node->command,"DEFRAM") == 0)
		{
			printf("Allocating ram\n");
			ram = malloc(sizeof(int)*pc_size*node->arg);
			printf("%lu k RAM allocated.\n",sizeof(int)*pc_size*node->arg);
		}

		if(strcmp(node->command,"SETACC") == 0)
		{
			// Sets the accumulator to a value, specified by arg
			setnull(acc);
			printf("\n");
			node->arg = node->arg;
			converttobinary(acc,node->arg);
		}
		if(strcmp(node->command,"LDA") == 0)
		{
			// Stores an inte
			for(int i=0;i<pc_size;i++)
				acc[i] = ram[pc_size*node->arg+i];
		}
		if(strcmp(node->command,"SPA") == 0)
		{
			// Store accu in register
			for(int i=0;i<pc_size;i++)
				ram[pc_size*node->arg+i] = acc[i];

		}
		// Check for those little things
		if(strcmp(node->command,"DBG") == 0)
		{
			printres(acc);
		}
		if(strcmp(node->command,"JMP") == 0)
			i = node->arg-1;
		if(strcmp(node->command,"ADD") == 0)
		{
			int cell[pc_size];
			setnull(cell);
			for(int i=0;i<pc_size;i++)
				cell[i] = ram[pc_size*node->arg+i];
			add(acc,cell);
		} 


	}
	if(ram != NULL)
		free(ram);
}