#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[10];
int main()
{
   bool check(int);
   for (int i=1;i<10;i++)
      a[i]=i;
   int ans=0;
   for (int i=9;i;i--)
      while (1)
      {
         int x=0;
         for (int j=1;j<=i;j++)
            x=x*10+a[j];
         if (check(x))
            ans=max(ans,x);
         if (!next_permutation(a+1,a+i+1))
            break;
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool check(int x)
{
   for (int i=2;i*i<=x;i++)
      if (!(x%i))
         return(false);
   return(true);
}
