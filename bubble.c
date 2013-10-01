/* BubbleSort */
#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y,buffer) do{ (buffer)=(x); (x)=(y); (y)=(buffer); }while(0)
#define MAX_IND(v,x,y) ((v[x])>(v[y])?(x):(y))
#define MIN_IND(v,x,y) ((v[x])>(v[y])?(y):(x))

#define REPEAT 5000

void read(int *a, int n) {
  int i;
  for( i=0; i<n; i++)
    scanf(", %d",&a[i]);
}

void prt(int *a, int n) {
  int i;
  for( i=0 ; i<n; i++)
    printf("%d ", a[i]);
  puts("\b");
}


int main(int argc, char** argv){
  int i, n, buffer;
  char flag;
  int size;
  int* v = (int*)malloc(sizeof(int)*size);
  int* v2= (int*)malloc(sizeof(int)*size);

  scanf(" %d", &size);
  read(v2,size);
  
  for(n=0; n<REPEAT; n++){
    for(i=0; i<size; i++){
      v[i] = v2[i];
    }

    do{
      flag = 0;
      for(i=1; i<size; i++){
	if( v[i-1] > v[i] ){ 
	  SWAP(v[i-1],v[i],buffer);
	  flag=1; // Sinaliza troca
	}
      }
    }while(flag); // Repita se houve alguma troca
  }

  free(v);
  free(v2);
  return 0;
}
