#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   int sqr(int);
   int a,b,c,d;
   double ans;
   scanf("%d%d%d%d",&a,&b,&c,&d);
   ans=sqrt((sqr(a-c)+sqr((int)(sqrt(b)+sqrt(d)))));
   printf("%.3lf\n",ans);
   system("pause");
   return(0);
}
int sqr(int x)
{
   return(x*x);
}
