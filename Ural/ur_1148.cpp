#include <cstdio>
#include <cstdlib>
#include <cstring>
const int p=149997;
const long long max=1LL<<48;
int h,f[150000][3];
long long d[150000];
int main()
{
   long long count(int,int,int);
   int n,m;
   scanf("%d%d%d",&n,&h,&m);
   memset(f,0,sizeof(f));
   memset(d,0,sizeof(d));
   printf("%I64d\n",count(1,m,n));
   while (1)
   {
      long long k;
      scanf("%I64d",&k);
      if (k==-1)
         break;
      int j=n,l=m;
      for (int i=2;i<=h;i++)
      {
         j-=l;
         printf("%d ",l);
         long long q=count(i,l-1,j);
         if (k<=q)
            l--;
         else
         {
            k-=q;
            l++;
         }
      }
      printf("%d\n",l);
   }
   system("pause");
   return(0);
}
long long count(int x,int y,int z)
{
   int hash(int,int,int);
   if (y<1)
      return(0);
   int a,b,c;
   if (h-x<y)
      a=(y*2-h+x)*(h-x+1)>>1;
   else
   {
      a=(y+1)*y>>1;
      b=h-x-y+1;
      c=b>>1;
      a+=c;
      a+=b-c>>1;
   }
   if (a>z)
      return(0);
   a=(y*2+h-x)*(h-x+1)>>1;
   if (z>a)
      z=a;
   if (x==h)
      return(1);
   int t=hash(x,y,z);
   if (d[t]>0)
      return(d[t]);
   long long r=count(x+1,y-1,z-y)+count(x+1,y+1,z-y);
   if (r<max)
   {
      f[t][0]=x;
      f[t][1]=y;
      f[t][2]=z;
      d[t]=r;
   }
   return(r);
}
int hash(int x,int y,int z)
{
   int r=z*z%p*z%p*y%p*x%p;
   while (d[r]>0 && (f[r][0]!=x || f[r][1]!=y || f[r][2]!=z))
      r=(r+1)%p;
   return(r);
}
