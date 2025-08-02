#include "../headers/first_util.h"  // include header
// No need to include iostream unless you print here

int getGCD(int a, int b){
    if(b==0)
        return a;
    return getGCD(b, a%b);
}   