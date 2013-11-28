#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
bool f[6000];
string a[6000];
int main()
{
   int now=0;
   for (int i=1;i<=100;i++)
   {
      now+=i;
      f[now]=true;
   }
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
   now=0;
   for (int i=1;i<=n;i++)
   {
      int sum=0;
      for (int j=0;j<a[i].size();j++)
         sum+=a[i][j]-'A'+1;
      if (f[sum])
         now++;
   }
   printf("%d\n",now);
   system("pause");
   return(0);
}
