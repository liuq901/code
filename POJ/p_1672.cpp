#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> a[10010];
int main()
{
   bool first=true;
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      if (!first)
         printf("\n");
      first=false;
      int sum=n*(n+1)>>1;
      if (sum&1)
      {
         printf("0\n");
         continue;
      }
      for (int i=1;i<=n;i++)
      {
         a[i].clear();
         for (int j=n;j>=i;j--)
            a[i].push_back(j);
      }
      for (int i=n;i;i--)
         if (a[i].size()&1)
         {
            int x=a[i-2][a[i-2].size()-1];
            a[i].push_back(x);
            a[i-2].pop_back();
         }
      for (int i=1;i<=n;i++)
         reverse(a[i].begin(),a[i].end());
      sort(a+1,a+n+1);
      printf("%d\n",n);
      for (int i=1;i<=n;i++)
         for (int j=0;j<a[i].size();j++)
            printf("%d%c",a[i][j],j==a[i].size()-1?'\n':' ');
   }
   system("pause");
   return(0);
}
