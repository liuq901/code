#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
   bool check(int);
   int ans=0;
   for (int i=100;i<1000;i++)
      for (int j=100;j<1000;j++)
      {
         int x=i*j;
         if (check(x))
            ans=max(ans,x);
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool check(int x)
{
   int a=x,b=0;
   while (x)
   {
      b=b*10+x%10;
      x/=10;
   }
   return(a==b);
}
