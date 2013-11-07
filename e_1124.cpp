#include <cstdio>
#include <cstdlib>
int q;
int main()
{
   int count(int,int);
   while (1)
   {
      int n,m;
      scanf("%d%d%d",&n,&m,&q);
      if (!n && !m && !q)
         break;
      printf("%d\n",count(n,m));
   }
   system("pause");
   return(0);
}
int count(int x,int p)
{
   if (!p)
      return(1);
   int ans,t=count(x,p/2);
   ans=t*t%q;
   if (p&1)
      ans=ans*x%q;
   return(ans);
}
