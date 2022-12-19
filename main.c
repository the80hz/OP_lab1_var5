/* Дана матрица размера M × N. Получить вектор, элементы которого равны сумме минимального и максимального
 * соответствующих элементов столбцов 2 и 4 секторов матрицы.
 *
 * +---+
 * ++-++
 * +++++
 * ++-++
 * +---+
 *
 *
 */

#include <stdio.h>

int main() {
    // Ввод размера матрицы
    int n = -1;
    while(n < 0) {
        printf("Введите размер матрицы n x n: ");
        scanf("%d", &n);
    }
    // Ввод матрицы
    int matrix[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("Введите элемент матрицы matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    // Вывод матрицы
    printf("Ваша матрица:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Поиск минимального и максимального элементов столбцов 2 и 4 секторов матрицы
    int vector[n];
    for(int j = 0; j < n; j++) {
        int min = 2147483647;
        int max = -2147483648;
        for(int i = 0; i < n; i++) {
            if(((i + j <= n - 1) && (i >= j)) || ((i + j >= n - 1) && (j >= i))) {
                if(matrix[i][j] < min) {
                    min = matrix[i][j];
                }
                if(matrix[i][j] > max) {
                    max = matrix[i][j];
                }
            }
        }

        vector[j] = min + max;
    }
    // Вывод вектора
    printf("Ваш вектор:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }

    return 0;
}
