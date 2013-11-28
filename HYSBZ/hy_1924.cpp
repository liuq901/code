#include <cstdio>
#include <cstdlib>
int p[100001],f[100001],b[100001],x[100001],y[100001],z[100001],a[5000000][2];
int dfn[100001],pos[100001],link[100001],c[5000001][2];
int main()
{
   void sort(int,int,int *,int *),tarjan(int),floodfill(int);
   int n;
   scanf("%d%*d%*d",&n);
   for (int i=1;i<=n;i++)
   {
      scanf("%d%d%d",&y[i],&x[i],&z[i]);
      p[i]=i;
   }
   int tot=0;
   sort(1,n,x,y);
   for (int i=1;i<=n;i++)
   {
      if (z[i]==1)
         continue;
      if (z[i]==3)
      {
         if (i!=1 && x[i-1]==x[i] && y[i-1]+1==y[i])
         {
            a[++tot][0]=p[i-1];
            a[tot][1]=b[p[i]];
            b[p[i]]=tot;
         }
         if (i!=n && x[i+1]==x[i] && y[i+1]-1==y[i])
         {
            a[++tot][0]=p[i+1];
            a[tot][1]=b[p[i]];
            b[p[i]]=tot;
         }
      }
      if (z[i]==2)
      {
         for (int j=i+1;j<=n;j++)
         {
            if (x[i]!=x[j])
               break;
            a[++tot][0]=p[j];
            a[tot][1]=b[p[i]];
            b[p[i]]=tot;
         }
         for (int j=i-1;j>=1;j--)
         {
            if (x[j]!=x[i])
               break;
            a[++tot][0]=p[j];
            a[tot][1]=b[p[i]];
            b[p[i]]=tot;
         }
      }
   }
   sort(1,n,y,x);
   for (int i=1;i<=n;i++)
   {
      if (z[i]==2)
         continue;
      if (z[i]==3)
      {
         if (i!=1 && y[i-1]==y[i] && x[i-1]+1==x[i])
         {
            a[++tot][0]=p[i-1];
            a[tot][1]=b[p[i]];
            b[p[i]]=tot;
         }
         if (i!=n && y[i+1]==y[i] && x[i+1]-1==x[i])
         {
            a[++tot][0]=p[i+1];
            a[tot][1]=b[p[i]];
            b[p[i]]=tot;
         }
      }
      if (z[i]==1)
      {
         for (int j=i+1;j<=n;j++)
         {
            if (y[i]!=y[j])
               break;
            a[++tot][0]=p[j];
            a[tot][1]=b[p[i]];
            b[p[i]]=tot;
         }
         for (int j=i-1;j>=1;j--)
         {
            if (y[j]!=y[i])
               break;
            a[++tot][0]=p[j];
            a[tot][1]=b[p[i]];
            b[p[i]]=tot;
         }
      }
   }
   for (int i=1;i<=n;i++)
   {
      int p=x[i]-y[i],q=x[i]+y[i];
      x[i]=p,y[i]=q;
   }
   sort(1,n,x,y);
   for (int i=1;i<=n;i++)
   {
      if (z[i]==1 || z[i]==2)
         continue;
      if (i!=1 && x[i-1]==x[i] && y[i-1]+2==y[i])
      {
         a[++tot][0]=p[i-1];
         a[tot][1]=b[p[i]];
         b[p[i]]=tot;
      }
      if (i!=n && x[i+1]==x[i] && y[i+1]-2==y[i])
      {
         a[++tot][0]=p[i+1];
         a[tot][1]=b[p[i]];
         b[p[i]]=tot;
      }
   }
   sort(1,n,y,x);
   for (int i=1;i<=n;i++)
   {
      if (z[i]==1 || z[i]==2)
         continue;
      if (i!=1 && y[i-1]==y[i] && x[i-1]+2==x[i])
      {
         a[++tot][0]=p[i-1];
         a[tot][1]=b[p[i]];
         b[p[i]]=tot;
      }
      if (i!=n && y[i+1]==y[i] && x[i+1]-2==x[i])
      {
         a[++tot][0]=p[i+1];
         a[tot][1]=b[p[i]];
         b[p[i]]=tot;
      }
   }
   for (int i=1;i<=n;i++)
      if (!dfn[i])
         tarjan(i);
   tot=0;
   for (int i=1;i<=n;i++)
      for (int j=b[i];j;j=a[j][1])
      {
         int x=pos[i],y=pos[a[j][0]];
         if (x==y)
            continue;
         c[++tot][0]=y;
         c[tot][1]=link[x];
         link[x]=tot;
      }
   for (int i=1;i<=n;i++)
      floodfill(i);
   int ans=0;
   for (int i=1;i<=pos[0];i++)
      if (f[i]>ans)
         ans=f[i];
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void sort(int l,int r,int *a,int *b)
{
   void swap(int &,int &);
   int i,j,x,y,t;
   i=l,j=r;
   x=a[l+r>>1];
   y=b[l+r>>1];
   while (i<=j)
   {
      while (a[i]<x || a[i]==x && b[i]<y)
         i++;
      while (a[j]>x || a[j]==x && b[j]>y)
         j--;
      if (i<=j)
      {
         swap(a[i],a[j]);
         swap(b[i],b[j]);
         swap(p[i],p[j]);
         swap(z[i],z[j]);
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r,a,b);
   if (l<j)
      sort(l,j,a,b);
}
void swap(int &x,int &y)
{
   int t;
   t=x,x=y,y=t;
}
int id,low[100001],sum[100001],stack[100001];
bool flag[100001];
void tarjan(int x)
{
   dfn[x]=low[x]=++id;
   flag[x]=true;
   stack[++stack[0]]=x;
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (!dfn[y])
      {
         tarjan(y);
         if (low[y]<low[x])
            low[x]=low[y];
      }
      else if (flag[y] && dfn[y]<low[x])
         low[x]=dfn[y];
   }
   if (low[x]==dfn[x])
   {
      pos[0]++;
      while (stack[stack[0]]!=x)
      {
         pos[stack[stack[0]]]=pos[0];
         flag[stack[stack[0]]]=false;
         stack[0]--;
         sum[pos[0]]++;
      }
      flag[x]=false;
      pos[x]=pos[0];
      sum[pos[0]]++;
      stack[0]--;
   }
}
void floodfill(int x)
{
   f[x]=sum[x];
   int max=0;
   for (int i=link[x];i;i=c[i][1])
   {
      int y=c[i][0];
      if (!f[y])
         floodfill(y);
      if (f[y]>max)
         max=f[y];
   }
   f[x]+=max;
}
