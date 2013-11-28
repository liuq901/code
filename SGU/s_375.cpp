#include <cstdio>
#include <cstdlib>
int main()
{
   int i,n,x;
   int a[100];
   scanf("%d",&n);
   if (n%2==0)
      printf("No solution\n");
   else
   {
      a[0]=0;
      while (n!=1)
      {
         a[0]++;
         x=n/2;
         if (x%2==1)
            a[a[0]]=2;
         else
            a[a[0]]=1;
         n/=2;
      }
      printf("%d\n",a[0]);
      for (i=a[0];i>=2;i--)
         printf("%d ",a[i]);
      if (a[0]!=0)
         printf("%d\n",a[1]);
   }
   system("pause");
   return(0);
}
