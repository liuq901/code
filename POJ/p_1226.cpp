#include <cstdio>
#include <cstdlib>
#include <cstring>
int tot,a[20010],sa[20010],rank[20010],height[20010],f[20010];
int main()
{
   void init();
   bool check(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,min=1<<30;
      tot=0;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         char s[110];
         scanf("%s",s);
         int l=strlen(s);
         for (int j=0;j<l;j++)
         {
            a[++tot]=s[j];
            f[tot]=i;
         }
         a[++tot]=i+300;
         f[tot]=0;
         for (int j=l-1;j>=0;j--)
         {
            a[++tot]=s[j];
            f[tot]=i;
         }
         a[++tot]=i+300;
         f[tot]=0;
         if (l<min)
            min=l;
      }
      init();
      int l=0,r=min,ans;
      while (l<=r)
      {
         int mid=l+r>>1;
         if (check(mid,n))
         {
            l=mid+1;
            ans=mid;
         }
         else
            r=mid-1;
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void init()
{
   void sort(int *);
   int count(int *,int *);
   int b[20010],c[20010];
   for (int i=1;i<=tot;i++)
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
      for (int i=1;i<=tot;i++)
      {
         c[i]=rank[i];
         if (i+k<=tot)
            b[i]=rank[i+k];
         else
            b[i]=0;
      }
      sort(b);
      sort(c);
      if (count(c,b)>=tot)
         break;
      k<<=1;
   }
   k=0;
   for (int i=1;i<=tot;i++)
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
void sort(int *a)
{
   int f[20010],x[20010],t=0;
   memset(f,0,sizeof(f));
   for (int i=1;i<=tot;i++)
   {
      f[a[i]]++;
      if (a[i]>t)
         t=a[i];
   }
   for (int i=1;i<=t;i++)
      f[i]+=f[i-1];
   for (int i=tot;i>=1;i--)
   {
      x[f[a[sa[i]]]]=sa[i];
      f[a[sa[i]]]--;
   }
   for (int i=1;i<=tot;i++)
      sa[i]=x[i];
}
int count(int *a,int *b)
{
   rank[sa[1]]=1;
   int t=1;
   for (int i=2;i<=tot;i++)
   {
      if (a[sa[i]]!=a[sa[i-1]] || b[sa[i]]!=b[sa[i-1]])
         t++;
      rank[sa[i]]=t;
   }
   return(t);
}
bool check(int x,int n)
{
   int sum=0;
   bool flag[101]={0};
   for (int i=1;i<=tot;i++)
   {
      if (height[i]<x)
      {
         memset(flag,0,sizeof(flag));
         sum=0;
         continue;
      }
      if (f[sa[i]] && !flag[f[sa[i]]])
      {
         flag[f[sa[i]]]=true;
         sum++;
      }
      if (f[sa[i-1]] && !flag[f[sa[i-1]]])
      {
         flag[f[sa[i-1]]]=true;
         sum++;
      }
      if (sum>=n)
         return(true);
   }
   return(false);
}
