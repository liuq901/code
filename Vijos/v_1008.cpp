#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[50001],b[50001][2],d[50001],w[50001];
int n,ans,i,j,t,max,flag;
int main()
{
   void init(),circle(),min();
   flag=1;
   init();
   if (flag)
      circle();
   if (flag)
      min();
   if (flag)
      printf("%d\n",ans);
   else
      printf("-1\n");
   system("pause");
   return(0);
}
void init()
{
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d%d",&b[i][0],&b[i][1]);
      d[b[i][0]]++;
      d[b[i][1]]++;
   }
   for (i=1;i<=n;i++)
      if (d[i]!=2)
      {
         flag=0;
         return;
      }
}
void circle()
{
   a[1]=1;
   a[2]=b[1][0];
   for (i=3;i<=n;i++)
      if (b[a[i-1]][0]!=a[i-2])
         a[i]=b[a[i-1]][0];
      else
         a[i]=b[a[i-1]][1];
   if (a[n]!=b[1][1])
      flag=0;
}
void min()
{
   memset(w,0,sizeof(w));
   for (i=1;i<=n;i++)
      w[(a[i]-i+n)%n]++;
   max=-1;
   for (i=0;i<=n-1;i++)
      if (max<w[i])
         max=w[i];
   for (i=1;i<=(n+1)/2;i++)
   {
      t=a[i];
      a[i]=a[n-i+1];
      a[n-i+1]=t;
   }
   memset(w,0,sizeof(w));
   for (i=1;i<=n;i++)
      w[(a[i]-i+n)%n]++;
   for (i=0;i<=n-1;i++)
      if (max<w[i])
         max=w[i];
   ans=n-max;
}
