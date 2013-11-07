#include <cstdio>
#include <cstdlib>
const char c[]="+-";
int main()
{
   void work(int);
   int i,j,n;
   scanf("%d",&n);
   for (i=1;i<=n-1;i++)
      printf("(");
   j=0;
   for (i=n;i>=2;i--)
   {
      j++;
      work(j);
      printf("+%d)",i);
   }
   work(n);
   printf("+1\n");
   system("pause");
   return(0);
}
void work(int n)
{
   int i;
   for (i=1;i<=n-1;i++)
      printf("sin(%d%c",i,c[i%2]);
   printf("sin(%d)",n);
   for (i=1;i<=n-1;i++)
      printf(")");
}
