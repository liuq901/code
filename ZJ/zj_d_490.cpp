#include <cstdio>
#include <cstdlib>
typedef long long ll;
int main()
{
   int a,b;
   scanf("%d%d",&a,&b);
   if (a&1)
      a++;
   if (b&1)
      b--;
   int t=(b-a>>1)+1;
   printf("%d\n",(ll(a)+b)*t/2);
   system("pause");
   return(0);
}
