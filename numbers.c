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

int main(void)
{
  Array_Ptr numbers = create_array(3);
  int numbers_array[3] = {1, 2, 3};
  copy(numbers, numbers_array);

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