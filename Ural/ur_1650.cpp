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
typedef map <string,int>::iterator data;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
struct heap
{
   ll value;
   int city,pos;
};
int tail,pos[10010],sum[60010];
ll money[10010];
heap p[60010];
map <string,int> A,B;
pair <string,int> ans[60010];
int main()
{
   void insert(int),modify(int,ll),update(int);
   int n,tot=0;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      string name,city;
      cin>>name>>city>>money[i];
      A[name]=i;
      if (!B.count(city))
      {
         B[city]=++tot;
         insert(tot);
      }
      modify(B[city],money[i]);
      pos[i]=B[city];
   }
   int m,k,num=1;
   scanf("%d%d",&m,&k);
   for (int i=1;i<=k;i++)
   {
      int now;
      string name,city;
      cin>>now>>name>>city;
      now++;
      if (now>num)
      {
         update(now-num);
         num=now;
      }
      if (!B.count(city))
      {
         B[city]=++tot;
         insert(tot);
      }
      modify(pos[A[name]],-money[A[name]]);
      modify(B[city],money[A[name]]);
      pos[A[name]]=B[city];
   }
   update(m+1-num);
   num=0;
   for (data k=B.begin();k!=B.end();k++)
   {
      if (!sum[k->second])
         continue;
      ans[++num].first=k->first,ans[num].second=sum[k->second];
   }
   sort(ans+1,ans+num+1);
   for (int i=1;i<=num;i++)
      printf("%s %d\n",ans[i].first.c_str(),ans[i].second);
   system("pause");
   return(0);
}
void insert(int x)
{
   p[++tail].value=0;
   p[tail].city=x;
   p[x].pos=tail;
}
void modify(int x,ll value)
{
   void up(int),down(int);
   x=p[x].pos;
   p[x].value+=value;
   value>0?up(x):down(x);
}
void up(int x)
{
   if (x==1 || p[x].value<=p[x>>1].value)
      return;
   swap(p[x].value,p[x>>1].value);
   swap(p[x].city,p[x>>1].city);
   p[p[x].city].pos=x,p[p[x>>1].city].pos=x>>1;
   up(x>>1);
}
void down(int x)
{
   int ls=x<<1,rs=ls+1;
   if (ls>tail)
      return;
   int t;
   if (ls==tail)
      t=ls;
   else
      t=p[ls].value>p[rs].value?ls:rs;
   if (p[x].value<p[t].value)
   {
      swap(p[x].value,p[t].value);
      swap(p[x].city,p[t].city);
      p[p[x].city].pos=x,p[p[t].city].pos=t;
      down(t);
   }
}
void update(int num)
{
   if (tail>=2 && p[1].value==p[2].value || tail>=3 && p[1].value==p[3].value)
      return;
   sum[p[1].city]+=num;
}
