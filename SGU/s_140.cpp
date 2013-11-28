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
#include <string>
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
int a[110],ans[110],pre[10010][3];
bool f[10010];
int main()
{
   int n,p,m;
   scanf("%d%d%d",&n,&p,&m);
   for (int i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      a[i]%=p;
   }
   f[0]=true;
   for (int i=1;i<=n;i++)
      for (int k=1;k<p;k<<=1)
      {
         int t=a[i]*k%p;
         for (int j=0;j<p;j++)
         {
            int q=j+t>p?j+t-p:j+t;
            if (f[j] && !f[q])
            {
               f[q]=true;
               pre[q][0]=i,pre[q][1]=k,pre[q][2]=j;
            }
         }
      }
   if (!f[m])
      printf("NO\n");
   else
   {
      printf("YES\n");
      for (int i=m;i;i=pre[i][2])
      {
         int x=pre[i][0];
         ans[x]+=pre[i][1];
      }
      for (int i=1;i<n;i++)
         printf("%d ",ans[i]);
      printf("%d\n",ans[n]);
   }
   system("pause");
   return(0);
}
