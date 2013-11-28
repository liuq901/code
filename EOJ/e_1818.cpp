#include <cstdio>
#include <cstdlib>
#include <cstring>
int d[110],b[110],c[110],a[3010][3];
bool f[110];
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
   c[1]=1;
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
         if (d[k]+a[j][1]<d[y])
         {
            d[y]=d[k]+a[j][1];
            c[y]=c[k];
         }
         else if (d[k]+a[j][1]==d[y])
            c[y]+=c[k];
      }
   }
   printf("%d %d\n",d[n]>1000000000?-1:d[n],c[n]);
   system("pause");
   return(0);
}
