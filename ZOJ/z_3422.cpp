#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <cstdlib>
using namespace std;
int n,m,opt[10010][3];
int main()
{
   bool check(int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      scanf("%d%d",&n,&m);
      for (int i=1;i<=m;i++)
         scanf("%d%d%d",&opt[i][0],&opt[i][1],&opt[i][2]);
      int l=1,r=m,ans=m+1;
      while (l<=r)
      {
         int mid=l+r>>1;
         if (check(mid))
            l=mid+1;
         else
            ans=mid,r=mid-1;
      }
      printf("%d\n",ans-1);
   }
   system("pause");
   return(0);
}
int now,tot,id,dfn[410],low[410],pos[410],b[410],a[40010][2];
bool flag[410];
bool check(int now)
{
   void add(int,int),tarjan(int);
   memset(b,0,sizeof(b));
   tot=0;
   for (int i=1;i<=now;i++)
   {
      int x=opt[i][0]+1,y=opt[i][1]+1,z=opt[i][2];
      if (!z)
      {
         add(x,y+n);
         add(y,x+n);
      }
      else if (z==1)
      {
         add(x,y);
         add(y,x);
         add(x+n,y+n);
         add(y+n,x+n);
      }
      else
      {
         add(x+n,y);
         add(y+n,x);
      }
   }
   memset(dfn,0,sizeof(dfn));
   memset(flag,0,sizeof(flag));
   now=id=0;
   for (int i=1;i<=n<<1;i++)
      if (!dfn[i])
         tarjan(i);
   for (int i=1;i<=n;i++)
      if (pos[i]==pos[i+n])
         return(false);
   return(true);
}
void add(int x,int y)
{
   a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
stack <int> s;
void tarjan(int x)
{
   dfn[x]=low[x]=++id;
   s.push(x);
   flag[x]=true;
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (!dfn[y])
      {
         tarjan(y);
         low[x]=min(low[x],low[y]);
      }
      else if (flag[y])
         low[x]=min(low[x],dfn[y]);
   }
   if (low[x]==dfn[x])
   {
      now++;
      while (s.top()!=x)
      {
         int p=s.top();
         s.pop();
         pos[p]=now;
         flag[p]=false;
      }
      pos[x]=now,flag[x]=false;
      s.pop();
   }
}
