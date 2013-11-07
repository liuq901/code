#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
   int a,b,c;
   scanf("%d%d%d",&a,&b,&c);
   if (a>c)
      swap(a,c);
   if (b>c)
      swap(b,c);
   a=a*a,b=b*b,c=c*c;
   printf("%s\n",a+b>c?"acute triangle":a+b==c?"right triangle":"obtuse triangle");
   system("pause");
   return(0);
}
