/**Sort a set of n numbers using quick sort --not optmized**/
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define MED_IND(v,i,j,k) (MIN_IND((v),(MAX_IND((v),(i),(j))), (MAX_IND((v),(j),(k)))))
#define SPOT 5

#define P(x) (printf("\tPOINT %d\n", (x)))

int partit(int *a, int l, int r) {
  int pivot = l;  
  int left = l;
  int right = r;
  
  if( (l - r) >= 2 ){ // pelo menos duas posiçoes
    pivot = MED_IND(a, l, (l+1), (l+2));
  }


  // prt(a,10); printf("PIVOT: v[%d] = %d\n", pivot, *(a+pivot));

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


void insertionSort(int *v, int size){
  int i, j, k, aux;
  // P(1);
  for(i=1; i<size; i++){
    for(j=0; j<i; j++){
      if( v[i] < v[j] ){
	aux = v[i];
	for( k=i; k>j; k--){
	  v[k] = v[k-1];
	}
	v[j] = aux;
	break;
      }
    }
  }

  // printf("\t\tOrg no Insertion: TAM: %d, ", size); prt(v,size); puts("");

}



void quickSort(int *a, int l, int r) {
  int pivot;
  
  if ( (r-l) > SPOT) {
    pivot = partit(a,l,r);
    
    quickSort(a,l,pivot-1);
    quickSort(a,pivot+1,r);
  } else if (r > l) {
    insertionSort( (a+l), (r-l+1) ); 
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
  // puts("");
  
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

    //  prt(a,n);

  free(a);
  free(b);
  return 0;
}
 
