#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[110];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      scanf("%s",s);
      int l=strlen(s);
      for (int i=0;i<l;i++)
         printf("%02d",s[i]-'a'+1);
      printf("\n");
   }
   system("pause");
   return(0);
}
