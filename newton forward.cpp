#include<stdio.h>
#define MAX 10
#define ORDER 4
int main()
{
	float ax[MAX], ay[MAX], diff[MAX][ORDER], nr=1.0,dr=1.0,x,p,h,yp;
	int n,i,j,k;
	printf("\nEnter the value of n: ");
	scanf("%d",&n);
	printf("\nEnter the value in form x,y: ");
	for(i=0;i<n;i++)
	{
		scanf("%f%f",&ax[i],&ay[i]);
	}
	printf("\nEnter the value of x for which the value of y is wanted: ");
	scanf("%f",&x);
	h=ax[1]-ax[0];
	for(i=0;i<=n-1;i++)
	{
		diff[i][1]=ay[i+1]-ay[i];
	}
	for(j=2;j<=ORDER;j++)
	{
		for(i=0;i<=n-j;i++)
		{
			diff[i][j]=diff[i+1][j-1]-diff[i][j-1];
		}
	}
	i=0;
	while(!(ax[i]>x))
	{
		i++;
	}
	i--;
	p=(x-ax[i])/h;
	yp=ay[i];
	for(k=1;k<=ORDER;k++)
	{
		nr*=p-k+1;
		dr*=k;
		yp+=(nr/dr)*diff[i][k];
	}
	printf("\nWhen x=%.2f, corresponding y=%.2f\n",x,yp);
	return 0;
}
