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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
struct trie
{
   bool end;
   int son[10];
   void init()
   {
      memset(son,0,sizeof(son));
   }
};
trie p[1000000];
string a[10010];
int main()
{
   bool check(string);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         cin>>a[i];
      bool flag=true;
      int m=1;
      p[m].init();
      for (int i=1;i<=n;i++)
      {
         int l=a[i].size(),k=1;
         for (int j=0;j<l;j++)
         {
            int x=a[i][j]-'0';
            if (!p[k].son[x])
            {
               p[k].son[x]=++m;
               p[m].init();
               p[m].end=j==l-1;
               k=m;
            }
            else
            {
               k=p[k].son[x];
               if (p[k].end || j==l-1)
               {
                  flag=false;
                  break;
               }
            }
         }
         if (!flag)
            break;
      }
      printf("%s\n",flag?"YES":"NO");
   }
   system("pause");
   return(0);
}
