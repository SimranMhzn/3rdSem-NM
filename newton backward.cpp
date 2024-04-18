#include<stdio.h>
float u_call(float u,int n)
{
	float temp=u;
	for(int i=1;i<n;i++)
	{
		temp=temp*(u+i);
	}
	return temp;
}
int fact(int n)
{
	int f=1;
	for(int i=2;i<=n;i++)
	{
		f*=i;
	}
	return f;
}
int main()
{
	int n=0;
	printf("\n Enter the value of n: ");
	scanf("%d",&n);
	float x[n], y[n][n];
	printf("\n Enter the value of x: ");
	for(int i=0;i<n;i++)
	{
		scanf("%f",&x[i]);
	}
	printf("\n Enter the values of y: ");
	for(int i=0;i<n;i++)
	{
		scanf("%f",&y[i][0]);
	}
	for(int i=1;i<n;i++)
	{
		for(int j=n-1;j>=i;j--)
		{
			y[j][i]=y[j][i-1]-y[j-1][i-1];
		}
	}
	printf("\n Displaying the backward difference table \n\n");
	for(int i=0;i<n;i++)
	{
		printf("%0.2f\t\t",x[i]);
		for(int j=0;j<=i;j++)
		{
			printf("%0.2f\t\t",y[i][j]);
		}
		printf("\n");
	}
	float value=0;
	printf("\n Enter the value of x: ");
	scanf("%f",&value);
	float sum=y[n-1][0];
	float u=(value-x[n-1])/x[1]-x[0];
	for(int i=1;i<n;i++)
	{
		sum=sum+(u_call(u,i)*y[n-1][i])/fact(i);
	}
	printf("\n When x=%.2f, corresponding y=%.2f.",value,sum);
	return 0;
}
