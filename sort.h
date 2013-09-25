/* sort.h: Define some functions and constants for sorting */
/* By Fernando Pereira */

#ifndef SORT_H
#define SORT_H

#define SWAP(x,y,buffer) do{ (buffer)=(x); (x)=(y); (y)=(buffer); }while(0); 
#define MAX_IND(v,x,y) ((v[x])>(v[y])?(x):(y))
#define REPEAT 1000


#endif
