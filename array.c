#include<stdio.h>
#include<stdlib.h>
#include"array.h"

Array_Ptr create_array(int length)
{
  Array_Ptr numbers = malloc(sizeof(Array));
  numbers->array = malloc(sizeof(int) * length); 
  numbers->length = length;
  return numbers;
}

Array_Ptr map(Array_Ptr src, Mapper mapper)
{
  Array_Ptr result = create_array(src->length);
  for (int i = 0; i < src->length; i++)
  {
    result->array[i] = mapper(src->array[i]);
  }
  return result;
}

Array_Ptr filter(Array_Ptr src, Predicate predicate)
{
  int result[src->length];
  int count = 0;
  for (int i = 0; i < src->length; i++)
  {
    Bool status = predicate(src->array[i]);
    if (status == True)
    {
      result[count] = src->array[i];
      count++;
    }
  }
  Array_Ptr filtered_list = create_array(count);
  for (int i = 0; i < count; i++)
  {
    filtered_list->array[i] = result[i];
  }
  return filtered_list;
}

int reduce(Array_Ptr src, int init, Reducer reducer)
{
  for (int i = 0; i < src->length; i++)
  {
    init = reducer(src->array[i], init);
  }
  return init;
}
