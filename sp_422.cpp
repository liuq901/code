#include <cstdio>
#include <cstdlib>
struct integer
{
   int a,b;
   integer(int a,int b):a(a),b(b){}
};
const int prime=1000003;
int main()
{
   void init(),work();
   init();
   int t;
   scanf("%d",&t);
   while (t--)
      work();
   system("pause");
   return(0);
}
int a[1000001],b[1000001];
bool f[1000001];
void init()
{
   for (int i=2;i<=1000000;i++)
   {
      if (f[i])
         continue;
      a[++a[0]]=i;
      b[i]=a[0];
      int k=1000000/i;
      for (int j=i;j<=k;j++)
         if (!f[i*j])
         {
            f[i*j]=true;
            b[i*j]=i;
         }
   }
}
int g,p,tot,sum,c[26][2],d[1000001];
long long ans;
void work()
{
   int gcd(int,int);
   integer extended_gcd(int,int);
   void did(int,int),search(int,int);
   long long multi(int);
   int n,m;
   scanf("%d%d",&n,&m);
   if (!n || !m)
   {
      printf("0\n");
      return;
   }
   g=gcd(n,m);
   int x=(n+m)/g;
   integer tmp=extended_gcd(x,prime);
   p=tmp.a;
   c[0][0]=c[0][1]=1;
   did(x,0);
   d[1]=x;
   ans=0;
   search(1,1);
   printf("%I64d\n",(multi(n+m)-ans+prime)%prime);
}
int gcd(int a,int b)
{
   if (!b)
      return(a);
   return(gcd(b,a%b));
}
integer extended_gcd(int a,int b)
{
   if (!b)
      return(integer(1,0));
   integer tmp=extended_gcd(b,a%b);
   int x=tmp.a,y=tmp.b;
   return(integer(y,x-(a/b)*y));
}
void did(int x,int y)
{
   if (!f[x])
   {
      if (x==c[y][0])
         c[y][1]++;
      else
      {
         y++;
         c[y][0]=x;
         c[y][1]=1;
      }
      tot=y;
      return;
   }
   int t=b[x];
   if (t==c[y][0])
      c[y][1]++;
   else
   {
      y++;
      c[y][0]=t;
      c[y][1]=1;
   
   }
   did(x/t,y);
}
void search(int x,int y)
{
   long long multi(int);
   for (int i=y;i<=tot;i++)
   {
      if (!c[i][1])
         continue;
      int t=x*c[i][0];
      d[t]=d[x]/c[i][0];
      d[x]-=d[t];
      c[i][1]--;
      search(t,i);
      c[i][1]++;
   }
   long long t=multi(g*x)*p%prime;
   while (t<0)
      t+=prime;
   ans+=t*d[x];
   ans%=prime;
}
long long q[1000001];
long long multi(int x)
{
   if (q[x])
      return(q[x]);
   if (!x)
      q[x]=1;
   else if (x&1)
      q[x]=multi(x/2)*multi(x/2)*2%prime;
   else
      q[x]=multi(x/2)*multi(x/2)%prime;
   return(q[x]);
}
