#include <stdio.h>

void doolittleLU(float A[][10], float L[][10], float U[][10], int n) {
    int i, j, k;

    // Initialize L and U matrices
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            U[i][j] = 0;
            if (i == j)
                L[i][j] = 1;
            else
                L[i][j] = 0;
        }
    }

    // Perform LU decomposition
    for (i = 0; i < n; i++) {
        // Upper triangular matrix
        for (j = i; j < n; j++) {
            U[i][j] = A[i][j];
            for (k = 0; k < i; k++)
                U[i][j] -= L[i][k] * U[k][j];
        }
        // Lower triangular matrix
        for (j = i + 1; j < n; j++) {
            L[j][i] = A[j][i];
            for (k = 0; k < i; k++)
                L[j][i] -= L[j][k] * U[k][i];
            L[j][i] /= U[i][i];
        }
    }
}

void solveLinearSystem(float L[][10], float U[][10], float b[], int n) {
    float y[10], x[10];
    int i, j;

    // Solve Ly = b using forward substitution
    for (i = 0; i < n; i++) {
        y[i] = b[i];
        for (j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
    }

    // Solve Ux = y using backward substitution
    for (i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (j = i + 1; j < n; j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }

    // Print solution
    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %0.2f\n", i + 1, x[i]);
    }
}

int main() {
    int n, i, j;
    float A[10][10], L[10][10], U[10][10], b[10];

    printf("Enter size of matrix (max 10): ");
    scanf("%d", &n);

    printf("Enter elements of matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    printf("Enter the values of b (right-hand side of equations):\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    doolittleLU(A, L, U, n);

    solveLinearSystem(L, U, b, n);

    return 0;
}

