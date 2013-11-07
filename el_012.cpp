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
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
vector <string> a[MAXN];
map <string,int> p;
string s;
int d[20010],b[20010],A[1000000][2];
int main()
{
   bool topsort(int);
   int n;
   scanf("%d",&n);
   bool flag=true;
   a[0].push_back("");
   for (int i=1;i<=n;i++)
   {
      cin>>s;
      if (p.count(s))
      {
         flag=false;
         break;
      }
      p[s]=0;
      a[0].push_back(s);
      int k;
      scanf("%d",&k);
      for (int j=1;j<=k;j++)
      {
         cin>>s;
         a[i].push_back(s);
      }
   }
   if (!flag)
      printf("NOT CORRECT\n");
   else
   {
      p.clear();
      int m=0,tot=0;
      for (int i=1;i<=n;i++)
      {
         if (!p.count(a[0][i]))
            p.insert(make_pair(a[0][i],++m));
         int x=p[a[0][i]],l=a[i].size();
         for (int j=0;j<l;j++)
         {
            if (!p.count(a[i][j]))
               p.insert(make_pair(a[i][j],++m));
            int y=p[a[i][j]];
            d[y]++;
            A[++tot][0]=y,A[tot][1]=b[x],b[x]=tot;
         }
      }
      printf("%s\n",topsort(m)?"CORRECT":"NOT CORRECT");
   }
   system("pause");
   return(0);
}
queue <int> q;
bool topsort(int n)
{
   for (int i=1;i<=n;i++)
      if (!d[i])
         q.push(i);
   int sum=0;
   while (!q.empty())
   {
      sum++;
      int x=q.front();
      for (int i=b[x];i;i=A[i][1])
      {
         int y=A[i][0];
         d[y]--;
         if (!d[y])
            q.push(y);
      }
      q.pop();
   }
   return(sum==n);
}
