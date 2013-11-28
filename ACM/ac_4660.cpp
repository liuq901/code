#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
   int calc(int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int a,b;
      scanf("%d%d",&a,&b);
      printf("%d\n",calc(a)+calc(b));
   }
   system("pause");
   return(0);
}
int calc(int x)
{
   int p=0,a[10];
   a[0]=0;
   while (x)
   {
      a[++a[0]]=x%10;
      x/=10;
      p=max(p,a[a[0]]);
   }
   int t=1,ans=0;
   for (int i=1;i<=a[0];i++)
   {
      ans+=a[i]*t;
      t*=p+1;
   }
   return(ans);
}
