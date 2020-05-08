#ifndef __ARRAY_H
#define __ARRAY_H
typedef enum
{
  False,
  True
} Bool;

typedef int * Int_Ptr;
typedef int (*Mapper)(int);
typedef Bool (*Predicate)(int);
typedef int (*Reducer)(int, int);

typedef struct
{
  int *array;
  int length;
} Array;

typedef Array * Array_Ptr;
Array_Ptr map(Array *src, Mapper mapper);
Array_Ptr filter(Array *src, Predicate predicate);
int reduce(Array *src, int init, Reducer reducer);
Array_Ptr create_numbers(int length);

#endif
