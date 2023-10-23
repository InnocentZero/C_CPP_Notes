uint64_t power(uint64_t a, uint64_t b){
    if (b == 0) return 1;
    uint64_t r = power(a, b/2);
    if (b%2 == 1) return a*r*r;
    return r*r;
}
