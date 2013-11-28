#include <cstdio>
#include <cstdlib>
#define SQR(x) ((x)*(x))
bool a[10000010],vis[10000010];
int main()
{
   bool check(int x);
   int ans=0;
   for (int i=1;i<=10000000;i++)
      ans+=check(i);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool check(int x)
{
   if (vis[x])
      return(a[x]);
   vis[x]=true;
   if (x==89)
      a[x]=true;
   else if (x!=1)
   {
      int t=x,p=0;
      while (t)
      {
         p+=SQR(t%10);
         t/=10;
      }
      a[x]=check(p);
   }
   return(a[x]);
}
