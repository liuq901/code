#include <cstdio>
#include <cstdlib>
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      bool flag=false;
      int n;
      scanf("%d",&n);
      for (int i=2;i<=1000;i++)
      {
         int p=i*i*i;
         if (!(n%p))
         {
            flag=true;
            break;
         }
      }
      printf("%s\n",flag?"YES":"NO");
   }
   system("pause");
   return(0);
}
