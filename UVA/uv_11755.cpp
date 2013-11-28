#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
double eps=1e-7;
char s[110];
double f[30][30];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      gets(s),gets(s);
      int n=strlen(s),x,y;
      bool flag=true;
      double p1,p2;
      scanf("%lf%lf",&p1,&p2);
      x=y=0;
      for (int i=0;i<n;i++)
      {
         if (s[i]=='W')
            x++;
         else if (s[i]=='L')
            y++;
         if ((x==21 || y==21) && i!=n-1)
         {
            flag=false;
            break;
         }
         if (x==20 && y==20)
            x=y=15;
         if(i/5&1 && (fabs(p2-1)<eps && s[i]=='L' || fabs(p2)<eps && s[i]=='W'))
         {
            flag=false;
            break;
         }
         if (!(i/5&1) && (fabs(p1-1)<eps && s[i]=='L' || fabs(p1)<eps && s[i]=='W'))
         {
            flag=false;
            break;
         }
      }
      static int id=0;
      printf("Case %d: ",++id);
      if (!flag)
      {
         printf("-1.000000\n");
         continue;
      }
      memset(f,0,sizeof(f));
      for (int i=0;i<21;i++)
         f[21][i]=1;
      for (int k=1;k<=260;k++)
         for (int i=20;i>=0;i--)
            for (int j=20;j>=0;j--)
            {
               if (i==20 && j==20)
               {
                  f[i][j]=f[15][15];
                  continue;
               }
               if ((i+j)/5&1)
                  f[i][j]=p2*f[i+1][j]+(1-p2)*f[i][j+1];
               else
                  f[i][j]=p1*f[i+1][j]+(1-p1)*f[i][j+1];
            }
      printf("%.6f\n",f[x][y]);
   }
   system("pause");
   return(0);
}
