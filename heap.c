/* Heapsort */
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define DEBUG 

#define FATHER(x) ((x)>0? ((((x)+1)/2)-1):0)
#define SON_L(x)  ((2*((x)+1))-1)
#define SON_R(x)  ((2*((x)+1)))

void read(int *a, int n) {
  int i;
  for(i = 0; i < n; i++)
    scanf("%d",&a[i]);
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
  } while(1); // eliminaรงao de recursao caudal
}

int main(int argc, char** argv){
  int i, j, k, buffer, father;
  int size;
  int* v = (int*)malloc(sizeof(int)*size);
  int M, sonR, sonL;
  
  if( argc != 2 ){
    fprintf(stderr, "Uso: ./heap N");
    exit(-1);
  }

  size = atoi(argv[1]);
  read(v,size);

  /* Heap construction */
  for(i=1; i<size; i++){
    j=i;
    father = FATHER(i);
    while( v[father] < v[j]){
      SWAP( v[father], v[j], buffer);
      j = father;
      father = FATHER(father);
    }
  }

  /* Sorting */  
  for(i=size-1; i>0; i--){
    SWAP(v[0], v[i], buffer);
    restore(v, 0, i-1);
  }  

#ifdef DEBUG
  for(j=0; j<size; j++){
    printf("%d,", v[j]);
  }
  puts("\b");
#endif
  
  return 0;
}
