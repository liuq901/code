#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[10010];
int main()
{
   void work();
   int n;
   scanf("%d",&n);
   while (n--)
   {
      scanf("%s",s+1);
      work();
   }
   system("pause");
   return(0);
}
void work()
{
   int n=strlen(s+1);
   if (s[n]=='x' || s[n]=='o' || s[n]=='s' || n>=2 && s[n-1]=='c' && s[n]=='h')
      printf("%ses\n",s+1);
   else if (s[n]=='f' || n>=2 && s[n-1]=='f' && s[n]=='e')
   {
      if (s[n]=='f')
         s[n]='\0';
      else
         s[n-1]='\0';
      printf("%sves\n",s+1);
   }
   else if (s[n]=='y')
   {
      s[n]='\0';
      printf("%sies\n",s+1);
   }
   else
      printf("%ss\n",s+1);
}
