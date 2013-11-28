#include <cstdio>
#include <cstdlib>
#include <cctype>
int main()
{
   char ch;
   int t,s;
   int a[1000];
   t=0;
   while (scanf("%c",&ch)!=EOF)
   {
      if (!isdigit(ch) && ch!='+' && ch!='-' && ch!='/' && ch!='*' && ch!='%' && ch!='\n')
         continue;
      if (isdigit(ch))
      {
         s=ch-'0';
         while (1)
         {
            scanf("%c",&ch);
            if (!isdigit(ch))
            {
               t++;
               a[t]=s;
               break;
            }
            s=s*10+ch-'0';
         }
      }
      if (ch=='+')
      {
         s=a[t-1]+a[t];
         a[t-1]=s;
         t--;
      }
      if (ch=='-')
      {
         s=a[t-1]-a[t];
         a[t-1]=s;
         t--;
      }
      if (ch=='*')
      {
         s=a[t-1]*a[t];
         a[t-1]=s;
         t--;
      }
      if (ch=='/')
      {
         s=a[t-1]/a[t];
         a[t-1]=s;
         t--;
      }
      if (ch=='%')
      {
         s=a[t-1]%a[t];
         a[t-1]=s;
         t--;
      }
      if (ch=='\n')
      {
         printf("%d\n",a[1]);
         t=0;
      }
   }
   system("pause");
   return(0);
}
