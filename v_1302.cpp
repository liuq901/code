#include <cstdio>
#include <cstdlib>
int main()
{
   void go(int,int);
   int m,i;
   scanf("%d",&m);
   for (i=1;i<=m/2;i++)
      go(i,m);
   system("pause");
   return(0);
}
void go(int n,int m)
{
   int i,sum;
   sum=0;
   for (i=n;i<=m;i++)
   {            
      sum+=i;
      if (sum>=m) 
         break;
   }
   if (sum==m)
      printf("%d %d\n",n,i);
}
