#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int a[110];
int main()
{
   while (1)
   {
      int N,w;
      scanf("%d%d",&N,&w);
      if (!N && !w)
         break;
      memset(a,0,sizeof(a));
      int n=0,m=0;
      for (int i=1;i<=N;i++)
      {
         int x;
         scanf("%d",&x);
         x/=w;
         n=max(n,x);
         m=max(m,++a[x]);
      }
      double ans=0.01;
      for (int i=0;i<=n;i++)
         ans+=double(a[i])*(n-i)/m/n;
      printf("%.10f\n",ans);
   }
   system("pause");
   return(0);
}
