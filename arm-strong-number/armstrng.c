#include<stdio.h>
#include<conio.h>
void main()
{
	int i,a,b,c,d,e,f,s;
	for(i=1;i<1000;i++)
	{
		a=i%10;
		b=i-a;
		c=b/10;
		d=c%10;
		e=c-(d);
		f=e/10;
		s=(a*a*a)+(d*d*d)+(f*f*f);
		if(i==s)
		{
			printf("%d ",i);
		}
	}
	getch();
}
