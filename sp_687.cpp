#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
int n,a[50010],sa[50010],rank[50010],height[50010],f[16][50010];
int main()
{
   void work();
   int t,i;
   scanf("%d",&t);
   for (i=1;i<=t;i++)
      work();
   system("pause");
   return(0);
}
void work()
{
   void build();
   int find(int);
   int i,t,ans;
   char ch;
   scanf("%d%*c",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%c%*c",&ch);
      if (ch=='a')
         a[i]=1;
      else
         a[i]=2;
   }
   a[n+1]=-1;
   build();
   ans=1;
   for (i=1;i<=n/2;i++)
   {
      t=find(i);
      if (t>ans)
         ans=t;
   }
   printf("%d\n",ans);
}
void build()
{
   void sort(int *);
   int count(int *,int *);
   int i,j,t,k,p,q;
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
   memset(f,0,sizeof(f));
   for (i=1;i<=n;i++)
      f[0][i]=height[i];
   t=(int)(log(n)/log(2));
   k=1;
   for (i=1;i<=t;i++)
   {
      k*=2;
      for (j=1;j<=n;j++)
      {
         if (j+k-1>n)
            continue;
         if (f[i-1][j]>f[i-1][j+k/2])
            f[i][j]=f[i-1][j+k/2];
         else
            f[i][j]=f[i-1][j];
      }
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
   for (i=1;i<=n;i++)
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
      if (a[sa[i-1]]!=a[sa[i]] || b[sa[i-1]]!=b[sa[i]])
         t++;
      rank[sa[i]]=t;
   }
   return(t);
}
int find(int l)
{
   int calc(int,int);
   int i,x,p,q,sum;
   i=1;
   sum=0;
   while (1)
   {
      if (i+l>n)
         break;
      p=calc(i,i+l);
      x=p%l;
      if (x!=0)
      {
         x=l-x;
         q=calc(i-x,i+l-x);
         if (q>x)
            p+=x;
      }
      if (p/l+1>sum)
         sum=p/l+1;
      i+=l;
   }
   return(sum);
}
int calc(int x,int y)
{
   int min(int,int);
   int p,q,t,k;
   p=rank[x];
   q=rank[y];
   if (p>q)
      t=p,p=q,q=t;
   p++;
   t=q-p+1;
   k=(int)(log(t)/log(2));
   return(min(f[k][p],f[k][q-(1<<k)+1]));
}
int min(int x,int y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
