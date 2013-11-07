#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
char buf[200000];
int len;
int main()
{
   bool work(int);
   char ch;
   while (scanf("%c",&ch)==1)
   {
      if (ch!='\n')
      {
         buf[len++]=ch;
         continue;
      }
      for (int i=0;i<26;i++)
         if (work(i))
            break;
      len=0;
   }
   system("pause");
   return(0);
}
char ans[200000];
bool work(int change)
{
   for (int i=0;i<len;i++)
   {
      if (!isalpha(buf[i]))
      {
         ans[i]=buf[i];
         continue;
      }
      char ch=buf[i];
      ans[i]=buf[i]+change;
      if (isupper(ch) && !isupper(ans[i]) || islower(ch) && !islower(ans[i]))
         ans[i]-=26;
   }
   ans[len]='\0';
   for (int i=2;i<len;i++)
      if (ans[i-2]=='t' && ans[i-1]=='h' && ans[i]=='e')
      {
         printf("%s\n",ans);
         return(true);
      }
   for (int i=3;i<len;i++)
      if (ans[i-3]=='t' && ans[i-2]=='h' && (ans[i-1]=='i' && ans[i]=='s' || ans[i-1]=='a' && ans[i]=='t'))
      {
         printf("%s\n",ans);
         return(true);
      }
   return(false);
}
