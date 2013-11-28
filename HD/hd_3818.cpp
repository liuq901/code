#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> a;
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      a.clear();
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         a.push_back(x);
      }
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         a.push_back(x);
      }
      while (1)
      {
         bool flag=false;
         sort(a.begin(),a.end());
         while (!a[0])
            a.erase(a.begin());
         for (int i=0;i<a.size()-1;i++)
            if (a[i]+1==a[i+1])
            {
               a[i+1]++;
               a.erase(a.begin()+i);
               flag=true;
            }
         for (int i=0;i<a.size()-1;i++)
            if (a[i]==a[i+1])
            {
               a[i]-=2,a[i+1]++;
               flag=true;
            }
         if (!flag)
            break;
      }
      static int id=0;
      printf("Case %d:\n%d",++id,a.size());
      for (int i=0;i<a.size();i++)
         printf(" %d",a[i]);
      printf("\n");
   }
   system("pause");
   return(0);
}
