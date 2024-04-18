#include <stdio.h>

union Test{
 long odd;
 short even;
};

int main(void) 
{
  const int size = 10;
  union Test unions[size];
  for(int i=0; i<size; i++)
    {
      if(i % 2 == 0)
      {
        unions[i].even = i;
      }
      else
      {
        unions[i].odd = i;
      }
    }
  printf("\n Odd : ");
  for(int i=1; i<size; i=i+2)
    {
      printf("%ld\n", unions[i].odd);
    }
  printf("\n Even: ");
  for(int i=0; i<size; i=i+2)
    {
      printf("%d\n", unions[i].even);
    }
}