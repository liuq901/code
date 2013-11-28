/*
ID: liuq9011
LANG: C++
TASK: schlnet
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int n,f[101],g[101],h[101],a[101][101],b[101][101];
int main()
{
   in=fopen("schlnet.in","r");
   out=fopen("schlnet.out","w");
   void floodfill(int),search(int,int),work();
   int i,j,k,t,x;
   fscanf(in,"%d",&n);
   memset(b,0,sizeof(b));
   for (i=1;i<=n;i++)
      while (1)
      {
         fscanf(in,"%d",&x);
         if (x==0)
            break;
         a[i][0]++;
         a[i][a[i][0]]=x;
         b[x][0]++;
         b[x][b[x][0]]=i;
      }
   memset(f,0,sizeof(f));
   memset(g,0,sizeof(g));
   x=0;
   for (i=1;i<=n;i++)
   {
      if (f[i]!=0)
         continue;
      x++;
      floodfill(i);
   }
   x=0;
   memset(h,0,sizeof(h));
   for (i=n;i>=1;i--)
   {
      if (h[g[i]]!=0)
         continue;
      x++;
      search(g[i],x);
   }
   work();
   fclose(in),fclose(out);
   return(0);
}
void floodfill(int x)
{
   int i;
   f[x]=1;
   for (i=1;i<=a[x][0];i++)
   {
      if (f[a[x][i]])
         continue;
      floodfill(a[x][i]);
   }
   g[0]++;
   g[g[0]]=x;
}
void search(int x,int t)
{
   int i;
   h[x]=t;
   for (i=1;i<=b[x][0];i++)
   {
      if (h[b[x][i]]!=0)
         continue;
      search(b[x][i],t);
   }
}
void work()
{
   int max(int,int);
   int i,j,m,x,y;
   int d[101],e[101],c[101][101];
   m=0;
   memset(c,0,sizeof(c));
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=a[i][0];j++)
         c[h[i]][h[a[i][j]]]=1;
      if (h[i]>m)
         m=h[i];
   }
   memset(d,0,sizeof(d));
   memset(e,0,sizeof(e));
   for (i=1;i<=m;i++)
      for (j=i;j<=m;j++)
         if (i!=j && c[i][j])
         {
            d[j]++;
            e[i]++;
         }
   x=y=0;
   for (i=1;i<=m;i++)
   {
      if (d[i]==0)
         x++;
      if (e[i]==0)
         y++;
   }
   fprintf(out,"%d\n",x);
   if (m==1)
      fprintf(out,"0\n");
   else
      fprintf(out,"%d\n",max(x,y));
}
int max(int x,int y)
{
   if (x>y)
      return(x);
   else
      return(y);
}
