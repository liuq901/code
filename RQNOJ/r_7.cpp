#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,j,m,n,k,x,ans;
   int a[401],b[21][21],c[21][21],d[21],e[21],f[21][1001];
   scanf("%d%d",&m,&n);
   for (i=1;i<=n*m;i++)
      scanf("%d",&a[i]);
   for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
         scanf("%d",&b[i][j]);
   for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
         scanf("%d",&c[i][j]);
   memset(d,0,sizeof(d));
   memset(e,0,sizeof(e));
   memset(f,0,sizeof(f));
   for (i=1;i<=n*m;i++)
   {
      d[a[i]]++;
      j=e[a[i]]+1;
      x=0;
      while (x<c[a[i]][d[a[i]]])
      {
         if (!f[b[a[i]][d[a[i]]]][j])
            x++;
         else
            x=0;
         j++;
      }
      e[a[i]]=j-1;
      for (k=j-x;k<=j-1;k++)
         f[b[a[i]][d[a[i]]]][k]=1;
   }
   ans=0;
   for (i=1;i<=m;i++)
      for (j=1000;j>=0;j--)
         if (f[i][j])
         {
            if (j>ans)
               ans=j;
            break;
         }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
