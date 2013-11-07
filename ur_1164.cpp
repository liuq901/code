#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int n,m,p,a[26]={0};
   scanf("%d%d%d%*c",&n,&m,&p);
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=m;j++)
      {
         char ch;
         scanf("%c",&ch);
         a[ch-'A']++;
      }
      scanf("%*c");
   }
   for (int i=1;i<=p;i++)
   {
      char s[110];
      gets(s);
      int l=strlen(s);
      for (int i=0;i<l;i++)
         a[s[i]-'A']--;
   }
   for (int i=0;i<26;i++)
      for (int j=1;j<=a[i];j++)
         printf("%c",i+'A');
   printf("\n");
   system("pause");
   return(0);
}
