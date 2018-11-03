long double power(long double num, int p){
    long double prod = 1;
    while(p > 0){
        if(p&1) prod = prod * num;
        num *= num;
        p >>= 1;
    }
    return prod;
}
