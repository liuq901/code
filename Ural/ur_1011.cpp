#include <cstdio>
#include <cstdlib>
int main()
{
   double p,q;
   scanf("%lf%lf",&p,&q);
   int x=int(p*100+0.5),y=int(q*100+0.5),ans=1;
   while (ans*x/10000>=ans*y/10000 || ans*y%10000<=0)
      ans++;
   printf("%d\n",ans);
   system("pause");
   return(0);
}
