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
int ans[1010],d[1010],a[1010][1010];
bool f[1010];
char s[100010];
int main()
{
   int n;
   scanf("%d",&n),gets(s);
   for (int i=1;i<=n;i++)
   {
      gets(s);
      int l=strlen(s),x=0;
      for (int j=0;j<l;j++)
         if (isdigit(s[j]))
            x=x*10+s[j]-'0';
         else if (x)
         {
            a[i][++a[i][0]]=x,d[x]++;
            x=0;
         }
      if (x)
         a[i][++a[i][0]]=x,d[x]++;
   }
   int x=1,t=0;
   f[1]=true;
   while (1)
   {
      int min=inf,k=-1;
      for (int i=1;i<=a[x][0];i++)
      {
         int y=a[x][i];
         if (f[y])
            continue;
         if (d[y]<min)
            min=d[y],k=y;
      }
      if (k==-1)
         break;
      ans[++t]=k;
      f[k]=true;
      x=k;
      for (int i=1;i<=a[x][0];i++)
      {
         int y=a[x][i];
         d[y]--;
      }
   }
   ans[n]=1;
   printf("1");
   for (int i=1;i<=n;i++)
      printf(" %d",ans[i]);
   printf("\n");
   system("pause");
   return(0);
}
