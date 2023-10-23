#include <bits/stdc++.h>

bool p[1000001];
int initmy(){
    p[0] = false; p[1] = false;
    for (uint64_t i = 2; i < 1000001 ; i++) p[i] = true;
    for (int64_t i = 2; i  <= 1000001; i++){
        if (p[i] == 1 && p[i]*p[i] <= 1000001){
            for (uint64_t j = i*i; j <= 1000001; j += i){
                p[j] = false;
            }
        }
    }
    return 1;
}

int trash = 1;
