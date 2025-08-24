int getGCD(const int a, const int b){
    if(b==0)
        return a;
    return getGCD(b, a%b);
}