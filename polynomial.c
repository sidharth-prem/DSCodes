#include<stdio.h>
void main()
{
	struct Poly
	{
	int coeff;
	int exp;
	}p[10];
	int n,i;
	printf("Enter number of terms in the polynomial:\n");
	scanf("%d",&n);
	printf("Enter the coefficients and exponents:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d%d", &p[i].coeff,&p[i].exp);
	}
	printf("The polynomial is:\n");
	for(i=0;i<n-1;i++)
	{
		printf("%dx^%d+",p[i].coeff,p[i].exp);
	}
	printf("%dx^%d",p[i].coeff,p[i].exp);
}
