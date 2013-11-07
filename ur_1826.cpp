#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[110];
int main()
{
   int calc(int,int,int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   sort(a+1,a+n+1);
   if (n==2)
      printf("%d\n",a[2]);
   else if (n==3)
      printf("%d\n",a[1]+a[2]+a[3]);
   else
   {
      int ans=a[2];
      for (int i=n-1;i>=3;i-=2)
         ans+=calc(a[1],a[2],a[i],a[i+1]);
      if (n&1)
         ans+=a[1]+a[3];
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
int calc(int a,int b,int c,int d)
{
   return(min((a<<1)+c+d,(b<<1)+a+d));
}
