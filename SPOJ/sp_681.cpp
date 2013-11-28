#include <cstdio>
#include <cstdlib>
#include <cstring>
const long long max=1LL<<48;
long long f[61][11][33000];
int main()
{
   void work();
   int t;
   scanf("%d",&t);
   memset(f,-1,sizeof(f));
   while (t--)
      work();
   system("pause");
   return(0);
}
int h;
void work()
{
   long long count(int,int,int);
   int n,m;
   scanf("%d%d%d",&n,&h,&m);
   printf("%lld\n",count(1,m,n));
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
   if (f[x][y][z]!=-1)
      return(f[x][y][z]);
   f[x][y][z]=count(x+1,y-1,z-y)+count(x+1,y+1,z-y);
   return(f[x][y][z]);
}
