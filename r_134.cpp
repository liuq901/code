#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
char s[100010];
int main()
{
   bool check(char,char);
   char work(char,int);
   int p1,p2,p3;
   scanf("%d%d%d%s",&p1,&p2,&p3,s);
   int len=strlen(s);
   for (int i=0;i<len;i++)
   {
      if (!i || i==len-1 || s[i]!='-')
      {
         printf("%c",s[i]);
         continue;
      }
      if (!check(s[i-1],s[i+1]) || check(s[i-1],s[i+1]) && s[i-1]>=s[i+1])
      {
         printf("-");
         continue;
      }
      if (p3==1)
         for (char ch=s[i-1]+1;ch<=s[i+1]-1;ch++)
            for (int k=1;k<=p2;k++)
               printf("%c",work(ch,p1));
      else
         for (char ch=s[i+1]-1;ch>=s[i-1]+1;ch--)
            for (int k=1;k<=p2;k++)
               printf("%c",work(ch,p1));
   }
   printf("\n");
   system("pause");
   return(0);
}
bool check(char x,char y)
{
   if (isdigit(x) && isdigit(y))
      return(true);
   if (isalpha(x) && isalpha(y))
      return(true);
   return(false);
}
char work(char ch,int order)
{
   if (order==3)
      return('*');
   if (isdigit(ch))
      return(ch);
   if (order==1)
      return(tolower(ch));
   else
      return(toupper(ch));
}
