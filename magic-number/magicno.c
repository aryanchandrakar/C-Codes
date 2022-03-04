#include<stdio.h>
void main()
{
    int a,i,s,j,m,n,l;
    printf("enter the number");
    scanf("%d",&a);
    for(i=1;i<a;i++)
    for(j=1;j<a;j++)
    {
    {
        s=(i*i*i)+(j*j*j);
    }
    }
    for(m=1;m<a;m++)
    for(n=1;n<a;n++)
    {
    {
        l=(m*m*m)+(n*n*n);
    }
    }
    if(s==l)
    {
        printf("%d is magic number",a);
    }
    else
    {
        printf("%d not a magic number",a);
    }

}
