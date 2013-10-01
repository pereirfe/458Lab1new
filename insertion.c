/* InsertionSort */
#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y,buffer) do{ (buffer)=(x); (x)=(y); (y)=(buffer); }while(0)
#define MAX_IND(v,x,y) ((v[x])>(v[y])?(x):(y))
#define MIN_IND(v,x,y) ((v[x])>(v[y])?(y):(x))

#define REPEAT 5000

void read(int *a, int n) {
  int i;
  for(i = 0; i < n; i++)
    scanf(", %d",&a[i]);
}

int main(int argc, char** argv){
  int i, j, k, m, buffer;
  int aux; // candidate
  char flag;
  int size;
  int* v = (int*)malloc(sizeof(int)*size);
  int* v2= (int*)malloc(sizeof(int)*size);

  scanf(" %d", &size);
  read(v2,size);

  for(m=0; m<REPEAT; m++){
    
    for(i=0; i<size; i++){
      v[i] = v2[i];
    }

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
  }

  
  free(v);
  free(v2);
  return 0;
}
