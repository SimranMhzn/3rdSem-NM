#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10
#define TOLERANCE 1e-6

int main() {
    float a[SIZE][SIZE], x[SIZE], ratio;
    int i, j, k, n;

    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    printf("\nEnter the coefficients of augmented matrix: ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("a[%d][%d]= ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }

    // Gauss-Jordan elimination
    for (i = 0; i < n; i++) {
        if (fabs(a[i][i]) < TOLERANCE) {
            printf("Mathematical Error!");
            exit(1);
        }

        // Normalize the current row
        float divisor = a[i][i];
        for (j = 0; j < n + 1; j++) {
            a[i][j] /= divisor;
        }

        // Make other rows zero for the current column
        for (j = 0; j < n; j++) {
            if (i != j) {
                ratio = a[j][i];
                for (k = 0; k < n + 1; k++) {
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }
    }

    // Extract solutions
    for (i = 0; i < n; i++) {
        x[i] = a[i][n];
    }

    printf("\nSolution: \n");
    for (i = 0; i < n; i++) {
        printf("x[%d]=%.3f\n", i + 1, x[i]);
    }

    return 0;
}

