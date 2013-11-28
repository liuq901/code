#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
bool f[11];
int b[11],a[100001][3];
ll d[11];
int main()
{
   void spfa();
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      memset(b,0,sizeof(b));
      int t=0;
      for (int i=1;i<=n;i++)
      {
         int k,y;
         scanf("%d%d",&k,&y);
         f[i]=y;
         for (int j=1;j<=k;j++)
         {
            int x,p;
            scanf("%d%d",&x,&p);
            a[++t][0]=x+1,a[t][1]=p,a[t][2]=b[i],b[i]=t;
         }
      }
      spfa();
      ll ans=1LL<<60;
      for (int i=1;i<=n;i++)
         if (f[i])
            ans=min(ans,d[i]);
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
queue <int> q;
bool flag[11];
void spfa()
{
   memset(d,63,sizeof(d));
   memset(flag,0,sizeof(flag));
   d[1]=0,flag[1]=true;
   q.push(1);
   while (!q.empty())
   {
      int x=q.front();
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (d[x]+a[i][1]<d[y])
         {
            d[y]=d[x]+a[i][1];
            if (!flag[y])
            {
               flag[y]=true;
               q.push(y);
            }
         }
      }
      flag[x]=false;
      q.pop();
   }
}
