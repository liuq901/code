#include <cstdio>
#include <cstdlib>
#include <cmath>
const double eps=1e-10;
int main()
{
   int n,m;
   while (scanf("%d%d",&n,&m)!=EOF)
      printf("%d\n",int(m*log10(n))+1);
   system("pause");
   return(0);
}
