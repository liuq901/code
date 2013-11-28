#include <cstdio>
#include <cstdlib>
const int c[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int main()
{
   int t;
   scanf("%d%*c",&t);
   while (t--)
   {
      bool a[12][12];
      int x0,y0,z0,x1,y1,z1;
      for (int i=1;i<=10;i++)
      {
         for (int j=1;j<=10;j++)
         {
            char ch;
            scanf("%c",&ch);
            a[i][j]=ch!='*';
            if (ch=='C')
               x0=i,y0=j;
            if (ch=='M')
               x1=i,y1=j;
         }
         scanf("%*c");
      }
      for (int i=1;i<=10;i++)
         a[0][i]=a[i][0]=a[i][11]=a[11][i]=false;
      int ans=0;
      z0=z1=0;
      while (ans<=1000000)
      {
         if (x0==x1 && y0==y1)
            break;
         ans++;
         int x,y;
         x=x1+c[z1][0],y=y1+c[z1][1];
         if (a[x][y])
            x1=x,y1=y;
         else
         {
            z1++;
            if (z1==4)
               z1=0;
         }
         x=x0+c[z0][0],y=y0+c[z0][1];
         if (a[x][y])
            x0=x,y0=y;
         else
         {
            z0++;
            if (z0==4)
               z0=0;
         }
      }
      printf("%d\n",ans>1000000?-1:ans);
   }
   system("pause");
   return(0);
}
