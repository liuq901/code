#include <cstdio>
#include <cstdlib>
int a[10][10];
char s[10];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int x0,y0;
      for (int i=1;i<=3;i++)
         for (int j=1;j<=3;j++)
         {
            scanf("%d",&a[i][j]);
            if (!a[i][j])
               x0=i,y0=j;
         }
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         scanf("%s",s);
         if (s[0]=='l' && y0>1)
         {
            a[x0][y0]=a[x0][y0-1];
            a[x0][y0-1]=0;
            y0--;
         }
         if (s[0]=='r' && y0<3)
         {
            a[x0][y0]=a[x0][y0+1];
            a[x0][y0+1]=0;
            y0++;
         }
         if (s[0]=='u' && x0>1)
         {
            a[x0][y0]=a[x0-1][y0];
            a[x0-1][y0]=0;
            x0--;
         }
         if (s[0]=='d' && x0<3)
         {
            a[x0][y0]=a[x0+1][y0];
            a[x0+1][y0]=0;
            x0++;
         }
      }
      for (int i=1;i<=3;i++)
         for (int j=1;j<=3;j++)
            printf("%d%c",a[i][j],j==3?'\n':' ');
      if (T)
         printf("\n");
   }
   system("pause");
   return(0);
}
