#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,a[50010],sa[50010],rank[50010],height[50010];
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
   void build();
   int i,ans;
   char s[50010];
   scanf("%s",s);
   n=strlen(s);
   for (i=0;i<n;i++)
      a[i+1]=s[i];
   a[n+1]=-1;
   build();
   ans=0;
   for (i=1;i<=n;i++)
      ans+=n-sa[i]-height[i]+1;
   printf("%d\n",ans);
}
void build()
{
   void sort(int *);
   int count(int *,int *);
   int i,k,p,q;
   int b[50010],c[50010];
   for (i=1;i<=n;i++)
   {
      b[i]=a[i];
      c[i]=-1;
      sa[i]=i;
   }
   sort(b);
   count(b,c);
   k=1;
   while (1)
   {
      for (i=1;i<=n;i++)
      {
         b[i]=rank[i];
         if (i+k<=n)
            c[i]=rank[i+k];
         else
            c[i]=0;
      }
      sort(c);
      sort(b);
      if (count(b,c)>=n)
         break;
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
}
void sort(int *a)
{
   int i,t;
   int f[50010],x[50010];
   memset(f,0,sizeof(f));
   t=0;
   for (i=1;i<=n;i++)
   {
      f[a[i]]++;
      if (a[i]>t)
         t=a[i];
   }
   for (i=1;i<=t;i++)
      f[i]+=f[i-1];
   for (i=n;i>=1;i--)
   {
      x[f[a[sa[i]]]]=sa[i];
      f[a[sa[i]]]--;
   }
   memcpy(sa,x,sizeof(x));
}
int count(int *a,int *b)
{
   int i,t;
   rank[sa[1]]=t=1;
   for (i=2;i<=n;i++)
   {
      if (a[sa[i]]!=a[sa[i-1]] || b[sa[i]]!=b[sa[i-1]])
         t++;
      rank[sa[i]]=t;
   }
   return(t);
}
