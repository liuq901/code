/*
ID: liuq9011
LANG: C++
TASK: latin
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
const int c[7]={1,1,2,6,24,120,720};
int n,a[10][2],f[10][10],g[10][10];
int main()
{
   in=fopen("latin.in","r");
   out=fopen("latin.out","w");
   void build();
   int search(int,int);
   int i,sum;
   long long ans;
   fscanf(in,"%d",&n);
   memset(f,0,sizeof(f));
   memset(g,0,sizeof(g));
   for (i=2;i<=n;i++)
   {
      g[i][i]=1;
      f[i][i]=1;
   }
   memset(a,-1,sizeof(a));
   sum=search(2,2);
   ans=(long long)sum*c[n-1];
   fprintf(out,"%lld\n",ans);
   fclose(in),fclose(out);
   return(0);
}
int search(int x,int y)
{
   int check();
   int i,j,s,t;
   if (x==n)
      return(1);
   s=0;
   for (i=1;i<=n;i++)
   {
      if (f[x][i] || g[y][i])
         continue;
      f[x][i]=1;
      g[y][i]=1;
      if (y==n)
         t=search(x+1,2);
      else
         t=search(x,y+1);
      f[x][i]=0;
      g[y][i]=0;
      if (x==2 && i==y+1)
         return(t*(n-y)+s);
      s+=t;
   }
   return(s);
}
