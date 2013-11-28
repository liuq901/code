#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   char s[1100];
   while (scanf("%s",s)!=EOF)
      printf("%d\n",strlen(s));
   system("pause");
   return(0);
}
