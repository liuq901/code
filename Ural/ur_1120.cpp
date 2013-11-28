#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   int n,i;
   scanf("%d",&n);
   n*=2;
   i=(int)sqrt(n)+1;
   while (!(n%i==0 && n/i+1-i>0 && (n/i+1-i)%2==0))
      i--;
   printf("%d %d\n",(n/i+1-i)/2,i);
   system("pause");
   return(0);
}
