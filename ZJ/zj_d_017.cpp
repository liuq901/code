#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,j,l,t,a,b,sa,sb;
   char s[1010];
   t=0;
   while (scanf("%s",&s[1])!=EOF)
   {
      t++;
      printf("AB Circle #%d:\n",t);
      l=strlen(&s[1]);
      sa=sb=0;
      for (i=1;i<=l;i++)
         if (s[i]=='a')
            sa++;
         else
            sb++;
      for (i=1;i<=l-1;i++)
      {
         a=b=0;
         if (s[i]=='a')
            a=1;
         else
            b=1;
         for (j=i+1;j<=l;j++)
         {
            if (sa-a==b || sb-b==a)
               printf("%d,%d\n",i-1,j-1);
            if (s[j]=='a')
               a++;
            else
               b++;
         }
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
