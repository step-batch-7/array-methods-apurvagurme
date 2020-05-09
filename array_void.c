#include"array_void.h"
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h> 

ArrayVoid_ptr create_void_array(int length)
{
  ArrayVoid_ptr numbers = malloc(sizeof(ArrayVoid));
  numbers->array = malloc(sizeof(Object) * length); 
  numbers->length = length;
  return numbers;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr result = create_void_array(3);
  int count = 0;
  for (int i = 0; i < src->length; i++)
  {
    result->array[count] = mapper(src->array[i]);
    count++;
  }
  return result;
}
