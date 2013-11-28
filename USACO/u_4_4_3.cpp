/*
ID: liuq9011
LANG: C++
TASK: frameup
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
struct data
{
   int x1,y1,x2,y2;
};
int n,h,w,s,f[30],g[30],q[30],a[30][30];
char b[30],c[31][31],ans[10000][30];
struct data p[30];
int main()
{
   in=fopen("frameup.in","r");
   out=fopen("frameup.out","w");
   void build(),work();
   int i,j;
   fscanf(in,"%d%d%*c",&h,&w);
   for (i=1;i<=h;i++)
   {
      for (j=1;j<=w;j++)
         fscanf(in,"%c",&c[i][j]);
      fscanf(in,"%*c");
   }
   build();
   work();
   for (i=1;i<=s;i++)
      fprintf(out,"%s\n",ans[i]);
   fclose(in),fclose(out);
   return(0);
}
void build()
{
   int i,j,t;
   char ch;
   struct data tmp;
   n=0;
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   memset(f,0,sizeof(f));
   for (i=1;i<=h;i++)
      for (j=1;j<=w;j++)
      {
         if (c[i][j]=='.')
            continue;
         if (f[c[i][j]-'A']==0)
         {
            n++;
            f[c[i][j]-'A']=n;
            b[n]=c[i][j];
            p[n].x1=p[n].x2=i;
            p[n].y1=p[n].y2=j;
         }
         else
         {
            t=f[c[i][j]-'A'];
            if (i<p[t].x1)
               p[t].x1=i;
            if (i>p[t].x2)
               p[t].x2=i;
            if (j<p[t].y1)
               p[t].y1=j;
            if (j>p[t].y2)
               p[t].y2=j;
         }
      }
   for (i=1;i<=n-1;i++)
      for (j=i+1;j<=n;j++)
         if (b[j]<b[i])
         {
            ch=b[i],b[i]=b[j],b[j]=ch;
            tmp=p[i],p[i]=p[j],p[j]=tmp;
         }
   for (i=1;i<=n;i++)
      f[b[i]-'A']=i;
   for (i=1;i<=n;i++)
   {
      for (j=p[i].x1;j<=p[i].x2;j++)
      {
         if (c[j][p[i].y1]!=b[i])
         {
            t=f[c[j][p[i].y1]-'A'];
            a[i][t]=1;
         }
         if (c[j][p[i].y2]!=b[i])
         {
            t=f[c[j][p[i].y2]-'A'];
            a[i][t]=1;
         }
      }
      for (j=p[i].y1;j<=p[i].y2;j++)
      {
         if (c[p[i].x1][j]!=b[i])
         {
            t=f[c[p[i].x1][j]-'A'];
            a[i][t]=1;
         }
         if (c[p[i].x2][j]!=b[i])
         {
            t=f[c[p[i].x2][j]-'A'];
            a[i][t]=1;
         }
      }
   }
}
void work()
{
   void search(int);
   int i;
   memset(g,0,sizeof(g));
   s=0;
   search(1);
}
void search(int t)
{
   void print();
   int check(int);
   int i;
   if (t==n+1)
   {
      print();
      return;
   }
   for (i=1;i<=n;i++)
   {
      if (!check(i))
         continue;
      g[i]=1;
      q[t]=i;
      search(t+1);
      g[i]=0;
   }
}
void print()
{
    int i;
    s++;
    for (i=1;i<=n;i++)
       ans[s][i-1]=b[q[i]];
    ans[s][n]='\0';
}
int check(int x)
{
   int i;
   if (g[x])
      return(0);
   for (i=1;i<=n;i++)
      if (!g[i] && a[i][x])
         return(0);
   return(1);
}
