#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
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
typedef complex <double> cp;
const double eps=1e-7;
const double pi=acos(-1);
struct BatchSystem
{
   multimap <pair <ll,int> ,string> a;
   typedef multimap <pair <ll,int> ,string>::iterator data;
   vector <int> schedule(vector <int> job,vector <string> user)
   {
      int n=job.size();
      for (int i=0;i<n;i++)
      {
         ll p=0;
         int x=i;
         for (data k=a.begin();k!=a.end();k++)
            if (k->second==user[i])
            {
               p=k->first.first;
               x=k->first.second;
               a.erase(k);
               break;
            }
         a.insert(make_pair(make_pair(p+job[i],x),user[i]));
      }
      int sum=0;
      vector <int> ans;
      for (data k=a.begin();k!=a.end();k++)
         for (int i=0;i<n;i++)
            if (k->second==user[i])
               ans.push_back(i);
      return(ans);
   }
};
int main()
{
   vector <int> a;
   vector <string> b;
   int n;
   scanf("%d",&n);
   a.resize(n),b.resize(n);
   for (int i=0;i<n;i++)
      scanf("%d",&a[i]);
   getline(cin,b[0]);
   for (int i=0;i<n;i++)
      getline(cin,b[i]);
   BatchSystem p;
   a=p.schedule(a,b);
   for (int i=0;i<n-1;i++)
      printf("%d ",a[i]);
   printf("%d\n",a[n-1]);
   system("pause");
   return(0);
}
