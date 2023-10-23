#include <bits/stdc++.h>

template<uint64_t base, uint64_t power> struct power_func {
    static constexpr uint64_t val = base*power_func<base, power - 1>::val;
};

template<uint64_t base> struct power_func<base, 0> {
    static constexpr uint64_t val = 1;
};

