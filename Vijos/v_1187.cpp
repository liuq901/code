#include <cstdio>
#include <cstdlib>
#include <cstring>
const int k=26;
long long a[1100][1100];
int main()
{
   int i,j,n,m,x1,y1,x2,y2;
   scanf("%d%d",&n,&m);
   scanf("%d%d",&x1,&y1);
   scanf("%d%d",&x2,&y2);
   memset(a,0,sizeof(a));
   a[x1+k][y1+k]=1;
   for (i=x1;i<=x2;i++)
      for (j=1;j<=m;j++)
         if (a[i+k][j+k]==0)
            a[i+k][j+k]=a[i-2+k][j-1+k]+a[i-1+k][j-2+k]+a[i-1+k][j+2+k]+a[i-2+k][j+1+k];
   if (a[x2+k][y2+k]==0)
      printf("NO\n");
   else
      printf("%I64d00000000\n",a[x2+k][y2+k]);
   system("pause");
   return(0);
}
