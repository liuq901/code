#include <cstdio>
#include <cstdlib>
int main()
{
   int log(int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      printf("%d\n",log(n));
   }
   system("pause");
   return(0);
}
int log(int x)
{
   int ans=0;
   while (x)
      ans++,x>>=1;
   return(ans);
}
