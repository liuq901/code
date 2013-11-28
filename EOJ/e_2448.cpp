#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;
const string ans[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int k,m;
      scanf("%*d%d%d",&k,&m);
      printf("%s\n",ans[int(ceil(double(k)/m))%7].c_str());
   }
   system("pause");
   return(0);
}
