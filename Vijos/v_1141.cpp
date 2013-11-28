#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int l,n;
   char s[10000];
   scanf("%s",s);
   l=strlen(s);
   if (l==1)
      n=s[0]-'0';
   else
      n=(s[l-2]-'0')*10+s[l-1];
   n%=4;
   if (n==1 || n==2)
      printf("1\n");
   else
      printf("0\n");
   system("pause");
   return(0);
}
