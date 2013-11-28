#include <cstdio>
#include <cstdlib>
int n,k,a[20010],sa[20010],rank[20010],height[20010],f[1000001];
int main()
{
   void build();
   int find(int);
   int i,l,r,mid,ans;
   scanf("%d%d",&n,&k);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   a[n+1]=-1;
   build();
   l=1;
   r=n;
   while (l<=r)
   {
      mid=(l+r)/2;
      if (find(mid))
      {
         ans=mid;
         l=mid+1;
      }
      else
         r=mid-1;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void build()
{
   void sort(int *);
   int count(int *,int *);
   int i,k,p,q;
   int b[20010],c[20010];
   b[0]=0;
   for (i=1;i<=n;i++)
   {
      b[i]=a[i];
      if (b[i]>b[0])
         b[0]=b[i];
      c[i]=-1;
      sa[i]=i;
   }
   c[0]=-1;
   sort(b);
   count(b,c);
   k=1;
   while (1)
   {
      b[0]=c[0]=0;
      for (i=1;i<=n;i++)
      {
         c[i]=rank[i];
         if (c[i]>c[0])
            c[0]=c[i];
         if (i+k<=n)
            b[i]=rank[i+k];
         else
            b[i]=0;
         if (b[i]>b[0])
            b[0]=b[i];
      }
      sort(b);
      sort(c);
      if (count(b,c)>=n)
         break;
      k*=2;
   }
   k=0;
   for (i=1;i<=n;i++)
   {
      if (k>0)
         k--;
      if (rank[i]==1)
      {
         height[rank[i]]=0;
         continue;
      }
      p=sa[rank[i]-1];
      q=sa[rank[i]];
      while (1)
      {
         if (a[p+k]!=a[q+k])
            break;
         k++;
      }
      height[rank[i]]=k;
   }
   height[n+1]=-1;
}
void sort(int *a)
{
   int i;
   int x[20010];
   for (i=1;i<=a[0];i++)
      f[i]=0;
   for (i=1;i<=n;i++)
      f[a[i]]++;
   for (i=1;i<=a[0];i++)
      f[i]+=f[i-1];
   for (i=n;i>=1;i--)
   {
      x[f[a[sa[i]]]]=sa[i];
      f[a[sa[i]]]--;
   }
   for (i=1;i<=n;i++)
      sa[i]=x[i];
}
int count(int *a,int *b)
{
   int i,t;
   rank[sa[1]]=t=1;
   for (i=2;i<=n;i++)
   {
      if (a[sa[i-1]]!=a[sa[i]] || b[sa[i-1]]!=b[sa[i]])
         t++;
      rank[sa[i]]=t;
   }
   return(t);
}
int find(int t)
{
   int i,p;
   p=0;
   for (i=1;i<=n+1;i++)
   {
      if (height[i]>=t)
      {
         p++;
         continue;
      }
      if (p>=k)
         return(1);
      p=1;
   }
   return(0);
}
