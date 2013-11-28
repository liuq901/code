#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
   int t=13456;
   for (int i=0;i<10000;i++)
      printf("%d\n",t=(t*3137+i)%65535);
   system("pause");
   return(0);
}
