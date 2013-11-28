#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
char s[1000000];
int main()
{
   while (gets(s))
   {
      int n=strlen(s);
      bool flag=false;
      for (int i=0;i<n;i++)
      {
         if (i+2<n && s[i]=='E' && s[i+1]=='O' && s[i+2]=='F')
         {
            flag=true;
            break;
         }
         if (!islower(s[i]) && !isspace(s[i]))
            continue;
         if (i+1<n && s[i]=='d' && s[i+1]=='d')
         {
            printf("p");
            i++;
         }
         else if (i+3<n && s[i]=='p' && s[i+1]=='i' && s[i+2]=='n' && s[i+3]=='k')
         {
            printf("floyd");
            i+=3;
         }
         else if (i+1<n && s[i]=='e' && s[i+1]=='i' && (!i || s[i-1]!='c'))
         {
            printf("ie");
            i++;
         }
         else
            printf("%c",s[i]);
      }
      if (flag)
         break;
      printf("\n");
   }
   system("pause");
   return(0);
}
