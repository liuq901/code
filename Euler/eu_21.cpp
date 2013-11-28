#include <cstdio>
#include <cstdlib>
#include <cmath>
int d[10010];
int main()
{
   int calc(int);
   for (int i=1;i<=10000;i++)
      d[i]=calc(i);
   int ans=0;
   for (int i=1;i<=10000;i++)
   {
      int p=d[i];
      if (p<=10000 && p!=i && d[p]==i)
         ans+=i;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int calc(int x)
{
   int limit=int(sqrt(x))+2,ans=0;
   for (int i=1;i<=limit;i++)
   {
      if (x%i)
         continue;
      int p=x/i;
      if (i>p)
         break;
      if (i==p)
         ans+=i;
      else
         ans+=i+p;
   }
   return(ans-x);
}
