/*
ID: liuq9011
LANG: C++
TASK: stall4
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int n,b[410],a[410][410];
int main()
{
   in=fopen("stall4.in","r");
   out=fopen("stall4.out","w");
   int make(),search(int,int);
   int i,j,k,m,x,ans;
   fscanf(in,"%d%d",&n,&m);
   memset(a,0,sizeof(a));
   for (i=1;i<=n;i++)
   {
      fscanf(in,"%d",&k);
      for (j=1;j<=k;j++)
      {
         fscanf(in,"%d",&x);
         a[i+1][x+n+1]=1;
      }
   }
   for (i=1;i<=n;i++)
      a[1][i+1]=1;
   for (i=1;i<=m;i++)
      a[i+n+1][n+m+2]=1;
   n+=m+2;
   ans=0;
   while (1)
   {
      if (!make())
         break;
      while (1)
      {
         x=search(1,20000000);
         if (x==0)
            break;
         ans+=x;
      }
   }
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
int make()
{
   int l,r,i;
   int q[410],f[410];
   l=r=1;
   memset(f,0,sizeof(f));
   f[1]=1;
   q[1]=1;
   while (1)
   {
      for (i=1;i<=n;i++)
      {
         if (f[i])
            continue;
         if (a[q[l]][i]!=0)
         {
            f[i]=1;
            b[i]=b[q[l]]+1;
            r++;
            q[r]=i;
            if (i==n)
                return(1);
         }
      }
      l++;
      if (l>r)
         break;
   }
   return(0);
}
int search(int t,int flow)
{
   int min(int,int);
   int x,i,ans;
   if (t==n)
      return(flow);
   for (i=1;i<=n;i++)
      if (a[t][i]!=0 && b[t]+1==b[i])
      {
         x=search(i,min(a[t][i],flow));
         if (x!=0)
         {
            a[t][i]-=x;
            a[i][t]+=x;
            return(x);
         }
      }
   return(0);
}
int min(int x,int y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
