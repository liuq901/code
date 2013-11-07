/*
ID: liuq9011
LANG: C++
TASK: wissqu
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
struct way
{
   int w,r,l;
};
struct way f[17];
int ans,p[5],g[5][5],a[6][6];
int main()
{
   in=fopen("wissqu.in","r");
   out=fopen("wissqu.out","w");
   void search(int);
   int i,j;
   char ch;
   for (i=1;i<=4;i++)
   {
      for (j=1;j<=4;j++)
      {
         fscanf(in,"%c",&ch);
         a[i][j]=ch-'A';
      }
      fscanf(in,"%*c");
   }
   for (i=1;i<=4;i++)
   {
      a[0][i]=26;
      a[5][i]=26;
      a[i][0]=26;
      a[i][5]=26;
   }
   memset(f,0,sizeof(f));
   memset(g,0,sizeof(g));
   ans=0;
   for (i=0;i<=4;i++)
      p[i]=3;
   p[3]=4;
   search(1);
   for (i=1;i<=16;i++)
      fprintf(out,"%c %d %d\n",f[i].w+'A',f[i].r,f[i].l);
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
void search(int t)
{
   int check(int,int,int);
   int i,j,k,x;
   if (t==17)
   {
      f[0].w=1;
      ans++;
      return;
   }
   for (i=0;i<=4;i++)
   {
      if (t==1 && i!=3)
         continue;
      if (p[i]<=0)
         continue;
      for (j=1;j<=4;j++)
         for (k=1;k<=4;k++)
         {
            if (!check(i,j,k))
               continue;
            if (g[j][k])
               continue;
            if (!f[0].w)
            {
               f[t].w=i;
               f[t].r=j;
               f[t].l=k;
            }
            x=a[j][k];
            p[i]--;
            a[j][k]=i;
            g[j][k]=1;
            search(t+1);
            a[j][k]=x;
            p[i]++;
            g[j][k]=0;
         }
   }
}
int check(int k,int x,int y)
{
   int i,j;
   for (i=-1;i<=1;i++)
      for (j=-1;j<=1;j++)
         if (a[x+i][y+j]==k)
            return(0);
   return(1);
}
