#include <cstdio>
#include <cstdlib>
#include <cctype>
int main()
{
   int i,l,s,t;
   char ch;
   s=t=0;
   while (scanf("%c",&ch)!=EOF)
   {
      if (ch=='\n')
      {
         if (t!=-1)
            s+=t;
         printf("%d\n",s);
         s=t=0;
         continue;
      }
      if (ch==' ')
      {
         if (t!=-1)
            s+=t;
         t=0;
         continue;
      }
      if (!isdigit(ch))
         t=-1;
      else if (t!=-1)
         t=t*10+ch-'0';
   }
   system("pause");
   return(0);
}
