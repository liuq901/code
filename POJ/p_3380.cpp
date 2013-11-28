#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,tot,d[10010],l[10010],b[10010],a[20010][3];
struct edge
{
   int id;
   ll len;
   edge(int x=0,ll y=0):id(x),len(y){}
};
edge e[10010];
bool operator <(edge a,edge b)
{
   return(a.len<b.len);
}
int main()
{
   void floodfill(int,int);
   int K,sh,sc;
   scanf("%d%d%d%d",&n,&K,&sh,&sc);
   for (int i=1;i<n;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      a[i][0]=y,a[i][1]=i,a[i][2]=b[x],b[x]=i;
      a[i+n][0]=x,a[i+n][1]=i,a[i+n][2]=b[y],b[y]=i+n;
      l[i]=z;
   }
   floodfill(1,0);
   sort(e+1,e+n);
   if (sc>sh)
      reverse(e+1,e+n);
   for (int i=1;i<=K;i++)
      printf("%d%c",e[i].id,i==K?'\n':' ');
   system("pause");
   return(0);
}
void floodfill(int x,int father)
{
   d[x]=1;
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (y==father)
         continue;
      floodfill(y,x);
      d[x]+=d[y];
      int id=a[i][1];
      ll sum=ll(n-d[y])*d[y]*l[id];
      e[++tot]=edge(id,sum);
   }
}
