#include<stdio.h>
#include<math.h>
#include<iostream>
bool narcissistic( int value ){
    if(value==1){std::cout<<"true";}if(value==0){std::cout<<"false";}
}
int calc( int a){
int b,c,d,e,q[10];
int i;
b=a;
d=0;
e=a;
c=0;
while (b!=0){c=c+1;
b/=10;
}
while (e!=0) {
      d += pow(e % 10, c);
      e /= 10;
}
return d;
}
int main()
{
int v,a;
std::cout<<"enter number: ";
std::cin>>a;
if(a==calc(a)){v=1;}if(a!=calc(a)){v=0;}
narcissistic(v);}
