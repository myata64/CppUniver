#include <stdio.h>

int main() {
    int a, b, number, max = 0;

    printf("Введите границы отрезка [a, b]: ");
    scanf("%d %d", &a, &b);

    printf("Введите целые числа (для завершения введите нечисловой символ): ");
    while (scanf("%d", &number) == 1) {
        if (number >= a && number <= b) {
            if (number > max) {
                max = number;
            }
        }
    }

    printf("Наибольшее значение в заданном диапазоне: %d\n", max);

    return 0;
}
