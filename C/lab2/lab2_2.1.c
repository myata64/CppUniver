#include <stdio.h>

void shiftDigits(int *number, int size) {
    int temp = number[0];
    for (int i = 0; i < size - 1; i++) {
        number[i] = number[i + 1];
    }
    number[size - 1] = temp;
}

int main() {
    int i;
    int size;

    printf("Введите размер числа: ");
    scanf("%d", &size);

    int number[size + 1]; // +1 для учета завершающего нуля

    printf("Введите число: ");
    for (i = 0; i < size; i++) {
        scanf("%1d", &number[i]); // Ввод одной цифры в каждой итерации
    }

    printf("Исходное число: ");
    for (i = 0; i < size; i++) {
        printf("%d", number[i]);
    }

    // Сдвиг цифр
    shiftDigits(number, size);

    printf("\nЧисло после сдвига: ");
    for (i = 0; i < size; i++) {
        printf("%d", number[i]);
    }

    return 0;
}
