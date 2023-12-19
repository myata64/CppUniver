#include <stdio.h>
#include <math.h>

int main() {
    double x, f;

    printf("Введите значение x: ");
    scanf("%lf", &x);

    if (x <= -1)
        f = atan(x / (1 - x));
    else if (x > -1 && x <= 10)
        f = M_PI + sqrt((x * x + 1) / x);
    else
        f = -M_PI + x / ((1 - x) * (1 - x));

    printf("Значение функции f: %lf\n", f);

    return 0;
}
