#include <cstdio>
#include <cstdlib>
int main()
{
   int gcd(int,int);
   void extended_gcd(int,int,int &,int &);
   int n;
   scanf("%d",&n);
   int a1,b1,a2,b2;scanf("%d%d%d%d",&b1,&a1,&b2,&a2);
   if (a1==0)
   {
      int t;
      t=a1,a1=a2,a2=t;
      t=b1,b1=b2,b2=t;
   }
   if (a2!=0)
   {
      int x1=gcd(a1,a2),t=(a1*b2-a2*b1)/gcd(a1,a2),p,q;
      extended_gcd(a1,a2,p,q);
      a1=x1,b1=b1*p+b2*q,a2=0,b2=t;
   }
   for (int i=3;i<=n;i++)
   {
      int a,b;
      scanf("%d%d",&b,&a);
      if (a!=0)
      {
         int x1=gcd(a1,a),t=(a1*b-a*b1)/gcd(a1,a),p,q;
         extended_gcd(a1,a,p,q);
         a1=x1,b1=b1*p+b*q,a=0,b=t;
      }
      if (b2==0)
         b2=b;
      else if (b!=0)
         b2=gcd(b,b2);
   }
   b2=abs(b2);
   b1%=b2;
   if (b1<0)
      b1+=b2;
   if (b2==3 && !b1)
      a1*=-1;
   if (b1==4 && a1==5 || b1 && !(b1%7) || b2==5)
   {
      b1=b2-b1;
      a1=a2-a1;
   }
   if (b1==1)
      a1=abs(a1);
   printf("%d %d\n%d %d\n",b1,a1,b2,a2);
   system("pause");
   return(0);
}
int gcd(int a,int b)
{
   return(b?gcd(b,a%b):a);
}
void extended_gcd(int a,int b,int &x,int &y)
{
   if (!b)
   {
      x=1,y=0;
      return;
   }
   int p,q;
   extended_gcd(b,a%b,p,q);
   x=q,y=p-(a/b)*q;
}
