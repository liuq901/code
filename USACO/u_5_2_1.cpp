/*
ID: liuq9011
LANG: C++
TASK: snail
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int ans,n,a[126][126],f[126][126];
int main()
{
   in=fopen("snail.in","r");
   out=fopen("snail.out","w");
   void search(int,int,int,int,int);
   int i,m,y;
   char x;
   fscanf(in,"%d%d%*c",&n,&m);
   memset(a,0,sizeof(a));
   for (i=1;i<=m;i++)
   {
      fscanf(in,"%c%d%*c",&x,&y);
      a[x-'A'+1][y]=1;
   }
   for (i=1;i<=n;i++)
   {
      a[0][i]=1;
      a[i][0]=1;
      a[n+1][i]=1;
      a[i][n+1]=1;
   }
   ans=0;
   memset(f,0,sizeof(f));
   f[1][1]=1;
   search(1,1,1,0,1);
   search(1,1,1,1,0);
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
void search(int s,int x,int y,int p,int q)
{
   if (s>ans)
      ans=s;
   if (f[x+p][y+q])
      return;
   if (!a[x+p][y+q])
   {
      f[x+p][y+q]=1;
      search(s+1,x+p,y+q,p,q);
      f[x+p][y+q]=0;
   }
   else
   {
      if (q==0)
      {
         if (!f[x][y-1] && !a[x][y-1])
         {
            f[x][y-1]=1;
            search(s+1,x,y-1,0,-1);
            f[x][y-1]=0;
         }
         if (!f[x][y+1] && !a[x][y+1])
         {
            f[x][y+1]=1;
            search(s+1,x,y+1,0,1);
            f[x][y+1]=0;
         }
      }
      if (p==0)
      {
         if (!f[x-1][y] && !a[x-1][y])
         {
            f[x-1][y]=1;
            search(s+1,x-1,y,-1,0);
            f[x-1][y]=0;
         }
         if (!f[x+1][y] && !a[x+1][y])
         {
            f[x+1][y]=1;
            search(s+1,x+1,y,1,0);
            f[x+1][y]=0;
         }
      }
   }
}
