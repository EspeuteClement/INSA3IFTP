#include <stdio.h>

void exchange(int t[], int p1, int p2)
{
  int buffer = t[p1];
  t[p1]=t[p2];
  t[p2]=buffer;
}

void display(int t[], int size)
{
  int i;
  for(i=0; i<size; i++)
    printf("%d ", t[i]);
  printf("\n");
}


void bubblesort(int t[], int size)
{
  int permut = 1;
  int i = size;
  while (i > 0 && permut)
  {
    permut = 0;
    for(int j = 0; j < i - 1; j++)
    {
      if(t[j]>t[j+1])
      {
        exchange(t, j, j+1);
        permut=1;
      }
    }
    i--;
  }
}


double mean(int t[], int size)
{
  if (size != 0) {
    int i;
    double sum=0;
    for(i = 0; i < size; i++)
      sum += t[i];
    sum /= size;
    return sum;
  }
  return 0;
}

int main()
{
  int tab1[] = {5, 4, 3, 6, 2, 1};
  int tab2[] = {3, 1, 17, 4, 10, 1};
  int tab3[] = {};

  bubblesort(tab1, 6);
  bubblesort(tab2, 6);
  bubblesort(tab3, 0);

  display(tab1, 6);
  display(tab2, 6);
  display(tab3, 0);

  printf("mean tab1: %f\n", mean(tab1, 6));
  printf("mean tab2: %f\n", mean(tab2, 6));
  printf("mean tab3: %f\n", mean(tab3, 0));
  return 0;
}
