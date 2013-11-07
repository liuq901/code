/*
ID: liuq9011
LANG: C++
TASK: ditch
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int n,b[201],a[201][201];
int main()
{
   in=fopen("ditch.in","r");
   out=fopen("ditch.out","w");
   int make(),search(int,int);
   int i,x,y,z,m,ans;
   fscanf(in,"%d%d",&m,&n);
   memset(a,0,sizeof(a));
   for (i=1;i<=m;i++)
   {
      fscanf(in,"%d%d%d",&x,&y,&z);
      a[x][y]+=z;
   }
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
   int q[201],f[201];
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
