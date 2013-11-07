#include <cstdio>
#include <cstdlib>
#include <cctype>
typedef long long ll;
int root,l[1000001],r[1000001],d[1000001];
ll a[1000002],b[1000002],v[1000001];
int main()
{
   void read(ll &),insert(int,ll),del();
   ll get();
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      read(a[i]);
      a[i]-=i;
   }
   insert(1,a[1]);
   int k=1;
   a[n+1]=1LL<<60;
   for (int i=2;i<=n+1;i++)
   {
      ll x=get();
      if (x<=a[i])
      {
         for (int j=k;j<=i-1;j++)
            b[j]=x;
         insert(i,a[i]);
         k=i;
      }
      else
      {
         insert(i,a[i]);
         if (i-k&1)
            del();
      }
   }
   ll ans=0;
   for (int i=1;i<=n;i++)
      ans+=abs(a[i]-b[i]);
   printf("%I64d\n",ans);
   system("pause");
   return(0);
}
void read(ll &x)
{
   char ch=' ';
   while (!isdigit(ch))
      ch=getchar();
   x=ch-'0';
   while (1)
   {
      ch=getchar();
      if (!isdigit(ch))
         return;
      x=x*10+ch-'0';
   }
}
void insert(int x,ll value)
{
   int merge(int,int);
   v[x]=value;
   l[x]=r[x]=d[x]=0;
   if (root)
      root=merge(root,x);
   else
      root=x;
}
void del()
{
   int merge(int,int);
   root=merge(l[root],r[root]);
}
int merge(int x,int y)
{
   if (!x)
      return(y);
   if (!y)
      return(x);
   if (v[x]<v[y])
   {
      int t;
      t=x,x=y,y=t;
   }
   r[x]=merge(r[x],y);
   if (d[l[x]]<d[r[x]])
   {
      int t;
      t=l[x],l[x]=r[x],r[x]=t;
   }
   if (!r[x])
      d[x]=0;
   else
      d[x]=d[r[x]]+1;
   return(x);
}
ll get()
{
   return(v[root]);
}
