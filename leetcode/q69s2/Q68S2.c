#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int mySqrt(int x) {
    if (x == 0) {
        return 0;
    }

    double C = x, x0 = x;
    while (true) {
        double xi = 0.5 * (x0 + C / x0);
        if (fabs(x0 - xi) < 1e-7) {
            break;
        }
        x0 = xi;
    }
    return (int) x0;
}

int main() {
    int test = 8;
    int result = mySqrt(test);
    printf("%d", result);
    return 0;
}
