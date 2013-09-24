#include <stdio.h>
#include <stdlib.h>

void read(int *a, int n) {
  int i;
  for(i = 0; i < n; i++)
    scanf("%d",&a[i]);
}

int main(int argc, char** argv){
  int i, n;

  if( argc != 2 ){
    fprintf(stderr, "Uso: ./verify N\n");
    return(-2);
  }

  n = atoi(argv[1]);
  
  int *a = (int*)malloc(sizeof(int)*n);
  if (a == NULL) exit(1);

  read(a,n);


  for(i=1; i<n; i++){
    if( a[i] < a[i-1] ){
      return -1;
    }
  }
  return 0;
}
