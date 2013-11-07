#include <cstdio>
#include <cstdlib>
int main()
{
   int work(int);
   int x,y,i,k,t,flag;
   while (scanf("%d%d",&x,&y)!=EOF)
   {
      flag=0;
      if (x>y)
      {
         t=x,x=y,y=t;
         flag=1;
      }
      t=0;
      for (i=x;i<=y;i++)
      {
         k=work(i);
         if (k>t)
            t=k;
      }
      if (flag)
         printf("%d %d %d\n",y,x,t);
      else
         printf("%d %d %d\n",x,y,t);
   }
   system("pause");
   return(0);
}
int work(int x)
{
   int s;
   s=1;
   while (1)
   {
      if (x==1)
         break;
      if (x%2==1)
         x=3*x+1;
      else
         x/=2;
      s++;
   }
   return(s);
}
