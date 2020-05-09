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

typedef Array *Array_Ptr;
Array_Ptr map(Array_Ptr src, Mapper mapper);
Array_Ptr filter(Array_Ptr src, Predicate predicate);
int reduce(Array_Ptr src, int init, Reducer reducer);
Array_Ptr create_array(int length);
int double_elements(int number);
int add(int previous, int a);
Bool greater_than_0(int number);
void copy(Array_Ptr into, int from[]);

#endif
