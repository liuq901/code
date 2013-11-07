#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
int a[1000],b[1000],c[10000],p[10000][50],q[10000][50];
double h[10000],g[10000];
int main()
{
   void work();
   int i,t;
   scanf("%d",&t);
   for (i=1;i<=t;i++)
      work();
   system("pause");
   return(0);
}
void work()
{
   void multi(int *,int *,int),plus(int *,int *),print(int *,int *);
   int check(int *,int *,int);
   int i,n;
   scanf("%d",&n);
   memset(p,0,sizeof(p));
   memset(q,0,sizeof(q));
   p[0][0]=1;
   p[0][1]=0;
   p[1][0]=1;
   p[1][1]=1;
   q[0][0]=1;
   q[0][1]=1;
   q[1][0]=1;
   q[1][1]=0;
   a[2]=(int)(sqrt(n));
   if (a[2]*a[2]==n)
      return;
   g[1]=0;
   h[1]=1;
   i=2;
   while (1)
   {
      g[i]=-g[i-1]+a[i]*h[i-1];
      h[i]=(n-g[i]*g[i])/(h[i-1]);
      a[i+1]=(int)((g[i]+a[2])/h[i]);
      multi(p[i],p[i-1],a[i]);
      plus(p[i],p[i-2]);
      multi(q[i],q[i-1],a[i]);
      plus(q[i],q[i-2]);
      if (check(p[i],q[i],n))
      {
         print(p[i],q[i]);
         break;
      }
      i++;
   }
}
void multi(int *b,int *a,int t)
{
   int i,x;
   x=0;
   for (i=1;i<=a[0];i++)
   {
      b[i]=a[i]*t+x;
      x=b[i]/10;
      b[i]%=10;
   }
   b[0]=a[0];
   while (x!=0)
   {
      b[0]++;
      b[b[0]]=x%10;
      x/=10;
   }
}
void plus(int *a,int *b)
{
   int i,x;
   if (b[0]>a[0])
      a[0]=b[0];
   x=0;
   for (i=1;i<=a[0];i++)
   {
      a[i]+=b[i]+x;
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
void print(int *a,int *b)
{
   int i;
   for (i=a[0];i>=1;i--)
      printf("%d",a[i]);
   printf(" ");
   for (i=b[0];i>=1;i--)
      printf("%d",b[i]);
   printf("\n");
}
int check(int *p,int *q,int n)
{
   int i,j,x;
   memset(b,0,sizeof(b));
   for (i=1;i<=p[0];i++)
      for (j=1;j<=p[0];j++)
      {
         b[i+j-1]+=p[i]*p[j];
         b[i+j]+=b[i+j-1]/10;
         b[i+j-1]%=10;
      }
   b[0]=2*p[0];
   while (b[b[0]]==0 && b[0]>0)
      b[0]--;
   memset(c,0,sizeof(c));
   for (i=1;i<=q[0];i++)
      for (j=1;j<=q[0];j++)
      {
         c[i+j-1]+=q[i]*q[j];
         c[i+j]+=c[i+j-1]/10;
         c[i+j-1]%=10;
      }
   c[0]=2*q[0];
   while (c[c[0]]==0 && c[0]>0)
      c[0]--;
   x=0;
   for (i=1;i<=c[0];i++)
   {
      c[i]=c[i]*n+x;
      x=c[i]/10;
      c[i]%=10;
   }
   while (x!=0)
   {
      c[0]++;
      c[c[0]]=x%10;
      x/=10;
   }
   i=1;
   c[1]++;
   while (c[i]>10 && i<=c[0])
   {
      c[i+1]+=c[i]/10;
      c[i]%=10;
      i++;
   }
   while (c[c[0]]>10)
   {
      c[0]++;
      c[c[0]]=c[c[0]-1]/10;
      c[c[0]-1]%=10;
   }
   if (b[0]!=c[0])
      return(0);
   for (i=1;i<=b[0];i++)
      if (b[i]!=c[i])
         return(0);
   return(1);
}
