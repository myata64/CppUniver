#include <stdio.h>

#define MAX_SIZE 100

void inputMatrix(double matrix[MAX_SIZE][MAX_SIZE], int n, int m) {
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void printMatrix(double matrix[MAX_SIZE][MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    double s;

    // Ввод размерности матрицы и значения s
    printf("Введите количество строк матрицы: ");
    scanf("%d", &n);

    printf("Введите количество столбцов матрицы: ");
    scanf("%d", &m);

    double matrix[MAX_SIZE][MAX_SIZE];

    inputMatrix(matrix, n, m);

    printf("Введите значение s: ");
    scanf("%lf", &s);

    // Найти номер первого из столбцов, не содержащих элементов, меньших заданного числа s
    int firstColumn = -1;
    for (int j = 0; j < m; j++) {
        int columnContainsElementGreaterThanS = 0;

        for (int i = 0; i < n; i++) {
            if (matrix[i][j] < s) {
                columnContainsElementGreaterThanS = 1;
                break;
            }
        }

        if (!columnContainsElementGreaterThanS) {
            firstColumn = j;
            break;
        }
    }

    if (firstColumn != -1) {
        printf("Номер первого столбца, не содержащего элементов меньших %lf: %d\n", s, firstColumn+1);
    } else {
        // Упорядочить строки матрицы по убыванию максимальных элементов
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                double max1 = matrix[j][0];
                double max2 = matrix[j + 1][0];

                for (int k = 1; k < m; k++) {
                    if (matrix[j][k] > max1) {
                        max1 = matrix[j][k];
                    }
                    if (matrix[j + 1][k] > max2) {
                        max2 = matrix[j + 1][k];
                    }
                }

                if (max1 < max2) {
                    // Поменять строки местами
                    for (int k = 0; k < m; k++) {
                        double temp = matrix[j][k];
                        matrix[j][k] = matrix[j + 1][k];
                        matrix[j + 1][k] = temp;
                    }
                }
            }
        }

        // Вывод результата
        printf("Матрица после упорядочивания строк по убыванию максимальных элементов:\n");
        printMatrix(matrix, n, m);
    }

    return 0;
}

