#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   char s[21];
   while (scanf("%s",s)!=EOF)
   {
      int l=strlen(s),ans=1;
      for (int i=0;i<l;i++)
         if (s[i]=='T' || s[i]=='D' || s[i]=='F' || s[i]=='L')
            ans*=2;
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
