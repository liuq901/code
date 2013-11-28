#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps=1e-8;
int n,m,b[1010],in[1010],d[20010],e[20010],a[20010][2];
int main()
{
   bool check(double);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      scanf("%d%d",&n,&m);
      memset(b,0,sizeof(b));
      memset(in,0,sizeof(in));
      for (int i=1;i<=m;i++)
      {
         int x,y,s;
         scanf("%d%d%d%d",&x,&y,&s,&d[i]);
         in[y]++;
         if (s<=60)
            e[i]=d[i]*(70-s);
         else
            e[i]=min(10,s-50)*d[i];
         a[i][0]=y,a[i][1]=b[x],b[x]=i;
      }
      double l=0,r=100;
      while (r-l>eps)
      {
         double mid=(l+r)/2;
         if (check(mid))
            r=mid;
         else
            l=mid;
      }
      printf("%.4f\n",ceil(l*10000)/10000);
   }
   system("pause");
   return(0);
}
double p[1010],v[20010];
int q[1010],tmp[1010];
bool check(double x)
{
   for (int i=1;i<=m;i++)
      v[i]=d[i]*x-e[i];
   for (int i=1;i<=n;i++)
   {
      p[i]=-1e100;
      tmp[i]=in[i];
   }
   int l,r;
   q[l=r=1]=1,p[1]=0;
   while (l<=r)
   {
      int x=q[l++];
      for (int i=b[x];i;i=a[i][1])
      {
         int y=a[i][0];
         p[y]=max(p[y],p[x]+v[i]);
         tmp[y]--;
         if (!tmp[y])
            q[++r]=y;
      }
   }
   return(p[n]>=0);
}
