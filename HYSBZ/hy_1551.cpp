#include <cstdio>
#include <cstdlib>
#include <cstring>
int ans[100001],x[200001],y[200001],f[200001],g[200001];
int p[400001],q[400001],d[400001],u[400001],v[100001][5];
int main()
{
   void sortx(int,int),sorty(int,int),min(int,int,int);
   int i,j,n,m,x0,y0,l,r,lef,rig,mid;
   scanf("%d%d%d%d",&n,&m,&q[1],&p[1]);
   for (i=1;i<=n+m;i++)
   {
      scanf("%d%d",&x[i],&y[i]);
      f[i]=g[i]=i;
   }
   memset(ans,26,sizeof(ans));
   memset(u,0,sizeof(u));
   memset(v,0,sizeof(v));
   sortx(1,n+m);
   f[0]=0;
   sorty(1,n+m);
   g[0]=0;
   l=0;
   r=1;
   while (l<r)
   {
      l++;
      x0=q[l];
      y0=p[l];
      if (l==1 || u[l])
      {
         lef=1;
         rig=n+m;
         while (lef<rig)
         {
            mid=(lef+rig+1)/2;
            if (y[g[mid]]<y0 || (y[g[mid]]==y0 && x[g[mid]]<x0))
               lef=mid;
            else
               rig=mid-1;
         }
         if (y[g[lef]]==y0)
         {
            i=lef;
            while (g[i]>n && y[g[i]]==y0)
               i--;
            if (g[i]<=n && y[g[i]]==y0 && !v[g[i]][4])
            {
               r++;
               v[g[i]][4]=1;
               d[r]=d[l]+1;
               q[r]=x[g[i]]+1;
               p[r]=y0;
            }
            for (j=i+1;j<=lef;j++)
            {
               min(g[j],d[l]+1,n);
               g[j]=g[i];
            }
         }
         rig=lef+1;
         if (y[g[rig]]==y0)
         {
            i=rig;
            while (g[i]>n && y[g[i]]==y0)
               i++;
            if (g[i]<=n && y[g[i]]==y0 && !v[g[i]][2])
            {
               r++;
               v[g[i]][2]=1;
               d[r]=d[l]+1;
               q[r]=x[g[i]]-1;
               p[r]=y0;
            }
            for (j=rig;j<=i-1;j++)
            {
               min(g[j],d[l]+1,n);
               g[j]=g[i];
            }
         }
      }
      if (l==1 || !u[l])
      {
         lef=1;
         rig=n+m;
         while (lef<rig)
         {
            mid=(lef+rig+1)/2;
            if (x[f[mid]]<x0 || (x[f[mid]]==x0 && y[f[mid]]<y0))
               lef=mid;
            else
               rig=mid-1;
         }
         if (x[f[lef]]==x0)
         {
            i=lef;
            while (f[i]>n && x[f[i]]==x0)
               i--;
            if (f[i]<=n && x[f[i]]==x0 && !v[f[i]][3])
            {
               r++;
               v[f[i]][3]=1;
               d[r]=d[l]+1;
               u[r]=1;
               q[r]=x0;
               p[r]=y[f[i]]+1;
            }
            for (j=i+1;j<=lef;j++)
            {
               min(f[j],d[l]+1,n);
               f[j]=f[i];
            }
         }
         rig=lef+1;
         if (x[f[rig]]==x0)
         {
            i=rig;
            while (f[i]>n && x[f[i]]==x0)
               i++;
            if (f[i]<=n && x[f[i]]==x0 && !v[f[i]][1])
            {
               r++;
               v[f[i]][1]=1;
               d[r]=d[l]+1;
               u[r]=1;
               q[r]=x0;
               p[r]=y[f[i]]-1;
            }
            for (j=rig;j<=i-1;j++)
            {
               min(f[j],d[l]+1,n);
               f[j]=f[i];
            }
         }
      }
   }
   for (i=1;i<=m;i++)
      if (ans[i]>20000000)
         ans[i]=-1;
   for (i=1;i<=m-1;i++)
      printf("%d ",ans[i]);
   printf("%d\n",ans[m]);
   system("pause");
   return(0);
}
void sortx(int l,int r)
{
   int i,j,k,k1,k2,t;
   i=l;
   j=r;
   k=f[(l+r)/2];
   k1=x[k];
   k2=y[k];
   while (i<=j)
   {
      while (x[f[i]]<k1 || (x[f[i]]==k1 && y[f[i]]<k2))
         i++;
      while (x[f[j]]>k1 || (x[f[j]]==k1 && y[f[j]]>k2))
         j--;
      if (i<=j)
      {
         t=f[i],f[i]=f[j],f[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sortx(i,r);
   if (l<j)
      sortx(l,j);
}
void sorty(int l,int r)
{
   int i,j,k,k1,k2,t;
   i=l;
   j=r;
   k=g[(l+r)/2];
   k1=y[k];
   k2=x[k];
   while (i<=j)
   {
      while (y[g[i]]<k1 || (y[g[i]]==k1 && x[g[i]]<k2))
         i++;
      while (y[g[j]]>k1 || (y[g[j]]==k1 && x[g[j]]>k2))
         j--;
      if (i<=j)
      {
         t=g[i],g[i]=g[j],g[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sorty(i,r);
   if (l<j)
      sorty(l,j);
}
void min(int x,int y,int n)
{
   if (y<ans[x-n])
      ans[x-n]=y;
}
