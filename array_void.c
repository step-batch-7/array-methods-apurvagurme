#include"array_void.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h> 

void display_number_array(ArrayVoid_ptr array)
{
  for (int index = 0; index < array->length; index++)
  {
    printf("%d\n", *(int *)array->array[index]);
  }
  printf("\n");
}

ArrayVoid_ptr create_void_array(int length)
{
  ArrayVoid_ptr numbers = malloc(sizeof(ArrayVoid));
  numbers->array = malloc(sizeof(Object) * length); 
  numbers->length = length;
  return numbers;
}

Object increment_void(Object num)
{
  int incremented_value = (*(int *)num + 1);
  Object incremented_void_value = malloc(sizeof(int));
  memcpy(incremented_void_value, &incremented_value, sizeof(int));
  return (Object) incremented_void_value;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr result = create_void_array(src->length);
  int count = 0;
  for (int i = 0; i < src->length; i++)
  {
    result->array[count] = mapper(src->array[i]);
    count++;
  }
  return result;
}

void copy_void(ArrayVoid_ptr into, Object from[])
{
  for (int i = 0; i < into->length; i++)
  {
    into->array[i] = (Object)(long int)from[i];
  }
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  Object result[src->length];
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
  ArrayVoid_ptr filtered_list = create_void_array(count);
  copy_void(filtered_list, result);
  return filtered_list;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  for (int i = 0; i < src->length; i++)
  {
    init = reducer(src->array[i], init);
  }
  return init;
}
