#include <cstdio>
#include <cstdlib>
double c[3001];
int main()
{
   double x,y,s=0;
   int n;
   scanf("%d%lf%lf",&n,&x,&y);
   for (int i=1;i<=n;i++)
   {
      scanf("%lf",&c[i]);
      c[i]+=c[i-1];
      s+=c[i];
   }
   printf("%.2lf\n",(n*x+y-s*2)/(n+1));
   system("pause");
   return(0);
}
