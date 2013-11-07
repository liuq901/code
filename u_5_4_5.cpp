/*
ID: liuq9011
LANG: C++
TASK: telecow
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int n,s,t;
int b[201],a[201][201];
int main()
{
   in=fopen("telecow.in","r");
   out=fopen("telecow.out","w");
   int build(),dinic(int,int);
   void print(int);
   int m,i,x,y,ans;
   fscanf(in,"%d%d%d%d",&n,&m,&s,&t);
   memset(a,0,sizeof(a));
   for (i=1;i<=m;i++)
   {
      fscanf(in,"%d%d",&x,&y);
      a[x+n][y]=20000000;
      a[y+n][x]=20000000;
   }
   for (i=1;i<=n;i++)
      a[i][i+n]=5100+i;
   s+=n;
   n*=2;
   ans=0;
   while (1)
   {
      if (!build())
         break;
      while (1)
      {
         x=dinic(s,20000000);
         if (x==0)
            break;
         ans+=x;
      }
   }
   print(ans/5100);
   fclose(in),fclose(out);
   return(0);
}
int build()
{
   int i,l,r;
   int f[201],q[201];
   l=r=1;
   q[l]=s;
   b[s]=0;
   memset(f,0,sizeof(f));
   f[s]=1;
   while (1)
   {
      for (i=1;i<=n;i++)
         if (!f[i] && a[q[l]][i]>0)
         {
            r++;
            q[r]=i;
            b[i]=b[q[l]]+1;
            f[i]=1;
            if (i==t)
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
   int min(int,int);
   int i,k;
   if (x==t)
      return(flow);
   for (i=1;i<=n;i++)
      if (a[x][i]>0 && b[x]+1==b[i])
      {
         k=dinic(i,min(a[x][i],flow));
         a[x][i]-=k;
         a[i][x]+=k;
         if (k!=0)
            return(k);
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
void print(int ans)
{
   void floodfill(int);
   int i,t;
   fprintf(out,"%d\n",ans);
   memset(b,0,sizeof(b));
   b[s]=1;
   floodfill(s);
   n/=2;
   t=0;
   for (i=1;i<=n;i++)
      if (b[i] && !b[i+n])
      {
         t++;
         fprintf(out,"%d",i);
         if (t<ans)
            fprintf(out," ");
         else
         {
            fprintf(out,"\n");
            break;
         }
      }
}
void floodfill(int x)
{
   int i;
   for (i=1;i<=n;i++)
      if (a[x][i]!=0 && !b[i])
      {
         b[i]=1;
         floodfill(i);
      }
}
