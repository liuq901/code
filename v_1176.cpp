#include <cstdio>
#include <cstdlib>
int main()
{
   int work(int);
   int n;
   scanf("%d",&n);
   printf("%d\n",work(n)+1);
   system("pause");
   return(0);
}
int work(int n)
{
   if (n==0) 
      return(0);
   else 
      return n^work((n/2));
}
