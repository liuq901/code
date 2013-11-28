#include <cstdio>
#include <cstdlib>
int a[1010][1010];
int main()
{
   int n,m,K;
   scanf("%d%d%d",&m,&n,&K);
   while (K--)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      a[y][x]=z;
   }
   for (int i=0;i<n;i++)
      for (int j=0;j<m;j++)
         if (a[i][j])
            printf("%d %d %d\n",i,j,a[i][j]);
   system("pause");
   return(0);
}
