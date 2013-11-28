#include <cstdio>
#include <cstdlib>
int main()
{
   double len;
   int i,n;
   long long l,t,v,s;
   scanf("%lf%d",&len,&n);
   l=(long long)(len*10000+0.5);
   s=0;
   for (i=1;i<=n;i++)
   {
      scanf("%I64d%I64d",&t,&v);
      t*=10000;
      s+=t*v;
      s%=l;
   }
   if (s>l/2)
      s=l-s;
   printf("%.4lf\n",(double)s/10000.0);
   system("pause");
   return(0);
}
