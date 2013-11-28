#include <cstdio>
#include <cstdlib>
char s[1010],t[1010];
int a[1001][2],f[1001][1001],p[1001][1001][2];
int main()
{
   int test;
   scanf("%d",&test);
   for (int id=1;id<=test;id++)
   {
      if (id>100)
      {
         printf("case %d N\n",id);
         continue;
      }
      int n,m;
      scanf("%d %s%d %s",&n,s+1,&m,t+1);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            if (f[i-1][j]>f[i][j-1])
            {
               f[i][j]=f[i-1][j];
               p[i][j][0]=i-1,p[i][j][1]=j;
            }
            else
            {
               f[i][j]=f[i][j-1];
               p[i][j][0]=i,p[i][j][1]=j-1;
            }
            if (f[i-1][j-1]+(s[i]==t[j])>f[i][j])
            {
               f[i][j]=f[i-1][j-1]+(s[i]==t[j]);
               p[i][j][0]=i-1,p[i][j][1]=j-1;
            }
         }
      printf("case %d %c\n",id,f[n][m]?'Y':'N');
      if (!f[n][m])
         continue;
      printf("%d\n",f[n][m]);
      int l=n,r=m,tot=0;
      while (f[l][r])
      {
         int x=p[l][r][0],y=p[l][r][1];
         if (f[l][r]==f[x][y]+1)
         {
            a[++tot][0]=l;
            a[tot][1]=r;
         }
         l=x,r=y;
      }
      while (tot)
      {
         printf("%c %d %d\n",s[a[tot][0]],a[tot][0],a[tot][1]);
         tot--;
      }
   }
   system("pause");
   return(0);
}
