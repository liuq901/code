#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,a[200010],sa[200010],rank[200010],height[200010];
int x[200010],f[200010],b[200010],c[200010];
char s[100010];
int main()
{
   void build();
   int l,i,m,ans;
   scanf("%s",s);
   l=strlen(s);
   n=l;
   for (i=1;i<=l;i++)
      a[i]=s[i-1];
   a[n+1]=0;
   m=l;
   scanf("%s",s);
   l=strlen(s);
   n++;
   for (i=1;i<=l;i++)
      a[n+i]=s[i-1];
   n+=l;
   a[n+1]=-1;
   build();
   ans=0;
   for (i=3;i<=n;i++)
      if ((sa[i]<=m && sa[i-1]>m || sa[i]>m && sa[i-1]<=m) && height[i]>ans)
         ans=height[i];
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void build()
{
   void sort(int *);
   int count(int *,int *);
   int i,k,p,q;
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
         c[i]=rank[i];
         if (i+k<=n)
            b[i]=rank[i+k];
         else
            b[i]=0;
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
         height[rank[i]]=0;
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
   t=0;
   for (i=1;i<=n;i++)
      if (a[i]>t)
         t=a[i];
   for (i=0;i<=t;i++)
      f[i]=0;
   for (i=1;i<=n;i++)
      f[a[i]]++;
   for (i=1;i<=t;i++)
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
