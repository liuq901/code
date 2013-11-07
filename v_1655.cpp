#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[100],t[100];
int main()
{
   bool check(char);
   while (1)
   {
      scanf("%s",s);
      if (s[0]=='-')
         break;
      scanf("%s",&t);
      printf("%s\n",check(s[strlen(s)-1]) && check(t[strlen(t)-1])?"SheepDaddy":"MengMeng");
   }
   system("pause");
   return(0);
}
bool check(char x)
{
   return(x=='2' || x=='3' || x=='7' || x=='8');
}
