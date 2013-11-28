#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   char s[260];
   int l,i,x;
   scanf("%s",s);
   l=strlen(s);
   x=s[l-1]-'0';
   if (x%2==0)
      printf("1\n");
   else
      printf("0\n");
   x=0;
   for (i=0;i<l;i++)
      x+=s[i]-'0';
   if (x%3==0)
      printf("1\n");
   else
      printf("0\n");
   x=10*(s[l-2]-'0')+s[l-1]-'0';
   if (x%4==0)
      printf("1\n");
   else
      printf("0\n");
   x=100*(s[l-3]-'0')+10*(s[l-2]-'0')+s[l-1]-'0';
   if (x%8==0)
      printf("1\n");
   else
      printf("0\n");
   printf("1\n");
   system("pause");
   return(0);
}
