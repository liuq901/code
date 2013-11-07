#include <cstdio>
#include <cstdlib>
#include <cstring>
int m=10000;
class bignum
{
   int a[20000];
public:
   bignum()
   {
      memset(a,0,sizeof(a));
   }
   bignum(int x)
   {
      a[0]=1,a[1]=x;
   }
   void print()
   {
      printf("%d",a[a[0]]);
      for (int i=a[0]-1;i;i--)
         printf("%04d",a[i]);
      printf("\n");
   }
   int &operator [](int x)
   {
      return(a[x]);
   }
};
bignum operator *(bignum a,bignum b)
{
   bignum c;
   c[0]=a[0]+b[0];
   for (int i=1;i<=a[0];i++)
      for (int j=1;j<=b[0];j++)
      {
         c[i+j-1]+=a[i]*b[j];
         c[i+j]+=c[i+j-1]/m;
         c[i+j-1]%=m;
      }
   while (!c[c[0]] && c[0]>1)
      c[0]--;
   return(c);
}
bignum ans=1;
int main()
{
   void calc(int,int);
   calc(7,86495);
   ans.print();
   system("pause");
   return(0);
}
int a[1000];
void calc(int x,int n)
{
   a[0]=0;
   while (n)
   {
      a[++a[0]]=n&1;
      n>>=1;
   }
   for (int i=a[0];i;i--)
   {
      ans=ans*ans;
      if (a[i])
         ans=ans*x;
   }
}
