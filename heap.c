/* Heapsort */
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


#define FATHER(x) (((x)-1)/2)
#define SON_L(x)  (2*(x) + 1)
#define SON_R(x)  (2*(x) + 2)


void read(int *a, int n) {
  int i;
  for(i = 0; i < n; i++)
    scanf(", %d",&a[i]);
}

void restore(int v[], int root, int size){
  int sonL, sonR, buffer;
  int newr, maxi;

  do{
    if(root > size) return;
    sonL = SON_L(root);
    sonR = SON_R(root);

    if(sonL > size) return;  //sem filhos

    if(sonR > size){ // lado esquerdo, apenas
      if(v[sonL] < v[root]){
	return;
      }

      SWAP(v[sonL], v[root], buffer);
      newr = sonL;  
  
    } else {
      maxi = MAX_IND(v,sonL,sonR);
    
      if(v[maxi] < v[root]) {
	return;
      } 
    
      SWAP(v[maxi],v[root],buffer);
      newr=maxi;
    }
    root = newr;

  } while(1); // eliminacao de recursao caudal
}

int main(int argc, char** argv){
  int i, j, k, buffer, father;
  int size;
  int* v;
  int M, sonR, sonL;
  
  scanf(" %d", &size);
  read(v,size);
  v = (int*)malloc(sizeof(int)*size);

  for(k=0; k<REPEAT; k++){
    for(i=1; i<size; i++){  /* Heap construction */
      j=i;
      father = FATHER(i);
      while( v[father] < v[j]){
	SWAP( v[father], v[j], buffer);
	j = father;
	father = FATHER(father);
      }
    }

    for(i=1; i<size; i++){     /* Sorting */  
      SWAP(v[0], v[size-i], buffer);
      restore(v, 0, (size-i-1));
    }  
  }
  return 0;
}
