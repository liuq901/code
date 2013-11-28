#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cstdarg>
#include <iostream>
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
const ld eps=1e-13;
const double pi=acos(-1.0);
map <char,int> p;
ld c[40][40],b[40][40],f[310][40];
string s,ans;
int pre[310][40];
char S[40];
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      p.clear();
      for (int i=1;i<=n;i++)
      {
         char ch;
         cin>>ch;
         p.insert(make_pair(ch,i));
         S[i]=ch;
      }
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
         {
            cin>>c[i][j];
            if (fabs(c[i][j])<eps)
               c[i][j]=-1e100;
            else
               c[i][j]=log(c[i][j]);
         }
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
         {
            cin>>b[i][j];
            if (fabs(b[i][j])<eps)
               b[i][j]=-1e100;
            else
               b[i][j]=log(b[i][j]);
         }
      int Q;
      scanf("%d",&Q);
      while (Q--)
      {
         cin>>s;
         int l=s.size();
         int order;
         order=p[s[0]];
         for (int i=1;i<=n;i++)
            f[1][i]=c[i][order];
         for (int i=2;i<=l;i++)
         {
            order=p[s[i-1]];
            for (int j=1;j<=n;j++)
            {
               f[i][j]=-1e100;
               ld now=c[j][order];
               for (int k=1;k<=n;k++)
                  if (f[i-1][k]+now+b[k][j]>f[i][j])
                  {
                     f[i][j]=f[i-1][k]+now+b[k][j];
                     pre[i][j]=k;
                  }
            }
         }
         int k=0;
         ld ma=-1e100;
         for (int i=1;i<=n;i++)
            if (f[l][i]>ma)
               ma=f[l][i],k=i;
         ans.clear();
         for (int i=l;i;i--)
         {
            ans=S[k]+ans;
            k=pre[i][k];
         }
         cout<<ans<<endl;
      }
   }
   system("pause");
   return(0);
}
