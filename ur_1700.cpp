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
const double eps=1e-7;
const double pi=acos(-1.0);
vector <int> b[1001];
map <string,int> a,f;
map <int,string> c;
char S[1100];
string d[1001],ans[1001];
int now[1001];
map <int,int> q;
typedef map <int,int>::iterator data;
int main()
{
   int n;
   scanf("%d",&n);
   int tot=0;
   for (int i=1;i<=n;i++)
   {
      scanf("%s",S);
      int l=strlen(S);
      S[l-1]='\0';
      string s;
      s=S;
      a.insert(make_pair(s,i));
      while (1)
      {
         char ch;
         scanf("%s%c",S,&ch);
         s=S;
         int x;
         if (!f.count(s))
            x=++tot,f[s]=x,c[x]=s;
         else
            x=f[s];
         b[i].push_back(x);
         if (ch=='\n')
            break;
      }
   }
   int m;
   scanf("%d",&m);
   while (m--)
   {
      int tot=0;
      while (1)
      {
         char ch;
         scanf("%s%c",S,&ch);
         d[++tot]=S;
         if (ch=='\n')
            break;
      }
      q.clear();
      for (int i=1;i<=tot;i++)
      {
         int x=a[d[i]],l=b[x].size();
         for (int j=0;j<l;j++)
            if (i==1 || q.count(b[x][j]))
               q[b[x][j]]++;
      }
      int sum=0;
      for (data k=q.begin();k!=q.end();k++)
         if (k->second==tot)
            now[++sum]=k->first;
      if (!sum)
         printf("No solution.\n");
      else
      {
         for (int i=1;i<=sum;i++)
            ans[i]=c[now[i]];
         sort(ans+1,ans+sum+1);
         for (int i=1;i<sum;i++)
            printf("%s ",ans[i].c_str());
         printf("%s\n",ans[sum].c_str());
      }
   }
   system("pause");
   return(0);
}
