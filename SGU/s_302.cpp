#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
int main()
{
   int l,i;
   int a[1001];
   char s[1010];
   gets(s);
   l=strlen(s);
   a[0]=0;
   i=-1;
   while (i<l)
   {
      i++;
      if (isalpha(s[i]))
      {
         if (a[0]==0)
         {
            printf("%c",s[i]);
            continue;
         }
         if (!a[a[0]])
         {
            printf("%c",toupper(s[i]));
            continue;
         }
         printf("%c",tolower(s[i]));
         continue;
      }
      i++;
      if (s[i]=='U')
      {
         a[0]++;
         a[a[0]]=0;
         i+=2;
         continue;
      }
      if (s[i]=='D')
      {
         a[0]++;
         a[a[0]]=1;
         i+=4;
         continue;
      }
      a[0]--;
      i++;
      if (s[i]=='U')
         i+=2;
      else
         i+=4;
   }
   printf("\n");
   system("pause");
   return(0);
}
