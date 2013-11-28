#include <cstdio>
#include <cstdlib>
int main()
{
   void work(long long);
   long long n;
   char ch;
   while (scanf("%I64d",&n)!=EOF)
      work(n);
   system("pause");
   return(0);
}
void work(long long n)
{
   long long count(long long);
   long long i,t,x,flag;
   long long a[100001];
   a[0]=1;
   a[1]=n;
   x=n;
   while (1)
   {
      x=count(x);
      flag=1;
      for (i=1;i<=a[0];i++)
         if (a[i]==x)
         {
            flag=0;
            t=i;
            break;
         }
      if (flag)
      {
         a[0]++;
         a[a[0]]=x;
      }
      else
         break;
   }
   for (i=t;i<a[0];i++)
      printf("%I64d ",a[i]);
   printf("%I64d\n",a[a[0]]);
}
long long count(long long s)
{
   long long n,i,j,t,x,y;
   long long a[100];
   i=0;
   while (s!=0)
   {
      i++;
      a[i]=s%10;
      s/=10;
   }
   n=i;
   for (i=1;i<=n-1;i++)
      for (j=i+1;j<=n;j++)
         if (a[i]>a[j])
            t=a[i],a[i]=a[j],a[j]=t;
   x=0;
   for (i=1;i<=n;i++)
      x=x*10+a[i];
   y=0;
   for (i=n;i>=1;i--)
      y=y*10+a[i];
   return(y-x);
}
