#include <cstdio>
#include <cstdlib>
const int m=10000;
int ans[50001],a[50001];
int p[200001];
int main()
{
   int gcd(int,int);
   void multi(int),divide(int);
   int n,max=0;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int k=gcd(n,i);
      p[k]++;
      if (k>max)
         max=k;
   }
   for (int i=max;i>=1;i--)
      while (p[i])
         multi(i);
   divide(n);
   system("pause");
   return(0);
}
int gcd(int a,int b)
{
   while (b!=0)
   {
      int t;
      t=a%b;
      a=b;
      b=t;
   }
   return(a);
}
int b[50001];
void multi(int x)
{
   void times(int),plus();
   if (!x)
   {
      a[0]=a[1]=1;
      return;
   }
   if (x==1)
   {
      a[0]=1;
      a[1]=2;
      if (p[x])
      {
         times(p[x]);
         plus();
         p[x]=0;
      }
      return;
   }
   multi(x/2);
   for (int i=1;i<=2*a[0];i++)
      b[i]=0;
   for (int i=1;i<=a[0];i++)
      for (int j=1;j<=a[0];j++)
      {
         b[i+j-1]+=a[i]*a[j];
         b[i+j]+=b[i+j-1]/m;
         b[i+j-1]%=m;
      }
   b[0]=2*a[0];
   while (b[b[0]]==0)
      b[0]--;
   for (int i=1;i<=b[0];i++)
      a[i]=b[i];
   a[0]=b[0];
   if (x&1)
   {
      int x=0;
      for (int i=1;i<=a[0];i++)
      {
         a[i]=a[i]*2+x;
         x=a[i]/m;
         a[i]%=m;
      }
      while (x!=0)
      {
         a[0]++;
         a[a[0]]=x%m;
         x/=m;
      }
   }
   if (p[x])
   {
      times(p[x]);
      plus();
      p[x]=0;
   }
}
void times(int k)
{
   b[0]=a[0];
   int x=0;
   for (int i=1;i<=a[0];i++)
   {
      b[i]=a[i]*k+x;
      x=b[i]/m;
      b[i]%=m;
   }
   while (x!=0)
   {
      b[0]++;
      b[b[0]]=x%m;
      x/=m;
   }
}
void plus()
{
   if (b[0]>ans[0])
      ans[0]=b[0];
   int x=0;
   for (int i=1;i<=ans[0];i++)
   {
      ans[i]+=(i<=b[0]?b[i]:0)+x;
      x=ans[i]/m;
      ans[i]%=m;
   }
   while (x!=0)
   {
      ans[0]++;
      ans[ans[0]]=x%m;
      x/=m;
   }
}
void divide(int n)
{
   int t;
   for (int i=1;i<=ans[0]/2;i++)
      t=ans[i],ans[i]=ans[ans[0]-i+1],ans[ans[0]-i+1]=t;
   int x=0;
   for (int i=1;i<=ans[0];i++)
   {
      int t;
      t=m*x+ans[i];
      ans[i]=t/n;
      x=t%n;
   }
   x=1;
   while (!ans[x])
      x++;
   printf("%d",ans[x]);
   for (int i=x+1;i<=ans[0];i++)
      printf("%04d",ans[i]);
   printf("\n");
}
