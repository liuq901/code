#include <cstdio>
#include <cstdlib>
int main()
{
   int check(int);
   int i,x,y;
   int ans[1000];
   while (scanf("%d%d",&x,&y)!=EOF)
   {
      ans[0]=0;
      for (i=x;i<=y;i++)
         if (check(i))
         {
            ans[0]++;
            ans[ans[0]]=i;
         }
      if (ans[0]==0)
      {
         printf("none\n");
         continue;
      }
      for (i=1;i<=ans[0]-1;i++)
         printf("%d ",ans[i]);
      printf("%d\n",ans[ans[0]]);
   }
   system("pause");
   return(0);
}
int check(int x)
{
   int calc(int,int);
   int i,s,t,n;
   int a[10];
   i=0;
   n=x;
   while (x!=0)
   {
      i++;
      a[i]=x%10;
      x/=10;
   }
   t=i;
   s=0;
   while (i!=0)
   {
      s+=calc(a[i],t);
      i--;
   }
   if (s==n)
      return(1);
   else
      return(0);
}
int calc(int x,int t)
{
   int i,s;
   s=1;
   for (i=1;i<=t;i++)
      s*=x;
   return(s);
}
