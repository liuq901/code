#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   char s[1010];
   int check(char *);
   while (scanf("%s",&s[1])!=EOF)
      if (check(s))
         printf("yes\n");
      else
         printf("no\n");
   system("pause");
   return(0);
}
int check(char *s)
{
   int i,l;
   l=strlen(&s[1]);
   for (i=1;i<=l/2;i++)
      if (s[i]!=s[l-i+1])
         return(0);
   return(1);
}
