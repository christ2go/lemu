// alu.c

/*
 * Emulation of a 64-Bit Arithmetic Logical Unit 
 */
#include <stdio.h>
#include "rechner.h"
int carry = 0; // Carryflag
int accu[pc_size];

void converttobinary(int result[pc_size],int dec)
{
      int d[pc_size];
      setnull(d);
      int i = 0;
      while(dec>0) 
      { 
           d[i]=dec%2; 
           i++; 
           dec=dec/2;
      }

      for(i = pc_size;i>=0;i--)
      {
        result[pc_size-1-i] = d[i];
      }
}
int add(int a[pc_size],int b[pc_size])
{
  int result[pc_size];
  int c = 0; // Carry flag
  // Function to add two numbers
  for(int i = pc_size;i>=0;i--)
  {
    int r = a[i] + b[i] + c;
    switch(r)
    {
      case 1:
	c = 0;
	r = 1;
	break;
      case 2:
	c = 1;
	r = 0;
	break;
      case 3:
	c = 1;
	r = 1;
	break;
    }
    
    // Append result to new array
    a[i] = r;
  }
  if(c == 1)
  {
    
    // Speicherüberlauf
    
  }
}

void negate(int array[pc_size])
{
  //for(;;;){}
  for(int i = 0 ;i < pc_size ; i++)
  {
    array[i] = !array[i];
    
  }
}

void printres(int array[pc_size])
{
  for(int i = 0;i<pc_size;i++)
    printf("%i ",array[i]);
  printf("\n");
}

void subtract(int a[pc_size],int b[pc_size])
{
  
}