#include <stdio.h>

int main() {
    int n, m;
    float a, b, c, d;

    // Ввод данных
    printf("Введите n, a, b (целое число, границы отрезка [a, b]): ");
    scanf("%d%f%f", &n, &a, &b);

    printf("Введите m, c, d (целое число, границы отрезка [c, d]): ");
    scanf("%d%f%f", &m, &c, &d);

    // Проверка вводимых данных
     if (n < 0 &&  m < 0 &&  a >= b || c >= d){
        printf("Ошибка ввода данных.\n");
        return 1;  // Возврат кода ошибки
    }

    // Вывод заголовка таблицы
    printf("\n   x/y  |");
    for (int i = 0; i <= n; i++) {
        printf("%9.5f |", a + i * (b - a) / n);
    }
    printf("\n--------|");
    for (int i = 0; i <= n; i++) {
        printf("-----------|");
    }
    printf("\n");

    // Вычисление и вывод значений функции
    for (int j = 0; j <= m; j++) {
        float y = c + j * (d - c) / m;
        printf("%7.5f |", y);

        for (int i = 0; i <= n; i++) {
            float x = a + i * (b - a) / n;
            float result;

            // Вычисление функции с использованием оператора if
            if (x * y < 0)
                result = (4 * x - y + 1) / (y * y + 1);
            else if (x * y == 0)
                result = 3 + x * x + y * y * y;
            else
                result = 1 + y * y - x * x;

            printf("%9.5f |", result);
        }

        printf("\n");
    }

    return 0;
}
