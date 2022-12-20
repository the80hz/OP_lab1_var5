#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int n = -1;
    while(n < 0) {
        printf("Enter matrix size n x n: ");
        scanf("%d", &n);
    }

    int matrix[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("Enter value of matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Your matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

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

    printf("Your vector:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }

    return 0;
}
