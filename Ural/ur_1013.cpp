#include <cstdio>
#include <cstdlib>
#include <cstring>
struct bignum
{
   bignum()
   {
      memset(a,0,sizeof(a));
      a[0]=1;
   }
   void print()
   {
      for (int i=a[0];i>=1;i--)
         printf("%d",a[i]);
      printf("\n");
   }
   bignum operator =(int x)
   {
      a[0]=0;
      while (x!=0)
      {
         a[0]++;
         a[a[0]]=x%10;
         x/=10;
      }
      if (a[0]<=0)
         a[0]=1;
   }
   int & operator [](int x)
   {
      return(a[x]);
   }
private:
   int a[2000];
};
bignum operator +(bignum a,bignum b)
{
   bignum c;
   if (a[0]>b[0])
      c[0]=a[0];
   else
      c[0]=b[0];
   int x=0;
   for (int i=1;i<=c[0];i++)
   {
      c[i]=a[i]+b[i]+x;
      x=c[i]/10;
      c[i]%=10;
   }
   while (x!=0)
   {
      c[0]++;
      c[c[0]]=x%10;
      x/=10;
   }
   return(c);
}
bignum operator *(int k,bignum a)
{
   bignum c;
   int x=0;
   for (int i=1;i<=a[0];i++)
   {
      c[i]=a[i]*k+x;
      x=c[i]/10;
      c[i]%=10;
   }
   c[0]=a[0];
   while (x!=0)
   {
      c[0]++;
      c[c[0]]=x%10;
      x/=10;
   }
   return(c);
}
bignum f[2000];
int main()
{
   int n,k,i;
   scanf("%d",&n);
   scanf("%d",&k);
   k--;
   f[0]=1;
   f[1]=k;
   for (i=2;i<=n;i++)
      f[i]=k*(f[i-1]+f[i-2]);
   f[n].print();
   system("pause");
   return(0);
}
