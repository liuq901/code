#include <cstdio>
#include <cstdlib>
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      if (n/10%10==1)
         printf("%dth\n",n);
      else
         switch (n%10)
         {
         case 1:
            printf("%dst\n",n);
            break;
         case 2:
            printf("%dnd\n",n);
            break;
         case 3:
            printf("%drd\n",n);
            break;
         default:
            printf("%dth\n",n);
            break;
         }
   }
   system("pause");
   return(0);
}
