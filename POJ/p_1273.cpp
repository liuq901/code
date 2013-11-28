#include <cstdio>
#include <cstdlib>
#include <cstring>
int ans,b[201],d[201],a[401][4];
int main()
{
   bool build(int);
   int dinic(int,int,int);
   int n,m;
   while (scanf("%d%d",&m,&n)!=EOF)
   {
      memset(b,0,sizeof(b));
      for (int i=1;i<=m;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         a[2*i-1][0]=y;
         a[2*i-1][1]=z;
         a[2*i-1][2]=b[x];
         a[2*i-1][3]=2*i;
         b[x]=2*i-1;
         a[2*i][0]=x;
         a[2*i][1]=0;
         a[2*i][2]=b[y];
         a[2*i][3]=2*i-1;
         b[y]=2*i;
      }
      ans=0;
      while (build(n))
         ans+=dinic(1,20000000,n);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
bool build(int n)
{
   int l=1,r=1,q[201];
   bool f[201]={false};
   f[1]=true;
   q[1]=d[1]=1;
   while (l<=r)
   {
      int i=b[q[l]];
      while (i!=0)
      {
         if (a[i][1]>0 && !f[a[i][0]])
         {
            r++;
            q[r]=a[i][0];
            f[q[r]]=true;
            d[q[r]]=d[q[l]]+1;
            if (q[r]==n)
               return(true);
         }
         i=a[i][2];
      }
      l++;
   }
   return(false);
}
int dinic(int x,int flow,int n)
{
   int min(int,int);
   if (x==n)
      return(flow);
   int i=b[x],s=0,t=flow;
   while (i!=0)
   {
      if (d[x]+1==d[a[i][0]] && a[i][1]>0)
      {
         int k=dinic(a[i][0],min(t,a[i][1]),n);
         a[i][1]-=k;
         a[a[i][3]][1]+=k;
         s+=k;
         t-=k;
         if (t==0)
            return(flow);
      }
      i=a[i][2];
   }
   if (s==0)
      d[x]=-1;
   return(s);
}
int min(int x,int y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
