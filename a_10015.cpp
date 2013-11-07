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
char c[]={"SHCD"};
map <char,int> a;
bool f[4][14];
int main()
{
   int n;
   a['S']=0,a['H']=1,a['C']=2,a['D']=3;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      char ch;
      int x;
      cin>>ch>>x;
      f[a[ch]][x]=true;
   }
   for (int i=0;i<4;i++)
      for (int j=1;j<=13;j++)
         if (!f[i][j])
            printf("%c %d\n",c[i],j);
   system("pause");
   return(0);
}
