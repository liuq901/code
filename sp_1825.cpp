#include <cstdio>
#include <cstdlib>
#include <cstring>
int ans,min,p,k,d[200001],f[200001],s[200001],q[200001][3];
int c[200001],b[200001],g[200001],a[400000][4];
int main()
{
   void search(int,int);
   int i,n,m,x,y,z;
   scanf("%d%d%d",&n,&k,&m);
   memset(f,0,sizeof(f));
   for (i=1;i<=m;i++)
   {
      scanf("%d",&x);
      f[x]=1;
   }
   memset(b,0,sizeof(b));
   for (i=1;i<=n-1;i++)
   {
      scanf("%d%d%d",&x,&y,&z);
      a[2*i-1][0]=y;
      a[2*i-1][1]=z;
      a[2*i-1][2]=b[x];
      a[2*i-1][3]=1;
      b[x]=2*i-1;
      a[2*i][0]=x;
      a[2*i][1]=z;
      a[2*i][2]=b[y];
      a[2*i][3]=1;
      b[y]=2*i;
   }
   ans=0;
   search(1,n);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void search(int x,int sum)
{
   int count(int,int),calc(int);
   void sort(int,int),work(int,int);
   int i,t;
   if (sum==1)
      return;
   min=1000000000;
   count(x,sum);
   i=b[p];
   calc(p);
   t=0;
   i=b[p];
   while (i!=0)
   {
      if (!a[i][3])
      {
         i=a[i][2];
         continue;
      }
      t++;
      q[t][0]=d[a[i][0]];
      q[t][1]=a[i][0];
      q[t][2]=a[i][1];
      i=a[i][2];
   }
   sort(1,t);
   work(p,t);
   i=b[p];
   count(p,sum);
   while (i!=0)
   {
      if (!a[i][3])
      {
         i=a[i][2];
         continue;
      }
      if (i%2==1)
         a[i+1][3]=0;
      else
         a[i-1][3]=0;
      search(a[i][0],s[a[i][0]]);
      i=a[i][2];
   }
}
int count(int x,int sum)
{
   int i,t,max;
   i=b[x];
   s[x]=1;
   max=-1000000000;
   while (i!=0)
   {
      if (!a[i][3])
      {
         i=a[i][2];
         continue;
      }
      if (i%2==1)
         a[i+1][3]=0;
      else
         a[i-1][3]=0;
      t=count(a[i][0],sum);
      if (i%2==1)
         a[i+1][3]=1;
      else
         a[i-1][3]=1;
      if (t>max)
         max=t;
      s[x]+=t;
      i=a[i][2];
   }
   if (sum-s[x]>max)
      max=sum-s[x];
   if (max<min)
   {
      min=max;
      p=x;
   }
   return(s[x]);
}
int calc(int x)
{
   int i,t,max;
   i=b[x];
   d[x]=f[x];
   max=0;
   while (i!=0)
   {
      if (!a[i][3])
      {
         i=a[i][2];
         continue;
      }
      if (i%2==1)
         a[i+1][3]=0;
      else
         a[i-1][3]=0;
      t=calc(a[i][0]);
      if (i%2==1)
         a[i+1][3]=1;
      else
         a[i-1][3]=1;
      if (t>max)
         max=t;
      i=a[i][2];
   }
   d[x]+=max;
   return(d[x]);
}
void sort(int l,int r)
{
   int i,j,x,t;
   i=l;
   j=r;
   x=q[(l+r)/2][0];
   while (i<=j)
   {
      while (q[i][0]<x)
         i++;
      while (q[j][0]>x)
         j--;
      if (i<=j)
      {
         t=q[i][0],q[i][0]=q[j][0],q[j][0]=t;
         t=q[i][1],q[i][1]=q[j][1],q[j][1]=t;
         t=q[i][2],q[i][2]=q[j][2],q[j][2]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
void work(int x,int sum)
{
   void find(int,int,int,int);
   int i,j,t,max,p,y;
   if (f[x])
      k--;
   c[0]=y=p=0;
   max=-1000000000;
   for (i=1;i<=sum;i++)
   {
      for (j=0;j<=q[i][0];j++)
         g[j]=-1000000000;
      find(x,q[i][1],0,q[i][2]);
      for (j=0;j<=q[i][0];j++)
      {
         if (j>k)
            break;
         if (k-j>y)
            t=c[p];
         else
            t=c[k-j];
         if (g[j]+t>ans)
            ans=g[j]+t;
      }
      for (j=0;j<=q[i][0];j++)
      {
         if (j>k)
            break;
         if (j>y)
            c[j]=g[j];
         if (g[j]>c[j])
            c[j]=g[j];
         if (j>0 && c[j-1]>c[j])
            c[j]=c[j-1];
         if (c[j]>max)
         {
            max=c[j];
            p=j;
         }
      }
      y=q[i][0];
   }
   if (f[x])
      k++;
}
void find(int root,int x,int t,int l)
{
   int i;
   if (t>k)
      return;
   i=b[x];
   while (i!=0)
   {
      if (!a[i][3] || root==a[i][0])
      {
         i=a[i][2];
         continue;
      }
      if (i%2==1)
         a[i+1][3]=0;
      else
         a[i-1][3]=0;
      find(root,a[i][0],t+f[x],l+a[i][1]);
      if (i%2==1)
         a[i+1][3]=1;
      else
         a[i-1][3]=1;
      i=a[i][2];
   }
   if (l>g[t+f[x]])
      g[t+f[x]]=l;
}
