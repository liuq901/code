#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
const int inf=1<<30;
int a[110],b[110];
int main()
{
   int calc(int,int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      for (int i=1;i<=m;i++)
         scanf("%d",&b[i]);
      for (int i=1;i<=m;i++)
      {
         int ans=inf,k=inf;
         for (int j=1;j<=n;j++)
         {
            int p=calc(b[i],a[j]);
            if (p<ans || p==ans && a[j]<k)
               ans=p,k=a[j];
         }
         printf("%d\n",k);
      }
   }
   system("pause");
   return(0);
}
int calc(int x,int y)
{
   int ans=0;
   while (x || y)
   {
      if ((x&1)!=(y&1))
         ans++;
      x>>=1,y>>=1;
   }
   return(ans);
}
