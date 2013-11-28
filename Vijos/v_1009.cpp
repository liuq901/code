#include <cstdio>
#include <cstdlib>
long long a,b,c,v1,v2,s1,s2,gy,t,l,x,y;
int main()
{
   long long gcd(long long,long long);
   scanf("%I64d%I64d%I64d%I64d%I64d",&s1,&s2,&v1,&v2,&l);
   a=v2-v1;
   b=-l;
   c=s1-s2;
   gy=gcd(a,b);
   if (c%gy==0)
   {
      x*=c/gy;
      y*=c/gy;
      t=abs(b/gy);
      while (x>0)
         x-=t;
      while (x<0)
         x+=t;
      printf("%I64d\n",x);
   }
   else
      printf("Impossible\n");
   system("pause");
   return(0);
}
long long gcd(long long a,long long b)
{
   long long result;
   if (b==0)
   {
      x=1;
      y=0;
      return(a);
   }
   result=gcd(b,a%b);
   t=x;
   x=y;
   y=t-(a/b)*y;
   return(result);
}
