#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <map>
using namespace std;
class ip
{
   int a,b,c,d,id;
   friend bool operator <(ip,ip);
public:
   ip(){}
   ip(int _a,int _b,int _c,int _d):a(_a),b(_b),c(_c),d(_d){}
   int change(int x)
   {
      id=x;
   }
   int get()
   {
      return(id);
   }
   void print()
   {
      printf("%d.%d.%d.%d\n",a,b,c,d);
   }
};
bool operator <(ip a,ip b)
{
   if (a.a<b.a)
      return(true);
   if (a.a>b.a)
      return(false);
   if (a.b<b.b)
      return(true);
   if (a.b>b.b)
      return(false);
   if (a.c<b.c)
      return(true);
   if (a.c>b.c)
      return(false);
   if (a.d<b.d)
      return(true);
   if (a.d>b.d)
      return(false);
   return(false);
}
typedef map <ip,int>::iterator type;
map <ip,int> p;
int sum,b[3001],a[1000001][3];
int main()
{
   void add(int,int,int);
   bool check(int);
   int spfa(int,int);
   int n,tot=0;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int a,b,c,d,t;
      scanf("%d.%d.%d.%d %d",&a,&b,&c,&d,&t);
      ip s=ip(a,b,c,d);
      type k=p.find(s);
      if (k==p.end())
      {
         s.change(++tot);
         p.insert(make_pair(s,t));
      }
      else
         k->second+=t;
   }
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int a1,b1,c1,d1,a2,b2,c2,d2,x,y,v;
      scanf("%d.%d.%d.%d %d.%d.%d.%d",&a1,&b1,&c1,&d1,&a2,&b2,&c2,&d2);
      ip s1,s2;
      type k1,k2;
      k1=p.find(ip(a1,b1,c1,d1)),k2=p.find(ip(a2,b2,c2,d2));
      if (k1==p.end() || k2==p.end())
         continue;
      s1=k1->first,s2=k2->first;
      x=s1.get(),y=s2.get(),v=k1->second+k2->second;
      add(x,y,v);
   }
   bool flag=false;
   int t;
   if (check(tot))
   {
      int max=-1<<30;
      for (int i=1;i<=tot;i++)
      {
         int now=spfa(i,tot);
         if (now==max)
            flag=false;
         if (now>max)
         {
            max=now;
            t=i;
            flag=true;
         }
      }
   }
   if (!flag)
      printf("The ONLY truth is: it is you, 222.240.168.135\n");
   else
   {
      ip ans;
      for (type k=p.begin();k!=p.end();k++)
      {
         ip s=k->first;
         if (s.get()==t)
         {
            ans=s;
            break;
         }
      }
      printf("The ONLY truth is: it is you, ");
      ans.print();
   }
   system("pause");
   return(0);
}
void add(int x,int y,int v)
{
   a[++sum][0]=x,a[sum][1]=v,a[sum][2]=b[y],b[y]=sum;
   a[++sum][0]=y,a[sum][1]=v,a[sum][2]=b[x],b[x]=sum;
}
bool check(int n)
{
   int l,r,q[3001];
   bool f[3001]={0};
   l=r=q[1]=1,f[1]=true;
   while (l<=r)
   {
      int x=q[l];
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (f[y])
            continue;
         f[y]=true;
         q[++r]=y;
      }
      l++;
   }
   for (int i=1;i<=n;i++)
      if (!f[i])
         return(false);
   return(true);
}
int spfa(int start,int n)
{
   int l,r,q[3001],d[3001];
   bool f[3001]={0};
   memset(d,26,sizeof(d));
   l=0,r=1,q[1]=start,d[start]=0,f[start]=true;
   while (l!=r)
   {
      l=l==n?1:l+1;
      int x=q[l];
      f[x]=false;
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (d[x]+a[i][1]<d[y])
         {
            d[y]=d[x]+a[i][1];
            if (!f[y])
            {
               f[y]=true;
               r=r==n?1:r+1;
               q[r]=y;
               int k=l==n?1:l+1;
               if (d[q[r]]<d[q[k]])
               {
                  int t;
                  t=q[r],q[r]=q[k],q[k]=t;
               }
            }
         }
      }
   }
   int ans=0;
   for (int i=1;i<=n;i++)
      ans+=d[i];
   return(ans);
}
