#include <cstdio>
#include <cstdlib>
int main()
{
   int n,a[10000];
   scanf("%d",&n);
   if (!n)
      printf("0\n");
   else
   {
      a[0]=0;
      while (n)
      {
         a[++a[0]]=n%-2;
         n/=-2;
         if (a[a[0]]<0)
         {
            a[a[0]]+=2;
            n++;
         }
      }
      for (int i=a[0];i>=1;i--)
         printf("%d",a[i]);
      printf("\n");
   }
   system("pause");
   return(0);
}
