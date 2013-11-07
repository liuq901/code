#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
   int n,t;
   while (scanf("%d%d",&n,&t)!=EOF)
   {
      int a[1001],b[1001];
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      for (int i=1;i<=n;i++)
         scanf("%d",&b[i]);
      sort(a+1,a+n+1);
      sort(b+1,b+n+1);
      int ans=0;
      for (int i=1;i<=n;i++)
      {
         int x=a[i]+b[n-i+1];
         ans+=(x-t)*(x>=t);
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
