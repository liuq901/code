#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int inf=2147483647;
struct edge
{
   int x,y,len;
};
bool operator <(edge a,edge b)
{
   return(a.len<b.len);
}
int S,T,f[2010];
edge a[3010];
int main()
{
   int find(int);
   int test;
   scanf("%d",&test);
   while (test--)
   {
      int n,m;
      scanf("%d%d%d%d",&n,&m,&S,&T);
      for (int i=1;i<=m;i++)
         scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].len);
      sort(a+1,a+m+1);
      int ans=inf;
      for (int i=1;i<=m;i++)
      {
         for (int j=0;j<n;j++)
            f[j]=j;
         for (int j=i;j<=m;j++)
         {
            int x=find(a[j].x),y=find(a[j].y);
            f[x]=y;
            if (find(S)==find(T))
            {
               ans=min(ans,a[j].len-a[i].len);
               break;
            }
         }
      }
      if (ans==inf)
         printf("NO PATH\n");
      else
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
