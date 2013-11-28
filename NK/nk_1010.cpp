#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
char s[60];
int main()
{
   int n;
   scanf("%d%s",&n,s);
   int ans=-1;
   for (int i=0;i<n;i++)
   {
      if (s[i]=='P')
         continue;
      if (i>0 && s[i-1]=='E' || i<n-1 && s[i+1]=='E')
      {
         int p=min(i,n-i-1),q=min(ans,n-ans-1);
         if (ans==-1 || p>q)
            ans=i;
      }
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
