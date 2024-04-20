#include <stdio.h>
#include <math.h>

#define MAX_ITER 100
#define TOLERANCE 0.00001

void jacobiMethod(double A[][10], double b[], double x[], int n) {
    double new_x[10];
    int iter = 0;
    double error = 0;

    do {
        // Perform one iteration of Jacobi method
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if (i != j)
                    sum += A[i][j] * x[j];
            }
            new_x[i] = (b[i] - sum) / A[i][i];
        }

        // Calculate error
        error = 0;
        for (int i = 0; i < n; i++) {
            error += fabs(new_x[i] - x[i]);
        }

        // Update x for next iteration
        for (int i = 0; i < n; i++) {
            x[i] = new_x[i];
        }

        iter++;
    } while (iter < MAX_ITER && error > TOLERANCE);

    if (iter >= MAX_ITER) {
        printf("Jacobi method did not converge within maximum iterations.\n");
    } else {
        printf("Solution converged after %d iterations.\n", iter);
        printf("Solution (x):\n");
        for (int i = 0; i < n; i++) {
            printf("x%d = %0.6f\n", i + 1, x[i]);
        }
    }
}

int main() {
    int n;
    double A[10][10], b[10], x[10];

    printf("Enter size of matrix (max 10): ");
    scanf("%d", &n);

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter elements of vector b:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    // Initial guess for x
    for (int i = 0; i < n; i++) {
        x[i] = 0; // You can set initial guesses to any value you want
    }

    jacobiMethod(A, b, x, n);

    return 0;
}

