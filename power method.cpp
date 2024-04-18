#include<stdio.h>
#include<conio.h>
#include<math.h>
#define s 50
int main()
{
	int n,i;
	float x[s],y[s],sumx=0,sumx2=0,sumy=0,sumxy=0,a,b,A;
	printf("How many data points?\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("x[%d]= ",i);
		scanf("%f",&x[i]);
		printf("y[%d]= ",i);
		scanf("%f",&y[i]);
	}
	for(i=1;i<=n;i++)
	{
		sumx=sumx+log(x[i]);
		sumx2=sumx2+log(x[i])*log(x[i]);
		sumy=sumy+log(y[i]);
		sumxy=sumxy+log(x[i])*log(y[i]);
	}
	b=(n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
	A=(sumy-b*sumx)/n;
	a=exp(A);
	printf("Values are: a=%0.2fand b=%0.2f",a,b);
	return 0;
}
