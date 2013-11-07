#include <cstdio>
#include <cstdlib>
#include <cstring>
int m,b[410],a[410][410];
int main()
{
   int build(),dinic(int,int);
   int k,i,j,t,x,n;
   int ans[201];
   scanf("%d%d",&n,&k);
   memset(a,0,sizeof(a));
   for (i=1;i<=n;i++)
   {
      scanf("%d",&t);
      for (j=1;j<=t;j++)
      {
         scanf("%d",&x);
         a[i][x+n]=1;
      }
      a[0][i]=1;
   }
   m=k+n;
   for (i=1;i<=k;i++)
   {
      a[m+2][m+1]+=2;
      a[i+n][m+3]=2;
   }
   a[m+1][0]=20000000;
   while (build())
      dinic(m+2,20000000);
   if (a[m+2][m+1]!=0)
      printf("NO\n");
   else
   {
      printf("YES\n");
      for (i=1;i<=k;i++)
      {
         ans[0]=0;
         for (j=1;j<=n;j++)
            if (a[i+n][j]==1)
            {
               ans[0]++;
               ans[ans[0]]=j;
            }
         printf("%d",ans[0]);
         for (j=1;j<=ans[0];j++)
            printf(" %d",ans[j]);
         printf("\n");
      }
   }
   system("pause");
   return(0);
}
int build()
{
   int l,r,i;
   int q[410],f[410];
   memset(f,0,sizeof(f));
   q[1]=m+2;
   l=r=1;
   b[m+2]=0;
   f[m+2]=1;
   while (1)
   {
      for (i=0;i<=m+3;i++)
      {
         if (f[i] || !a[q[l]][i])
            continue;
         r++;
         q[r]=i;
         f[i]=1;
         b[i]=b[q[l]]+1;
         if (i==m+3)
            return(1);
      }
      l++;
      if (l>r)
         break;
   }
   return(0);
}
int dinic(int x,int flow)
{
   int min(int x,int y);
   int i,t,s,k;
   if (x==m+3)
      return(flow);
   k=flow;
   s=0;
   for (i=0;i<=m+3;i++)
      if (a[x][i] && b[x]+1==b[i])
      {
         t=dinic(i,min(k,a[x][i]));
         s+=t;
         k-=t;
         a[x][i]-=t;
         a[i][x]+=t;
         if (k==0)
            break;
      }
   if (s==0)
      b[x]=-1;
   return(s);
}
int min(int x,int y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
