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
#define MAXN 25010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
struct trie
{
   int pos,a[26];
   trie()
   {
      memset(a,0,sizeof(a));
   }
};
const int inf=1061109567;
const double eps=1e-7;
const double pi=acos(-1.0);
string s,a[MAXN];
int tot=1,f[MAXN];
trie q[500000];
int main()
{
   void insert(int);
   int find();
   ios::sync_with_stdio(false);
   int n=0;
   while (cin>>a[0])
      a[++n]=a[0];
   for (int i=1;i<=n;i++)
      insert(i);
   int ans=1;
   f[1]=1;
   for (int i=2;i<=n;i++)
   {
      f[i]=1;
      s=a[i];
      int l=s.size();
      for (int j=0;j<l;j++)
      {
         char ch=s[j];
         for (char k='a';k<='z';k++)
         {
            if (ch==k)
               continue;
            s[j]=k;
            int pos=find();
            if (pos!=-1)
               f[i]=max(f[i],f[pos]+1);
            if (f[i]>ans)
               break;
         }
         s[j]=a[i][j];
         if (f[i]>ans)
            break;
      }
      for (int j=0;j<l;j++)
      {
         char ch=s[j];
         s.erase(j,1);
         int pos=find();
         if (pos!=-1)
            f[i]=max(f[i],f[pos]+1);
         s.insert(j,1,ch);
         if (f[i]>ans)
            break;
      }
      for (int j=0;j<=l;j++)
      {
         for (char k='a';k<='z';k++)
         {
            s.insert(j,1,k);
            int pos=find();
            if (pos!=-1)
               f[i]=max(f[i],f[pos]+1);
            s.erase(j,1);
            if (f[i]>ans)
               break;
         }
         if (f[i]>ans)
            break;
      }
      ans=max(ans,f[i]);
   }
   cout<<ans<<endl;
   system("pause");
   return(0);
}
void insert(int p)
{
   int k=1,l=a[p].length();
   for (int i=0;i<l;i++)
   {
      int t=a[p][i]-'a';
      if (!q[k].a[t])
         q[k].a[t]=++tot;
      k=q[k].a[t];
   }
   q[k].pos=p;
}
int find()
{
   int k=1,l=s.length();
   for (int i=0;i<l;i++)
   {
      int t=s[i]-'a';
      if (!q[k].a[t])
         return(-1);
      k=q[k].a[t];
   }
   return(q[k].pos);
}
