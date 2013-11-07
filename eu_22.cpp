#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
string a[6000];
int main()
{
   char ch;
   int n=0;
   while (scanf("%c",&ch)==1)
   {
      if (ch!='"')
         continue;
      string s;
      while (1)
      {
         scanf("%c",&ch);
         if (ch=='"')
            break;
         s+=ch;
      }
      a[++n]=s;
   }
   sort(a+1,a+n+1);
   int ans=0;
   for (int i=1;i<=n;i++)
      for (int j=0;j<a[i].size();j++)
         ans+=(a[i][j]-'A'+1)*i;
   printf("%d\n",ans);
   system("pause");
   return(0);
}
