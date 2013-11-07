#include <cstdio>
#include <cstdlib>
int main()
{
   int count(int,int);
   int n,q;
   scanf("%d%d",&n,&q);
   printf("%d\n",count(n,q));
   system("pause");
   return(0);
}
int count(int x,int y)
{
   int k;
   if (x==1)
      return(1);
   else
   {
      k=x/2;
      if (y>k)
         return(count(x-k,x-y+1));
      else
         return(x-k+count(k,k-y+1));
   }
}
