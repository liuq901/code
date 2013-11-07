#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
   void work(int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      work(i);
   system("pause");
   return(0);
}
void work(int time)
{
   int n,m;
   scanf("%d%d",&n,&m);
   int a[31];
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   sort(a+1,a+n+1);
   int sum=0,f[31][1001]={0};
   for (int i=1;i<=n;i++)
   {
      sum+=a[i];
      for (int j=1;j<=m;j++)
         if (j>=sum)
            f[i][j]=1;
         else
         {
            f[i][j]=f[i-1][j];
            if (j-a[i]>=0)
               if (f[i-1][j-a[i]]>0)
                  f[i][j]+=f[i-1][j-a[i]];
               else
                  f[i][j]++;
         }
   }
   printf("%d %d\n",time,f[n][m]);
}
