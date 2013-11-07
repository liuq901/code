#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
char s[100];
int main()
{
   gets(s);
   int n=strlen(s),ans=1,now=1;
   for (int i=1;i<n;i++)
   {
      if (s[i-1]!=s[i])
         now++;
      else
         now=1;
      ans=max(ans,now);
   }
   if (!n)
      ans=0;
   printf("%d\n",ans);
   system("pause");
   return(0);
}
