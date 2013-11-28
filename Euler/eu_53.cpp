#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int c[110][110];
int main()
{
   int ans=0;
   for (int i=1;i<=100;i++)
   {
      c[i][0]=c[i][i]=1;
      for (int j=1;j<i;j++)
      {
         c[i][j]=min(c[i-1][j-1]+c[i-1][j],1000001);
         ans+=c[i][j]>1000000;
      }
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
