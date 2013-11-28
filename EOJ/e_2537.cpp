#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
char s[10010];
int main()
{
   int T;
   scanf("%d",&T);
   gets(s);
   while (T--)
   {
      gets(s);
      int n=strlen(s),a=0,b=0;
      for (int i=0;i<n;i++)
      {
         a+=bool(isalpha(s[i]));
         b+=bool(isdigit(s[i]));
      }
      printf("character:%d\nnumber:%d\nothers:%d\n",a,b,n-a-b);
   }
   system("pause");
   return(0);
}
