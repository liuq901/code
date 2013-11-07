#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int b[100010],e[100010][2],a[200010][3];
bool use[100010];
int main()
{
   void build(int,int),print(int,int);
   int solve(int,int);
   int n;
   scanf("%d%*d",&n);
   for (int i=1;i<n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      e[i][0]=x,e[i][1]=y;
      a[i][0]=y,a[i][1]=i,a[i][2]=b[x],b[x]=i;
      a[i+n][0]=x,a[i+n][1]=i,a[i+n][2]=b[y],b[y]=i+n;
   }
   build(1,0);
   printf("%d\n",solve(1,1));
   print(1,1);
   for (int i=1;i<n;i++)
      if (use[i])
         printf("%d %d\n",e[i][0],e[i][1]);
   system("pause");
   return(0);
}
int l[100010],r[100010],last[100010],p[100010];
void build(int x,int father)
{
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (y==father)
         continue;
      p[y]=a[i][1];
      build(y,x);
      if (!l[x])
         l[x]=y;
      else
         r[last[x]]=y;
      last[x]=y;
   }
}
int f[100010][2];
void print(int x,int op)
{
   if (!x)
      return;
   if (op)
      print(l[x],0),print(r[x],1);
   else if (f[x][op]==f[l[x]][0]+f[r[x]][0])
      print(l[x],0),print(r[x],0);
   else
      use[p[x]]=true,print(l[x],1),print(r[x],1);
}
bool vis[100010][2];
int solve(int x,int op)
{
   if (vis[x][op])
      return(f[x][op]);
   vis[x][op]=true;
   int &ret=f[x][op];
   if (!x)
      ret=0;
   else if (!op)
      ret=max(solve(l[x],0)+solve(r[x],0),solve(l[x],1)+solve(r[x],1)+1);
   else
      ret=solve(l[x],0)+solve(r[x],1);
   return(ret);
}
