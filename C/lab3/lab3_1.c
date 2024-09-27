#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, t, a, b;

    // Ввод размерности массива и значений t, a, b
    printf("Введите размерность массива: ");
    scanf("%d", &n);

    // Выделение памяти под массив
    int A[n];

    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Введите значение t: ");
    scanf("%d", &t);

    printf("Введите значения a и b: ");
    scanf("%d %d", &a, &b);

    // Найти номер последнего максимального элемента среди положительных элементов,
    // начиная с последнего элемента, большего заданного числа t.
    int max_positive_index = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (A[i] > t) {
            if (max_positive_index == -1 || A[i] > A[max_positive_index]) {
                max_positive_index = i;
            }
        }
    }

    // Сжать вектор, удалив из него все элементы, модуль которых находится в интервале [a, b].
    int newSize = 0;
    for (int i = 0; i < n; i++) {
        if (abs(A[i]) < a || abs(A[i]) > b) {
            A[newSize++] = A[i];
        }
    }

    // Освободившиеся в конце вектора элементы заполнить нулями.
    for (int i = newSize; i < n; i++) {
        A[i] = 0;
    }

    // Вывод результата
    printf("Результат:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Вывод номера последнего максимального положительного элемента
    if (max_positive_index != -1) {
        printf("Номер последнего максимального положительного элемента: %d\n", max_positive_index + 1);
    } else {
        printf("В массиве нет положительных элементов, больших чем %d\n", t);
    }

    return 0;
}
