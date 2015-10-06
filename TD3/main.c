#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int allocated; /* current allocation of array */
  int filled;    /* number of items present in the binheap */
  int *array;    /* array of values */
} BinaryHeap;

/* Init allocates the structure BinaryHeap and
 * also the membre array with the given size 
 * it also fill allocated (size) and intializes 
 * filled to 0 */
BinaryHeap * Init(int size);

/* InsertValue insert value into the binary heap
 * the array is reallocated if necessary (allocated changed 
 * with respect to the new size )
 * filled is incremented by 1 */
void InsertValue(BinaryHeap * heap, int value);

/* ExtractMax returns 0 if the binary heap is empty
 * otherwise it return 1 and fills *val with the maximum 
 * value present in the binary heap
 * filled is decremented by 1  and the max value is removed
 * from the binary heap */
int ExtractMax(BinaryHeap * heap, int * val);

/* Destroy frees the structure and the array */
void Destroy(BinaryHeap * heap);

/* Get the left value of the nth element in the heap*/
int GetLeft(int n) {return n*2+1;};

/* Get the right value of the nth element in the heap*/
int GetRight(int n) {return n*2+2;};

/* Swap two values */
void Swap(int *a, int *b);

/* Reform the heap */
void ReformHeap(BinaryHeap * heap);

int main(void) 
{

  char lecture[100];
  int val;
  BinaryHeap * heap;
  heap = Init(10);
  fscanf(stdin,"%99s",lecture);
  while (strcmp(lecture,"bye")!=0) {
    if (strcmp(lecture,"insert")==0) {
      fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);
      InsertValue(heap,val);
    } else if (strcmp(lecture,"extract")==0) {
      if(ExtractMax(heap,&val))
      {
        printf("%d\r\n",val);
      }
    }
    fscanf(stdin,"%99s",lecture);
  }
  Destroy(heap);
  return 0;
}

BinaryHeap * Init(int size)
{
  BinaryHeap * heap;
  heap = malloc(sizeof(BinaryHeap));
  heap->array = malloc(size * sizeof(int));
  heap->allocated = size;
  heap->filled = 0;
  return heap;
}

void InsertValue(BinaryHeap * heap, int value)
{
  if (heap->filled+2 == heap->allocated){
      heap->allocated += 1;
      int *tmp = malloc(heap->allocated * sizeof(int));
      memcpy(tmp,heap->array,(heap->allocated-1) * sizeof(int));
      free(heap->array);
      heap->array = tmp;
  }
  heap->array[heap->filled] = value;
  int position = heap->filled;
  heap->filled++;
  int father = (position-1)/2;
  while(position > 0 && heap->array[father] < heap->array[position]){
    Swap(&(heap->array[father]),&(heap->array[position]));
    position = father;
    father = (position-1)/2;
  }

}

int ExtractMax(BinaryHeap * heap, int *res)
{
  if (heap->filled == 0)
    return 0;
  *res = heap->array[0];
  heap->array[0] = heap->array[heap->filled];
  heap->array[heap->filled] = 0;
  heap->filled--;

  ReformHeap(heap);
  return 1;
}

void ReformHeap(BinaryHeap * heap){
  int position = 0;
  int * array = heap->array;
  while (position < heap->filled)
  {
    if (array[position] < array[GetLeft(position)] && array[position] < array[GetLeft(position)])
    {
      if (array[GetLeft(position)] > array[GetRight(position)]){
        Swap(&(array[position]),&(array[GetLeft(position)]));
        position = GetLeft(position);
      }
      else
      {
        Swap(&(array[position]),&(array[GetRight(position)]));
        position = GetRight(position);
      }
    }
    else if (array[position] < array[GetLeft(position)]){
      Swap(&(array[position]),&(array[GetLeft(position)]));
      position = GetLeft(position);
    }
    else if (array[position] < array[GetRight(position)]){
      Swap(&(array[position]),&(array[GetRight(position)]));
      position = GetRight(position);
    }
    else {
      break;
    }
  }
}

void Destroy(BinaryHeap * heap)
{
  free(heap->array);
  free(heap);
}

void Swap(int *a, int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
