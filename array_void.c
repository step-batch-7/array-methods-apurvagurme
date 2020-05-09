#include"array_void.h"
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h> 

Object increment_void(Object num)
{
  long int number = (long int )num;
  Object result = (Object)(number + 1);
  return result;
}

void display_number_array(ArrayVoid_ptr array)
{
  for (int index = 0; index < array->length; index++)
  {
    printf("%d\n", (int)array->array[index]);
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

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  for (int i = 0; i < src->length; i++)
  {
    init = reducer(src->array[i], init);
  }
  return init;
}
