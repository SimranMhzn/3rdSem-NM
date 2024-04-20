#include <stdio.h>
#include <conio.h>
#include <math.h>
#define e 2.718281828
int main()
{
    int n,i;
    printf("Enter the number of data = ");
    scanf("%d", &n);
    float x[n], y[n], Y[n], sumx = 0, sumxY = 0, sumx2 = 0, sumY = 0;
    printf("Enter data:\n");
    for ( i = 0; i < n; i++)
    {
        printf("x[%d] = ", i + 1);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i + 1);
        scanf("%f", &y[i]);
        Y[i] = log(y[i]);// in c , log = ln and log10 = log
    }
    for ( i = 0; i < n; i++)
    {
        sumx = sumx + x[i];
        sumxY = sumxY + x[i] * Y[i];
        sumx2 = sumx2 + x[i] * x[i];
        sumY = sumY + Y[i];
    }
    float b = (n * sumxY - sumx * sumY) / (n * sumx2 - sumx * sumx);
    float A = (sumY - b * sumx) / n;
    float a = pow(e, A);
    printf("a = %f , b = %f", a, b);
    return 0;
}
