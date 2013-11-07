#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct edge
{
   int x,y,len;
};
bool operator <(edge a,edge b)
{
   return(a.len<b.len);
}
edge a[200010];
int f[200010];
int main()
{
   int find(int);
   int n,m;
   while (scanf("%d%d",&n,&m)==2)
   {
      for (int i=1;i<=m;i++)
         scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].len);
      sort(a+1,a+m+1);
      int sum=0;
      long long ans=0;
      for (int i=0;i<n;i++)
         f[i]=i;
      for (int i=1;i<=m;i++)
      {
         int x=a[i].x,y=a[i].y;
         if (find(x)==find(y))
            continue;
         sum++;
         ans+=a[i].len;
         f[f[x]]=f[y];
         if (sum==n-1)
            break;
      }
      if (sum!=n-1)
         printf("-1\n");
      else
         printf("%lld\n",ans);
   }
   system("pause");
   return(0);
}
int find(int x)
{
   if (x!=f[x])
      f[x]=find(f[x]);
   return(f[x]);
}
