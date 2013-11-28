#include <cstdio>
#include <cstdlib>
int flag1,flag2,flag3;
int main()
{
   void print(int);
   int n,x;
   while (scanf("%d",&n)!=EOF)
   {
      flag1=flag2=0;
      x=n/100000000;
      if (x!=0)
      {
         flag1=1;
         flag2=1;
         flag3=2;
         print(x);
         printf("É|");
      }
      n%=100000000;
      x=n/10000;
      if (x!=0)
      {
         flag2=1;
         flag3=1;
         print(x);
         printf("»f");
      }
      if (flag1 && x%10==0 && n/1000!=0)
         printf("¡„");
      x=n%10000;
      if (x!=0)
      {
         flag3=0;
         print(x);
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
void print(int x)
{
   int i;
   int a[5],b[5];
   a[1]=x/1000;
   a[2]=x/100%10;
   a[3]=x/10%10;
   a[4]=x%10;
   b[1]=a[1]+a[2]+a[3]+a[4];
   b[2]=a[2]+a[3]+a[4];
   b[3]=a[3]+a[4];
   b[4]=a[4];
   for (i=1;i<=4;i++)
   {
      if (a[i]==1)
         printf("“º");
      else if (a[i]==2)
         printf("ŸE");
      else if (a[i]==3)
         printf("Ö¢");
      else if (a[i]==4)
         printf("À¡");
      else if (a[i]==5)
         printf("ŒÈ");
      else if (a[i]==6)
         printf("Íë");
      else if (a[i]==7)
         printf("∆‚");
      else if (a[i]==8)
         printf("∞∆");
      else if (a[i]==9)
         printf("æ¡");
      if (a[i]>=1 && a[i]<=9)
      {
         if (i==3)
            printf(" ∞");
         if (i==2)
            printf("∞€");
         if (i==1)
            printf("«™");
      }
      else
      {
         if (flag3==2)
            continue;
         if (flag3==1)
         {
            if (i==1 && flag1)
               printf("¡„");
            if (i==2 && b[2]!=0 && a[1]!=0)
               printf("¡„");
            if (i==3 && b[3]!=0 && a[2]!=0)
               printf("¡„");
         }
         if (flag3==0)
         {
            if (i==1 && flag2)
               printf("¡„");
            if (i==2 && b[2]!=0 && a[1]!=0)
               printf("¡„");
            if (i==3 && b[3]!=0 && a[2]!=0)
               printf("¡„");
         }
      }
   }
}
