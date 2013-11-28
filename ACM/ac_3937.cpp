#include <cstdio>
#include <cstdlib>
int a[40];
int main()
{
   int solve(int,int,int);
   int n;
   while (scanf("%d",&n)==1)
   {
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      int t=0;
      for (int i=1;i<=n;i++)
         if (a[i]!=a[i-1])
            t++;
      static int id=0;
      printf("Case %d: %d\n",++id,(t+2)/3);
   }
   system("pause");
   return(0);
}
