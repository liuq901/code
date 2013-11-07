#include <cstdio>
#include <cstdlib>
#include <cstring>
int s,t,b[100001],a[200001][4];
int main()
{
   bool build();
   int dinic(int,int);
   int n,m,p;
   scanf("%d%d%d",&n,&m,&p);
   int sum=0,c[201][201]={0};
   for (int i=1;i<=p;i++)
   {
      int x1,y1,x2,y2,v;
      scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
      if (!c[x1][y1])
         c[x1][y1]=++sum;
      if (!c[x2][y2])
         c[x2][y2]=++sum;
      int x=c[x1][y1],y=c[x2][y2];
      a[i][0]=y;
      a[i][1]=v;
      a[i][2]=b[x];
      a[i][3]=i+p;
      b[x]=i;
      a[i+p][0]=x;
      a[i+p][1]=v;
      a[i+p][2]=b[y];
      a[i+p][3]=i;
      b[y]=i+p;
   }
   if (!c[1][1] || !c[n][m])
      printf("0\n");
   else
   {
      s=c[1][1];
      t=c[n][m];
      int ans=0;
      while (build())
         ans+=dinic(s,1000000000);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
int d[100001],q[100001];
bool f[100001];
bool build()
{
   int l=1,r=1;
   memset(f,0,sizeof(f));
   f[s]=true;
   q[1]=s;
   d[s]=1;
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
            if (q[r]==t)
               return(true);
         }
         i=a[i][2];
      }
      l++;
   }
   return(false);
}
int dinic(int x,int flow)
{
   int min(int,int);
   if (x==t)
      return(flow);
   int i=b[x],s=0,t=flow;
   while (i!=0)
   {
      if (d[x]+1==d[a[i][0]] && a[i][1]>0)
      {
         int k=dinic(a[i][0],min(t,a[i][1]));
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
