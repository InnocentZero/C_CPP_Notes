
uint64_t square_root(uint64_t n){
    uint64_t ans;
    uint64_t start = 1, end = n, mid = (n+1)/2;
    while (end - start > 1){
        if (mid*mid < n){
            start = mid;
            mid = (end - start)/2 + start;
        } else if(mid*mid > n){
            end = mid;
            mid = (end - start)/2 + start;
        } else {
            break;
        }
    }
    ans = mid;
    return ans;
}

