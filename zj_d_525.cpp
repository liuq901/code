#include <cstdio>
#include <cstdlib>
#include <cstring>
typedef long long ll;
char s[100010];
int main()
{
   while (1)
   {
      gets(s);
      int l=strlen(s),now=s[strlen(s)-1]-'0';
      if (l==1 && s[0]=='0')
         break;
      int sum=0;
      while (1)
      {
         gets(s);
         l=strlen(s);
         if (l==1 && s[0]=='0')
            break;
         sum+=s[l-1]-'0';
      }
      int ans=sum&1?2:1;
      if (now!=sum%10)
         ans=0;
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
