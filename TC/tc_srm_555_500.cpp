#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
double f[2][5001];
struct RedIsGood
{
   double getProfit(int r,int b)
   {
      for (int i=0;i<=r;i++)
         for (int j=0;j<=b;j++)
            if (i==0)
               f[i&1][j]=0;
            else if (j==0)
               f[i&1][j]=f[(i-1)&1][j]+1;
            else
               f[i&1][j]=max(0.0,(f[(i-1)&1][j]+1)*i/(i+j)+(f[i&1][j-1]-1)*j/(i+j));
      return(f[r&1][b]);
   }
};
int main()
{
   int x,y;
   scanf("%d%d",&x,&y);
   RedIsGood t;
   printf("%.10lf\n",t.getProfit(x,y));
   system("pause");
   return(0);
}
