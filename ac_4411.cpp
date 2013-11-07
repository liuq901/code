#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int b[110],q[110],d[110],sg[110],sum[1<<16],a[110][20];
bool vis[1<<16];
int main()
{
   int T;
   scanf("%d",&T);
   for (int i=0;i<1<<16;i++)
      for (int j=0;j<16;j++)
         sum[i]+=i>>j-1&1;
   while (T--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      for (int i=1;i<=n;i++)
         a[i][0]=0;
      memset(d,0,sizeof(d));
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         x++,y++;
         a[x][++a[x][0]]=y;
         d[y]++;
      }
      int l=1,r=0;
      for (int i=1;i<=n;i++)
      {
         scanf("%d",&b[i]);
         if (!d[i])
            q[++r]=i;
      }
      while (l<=r)
      {
         int x=q[l++];
         for (int i=1;i<=a[x][0];i++)
         {
            int y=a[x][i];
            d[y]--;
            if (!d[y])
               q[++r]=y;
         }
      }
      reverse(q+1,q+n+1);
      for (int i=1;i<=n;i++)
      {
         int x=q[i];
         if (!a[x][0])
         {
            sg[x]=0;
            continue;
         }
         memset(vis,0,sizeof(vis));
         for (int j=0;j<1<<a[x][0];j++)
         {
            if (sum[j]>b[x] || (sum[j]&1)!=(b[x]&1))
               continue;
            int t=0;
            for (int k=1;k<=a[x][0];k++)
               if (j>>k-1&1)
               {
                  int y=a[x][k];
                  t^=sg[y];
               }
            vis[t]=true;
         }
         for (int j=0;j<1<<16;j++)
            if (!vis[j])
            {
               sg[x]=j;
               break;
            }
      }
      static int id=0;
      printf("Game#%d:\n",++id);
      int Q,tmp=0;
      scanf("%d",&Q);
      while (Q--)
      {
         int ans=0;
         for (int i=1;i<=n;i++)
         {
            int x;
            scanf("%d",&x);
            if (x&1)
               ans^=sg[i];
         }
         printf("Round#%d: %s\n",++tmp,ans?"WINNING":"LOSING");
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
