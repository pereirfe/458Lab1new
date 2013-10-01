/* Prints a random numbers' vector of size given */
/* By Fernando Pereira, 05/09/2013               */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SWAP(x,y,buffer) do{ (buffer)=(x); (x)=(y); (y)=(buffer); }while(0)
#define MAX_IND(v,x,y) ((v[x])>(v[y])?(x):(y))
#define MIN_IND(v,x,y) ((v[x])>(v[y])?(y):(x))

#define REPEAT 5000
#define MAX 10000


int ord(const void* a, const void* b){
  if(*(int*)a > *(int*)b) return 1;
  return -1;
}


int quickV(int* a, int n){
  int half = n/2;
  int buffer;
  int i;

  if( n > 1 ) {
    SWAP(a[half],a[n-1],buffer);
    qsort(a,n-1,sizeof(int),ord);
    quickV(a, half);
    quickV(a+half, n-half-1);
  }
}




int rev(const void* a, const void* b){
  if(*(int*)a < *(int*)b) return 1;
  return -1;
}


int ale(const void* a, const void* b){
  return 0;
}



int main(int argc, char* argv[] ) {
  int size, i;
  char opt;
  int *v, *v2;
  int max;
  int half, buffer;
  int t = 1;

  if(argc != 3 ){
    fprintf(stderr, "Uso: ./numgen tamanho tipo\n\t a: aleatorio\n\t o: ordenado\n\t r: ordenado reverso\n\t i: iguais\n\t t: alternado\n\t m: alternado para merge(pior caso)\n\n");
    exit(-1);
  }
  

  size = atoi(argv[1]);
  opt = argv[2][0];
  v = (int*)malloc(sizeof(int)*size);

  srand(time(0));

  max = size>MAX? size:MAX;

  for(i=0; i<size; i++){
    v[i] = rand()%max;
  }
  
  switch(opt){
  case 'a':
    break;
  case 'o':
    qsort(v,size,sizeof(int),ord);
    break;
  case 'r':
    qsort(v,size,sizeof(int),rev);
    break;
  case 'i':
    for(i=1; i<size; i++){
      v[i] = v[0];
    }
    break;
  case 't':
    qsort(v,size,sizeof(int),ord);
    quickV(v,size);
    break;
  case 'm':
    while(t<size){
      for(i=0; i<t; i++){
	v[t+i] = v[i] + 1;
	v[i]*=2;
	v[t+i]*=2;
      }
      t*=2;
    }

    half = size/2;
    for(i=0; i<half/2; i++){
      SWAP(v[i],v[half-i-1], buffer);
      SWAP(v[i+half],v[size-i-1],buffer);
    }
    break;

  default:
    puts("ERRO!!!");
  }

  for(i=0; i<size; i++){
    printf(", %d", v[i]);
  }

  free(v);
  free(v2);
  printf("\n");
}
