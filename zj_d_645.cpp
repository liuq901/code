#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int f[1010];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
   {
      int a,b,c;
      scanf("%d%d%d",&b,&a,&c);
      if (c==-1 || a*c>=m)
         for (int j=a;j<=m;j++)
            f[j]=max(f[j],f[j-a]+b);
      else
         for (int k=1;k<=c;k++)
            for (int j=m;j>=a;j--)
               f[j]=max(f[j],f[j-a]+b);
   }
   printf("%d\n",f[m]);
   system("pause");
   return(0);
}
