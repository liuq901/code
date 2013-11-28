#include <cstdio>
#include <cstdlib>
int main()
{
   long n,m,x,y,i,j;
   long long a[16][16]={0};
   scanf("%d%d%d%d",&n,&m,&x,&y);
   a[x][y]=-1;
   a[x+1][y+2]=-1;
   a[x+1][y-2]=-1;
   a[x+2][y+1]=-1;
   a[x+2][y-1]=-1;
   a[x-1][y+2]=-1;
   a[x-1][y-2]=-1;
   a[x-2][y+1]=-1;
   a[x-2][y-1]=-1;
   for (i=0;i<=n;i++)
      if (a[i][0]==-1)
         break;
      else
         a[i][0]=1;
   for (i=0;i<=m;i++)
      if (a[0][i]==-1)
         break;
      else
         a[0][i]=1;
   for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
         if (a[i][j]==-1)  
            continue;
         if (a[i-1][j]==-1 && a[i][j-1]==-1)  
            a[i][j]=0;
         if (a[i-1][j]==-1 && a[i][j-1]!=-1)  
            a[i][j]=a[i][j-1];
         if (a[i-1][j]!=-1 && a[i][j-1]==-1)  
            a[i][j]=a[i-1][j];
         if (a[i-1][j]!=-1 && a[i][j-1]!=-1)  
            a[i][j]=a[i][j-1]+a[i-1][j];          
      }
   printf("%I64d\n",a[n][m]);
   system("pause");
   return(0);
}
