#include <cstdio>
#include <cstdlib>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool map[1001][1001];
int a[1001][1001],q[1000001];
int main()
{
   int n,m;
   scanf("%d%d%*c",&n,&m);
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=m;j++)
      {
         char ch;
         scanf("%c",&ch);
         map[i][j]=ch=='X';
      }
      scanf("%*c");
   }
   int l=1,r=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         if (map[i][j])
         {
            q[++r]=i*10000+j;
            a[i][j]=2;
         }
   while (l<=r)
   {
      int x0=q[l]/10000,y0=q[l]%10000;
      for (int i=0;i<4;i++)
      {
         int x=x0+c[i][0],y=y0+c[i][1];
         if (!x || x>n || !y || y>m)
            continue;
         a[x][y]++;
         if (a[x][y]==2)
            q[++r]=x*10000+y;
      }
      l++;
   }
   printf("%d\n",r);
   system("pause");
   return(0);
}
