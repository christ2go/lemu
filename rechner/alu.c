// alu.c

/*
 * Emulation of a 64-Bit Arithmetic Logical Unit 
 */
#include <stdio.h>
#include "rechner.h"
int carry = 0; // Carryflag
int accu[pc_size];

int int_pow(int base,int exponent)
{
  if(exponent == 0)
    return 1;
  if(exponent == 1)
    return base;
  int result = base;
  for(int i = 1;i<exponent;i++)
  {
    result *= base;
  }
  return result;
}
int dectobin(int bin[pc_size])
{
  int erg = 0;

  for(int i = pc_size-1;i>=0;i--)
  {
    if(bin[i] == 1)
    {
      erg += int_pow(2,pc_size-1-i);
    }
  }
  return erg;
}
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

void subtract(int a[pc_size],int b[pc_size])
{
  // Negate b
  int temp[pc_size];
  setnull(temp);
  arrcpy(temp,b);
  negate(temp);
  int one[pc_size];
  setnull(one);
  one[pc_size-1] = 1; 
  add(temp,one);
  add(a,temp);

}
void printres(int array[pc_size])
{
  for(int i = 0;i<pc_size;i++)
    printf("%i ",array[i]);
  printf("\n");
}

