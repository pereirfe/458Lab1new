/**Sort a set of n numbers using quick sort --not optmized**/
#include <stdio.h>
#include <stdlib.h>

#define MED(i,j,k,v) do{ v[i] <= v[j] :            }while(0)

int *a = 0;

int partit(int l, int r) {
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

void quickSort(int l, int r) {
  int pivot;
  if (r > l) {
    pivot = partit(l,r);
    quickSort(l,pivot-1);
    quickSort(pivot+1,r);
  }
}

void read(int* b, int n) {
  int i;
  for(i = 0; i < n; i++)
    scanf("%d",&b[i]);
}


int main(int argc, char **argv) {
  int n, i, j, *b;

  if( argc != 2 ){
    fprintf(stderr, "Uso: ./quick N");
    exit(-1);
  }
  n = atoi(argv[1]);
  a = (int*)malloc(sizeof(int)*n);
  b = (int*)malloc(sizeof(int)*n);
  if (a == NULL || b == NULL){
    puts("Malloc falhou!");
    exit(1);
  }
	

	
  read(b,n);
	
  for(j=0; j<5000; j++){
    for(i=0; i<n; i++){
      a[i] = b[i];
    }
    quickSort(0,n-1);
  }

  //	for(i=0;i<n; i+=10000){
  // printf("%d ", a[i]);
  //}

  free(a);
  free(b);
  return 0;
}
