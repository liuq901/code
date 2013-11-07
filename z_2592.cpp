#include <cstdio>
#include <cstdlib>
int main()
{
   void work();
   int t;
   scanf("%d",&t);
   for (int i=1;i<=t;i++)
      work();
   system("pause");
   return(0);
}
void work()
{
   int n;
   scanf("%d",&n);
   int s=0;
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      s+=x;
   }
   if (s<0)
      s=0;
   printf("%d\n",s);
}
