#include <cstdio>
#include <cstdlib>
#include <cmath>
int h,n,m,k,w;
int a[201],b[201],c[201];
int len,len1,len2;
int main()
{
   void init(),work(),out();
   init();
   work();
   out();
   system("pause");
   return(0);
}
void init()
{
   scanf("%d%d",&k,&w);
   n=w/k;
   m=w%k;
   h=(int)(pow(2,k)+0.5)-1;
}
void work()
{
   void js(int,int),add();
   int i;
   for (i=0;i<=201;i++)
      a[i]=0;
   len=0;
   for (i=2;i<=n;i++)
      if (i<=h)
      {
         js(i,h);
         add();
      }
   if (h>=n+1 && m>0)
      for (i=1;i<=((int)(pow(2,m)+0.5)-1);i++)
         if (n<=h-i)
         {
            js(n,h-i);
            add();
         }
}
void out()
{
   int i;
   for (i=len;i>=1;i--)
      printf("%d",a[i]);
   printf("\n");
}
void js(int m,int n)
{
   void chen(int,int);
   int i,x,j;
   for (i=0;i<=201;i++)
      b[i]=0;
   b[1]=1;
   len1=1;
   for (i=1;i<=m;i++)
   {
      x=n-i+1;
      chen(x,i);
   }
}
void add()
{
   int x,y,i;
   if (len<len1)
      len=len1;
   x=0;
   for (i=1;i<=len;i++)
   {
      y=a[i]+b[i]+x;
      a[i]=y%10;
      x=y/10;
   }
   while (x>0)
   {
      len++;
      a[len]=x%10;
      x/=10;
   }
}
void chen(int x,int h)
{
   int i,j,y,jw;
   jw=0;
   for (j=1;j<=len1;j++)
   {
      y=b[j]*x+jw;
      b[j]=y%10;
      jw=y/10;
   }
   while (jw>0)
   {
      len1++;
      b[len1]=jw%10;
      jw/=10;
   }
   y=0;
   for (i=len1;i>=1;i--)
   {
      y=y*10+b[i];
      b[i]=y/h;
      y%=h;
   }
   while (b[len1]==0)
      len1--;
}
