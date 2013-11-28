#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int n=100;
set <vector <int> > s;
int a[n+10];
int main()
{
   void init();
   init();
   int ans=0;
   for (int i=2;i<=n;i++)
      for (int j=2;j<=n;j++)
      {
         vector <int> tmp;
         int x=i;
         for (int k=1;k<=a[0];k++)
         {
            int t=0;
            while (!(x%a[k]))
            {
               t++;
               x/=a[k];
            }
            tmp.push_back(t*j);
         }
         if (!s.count(tmp))
         {
            ans++;
            s.insert(tmp);
         }
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool f[n+10];
void init()
{
   for (int i=2;i*i<=n;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=n;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=n;i++)
      if (!f[i])
         a[++a[0]]=i;
}
