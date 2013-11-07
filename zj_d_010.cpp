#include <cstdio>
#include <cstdlib>
int main()
{
   int count(int);
   int n,x;
   while (scanf("%d",&n)!=EOF)
   {
      x=count(n);
      if (x<n)
         printf("Ì”µ\n");
      if (x>n)
         printf("Ó¯”µ\n");
      if (x==n)
         printf("ÍêÈ«”µ\n");
   }
   system("pause");
   return(0);
}
int count(int x)
{
   int i,s;
   s=0;
   for (i=1;i<=x/2;i++)
      if (x%i==0)
         s+=i;
   return(s);
}
