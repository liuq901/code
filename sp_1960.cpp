#include <cstdio>
#include <cstdlib>
#include <cstring>
const int m=500;
int x0,y0,x[250001],y[250001],s[250001],l[250001],r[250001];
int a[250001],b[250001],p[250001],q[250001],g[250001];
bool f[250001];
int main()
{
   void init(int),sort(int,int,int *,int *);
   long long count(int);
   int n;
   long long ans=0;
   scanf("%d",&n);
   init(n);
   sort(1,n,y,x);
   memset(l,26,sizeof(l));
   for (int i=1;i<=n;i++)
   {
      s[y[i]]++;
      l[y[i]]<?=i;
      r[y[i]]>?=i;
   }
   for (int i=1;i<=y0;i++)
   {
      if (s[i]<=m)
         continue;
      for (int j=l[i];j<=r[i];j++)
         f[x[j]]=true;
      for (int j=1;j<=y0;j++)
      {
         if (i==j || j<i && s[i]>m)
            continue;
         int sum=0;
         for (int k=l[j];k<=r[j];k++)
            if (f[x[k]])
               sum++;
         ans+=count(sum);
      }
      for (int j=l[i];j<=r[i];j++)
         f[x[j]]=false;
   }
   int t=0;
   for (int i=1;i<=y0;i++)
   {
      if (s[i]>m)
         continue;
      for (int j=l[i];j<=r[i];j++)
      {
         a[++t]=x[j];
         p[t]=j;
      }
   }
   sort(1,t,a,p);
   int k=0,tot=0;
   for (int i=1;i<=t;i++)
      if (k!=a[i])
      {
         tot++;
         b[tot]=i;
         k=a[i];
      }
   memset(s,0,sizeof(s));
   memset(q,0,sizeof(q));
   memset(a,0,sizeof(a));
   for (int i=1;i<=tot-1;i++)
   {
      int s0=0;
      for (int j=b[i];j<=b[i+1]-1;j++)
         for (int k=p[j]+1;k<=r[y[p[j]]];k++)
         {
            int t=x[k];
            if (!q[t])
            {
               q[t]=++s0;
               a[s0]=t;
            }
            s[q[t]]++;
         }
      for (int i=1;i<=s0;i++)
      {
         ans+=count(s[i]);
         s[i]=0;
         q[a[i]]=0;
         a[i]=0;
      }
   }
   printf("%lld\n",ans);
   system("pause");
   return(0);
}
void init(int n)
{
   void sort(int,int,int *,int *);
   for (int i=1;i<=n;i++)
   {
      scanf("%d%d",&a[i],&b[i]);
      p[i]=q[i]=i;
   }
   sort(1,n,a,p);
   sort(1,n,b,q);
   int t1,t2;
   x0=y0=1;
   x[p[1]]=y[q[1]]=1;
   t1=a[1],t2=b[1];
   for (int i=2;i<=n;i++)
   {
      if (a[i]!=t1)
      {
         t1=a[i];
         x0++;
      }
      if (b[i]!=t2)
      {
         t2=b[i];
         y0++;
      }
      x[p[i]]=x0;
      y[q[i]]=y0;
   }
}
void sort(int l,int r,int *y,int *x)
{
   int i,j,p,q,t;
   i=l;
   j=r;
   p=x[l+r>>1];
   q=y[l+r>>1];
   while (i<=j)
   {
      while (y[i]<q || y[i]==q && x[i]<p)
         i++;
      while (y[j]>q || y[j]==q && x[j]>p)
         j--;
      if (i<=j)
      {
         t=x[i],x[i]=x[j],x[j]=t;
         t=y[i],y[i]=y[j],y[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r,y,x);
   if (l<j)
      sort(l,j,y,x);
}
long long count(int x)
{
   if (x<2)
      return(0);
   long long ans;
   ans=(long long)x*(x-1);
   return(ans/2);
}
