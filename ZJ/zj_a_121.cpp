#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   bool check(int);
   int l,r;
   while (scanf("%d%d",&l,&r)==2)
   {
      int ans=0;
      for (int i=l;i<=r;i++)
         ans+=check(i);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
bool check(int x)
{
   if (x==1)
      return(false);
   if (x==2 || x==3)
      return(true);
   int limit=int(sqrt(x))+2;
   for (int i=2;i<=limit;i++)
      if (x%i==0)
         return(false);
   return(true);
}
