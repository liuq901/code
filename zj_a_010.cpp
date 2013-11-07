#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[500001],ans[500001][2],f[1000001];
int main()
{
   void build(),work(int);
   int n;
   build();
   while (scanf("%d",&n)!=EOF)
      work(n);
   system("pause");
   return(0);
}
void build()
{
   int i,j;
   memset(f,0,sizeof(f));
   for (i=2;i<=1000000;i++)
   {
      if (f[i])
         continue;
      j=i-1;
      while (1)
      {
         j++;
         if (i*j>1000000 || i*j<=0)
            break;
         f[i*j]=1;
      }
   }
   a[0]=0;
   for (i=2;i<=1000000;i++)
      if (!f[i])
      {
         a[0]++;
         a[a[0]]=i;
      }
}
void work(int n)
{
   int t,i,flag;
   t=0;
   i=1;
   flag=1;
   while (1)
   {
      if (!f[n])
         break;
      if (n%a[i]!=0)
      {
         i++;
         flag=1;
         continue;
      }
      if (flag)
      {
         t++;
         ans[t][0]=a[i];
         ans[t][1]=1;
         flag=0;
      }
      else
         ans[t][1]++;
      n/=a[i];
   }
   if (ans[t][0]==n)
      ans[t][1]++;
   else
   {
      t++;
      ans[t][0]=n;
      ans[t][1]=1;
   }
   for (i=1;i<=t;i++)
   {
      printf("%d",ans[i][0]);
      if (ans[i][1]!=1)
         printf("^%d",ans[i][1]);
      if (i!=t)
         printf(" * ");
      else
         printf("\n");
   }
}
