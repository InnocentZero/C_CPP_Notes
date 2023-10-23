uint64_t findgcd(uint64_t a, uint64_t b){
    return b? findgcd(b, a%b): a;
}
