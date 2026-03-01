// Copyright 2022 NNTU_G
#include <cstdint>
#include <cmath>
#include <iostream>
#include "alg.h"


bool CheckPrime(uint64_t value) {
    if (value <= 1) {
        return false;
    }

    for (uint64_t i = 2; i * i <= value; ++i) {
        if (value % i == 0) {
            return false;
        }
    }

    return true;
}

uint64_t NPrime(uint64_t n) {
    if (n == 0) {
        return 0;
    }

    uint64_t count = 0;
    uint64_t number = 2;

    while (count < n) {
        if (CheckPrime(number)) {
            ++count;
            if (count == n) {
                return number;
            }
        }
        ++number;
    }

    return 0;
}

uint64_t NextPrime(uint64_t value) {
    uint64_t number = value + 1;

    while (true) {
        if (CheckPrime(number)) {
            return number;
        }
        ++number;
    }
}

uint64_t SumPrime(uint64_t hbound) {
    uint64_t sum = 0;

    for (uint64_t i = 2; i < hbound; ++i) {
        if (CheckPrime(i)) {
            sum += i;
        }
    }

    return sum;
}

uint64_t TwinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t count = 0;

    for (uint64_t i = lbound; i < hbound - 1; ++i) {
        if (CheckPrime(i) && CheckPrime(i + 2)) {
            if (i >= lbound && i + 2 < hbound) {
                ++count;
            }
        }
    }

    return count;
}
