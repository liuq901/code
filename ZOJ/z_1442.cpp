#include <cstdio>
#include <cstdlib>
#include <cstring>
class bignum
{
   int a[50];
public:
   bignum()
   {
      memset(a,0,sizeof(a));
      a[0]=1;
   }
   bignum(int x)
   {
      memset(a,0,sizeof(a));
      a[1]=x,a[0]=1;
   }
   void print()
   {
      for (int i=a[0];i>=1;i--)
         printf("%d",a[i]);
      printf("\n");
   }
   int &operator [](int x)
   {
      return(a[x]);
   }
};
bignum operator +(bignum a,bignum b)
{
   bignum c;
   c[0]=a[0]>b[0]?a[0]:b[0];
   int x=0;
   for (int i=1;i<=c[0];i++)
   {
      c[i]=a[i]+b[i]+x;
      x=c[i]/10;
      c[i]%=10;
   }
   while (x)
   {
      c[++c[0]]=x%10;
      x/=10;
   }
   return(c);
}
bignum operator -(bignum a,bignum b)
{
   bignum c;
   c[0]=a[0];
   for (int i=1;i<=c[0];i++)
   {
      c[i]+=a[i]-b[i];
      if (c[i]<0)
      {
         c[i+1]--;
         c[i]+=10;
      }
   }
   while (!c[c[0]] && c[0]>1)
      c[0]--;
   return(c);
}
bignum operator *(bignum a,int b)
{
   bignum c;
   c[0]=a[0];
   int x=0;
   for (int i=1;i<=c[0];i++)
   {
      c[i]=a[i]*b+x;
      x=c[i]/10;
      c[i]%=10;
   }
   while (x!=0)
   {
      c[++c[0]]=x%10;
      x/=10;
   }
   return(c);
}
bignum operator /(bignum a,int b)
{
   bignum c;
   c[0]=a[0];
   int x=0;
   for (int i=c[0];i>=1;i--)
   {
      int t=x*10+a[i];
      c[i]=t/b;
      x=t%b;
   }
   while (!c[c[0]] && c[0]>1)
      c[0]--;
   return(c);
}
int n,m,a[10][2];
bignum ans;
int main()
{
   void work(int,bool);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      scanf("%d%d",&n,&m);
      for (int i=1;i<=n;i++)
      {
         scanf("%d%d",&a[i][0],&a[i][1]);
         a[i][1]++;
      }
      int tot=1<<n;
      ans=0;
      for (int i=0;i<tot;i++)
         work(i,false);
      for (int i=0;i<tot;i++)
         work(i,true);
      ans.print();
   }
   system("pause");
   return(0);
}
void work(int k,bool flag)
{
   bignum count(int,int);
   int p=m,s=0;
   for (int i=1;i<=n;i++)
   {
      int t=k&1;
      s+=t;
      p-=a[i][t];
      k>>=1;
   }
   if (p<0)
      return;
   if (s&1 && flag)
      ans=ans-count(p+n-1,n-1);
   if (!(s&1) && !flag)
      ans=ans+count(p+n-1,n-1);
}
bignum count(int n,int k)
{
   if (n<k || k<0 || n<0)
      return(0);
   bignum ans(1);
   for (int i=n;i>=n-k+1;i--)
      ans=ans*i;
   for (int i=k;i>=1;i--)
      ans=ans/i;
   return(ans);
}
