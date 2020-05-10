#include<stdio.h>
#include<stdlib.h>
#include <ctype.h> 
#include"array.h"
#include"array_void.h"

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

  ArrayVoid_ptr numbers_list = create_void_array(3);
  int a[] = {1, 2, 3};
  numbers_list->array[0] = a; 
  numbers_list->array[1] = a+1; 
  numbers_list->array[2] = a+2;

  Object result4 = map_void(numbers_list, &increment_void);
  printf("\nIncremented numbers list is:\n");
  display_number_array(result4);

  Object result5 = filter_void(numbers_list, &is_even_void);
  printf("\nEven numbers list is:\n");
  display_number_array(result5);

  return 0;
}