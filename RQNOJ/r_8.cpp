#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
int a[201],b[201];
int main()
{
   void work(int,int),add();
   int i,k,w,n,m,h;
   scanf("%d%d",&k,&w);
   n=w/k;
   m=w%k;
   h=(int)(exp(k*log(2))+0.5)-1;
   memset(a,0,sizeof(a));
   a[0]=0;
   for (i=2;i<=n;i++)
      if (i<=h)
      {
         work(i,h);
         add();
      }
   if (h>=n+1 && m>0)
      for (i=1;i<=(int)(exp(m*log(2))+0.5)-1;i++)
         if (n<=h-i)
         {
            work(n,h-i);
            add();
         }
   for (i=a[0];i>=1;i--)
      printf("%d",a[i]);
   printf("\n");
   system("pause");
   return(0);
}
void work(int m,int n)
{
   void chen(int,int);
   int i,j,x;
   memset(b,0,sizeof(b));
   b[1]=1;
   b[0]=1;
   for (i=1;i<=m;i++)
   {
      x=n-i+1;
      chen(x,i);
   }
}
void chen(int x,int h)
{
   int i,j,y,s;
   s=0;
   for (j=1;j<=b[0];j++)
   {
      y=b[j]*x+s;
      b[j]=y%10;
      s=y/10;
   }
   while (s>0)
   {
      b[0]++;
      b[b[0]]=s%10;
      s/=10;
   }
   y=0;
   for (i=b[0];i>=1;i--)
   {
      y=y*10+b[i];
      b[i]=y/h;
      y%=h;
   }
   while (b[b[0]]==0)
      b[0]--;
}
void add()
{
   int x,y,i;
   if (a[0]<b[0])
      a[0]=b[0];
   x=0;
   for (i=1;i<=a[0];i++)
   {
      y=a[i]+b[i]+x;
      a[i]=y%10;
      x=y/10;
   }
   while (x>0)
   {
      a[0]++;
      a[a[0]]=x%10;
      x/=10;
   }
}
