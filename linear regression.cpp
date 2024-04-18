#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	float x[50],y[50],sum1=0,sum2=0,sumy=0,sumxy=0,a,b;
	printf("How many data points do you have? \n");
	scanf("%d",&n);
	printf("Enter data: ");
	for(i=1;i<=n;i++)
	{
		printf("x[%d]= ",i);
		scanf("%f",&x[i]);
		printf("y[%d]= ",i);
		scanf("%f",&y[i]);
	}
	for(i=1;i<=n;i++)
	{
		sum1=sum1+x[i];
		sum2=sum2+x[i]*x[i];
		sumy=sumy+y[i];
		sumxy=sumxy+x[i]*y[i];
	}
	b=(n*sumxy-sum1*sumy)/(n*sum2-sum1*sum1);
	a=(sumy-b*sum1)/n;
	printf("Values are: a=%0.2f and b=%0.2f.",a,b);
	printf("\nEquation of best fit is y = %0.2f +%0.2fx.",a,b);
	return 0;
}
