#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,a[110000],sa[110000],rank[110000],height[110000];
char s[51000],t[51000];
int main()
{
   void build();
   int check(int,int);
   scanf("%s%s",s,t);
   int l1=strlen(s),l2=strlen(t);
   n=l1+l2+1;
   for (int i=1;i<=l1;i++)
      a[i]=s[i-1]+10000;
   a[l1+1]=0;
   for (int i=1;i<=l2;i++)
      a[i+l1+1]=t[i-1]+10000;
   a[n+1]=-1;
   build();
   int l=0,r=n,ans=0;
   while (l<=r)
   {
      int mid=l+r>>1;
      if (check(mid,l1))
         l=mid+1,ans=mid;
      else
         r=mid-1;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int b[110000],c[110000];
void build()
{
   void sort(int *);
   int count(int *,int *);
   for (int i=1;i<=n;i++)
   {
      c[i]=a[i];
      b[i]=-1;
      sa[i]=i;
   }
   sort(c);
   count(c,b);
   int k=1;
   while (1)
   {
      for (int i=1;i<=n;i++)
      {
         c[i]=rank[i];
         b[i]=i+k<=n?rank[i+k]:0;
      }
      sort(b),sort(c);
      if (count(c,b)>=n)
         break;
      k<<=1;
   }
   k=0;
   for (int i=1;i<=n;i++)
   {
      k=k?k-1:0;
      if (rank[i]==1)
      {
         height[rank[i]]=0;
         continue;
      }
      int p=sa[rank[i]-1],q=sa[rank[i]];
      while (a[p+k]==a[q+k])
         k++;
      height[rank[i]]=k;
   }
}
int f[110000],x[110000];
void sort(int *a)
{
   memset(f,0,sizeof(f));
   int t=0;
   for (int i=1;i<=n;i++)
   {
      f[a[i]]++;
      if (a[i]>t)
         t=a[i];
   }
   for (int i=1;i<=t;i++)
      f[i]+=f[i-1];
   for (int i=n;i;i--)
   {
      x[f[a[sa[i]]]]=sa[i];
      f[a[sa[i]]]--;
   }
   for (int i=1;i<=n;i++)
      sa[i]=x[i];
}
int count(int *a,int *b)
{
   rank[sa[1]]=1;
   int t=1;
   for (int i=2;i<=n;i++)
   {
      if (a[sa[i]]!=a[sa[i-1]] || b[sa[i]]!=b[sa[i-1]])
         t++;
      rank[sa[i]]=t;
   }
   return(t);
}
bool check(int x,int m)
{
   int sum0=0,sum1=0;
   for (int i=1;i<=n;i++)
   {
      if (height[i]<x)
      {
         if (sum0 && sum1)
            return(true);
         sum0=sum1=0;
      }
      sum0+=sa[i]<=m;
      sum1+=sa[i]>=m+2;
   }
   return(sum0 && sum1);
}
