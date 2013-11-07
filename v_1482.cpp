#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int check(char *);
   int n,i;
   char s[26];
   scanf("%d%*c",&n);
   for (i=1;i<=n;i++)
   {
      gets(s);
      if (check(s))
         printf("safe\n");
      else
         printf("de1ete\n");
   }
   system("pause");
   return(0);
}
int check(char *s)
{
   int i,j,k,l,len;
   len=strlen(s);
   for (i=0;i<len-3;i++)
      for (j=i+1;j<len-2;j++)
         for (k=j+1;k<len-1;k++)
            for (l=k+1;l<len;l++)
            {
               if (s[i]==s[j] && s[k]==s[l])
                  return(0);
               if (s[i]==s[l] && s[j]==s[k])
                  return(0);
            }
   return(1);
}
