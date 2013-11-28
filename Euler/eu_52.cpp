#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
int main()
{
   string calc(int);
   for (int i=1;;i++)
   {
      string now=calc(i);
      if (now==calc(i<<1) && now==calc(i*3) && now==calc(i<<2) && now==calc(i*5) && now==calc(i*6))
      {
         printf("%d\n",i);
         break;
      }
   }
   system("pause");
   return(0);
}
string calc(int x)
{
   string ret="0000000000";
   while (x)
   {
      ret[x%10]++;
      x/=10;
   }
   return(ret);
}
