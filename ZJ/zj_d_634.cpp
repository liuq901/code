#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
string a[100010];
char s[100];
int main()
{
   int n;
   scanf("%d",&n);
   gets(s);
   for (int i=1;i<=n;i++)
   {
      gets(s);
      a[i]=s;
   }
   sort(a+1,a+n+1);
   for (int i=1;i<=n;i++)
      printf("%s\n",a[i].c_str());
   system("pause");
   return(0);
}
