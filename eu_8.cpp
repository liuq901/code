#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
char a[1010],s[1010];
int main()
{
   while (scanf("%s",s)==1)
      strcat(a,s);
   int ans=0;
   for (int i=4;i<1000;i++)
   {
      int x=1;
      for (int j=0;j<5;j++)
         x*=a[i-j]-'0';
      ans=max(ans,x);
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
