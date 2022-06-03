#include <iostream>
using namespace std;

uint64_t powmod(uint64_t base, uint64_t exponent, uint64_t modulus)
{
    if (modulus == 1)
        return 0;

    uint64_t result = 1;
    base = base % modulus;

    while (exponent > 0)
    {
        if (exponent & 1 == 0)
            result = (result * base) % modulus;
        exponent >>= 1;
        base = (base * base) % modulus; // overflows!
    }

    return result;
}
uint64_t mulmod(uint64_t a, uint64_t b, uint64_t m) {
    uint64_t res = 0;
    uint64_t temp_b;

    b %= m; // now b will be less than m

    while (a != 0) {
        if (a & 1) {
            // equivalent to: res = (res + b) % m
            if (b >= m - res)
                res -= m;
            res += b;
        }
        a >>= 1;

        // equivalent to b = 2*b % m
        temp_b = b;
        if (b >= m - b)
            temp_b -= m;
        b += temp_b;
    }
    return res;
}

bool miller_rabin_test(const uint64_t &number, const uint64_t &acc)
{
    // initial check
    if (number == 2 || number == 3)
        return true;
    if (number % 2 == 0 || number % 3 == 0)
        return false;
    // factorise number to 2^s * d
    uint64_t d = number - 1;
    uint64_t s = 0;
    while ((d & 1) == 0 && d > 0)
    {
        d >>= 1;
        s++;
    }

    uint64_t witness;
    uint64_t x;
    for (int k = 0; k < acc; ++k) // run k miller-rabin tests
    {
    x = powmod(witness, d, number);
    if (x == 1 || x == number - 1) // test passed, run next one
        continue;

    for (int i = 0; i < s - 1; ++i)
    {
    x = powmod(x, 2, number); // <- evil modular exponentiation

    if (x == 1) // test failed, n is not prime
        return false; // break from function

    if (x == (number - 1)) // test passed, run next one
        break; // break from inner for loop into outer for loop
}

if (x != number - 1) // test failed, n is not prime
    return false;
    }

    /* TODO: Miller-Rabin */
};




int main(){

}