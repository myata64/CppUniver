#include <stdio.h>
#include <math.h>

float x, sum, pr, max, min;

float initFunction(float x) {
    float f, g;
    int j;
    int n = 5;

    for (j = 0; j < n; j++) {
        g = j * j - j;
    }

    if (x < 1) {
        f = (3 * x + sin(x - 2)) / (x * x - 1);
    } else if (x >= 1 && x <= 5) {
        f = (x * x + 10 - g);
    }else{
        f = (100/(abs(x*x-7)));
    }

    return f;
}

float summ(){
    
}

int main() {
    printf("Введите значение x: ");
    scanf("%f", &x);

    float result = initFunction(x);
    
    printf("Результат: %f\n", result);

    return 0;
}

