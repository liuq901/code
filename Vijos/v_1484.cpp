#include <cstdio>
#include <cstdlib>
int main()
{
   int i,s,ans;
   int a[10];
   char ch;
   scanf("%c%*c",&ch);
   a[1]=ch-'0';
   for (i=2;i<=4;i++)
   {
      scanf("%c",&ch);
      a[i]=ch-'0';
   }
   scanf("%*c");
   for (i=5;i<=9;i++)
   {
      scanf("%c",&ch);
      a[i]=ch-'0';
   }
   scanf("%*c");
   scanf("%c",&ch);
   if (ch=='X')
      s=10;
   else
      s=ch-'0';
   ans=0;
   for (i=1;i<=9;i++)
      ans+=a[i]*i%11;
   ans%=11;
   if (ans==s)
      printf("Right\n");
   else
   {
      printf("%d",a[1]);
      printf("-");
      for (i=2;i<=4;i++)
         printf("%d",a[i]);
      printf("-");
      for (i=5;i<=9;i++)
         printf("%d",a[i]);
      printf("-");
      if (ans==10)
         printf("X\n");
      else
         printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
