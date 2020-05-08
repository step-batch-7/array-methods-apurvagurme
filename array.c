#include<stdio.h>
#include<stdlib.h>
#include"array.h"

Array_Ptr create_numbers(int length)
{
  Array_Ptr numbers = malloc(sizeof(Array));
  numbers->array = malloc(sizeof(int) * length); 
  numbers->length = length;
  return numbers;
}

Array_Ptr map(Array_Ptr numbers, Mapper double_elements)
{
  Array_Ptr result = create_numbers(numbers->length);
  for (int i = 0; i < numbers->length; i++)
  {
    result->array[i] = double_elements(numbers->array[i]);
  }
  return result;
}

Array_Ptr filter(Array_Ptr numbers, Predicate greater_than_0)
{
  int result[numbers->length];
  int count = 0;
  for (int i = 0; i < numbers->length; i++)
  {
    Bool status = greater_than_0(numbers->array[i]);
    if (status == True)
    {
      result[count] = numbers->array[i];
      count++;
    }
  }
  Array_Ptr filtered_list = create_numbers(count);
  for (int i = 0; i < count; i++)
  {
    filtered_list->array[i] = result[i];
  }
  return filtered_list;
}

int reduce(Array_Ptr numbers, int init, Reducer add)
{
  for (int i = 0; i < numbers->length; i++)
  {
    init = add(numbers->array[i], init);
  }
  return init;
}
