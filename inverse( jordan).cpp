#include <stdio.h>

// Function to print a matrix
void printMatrix(float matrix[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%0.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Jordan method for finding inverse
void jordanInverse(float matrix[][10], int n) {
    float identity[10][10];
    float ratio, temp;
    int i, j, k;

    // Initializing identity matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                identity[i][j] = 1;
            else
                identity[i][j] = 0;
        }
    }

    // Applying Gauss-Jordan elimination
    for (i = 0; i < n; i++) {
        if (matrix[i][i] == 0) {
            printf("Matrix is singular, cannot compute inverse\n");
            return;
        }

        for (j = 0; j < n; j++) {
            if (i != j) {
                ratio = matrix[j][i] / matrix[i][i];

                for (k = 0; k < n; k++) {
                    matrix[j][k] -= ratio * matrix[i][k];
                    identity[j][k] -= ratio * identity[i][k];
                }
            }
        }
    }

    // Scaling rows to make diagonal elements 1
    for (i = 0; i < n; i++) {
        temp = matrix[i][i];
        for (j = 0; j < n; j++) {
            matrix[i][j] /= temp;
            identity[i][j] /= temp;
        }
    }

    printf("Inverse Matrix:\n");
    printMatrix(identity, n);
}

int main() {
    int n;
    float matrix[10][10];

    printf("Enter size of matrix (max 10): ");
    scanf("%d", &n);

    printf("Enter elements of matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    jordanInverse(matrix, n);

    return 0;
}

