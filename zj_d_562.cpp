#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> a;
int main()
{
   int n;
   while (scanf("%d",&n)==1)
   {
      a.resize(n);
      for (int i=0;i<n;i++)
         scanf("%d",&a[i]);
      while (a.size())
      {
         for (int i=0;i<a.size();i++)
            printf("%d%c",a[i],i==a.size()-1?'\n':' ');
         a.erase(a.begin());
         reverse(a.begin(),a.end());
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
