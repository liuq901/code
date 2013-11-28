#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int d[610],b[610],a[360010][3];
bool f[610];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=m;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
   }
   memset(d,63,sizeof(d));
   d[1]=0;
   for (int i=1;i<=n;i++)
   {
      int k=0;
      for (int j=1;j<=n;j++)
         if (!f[j] && d[j]<d[k])
            k=j;
      if (!k)
         break;
      f[k]=true;
      for (int j=b[k];j;j=a[j][2])
      {
         int y=a[j][0];
         d[y]=min(d[y],d[k]+a[j][1]);
      }
   }
   printf("%d\n",d[n]>1000000000?-1:d[n]);
   system("pause");
   return(0);
}
