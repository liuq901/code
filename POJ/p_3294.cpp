#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,min,a[101000],sa[101000],rank[101000],height[101000];
int b[101000],c[101000],x[101000],f[101000],p[101000];
int main()
{
   void build(),work(int);
   int t,l,i,j,m;
   char s[1010];
   t=0;
   while (1)
   {
      scanf("%d",&m);
      if (m==0)
         break;
      t++;
      if (t>1)
         printf("\n");
      n=0;
      min=20000000;
      for (i=1;i<=m;i++)
      {
         scanf("%s",s);
         l=strlen(s);
         if (l<min)
            min=l;
         for (j=0;j<l;j++)
         {
            n++;
            a[n]=s[j]+126;
            p[n]=i;
         }
         n++;
         a[n]=i;
         p[n]=0;
      }
      a[n]=-1;
      n--;
      build();
      work(m/2);
   }
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
   k=1;
   while (count(b,c)<n)
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
      while (a[p+k]==a[q+k])
         k++;
      height[rank[i]]=k;
   }
   height[n+1]=-1;
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
      if (a[sa[i]]!=a[sa[i-1]] || b[sa[i]]!=b[sa[i-1]])
         t++;
      rank[sa[i]]=t;
   }
   return(t);
}
void work(int k)
{
   int find(int,int);
   void print(int,int);
   int l,r,ans,mid;
   l=1;
   ans=0;
   r=min;
   while (l<=r)
   {
      mid=(l+r)/2;
      if (find(mid,k))
      {
         ans=mid;
         l=mid+1;
      }
      else
         r=mid-1;
   }
   if (ans==0)
      printf("?\n");
   else
      print(ans,k);
}
int find(int t,int k)
{
   int i,sum;
   int f[110];
   sum=0;
   for (i=1;i<=n+1;i++)
   {
      if (height[i]<t)
      {
         if (sum>k)
            return(1);
         memset(f,0,sizeof(f));
         f[p[sa[i]]]=1;
         sum=1;
         continue;
      }
      if (!f[p[sa[i]]])
      {
         f[p[sa[i]]]=1;
         sum++;
      }
   }
   return(0);
}
void print(int ans,int k)
{
   int i,j,sum;
   int f[110];
   sum=0;
   for (i=1;i<=n+1;i++)
   {
      if (height[i]<ans)
      {
         if (sum>k)
         {
            for (j=1;j<=ans;j++)
               printf("%c",a[sa[i-1]+j-1]-126);
            printf("\n");
         }
         memset(f,0,sizeof(f));
         f[p[sa[i]]]=1;
         sum=1;
         continue;
      }
      if (!f[p[sa[i]]])
      {
         f[p[sa[i]]]=1;
         sum++;
      }
   }
}
