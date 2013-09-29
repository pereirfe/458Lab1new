/**Sort a set of n numbers using merge sort --not optmized**/
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define SPOT 20


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

//Merge two halves of the array
void mergeS(int *a, int n) {
    int i, j, k, half;
    half = n/2;

    int *temp = (int*)malloc(sizeof(int)*n);
    if (!temp) exit(1);

    i = 0;
    j = half;
    k = 0;

    while (i < half && j < n) {
        if (a[i] > a[j]) {
            temp[k] = a[j];
            ++j;
        } else {
            temp[k] = a[i];
            ++i;
        }
        ++k;
    }
        if ( i == half) {
            while(j < n) {
                temp[k] = a[j];
                ++k;
                ++j;
            }

        }
            else {
                    while (i < half) {
                    temp[k] = a[i];
                    ++k;
                    ++i;
                }
            }
        for (i = 0; i < n; ++i) a[i] = temp[i];
        free(temp);
}



void mergeSort(int *a, int n) {
  if (n > SPOT) {
    int half = n/2;
    mergeSort(a,half);
    mergeSort(a + half, n - half);
    mergeS(a,n);
  } else if (n > 1){
    insertionSort(a,n);
  }
}


void read(int *a, int n) {
  int i;
  for(i = 0; i < n; i++)
    scanf(", %d",&a[i]);
}


int main(int argc, char **argv) {
  int n, i, j;

  scanf(" %d", &n);
  int *a = (int*)malloc(sizeof(int)*n);
  int *b = (int*)malloc(sizeof(int)*n);
  if (a == NULL || b == NULL){
    puts("Malloc falhou!");
    exit(1);
  }
	
  read(b,n);
	
  for(j=0; j<REPEAT; j++){
    for(i=0; i<n; i++){
      a[i] = b[i];
    }
    mergeSort(a,n);
  }

  free(b);
  free(a);
  return 0;
}


