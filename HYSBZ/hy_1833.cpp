#include <cstdio>
#include <cstdlib>
long long ans[10];
int main()
{
   void init(),work(long long,int),check(long long,int);
   init();
   long long a,b;
   scanf("%I64d%I64d",&a,&b);
   work(b,1);
   check(b,-1);
   work(a-1,-1);
   check(a-1,1);
   for (int i=0;i<9;i++)
      printf("%I64d ",ans[i]);
   printf("%I64d\n",ans[9]);
   system("pause");
   return(0);
}
long long a[15];
void init()
{
   a[0]=1;
   for (int i=1;i<=14;i++)
      a[i]=a[i-1]*10;
}
void work(long long x,int value)
{
   if (x<10)
   {
      for (int i=0;i<=x;i++)
         ans[i]+=value;
      return;
   }
   int p=0;
   while (a[p]<=x)
      p++;
   p--;
   long long first=x/a[p],second=x%a[p];
   for (int i=0;i<first;i++)
   {
      ans[i]+=a[p]*value;
      for (int j=0;j<10;j++)
         ans[j]+=p*a[p-1]*value;
   }
   ans[first]+=(second+1)*value;
   if (!second)
   {
      ans[0]+=p*value;
      return;
   }
   int k=0;
   while (a[k]<=second)
      k++;
   k--;
   ans[0]+=(p-k-1)*value*(second+1);
   work(second,value);
}
void check(long long x,int value)
{
   if (x<0)
      return;
   int p=0;
   while (a[p]<=x)
      p++;
   p--;
   for (int i=1;i<=p;i++)
      ans[0]+=a[i]*value;
}
