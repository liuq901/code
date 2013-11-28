#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
int main()
{
   int ss(int);
   char s[260];
   int max,min,i;
   int a[26];
   scanf("%s",s);
   memset(a,0,sizeof(a));
   for (i=0;i<strlen(s);i++)
      a[s[i]-'a']++;
   max=0;
   min=20000;
   for (i=0;i<=25;i++)
   {
      if (a[i]>max)
         max=a[i];
      if (a[i]<min && a[i]!=0)
         min=a[i];
   }
   if (ss(max-min))
   {
      printf("Lucky Word\n");
      printf("%d\n",max-min);
   }
   else
   {
      printf("No Answer\n");
      printf("0\n");
   }
   system("pause");
   return(0);
}
int ss(int n)
{
   if (n==0 || n==1)
      return(0);
   int i;
   for (i=2;i<=sqrt(n)+0.5;i++)
      if (n%i==0)
         return(0);
   return(1);
}
