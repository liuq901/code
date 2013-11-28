#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
using namespace std;
bool f[5010];
int num[5010],cou[5010];
int now,d[5010],b[5010],a[30010][2],e[30010][2];
int index,dfn[5010],low[5010],pos[5010],print[5010];
vector <int> c[5010];
stack <int> S;
int main()
{
   void tarjan(int),floodfill(int);
   int test;
   scanf("%d",&test);
   for (int id=1;id<=test;id++)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      memset(b,0,sizeof(b));
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         x++,y++;
         e[i][0]=x,e[i][1]=y;
         a[i][0]=x,a[i][1]=b[y],b[y]=i;
      }
      memset(dfn,0,sizeof(dfn));
      memset(f,0,sizeof(f));
      index=pos[0]=0;
      for (int i=1;i<=n;i++)
         if (!dfn[i])
            tarjan(i);
      memset(b,0,sizeof(b));
      memset(d,0,sizeof(d));
      int t=0;
      for (int i=1;i<=m;i++)
      {
         int x=e[i][0],y=e[i][1];
         if (pos[x]==pos[y])
            continue;
         x=pos[x],y=pos[y];
         a[++t][0]=x,a[t][1]=b[y],b[y]=t;
         d[x]++;
      }
      int ans=0;
      for (int i=1;i<=pos[0];i++)
         if (!d[i])
         {
            now=0;
            memset(f,0,sizeof(f));
            floodfill(i);
            num[i]=now;
            ans=max(ans,now);
         }
      t=0;
      for (int i=1;i<=pos[0];i++)
         if (!d[i] && ans==num[i])
         {
            int l=c[i].size();
            for (int j=0;j<l;j++)
               print[++t]=c[i][j];
         }
      sort(print+1,print+t+1);
      printf("Case %d: %d\n",id,ans-1);
      for (int i=1;i<t;i++)
         printf("%d ",print[i]-1);
      printf("%d\n",print[t]-1);
   }
   system("pause");
   return(0);
}
void tarjan(int x)
{
   dfn[x]=low[x]=++index;
   f[x]=true;S.push(x);
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
      int now=pos[0];
      c[now].clear();
      cou[now]=0;
      while (S.top()!=x)
      {
         int p=S.top();
         S.pop();
         pos[p]=now;
         cou[now]++;
         c[now].push_back(p);
         f[p]=false;
      }
      pos[x]=now,cou[now]++,c[now].push_back(x),f[x]=false;
      S.pop();
   }
}
void floodfill(int x)
{
   f[x]=true;
   now+=cou[x];
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (f[y])
         continue;
      floodfill(y);
   }
}
