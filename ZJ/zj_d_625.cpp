#include <cstdio>
#include <cstdlib>
#include <cctype>
const int c[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,1},{1,-1},{-1,-1},{1,1}};
char a[110][110];
int main()
{
   int n;
   while (scanf("%d",&n)==1)
   {
      for (int i=1;i<=n;i++)
         scanf("%s",a[i]+1);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
         {
            if (a[i][j]!='*')
               continue;
            for (int k=0;k<8;k++)
            {
               int x=i+c[k][0],y=j+c[k][1];
               if (a[x][y]=='-')
                  a[x][y]='1';
               else if (isdigit(a[x][y]))
                  a[x][y]++;
            }
         }
      for (int i=1;i<=n;i++)
         printf("%s\n",a[i]+1);
   }
   system("pause");
   return(0);
}
