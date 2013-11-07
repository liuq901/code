#include <cstdio>
#include <cstdlib>
const int q=10007;
int main()
{
   int count(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      printf("%d\n",count((n+1)%q,n-1));
   }
   system("pause");
   return(0);
}
int count(int x,int p)
{
   if (!p)
      return(1);
   int t=count(x,p>>1),ans=t*t%q;
   if (p&1)
      ans=ans*x%q;
   return(ans);
}
