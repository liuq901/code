#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
stack <int> s;
int tot,pos[10010],dfn[10010],low[10010],b[10010],a[100010][2],e[100010][2];
bool f[10010];
int main()
{
   void tarjan(int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      memset(b,0,sizeof(b));
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[i][0]=y,a[i][1]=b[x],b[x]=i;
         e[i][0]=x,e[i][1]=y;
      }
      memset(dfn,0,sizeof(dfn));
      memset(f,0,sizeof(f));
      tot=pos[0]=0;
      for (int i=1;i<=n;i++)
         if (!dfn[i])
            tarjan(i);
      for (int i=1;i<=m;i++)
      {
         int x=e[i][0],y=e[i][1];
         if (pos[x]==pos[y])
            continue;
         f[pos[y]]=true;
      }
      static int id=0;
      printf("Case %d: %d\n",++id,count(f+1,f+pos[0]+1,false));
   }
   system("pause");
   return(0);
}
void tarjan(int x)
{
   dfn[x]=low[x]=++tot;
   s.push(x),f[x]=true;
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (!dfn[y])
      {
         tarjan(y);
         low[x]=min(low[x],low[y]);
      }
      else if (f[y])
         low[x]=min(low[x],dfn[y]);
   }
   if (dfn[x]==low[x])
   {
      pos[0]++;
      while (s.top()!=x)
      {
         int p=s.top();
         f[p]=false,pos[p]=pos[0],s.pop();
      }
      f[x]=false,pos[x]=pos[0],s.pop();
   }
}
