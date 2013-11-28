#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps=1e-8;
int n;
double x[1010],y[1010];
char S[10000];
int main()
{
   int calc(int);
   while (1)
   {
      gets(S);
      if (S[0]=='-' && S[1]=='-')
         break;
      sscanf(S,"%lf%lf",&x[1],&y[1]);
      n=1;
      while (1)
      {
         gets(S);
         if (S[0]=='-' && S[1]=='-')
            break;
         n++;
         sscanf(S,"%lf%lf",&x[n],&y[n]);
      }
      int ans=0;
      for (int i=1;i<=n;i++)
         ans=max(ans,calc(i));
      static int id=0;
      printf("%d. %d\n",++id,ans);
   }
   system("pause");
   return(0);
}
double a[1010];
int c[1010];
int calc(int id)
{
   int m=0;
   for (int i=1;i<=n;i++)
   {
      if (i==id)
         continue;
      a[++m]=atan2(y[i]-y[id],x[i]-x[id]);
   }
   sort(a+1,a+m+1);
   c[1]=1;
   int ans=1;
   for (int i=2;i<=m;i++)
   {
      if (fabs(a[i]-a[i-1])<eps)
         c[i]=c[i-1]+1;
      else
         c[i]=1;
      ans=max(ans,c[i]);
   }
   return(ans+1);
}
