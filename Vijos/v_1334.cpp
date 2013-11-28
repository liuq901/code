#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int l,i,j,k,x,y,n;
   int a[51],b[51],c[51];
   int f[401][401];
   scanf("%d%d",&x,&y);
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d%d%d",&a[i],&b[i],&c[i]);
   memset(f,0,sizeof(f));
   for (i=1;i<=n;i++)
      for (j=x;j>=a[i];j--)
         for (k=y;k>=b[i];k--)
            if (f[j][k]<f[j-a[i]][k-b[i]]+c[i])
               f[j][k]=f[j-a[i]][k-b[i]]+c[i];
   printf("%d\n",f[x][y]);
   system("pause");
   return(0);
}
