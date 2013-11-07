#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll s[510],a[510][510],b[510][510];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,m,Q;
      scanf("%d%d%d",&n,&m,&Q);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            int x;
            scanf("%d",&x);
            a[i][j]=a[i-1][j]+x;
            b[i][j]=b[i][j-1]+x;
         }
      static int cas=0;
      printf("Test Case %d:\n",++cas);
      int id=0;
      while (Q--)
      {
         int x1,y1,x2,y2;
         scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
         s[x1-1]=0;
         ll ans=1LL<<60,x=0,y=0;
         for (int i=x1;i<=x2;i++)
         {
            s[i]=s[i-1]+b[i][y2]-b[i][y1-1];
            y+=(b[i][y2]-b[i][y1-1])*(i-x1);
         }
         for (int i=x1;i<=x2;i++)
         {
            ans=min(ans,x+y);
            x+=s[i]-s[x1-1];
            y-=s[x2]-s[i];
         }
         ll now=1LL<<60;
         x=0,y=0;
         s[y1-1]=0;
         for (int i=y1;i<=y2;i++)
         {
            s[i]=s[i-1]+a[x2][i]-a[x1-1][i];
            y+=(a[x2][i]-a[x1-1][i])*(i-y1);
         }
         for (int i=y1;i<=y2;i++)
         {
            now=min(now,x+y);
            x+=s[i]-s[y1-1];
            y-=s[y2]-s[i];
         }
         cout<<++id<<" "<<ans+now<<endl;
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
