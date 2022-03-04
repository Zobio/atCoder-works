//monte.cpp
#include <iostream>
#include <random>
using namespace std;

#define NUM 10000000

int main(int argc, char const *argv[])
{
    random_device rnd;
    mt19937 mt(rnd());
    uniform_real_distribution<double> score(0.0,1.0);
    double x, y;
    int counter=0;
    for(int i=0;i<NUM;i++){
        x=score(mt);
        y=score(mt);
        if(x*x + y*y < 1.0){
            counter++;
        }
    }
    double pi=4.0*counter/NUM;
    printf("%f\n",pi );
    return 0;
}