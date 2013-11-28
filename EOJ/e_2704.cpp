#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int f[1000010],ans[1000010];
int main()
{
   int n,t=0;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      t=max(t,x);
      f[x]++;
   }
   scanf("%d",&n);
   long long lq=0;
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      if (ans[x])
      {
         lq+=ans[x]-1;
         continue;
      }
      for (int j=1;x*j<=t;j++)
         ans[x]+=f[x*j];
      lq+=ans[x];
      ans[x]++;
   }
   cout<<lq<<endl;
   system("pause");
   return(0);
}
