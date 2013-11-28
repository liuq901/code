#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=100000000;
int c1,c2,l[10010],r[10010],b[10010],a[20010][2],f[10010][4];
int main()
{
   void dfs(int,int);
   int dp(int,int);
   while (1)
   {
      int n;
      scanf("%d%d%d",&n,&c1,&c2);
      if (!n && !c1 && !c2)
         break;
      memset(b,0,sizeof(b));
      for (int i=1;i<n;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[i][0]=y,a[i][1]=b[x],b[x]=i;
         a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
      }
      memset(l,0,sizeof(l));
      memset(r,0,sizeof(r));
      dfs(1,0);
      memset(f,-1,sizeof(f));
      printf("%d\n",dp(1,2));
   }
   system("pause");
   return(0);
}
void dfs(int x,int father)
{
   int p;
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (y==father)
         continue;
      dfs(y,x);
      if (!l[x])
         l[x]=p=y;
      else
         p=r[p]=y;
   }
}
int dp(int x,int op)
{
   int &ret=f[x][op];
   if (ret!=-1)
      return(ret);
   if (!x)
      return(ret=!op?inf:0);
   ret=inf;
   if (!op)
   {
      ret=min(ret,dp(l[x],2)+dp(r[x],0)+c1);
      ret=min(ret,min(dp(l[x],1)+dp(r[x],0),dp(l[x],3)+dp(r[x],2)+c2));
   }
   else if (op==1)
   {
      ret=min(ret,min(dp(l[x],1)+dp(r[x],0),dp(l[x],0)+dp(r[x],1)));
      ret=min(ret,min(dp(l[x],2)+dp(r[x],1)+c1,dp(l[x],3)+dp(r[x],2)+c2));
   }
   else if (op==2)
   {
      ret=min(ret,dp(l[x],1)+dp(r[x],2));
      ret=min(ret,min(dp(l[x],2)+dp(r[x],2)+c1,dp(l[x],3)+dp(r[x],2)+c2));
   }
   else
      ret=min(ret,min(dp(l[x],2)+dp(r[x],3),dp(l[x],3)+dp(r[x],3)+c2));
   return(ret);
}
