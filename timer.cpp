#include <iostream>
#include <cstdio>
#include <ctime>
#include <sys/time.h>
#include <string>


// USAR ASPAS PARA PASSAR PARAMETROS

int main(int argc, char* argv[]) {
    std::clock_t start;
    double duration;
    std::string a = "./";
    timeval tin, tf;
    double t1,t2;

    if(argc != 2){
      fprintf(stderr, "TIMER: Algoritmo nao especificado\n");
      exit(-1);
    }
        
    a = a + argv[1];
    
    ::gettimeofday(&tin, NULL);
    system(a.c_str());
    ::gettimeofday(&tf, NULL);
    
    t1 = tf.tv_sec+(tf.tv_usec/1000000.0) - tin.tv_sec+(tin.tv_usec/1000000.0);
    std::cout<< t1;
    
    return 0;
}
