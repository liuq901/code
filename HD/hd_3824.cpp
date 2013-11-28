#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
int n,S,b[1010],a[100010][3];
ll inf,d[1010];
int main()
{
   void dijkstra(int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int m,A;
      scanf("%d%d%d%d",&n,&m,&S,&A);
      A++;
      memset(b,0,sizeof(b));
      for (int i=1;i<=m;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         x++,y++;
         a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
         a[i+m][0]=x,a[i+m][1]=z,a[i+m][2]=b[y],b[y]=i+m;
      }
      dijkstra(A);
      static int id=0;
      printf("Case %d: ",++id);
      if (d[1]==d[0])
         printf("Poor princess, we will miss you!\n");
      else
         cout<<d[1]<<endl;
   }
   system("pause");
   return(0);
}
bool vis[1010];
void dijkstra(int start)
{
   memset(vis,0,sizeof(vis));
   memset(d,63,sizeof(d));
   d[start]=0;
   for (int i=1;i<=n;i++)
   {
      int k=0;
      for (int j=1;j<=n;j++)
         if (d[j]<d[k] && !vis[j])
            k=j;
      if (!k)
         break;
      vis[k]=true;
      for (int i=b[k];i;i=a[i][2])
      {
         int y=a[i][0],x=a[i][1];
         if (vis[y])
            continue;
         ll M=d[k],p=d[0];
         if (S-3*x>=M)
            p=M+2*x;
         else if (S-5*x>0)
         {
            ll K;
            K=(M-(S-3*x)+(S-5*x-1))/(S-5*x);
            ll delta=(S-5*x)*K+S-3*x-M;
            p=(S-x)*(K+1)-delta;
         }
         if (p<d[y])
            d[y]=p;
      }
   }
}
