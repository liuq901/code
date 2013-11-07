#include <cstdio>
#include <cstdlib>
int main()
{
   int i,n;
   int ans[100];
   scanf("%d",&n);
   if (n==0)
      printf("10\n");
   else if (n==1)
      printf("1\n");
   else
   {
      ans[0]=0;
      for (i=9;i>=2;i--)
         while (n%i==0)
         {
            n/=i;
            ans[0]++;
            ans[ans[0]]=i;
         }
      if (n>10)
         printf("-1\n");
      else
      {
         for (i=ans[0];i>=1;i--)
            printf("%d",ans[i]);
         printf("\n");
      }
   }
   system("pause");
   return(0);
}
