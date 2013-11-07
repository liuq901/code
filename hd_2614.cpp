#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[20][20],f[20][20][17000];
int main()
{
   int calc(int,int,int);
   while (scanf("%d",&n)==1)
   {
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
      memset(f,-1,sizeof(f));
      printf("%d\n",calc(1,0,1)+1);
   }
   system("pause");
   return(0);
}
int calc(int x,int t,int state)
{
   if (f[x][t][state]!=-1)
      return(f[x][t][state]);
   int &ret=f[x][t][state];
   ret=0;
   for (int i=1;i<=n;i++)
   {
      if (state>>i-1&1)
         continue;
      if (a[x][i]>=t)
         ret=max(ret,calc(i,a[x][i],state+(1<<i-1))+1);
   }
   return(ret);
}
