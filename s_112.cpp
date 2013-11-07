#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   void multiply(int[],int),minus(int[],int[]);
   int compare(int[],int[]);
   int n,m,i;
   int a[1000],b[1000];
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   scanf("%d%d",&n,&m);
   a[0]=b[0]=1;
   a[1]=b[1]=1;
   for (i=1;i<=m;i++)
      multiply(a,n);
   for (i=1;i<=n;i++)
      multiply(b,m);
   if (!compare(a,b))
   {
      printf("-");
      minus(b,a);
      for (i=b[0];i>=1;i--)
         printf("%d",b[i]);
   }
   else
   {
      minus(a,b);
      for (i=a[0];i>=1;i--)
         printf("%d",a[i]);
   }
   printf("\n");
   system("pause");
   return(0);
}
void multiply(int a[],int t)
{
   int i,x;
   x=0;
   for (i=1;i<=a[0];i++)
   {
      a[i]=a[i]*t+x;
      x=a[i]/10;
      a[i]%=10;
   }
   while (x!=0)
   {
      a[0]++;
      a[a[0]]=x%10;
      x/=10;
   }
}
void minus(int a[],int b[])
{
   int i;
   for (i=1;i<=a[0];i++)
   {
      a[i]-=b[i];
      if (a[i]<0)
      {
         a[i]+=10;
         a[i+1]--;
      }
   }
   while (a[a[0]]==0 && a[0]>1)
      a[0]--;
}
int compare(int a[],int b[])
{
   int i;
   if (a[0]>b[0])
      return(1);
   if (a[0]<b[0])
      return(0);
   for (i=a[0];i>=1;i--)
   {
      if (a[i]>b[i])
         return(1);
      if (a[i]<b[i])
         return(0);
   }
   return(1);
}
