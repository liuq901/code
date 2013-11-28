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
int row[1300],a[1300],col[5700],b[5700];
int main()
{
   char ch;
   for (int i=1;i<=1234;i++)
      row[i]=a[i]=i;
   for (int i=1;i<=5678;i++)
      col[i]=b[i]=i;
   while (cin>>ch)
   {
      int x,y;
      if (ch=='R')
      {
         scanf("%d%d",&x,&y);
         swap(row[x],row[y]);
         a[row[x]]=x,a[row[y]]=y;
      }
      else if (ch=='C')
      {
         scanf("%d%d",&x,&y);
         swap(col[x],col[y]);
         b[col[x]]=x,b[col[y]]=y;
      }
      else if (ch=='Q')
      {
         int x,y;
         scanf("%d%d",&x,&y);
         printf("%d\n",(row[x]-1)*5678+col[y]);
      }
      else
      {
         scanf("%d",&x);
         int p,q;
         p=(x-1)/5678+1,q=(x-1)%5678+1;
         printf("%d %d\n",a[p],b[q]);
      }
   }
   system("pause");
   return(0);
}
