//fibonaci series
#include<stdio.h>
void fact();
void main()
{
    fact();
}
void fact()
{
    int i,n,a[50],q;
    printf("enter the number");
    scanf("%d",&n);
    a[0]=0;
    a[1]=1;
    printf("%d %d ",a[0],a[1]);
    for(i=2;i<=n+1;i++)
    {
        a[i]=a[i-1]+a[i-2];
        printf("%d ",a[i]);
        if(a[i]==n)
            break;
    }

}
