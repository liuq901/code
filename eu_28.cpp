#include <cstdio>
#include <cstdlib>
const int n=1001;
int a[1010][1010];
int main()
{
   int c=n+1>>1,t,x=c,y=c;
   a[c][c]=t=1;
   for (int i=1;i<c;i++)
   {
      a[x][++y]=++t;
      int m=(i<<1)+1;
      for (int j=1;j<m-1;j++)
         a[++x][y]=++t;
      for (int j=1;j<m;j++)
         a[x][--y]=++t;
      for (int j=1;j<m;j++)
         a[--x][y]=++t;
      for (int j=1;j<m;j++)
         a[x][++y]=++t;
   }
   int ans=0;
   for (int i=1;i<=n;i++)
      ans+=a[i][i];
   for (int i=1;i<=n;i++)
      ans+=a[i][n-i+1];
   printf("%d\n",ans-1);
   system("pause");
   return(0);
}
