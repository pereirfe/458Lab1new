/**Sort a set of n numbers using quick sort --not optmized**/
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define P(x) do{ fprintf(stderr, "PTO %d\n", x); }while(0)


int partit(int *a, int l, int r) {
  int pivot = a[l];
  int left = l;
  int right = r;
  while(left < right) {
    while(a[left] <= pivot) left++;
    while(a[right] > pivot) right--;
    if (left < right) {
      int t = a[left];
      a[left] = a[right];
      a[right] = t;
    }
  }
  a[l] = a[right];
  a[right] = pivot;
  return right;
}

void quickSort(int *a, int l, int r) {
  int pivot;
  if (r > l) {
    pivot = partit(a,l,r);
    quickSort(a,l,pivot-1);
    quickSort(a,pivot+1,r);
  }
}

void read(int* a, int n) {
  int i;
  for(i = 0; i < n; i++)
    scanf(", %d",&a[i]);
}

void prt(int* a, int n) {
  int i;
  for(i = 0; i < n; i++)
    printf("%d ",a[i]);
  puts("");
  
}


int main(int argc, char **argv) {
  int n, i, j, *b, *a;

  scanf(" %d", &n);
  a = (int*)malloc(sizeof(int)*n);
  b = (int*)malloc(sizeof(int)*n);
  if (a == NULL || b == NULL){
    puts("Malloc falhou!");
    exit(1);
  }
	
  read(b,n);
	
  for(j=0; j<REPEAT; j++){
    for(i=0; i<n; i++){
      a[i] = b[i];
    }
    quickSort(a,0,n-1);
  }

  //prt(a,n);

  free(a);
  free(b);
  return 0;
}
