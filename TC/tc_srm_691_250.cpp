#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cstdarg>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <complex>
#include <iterator>
#include <memory>
#define SQR(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
struct AfraidOfEven
{
   vector <int> restoreProgression(vector <int> a)
   {
      vector <int> ans,b;
      int n=a.size();
      ans.resize(n);
      b.resize(n);
      for (int i=0;i<n;i++)
         ans[i]=inf;
      for (int i=0;i<n;i++)
         for (int j=i+1;j<n;j++)
         {
            if ((a[j]-a[i])%(j-i))
               continue;
            int d=(a[j]-a[i])/(j-i);
            int t=a[i];
            for (int k=i-1;k>=0;k--)
            {
               b[k]=t-d;
               t-=d;
            }
            t=a[i];
            for (int k=i+1;k<j;k++)
            {
               b[k]=t+d;
               t+=d;
            }
            t=a[j];
            for (int k=j+1;k<n;k++)
            {
               b[k]=t+d;
               t+=d;
            }
            b[i]=a[i],b[j]=a[j];
            bool flag=true;
            for (int i=0;i<n;i++)
            {
               if (b[i]<=0 || b[i]%a[i])
               {
                  flag=false;
                  break;
               }
               int t=b[i]/a[i];
               if (!check(t))
               {
                  flag=false;
                  break;
               }
            }
            if (flag)
               ans=min(ans,b);
         }
      return(ans);
   }
private:
   bool check(int x)
   {
      for (int i=0;i<=31;i++)
         if (1<<i==x)
            return(true);
      return(false);
   }
};
int main()
{
   vector <int> a;
   int n;
   scanf("%d",&n);
   a.resize(n);
   for (int i=0;i<n;i++)
      scanf("%d",&a[i]);
   AfraidOfEven p;
   a=p.restoreProgression(a);
   for (int i=0;i<n;i++)
      printf("%d\n",a[i]);
   system("pause");
   return(0);
}
