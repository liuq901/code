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
char a[4][13];
int main()
{
   void dfs(int,int *,bool *);
   for (int i=0;i<4;i++)
      for (int j=0;j<13;j++)
      {
         string s;
         cin>>s;
         a[i][j]=s[1];
      }
   int ans=0;
   for (int j=11;j>=0;j--)
   {
      int pre[4];
      for (int i=0;i<4;i++)
         for (int k=0;k<4;k++)
            if (a[i][j]==a[k][j+1])
            {
               pre[i]=k;
               break;
            }
      bool f[4]={0};
      int sum=0;
      for (int i=0;i<4;i++)
      {
         if (i==pre[i])
            continue;
         sum++;
         if (!f[i])
         {
            sum++;
            dfs(i,pre,f);
         }
      }
      ans+=sum;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void dfs(int x,int *pre,bool *f)
{
   f[x]=true;
   if (!f[pre[x]])
      dfs(pre[x],pre,f);
}
