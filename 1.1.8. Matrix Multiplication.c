#include <stdio.h>

int main() {
    int m, n, row_b, p;
    int i, j, k;
    int matrix_a[100][100];
    int matrix_b[100][100];
    int product_matrix[100][100];

    // Read dimensions of Matrix A
    scanf("%d %d", &m, &n);

    // Read elements of Matrix A
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix_a[i][j]);
        }
    }

    // Read dimensions of Matrix B
    scanf("%d %d", &row_b, &p);

    // Check compatibility: Columns of A must equal Rows of B
    if (n != row_b) {
        printf("Invalid input\n");
        return 0;
    }

    // Read elements of Matrix B only if valid
    for (i = 0; i < row_b; i++) {
        for (j = 0; j < p; j++) {
            scanf("%d", &matrix_b[i][j]);
        }
    }

    // Perform matrix multiplication
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            product_matrix[i][j] = 0;
            for (k = 0; k < n; k++) {
                product_matrix[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }

    // Print the final product matrix
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            printf("%d ", product_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
