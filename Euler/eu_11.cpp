#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int c[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,1},{1,-1},{1,1},{-1,-1}};
int a[30][30];
int main()
{
   for (int i=1;i<=20;i++)
      for (int j=1;j<=20;j++)
         scanf("%d",&a[i][j]);
   int ans=0;
   for (int i=1;i<=20;i++)
      for (int j=1;j<=20;j++)
         for (int k=0;k<8;k++)
         {
            int t=1,x=i,y=j;
            for (int p=0;p<4;p++)
            {
               x+=c[k][0],y+=c[k][1];
               if (!x || x==21 || !y || y==21)
               {
                  t=0;
                  break;
               }
               t*=a[x][y];
            }
            ans=max(ans,t);
         }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
