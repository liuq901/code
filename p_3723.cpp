#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
struct edge
{
   int x,y,len;
};
bool operator <(const edge &a,const edge &b)
{
   return(a.len>b.len);
}
int f[20010];
edge a[50010];
int main()
{
   int find(int x);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,m,r;
      scanf("%d%d%d",&n,&m,&r);
      for (int i=1;i<=n+m;i++)
          f[i]=i;
      for (int i=1;i<=r;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         a[i].x=x+1,a[i].y=y+n+1,a[i].len=z;
      }
      sort(a+1,a+r+1);
      int ans=(n+m)*10000;
      for (int i=1;i<=r;i++)
      {
         if (find(a[i].x)==find(a[i].y))
            continue;
         ans-=a[i].len;
         f[find(a[i].x)]=find(a[i].y);
      }
      printf("%d\n",ans);
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
