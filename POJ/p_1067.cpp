#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
   int n,m;
   while (scanf("%d%d",&n,&m)!=EOF)
   {
      if (n>m)
         swap(n,m);
      double pi=(sqrt(5)+1)/2;
      int k=m-n;
      if (int(pi*k)==n)
         printf("0\n");
      else
         printf("1\n");
   }
   system("pause");
   return(0);
}
