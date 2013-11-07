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
struct heap
{
   int value,pos;
   heap(int _x,int _y):value(_x),pos(_y){}
};
bool operator <(heap a,heap b)
{
   return(a.value<b.value);
}
priority_queue <heap> a;
int w[15010],l[15010],p[15010],out[15010];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d%d%d",&w[i],&l[i],&p[i]);
   int ans=inf,sum=0,k,water=0;
   for (int i=n;i;i--)
   {
      water+=w[i],sum+=p[i];
      a.push(heap(w[i]-water-l[i],i));
      while (!a.empty() && a.top().value+water>0)
      {
         sum-=p[a.top().pos];
         out[a.top().pos]=i;
         a.pop();
      }
      if (sum<ans)
         ans=sum,k=i;
   }
   for (int i=k;i<=n;i++)
      if (out[i]<k)
         printf("%d\n",i);
   system("pause");
   return(0);
}
