#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,m,d,f,a[10000];
int main()
{
   int work(int);
   int i,j,k,t,x,y,ans;
   scanf("%d",&n);
   memset(a,0,sizeof(a));
   scanf("%d%d",&x,&y);
   a[x]=y;
   d=x;
   while (1)
   {
      scanf("%d%d",&x,&y);
      if (x==y && y==-1)
         break;
      a[x]=y;
      f=x;
   }
   for (i=d;i<=f;i++)
      if (a[i]!=0)
      {
         for (j=i+1;j<=f;j++)
            if (a[j]!=0)
            {
               k=j;
               break;
            }
         if (k!=i)
         {
            t=(a[k]-a[i])/(k-i);
            for (j=i+1;j<=k-1;j++)
               a[j]=a[j-1]+t;
         }
      }
   scanf("%d",&x);
   while (1)
   {
      if (a[f]-x<=0)
         break;
      f++;
      a[f]=a[f-1]-x;
   }
   ans=-26262626;
   for (i=-50;i<=50;i++)
      if (work(i)==n && abs(i)<abs(ans))
         ans=i;
   if (ans==-26262626)
      printf("NO SOLUTION\n");
   else
      printf("%d\n",ans);
   system("pause");
   return(0);
}
int work(int x)
{
   int i,max,ans;
   max=0;
   for (i=d;i<=f;i++)
      if ((i-d+x)*a[i]>=max)
      {
         max=(i-d+x)*a[i];
         ans=i;
      }
   return(ans);
}
