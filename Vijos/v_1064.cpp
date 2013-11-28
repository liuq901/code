#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{ 
   int i,j,l,k;
   char s[260];
   scanf("%d%*c",&k);
   scanf("%s",s);
   for (i=0;i<strlen(s);i++)
   {
      printf(" ");
      if (s[i]=='1' || s[i]=='4')
         for (j=1;j<=k;j++)
            printf(" ");
      else
         for (j=1;j<=k;j++)
            printf("-");
      printf(" ");
      if (i==strlen(s)-1)
         printf("\n");
      else
         printf(" ");
   }
   for (i=1;i<=k;i++)
      for (j=0;j<strlen(s);j++)
      {
         if (s[j]=='1' || s[j]=='2' || s[j]=='3' || s[j]=='7')
         {
            for (l=1;l<=k+1;l++)
               printf(" ");
            printf("|");
         }
         else if (s[j]=='5' || s[j]=='6')
         {
            printf("|");
            for (l=1;l<=k+1;l++)
               printf(" ");
         }
         else
         {
            printf("|");
            for (l=1;l<=k;l++)
               printf(" ");
            printf("|");
         }
         if (j==strlen(s)-1)
            printf("\n");
         else
            printf(" ");
      }
   for (i=0;i<strlen(s);i++)
   {
      printf(" ");
      if (s[i]=='1' || s[i]=='7' || s[i]=='0')
         for (j=1;j<=k;j++)
            printf(" ");
      else
         for (j=1;j<=k;j++)
            printf("-");
      printf(" ");
      if (i==strlen(s)-1)
         printf("\n");
      else
         printf(" ");
   }
   for (i=1;i<=k;i++)
      for (j=0;j<strlen(s);j++)
      {
         if (s[j]=='2')
         {
            printf("|");
            for (l=1;l<=k+1;l++)
               printf(" ");
         }
         else if (s[j]=='6' || s[j]=='8' || s[j]=='0')
         {
            printf("|");
            for (l=1;l<=k;l++)
               printf(" ");
            printf("|");
         }
         else
         {
            for (l=1;l<=k+1;l++)
               printf(" ");
            printf("|");
         }
         if (j==strlen(s)-1)
            printf("\n");
         else
            printf(" ");
      }
   for (i=0;i<strlen(s);i++)
   {
      printf(" ");
      if (s[i]=='1' || s[i]=='4' || s[i]=='7')
         for (j=1;j<=k;j++)
            printf(" ");
      else
         for (j=1;j<=k;j++)
            printf("-");
      printf(" ");
      if (i==strlen(s)-1)
         printf("\n");
      else
         printf(" ");
   }
   system("pause");
   return(0);
}
