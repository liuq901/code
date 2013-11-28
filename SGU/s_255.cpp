#include <cstdio>
#include <cstdlib>
int main()
{
   int i,j,n,m,flag;
   long long x;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&m);
      j=0;
      x=1;
      flag=0;
      while (1)
      {
         j++;
         x+=j;
         if (m==x)
         {
            flag=1;
            break;
         }
         if (x>m)
            break;
      }
      if (flag)
         printf("YES\n");
      else
         printf("NO\n");
   }
   system("pause");
   return(0);
}
