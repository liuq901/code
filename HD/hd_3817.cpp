#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      if (c<a)
         swap(a,c);
      if (c<b)
         swap(b,c);
      a*=a,b*=b,c*=c;
      static int id=0;
      printf("Case %d: ",++id);
      if (a+b==c)
         printf("Right triangle\n");
      else if (a+b<c)
         printf("Obtuse triangle\n");
      else
         printf("Acute triangle\n");
   }
   system("pause");
   return(0);
}
