#include<stdio.h>
#include<stdlib.h>
#include"array.h"

void display(Int_Ptr array, int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%d\n", array[i]);  
  }
}

int double_elements(int number)
{
  return number * 2;
}

int add(int previous, int a)
{
  return previous + a;
}

Bool greater_than_0(int number)
{
  Bool is_greater = number > 0 ? True : False;
  return is_greater;
}

int main(void)
{
  Array_Ptr numbers = create_array(3);
  numbers->array[0] = 1;
  numbers->array[1] = 2;
  numbers->array[2] = 3;

  Array_Ptr result1 = map(numbers, &double_elements);
  printf("\nMapped List is:\n");
  display(result1->array, result1->length);

  int result2 = reduce(numbers, 0, &add);
  printf("\nReduced result is:\n");
  printf("Sum is: %d\n", result2);

  Array_Ptr result3 = filter(numbers, &greater_than_0);
  printf("\nFiltered List is:\n");
  display(result3->array, result3->length);
  return 0;
}