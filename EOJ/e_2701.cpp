#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
struct tree
{
   ll l,r,mid;
   int state;
};
tree a[530000];
ll left[100010],right[100010],num[200010];
bool op[100010];
int main()
{
   void work(int,int,int,int,int,int),build(int,int,int),did(int,ll,ll,bool);
   ll calc(int,int,int,int);
   bool get(int,ll);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      char s[100],t[100];
      scanf("%s %*s %s",s,t);
      op[i]=s[0]=='a';
      int pos=string(t).find('/');
      int a,b,c,d,p;
      if (pos==string::npos)
      {
         sscanf(t,"%d.%d.%d.%d",&a,&b,&c,&d);
         p=32;
      }
      else
         sscanf(t,"%d.%d.%d.%d/%d",&a,&b,&c,&d,&p);
      work(a,b,c,d,32-p,i);
      num[i]=left[i],num[i+n]=right[i]+1;
   }
   int N=(n<<1)+1;
   num[N]=0;
   sort(num+1,num+N+1);
   N=unique(num+1,num+N+1)-num-1;
   num[N+1]=1LL<<32;
   build(1,1,N);
   for (int i=n;i;i--)
      did(1,left[i],right[i],op[i]);
   int m;
   scanf("%d",&m);
   while (m--)
   {
      int a,b,c,d;
      scanf("%d.%d.%d.%d",&a,&b,&c,&d);
      printf("%c",get(1,calc(a,b,c,d))?'A':'D');
   }
   printf("\n");
   system("pause");
   return(0);
}
void work(int a,int b,int c,int d,int p,int id)
{
   ll l=(ll(a)<<24)+(ll(b)<<16)+(ll(c)<<8)+ll(d);
   for (int i=0;i<p;i++)
      l&=~(1LL<<i);
   ll r=l;
   for (int i=0;i<p;i++)
      r|=1LL<<i;
   left[id]=l,right[id]=r;
}
void build(int x,int l,int r)
{
   a[x].state=1;
   if (l==r)
   {
      a[x].l=num[l],a[x].r=num[l+1]-1;
      a[x].mid=num[l];
      return;
   }
   int ls=x<<1,rs=ls+1,mid=l+r>>1;
   build(ls,l,mid);
   build(rs,mid+1,r);
   a[x].l=a[ls].l,a[x].mid=a[ls].r,a[x].r=a[rs].r;
}
void did(int x,ll left,ll right,bool state)
{
   if (a[x].l==left && a[x].r==right)
   {
      a[x].state=state?1:-1;
      return;
   }
   int ls=x<<1,rs=ls+1;
   if (a[x].state)
      a[ls].state=a[rs].state=a[x].state;
   if (right<=a[x].mid)
      did(ls,left,right,state);
   else if (left>a[x].mid)
      did(rs,left,right,state);
   else
   {
      did(ls,left,a[x].mid,state);
      did(rs,a[x].mid+1,right,state);
   }
   if (!a[ls].state || !a[rs].state || a[ls].state!=a[rs].state)
      a[x].state=0;
   else
      a[x].state=a[ls].state;
}
ll calc(int a,int b,int c,int d)
{
   return((ll(a)<<24)+(ll(b)<<16)+(ll(c)<<8)+ll(d));
}
bool get(int x,ll pos)
{
   if (a[x].state)
      return(a[x].state==1);
   int ls=x<<1,rs=ls+1;
   if (a[x].state)
      a[ls].state=a[rs].state=a[x].state;
   if (pos<=a[x].mid)
      return(get(ls,pos));
   else
      return(get(rs,pos));
}
