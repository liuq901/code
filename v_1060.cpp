#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,a,b,i,j,k,l,m;
int s[21][16][16][100];
int main()
{
   void plus(int,int,int,int,int,int);
   scanf("%d%d%d",&n,&a,&b);
   memset(s,0,sizeof(s));
   for (i=0;i<=a;i++)
      for (j=0;j<=b;j++)
      {
         s[0][i][j][0]=1;
         s[0][i][j][1]=1;
      }
   for (i=1;i<=n;i++)
      for (j=0;j<=a;j++)
         for (k=0;k<=b;k++)
            for (l=0;l<=j;l++)
               for (m=0;m<=k;m++)
                  plus(i,j,k,i-1,j-l,k-m);
   for (i=s[n][a][b][0];i>=1;i--)
      printf("%d",s[n][a][b][i]);
   printf("\n");
   system("pause");
   return(0);
}
void plus(int x1,int y1,int z1,int x2,int y2,int z2)
{
   int i,x,y;
   if (s[x1][y1][z1][0]>s[x2][y2][z2][0])
      y=s[x1][y1][z1][0];
   else
      y=s[x2][y2][z2][0];
   x=0;
   for (i=1;i<=y;i++)
   {
      s[x1][y1][z1][i]+=s[x2][y2][z2][i]+x;
      x=s[x1][y1][z1][i]/10;
      s[x1][y1][z1][i]%=10;
   }
   s[x1][y1][z1][0]=y;
   while (x!=0)
   {
      s[x1][y1][z1][0]++;
      y++;
      s[x1][y1][z1][y]=x%10;
      x/=10;
   }
}
