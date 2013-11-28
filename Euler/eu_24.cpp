#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[10];
int main()
{
   for (int i=0;i<10;i++)
      a[i]=i;
   for (int i=1;i<1000000;i++)
      next_permutation(a,a+10);
   for (int i=0;i<10;i++)
      printf("%d",a[i]);
   printf("\n");
   system("pause");
   return(0);
}
