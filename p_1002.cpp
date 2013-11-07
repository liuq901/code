#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;
const int c[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
int a[100010]={0};
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      char tmp[260];
      scanf("%s",tmp);
      string s;
      s=tmp;
      int l=s.length();
      for (int j=0;j<l;j++)
      {
         if (isdigit(s[j]))
            a[i]=a[i]*10+s[j]-'0';
         if (isalpha(s[j]))
            a[i]=a[i]*10+c[s[j]-'A'];
      }
   }
   sort(a+1,a+n+1);
   bool flag=false;
   int now=a[1],s=1;
   a[n+1]=-1;
   for (int i=2;i<=n+1;i++)
   {
      if (a[i]==now)
      {
         s++;
         continue;
      }
      if (s>1)
      {
         printf("%03d-%04d %d\n",now/10000,now%10000,s);
         flag=true;
      }
      now=a[i];
      s=1;
   }
   if (!flag)
      printf("No duplicates.\n");
   system("pause");
   return(0);
}
