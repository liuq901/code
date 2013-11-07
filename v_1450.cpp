#include <cstdio>
#include <cstdlib>
const long double eps=1e-5;
int x[200001],y[200001],s[200001];
int main()
{
   bool check(long double,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d%d%d",&x[i],&y[i],&s[i]);
   long double l=0,r=1e7,ans;
   while (r-l>eps)
   {
      long double mid=(l+r)/2;
      if (check(mid,n))
      {
         ans=mid;
         r=mid;
      }
      else
         l=mid;
   }
   printf("%.2lf\n",double(ans));
   system("pause");
   return(0);
}
bool check(long double v,int n)
{
   long double t=0;
   for (int i=1;i<=n;i++)
   {
      t+=s[i]/v;
      if (t>y[i])
         return(false);
      if (x[i]>t)
         t=x[i];
   }
   return(true);
}
