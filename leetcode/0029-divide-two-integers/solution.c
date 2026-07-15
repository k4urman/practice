#include <limits.h>
#include <stdlib.h>

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
    long long dvd = labs((long long)dividend);
    long long dvs = labs((long long)divisor);
    long long quotient = 0;

    while (dvd >= dvs) {
        long long temp = dvs;
        long long multiple = 1;
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        dvd -= temp;
        quotient += multiple;
    }
    return (int)(sign * quotient);
}
