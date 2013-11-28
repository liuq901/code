#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,j,k,p1,p2,p3;
   char s[26000];
   scanf("%d%d%d%*c",&p1,&p2,&p3);
   scanf("%s",s);
   printf("%c",s[0]);
   for (i=1;i<strlen(s);i++)
      if (s[i]!='-')
         printf("%c",s[i]);
      else
      {
         if (!(s[i-1]>='a' && s[i-1]<='z') && !(s[i-1]>='0' && s[i-1]<='9'))
         {
            printf("-");
            continue;
         }
         if (s[i-1]>='a' && s[i-1]<='z')
            if (!(s[i+1]>='a' && s[i+1]<='z'))
            {
               printf("-");
               continue;
            }
         if (s[i-1]>='0' && s[i-1]<='9')
            if (!(s[i+1]>='0' && s[i+1]<='9'))
            {
               printf("-");
               continue;
            }
         if (s[i-1]>=s[i+1])
         {
            printf("-");
            continue;
         }
         if (p3==1)
            for (j=s[i-1]+1;j<s[i+1];j++)
               for (k=1;k<=p2;k++)
               {
                  if (p1==1)
                     printf("%c",j);
                  if (p1==2)
                     if (j>='a' && j<='z')
                        printf("%c",j-'a'+'A');
                     else
                        printf("%c",j);
                  if (p1==3)
                     printf("*");
               }
         if (p3==2)
            for (j=s[i+1]-1;j>s[i-1];j--)
               for (k=1;k<=p2;k++)
               {
                  if (p1==1)
                     printf("%c",j);
                  if (p1==2)
                     if (j>='a' && j<='z')
                        printf("%c",j-'a'+'A');
                     else
                        printf("%c",j);
                  if (p1==3)
                     printf("*");
               }
      }
   printf("\n");
   system("pause");
   return(0);
}
