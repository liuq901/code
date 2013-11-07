#include <cstdio>
#include <cstdlib>
#include <cstring>
int r[30],t[30],b[30],a[10000][3];
int main()
{
   bool bellman_ford(int);
   int test;
   scanf("%d",&test);
   while (test--)
   {
      for (int i=0;i<24;i++)
         scanf("%d",&r[i]);
      int n;
      scanf("%d",&n);
      memset(t,0,sizeof(t));
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         t[x]++;
      }
      int ans=-1;
      for (int i=0;i<=n;i++)
         if (bellman_ford(i))
         {
            ans=i;
            break;
         }
      if (ans==-1)
         printf("No Solution\n");
      else
         printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
bool bellman_ford(int sum)
{
   int d[30];
   memset(d,0,sizeof(d));
   bool flag;
   for (int i=0;i<=24;i++)
   {
      flag=false;
      for (int j=1;j<24;j++)
         if (d[j]<d[j-1])
         {
            flag=true;
            d[j]=d[j-1];
         }
      for (int j=1;j<24;j++)
         if (d[j-1]<d[j]-t[j])
         {
            flag=true;
            d[j-1]=d[j]-t[j];
         }
      if (d[0]>t[0])
      {
         flag=true;
         d[0]=t[0];
      }
      if (d[23]<sum)
      {
         flag=true;
         d[23]=sum;
      }
      for (int j=8;j<24;j++)
         if (d[j]<d[j-8]+r[j])
         {
            flag=true;
            d[j]=d[j-8]+r[j];
         }
      for (int j=0;j<8;j++)
         if (d[j]<d[j+16]+r[j]-sum)
         {
            flag=true;
            d[j]=d[j+16]+r[j]-sum;
         }
      if (!flag)
         break;
   }
   if (!flag && d[23]==sum)
      return(true);
   else
      return(false);
}
