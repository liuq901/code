/*
ID: liuq9011
LANG: C++
TASK: rectbarn
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int l[3001],r[3001],h[3001];
char a[3001][3001];
int main()
{
   in=fopen("rectbarn.in","r");
   out=fopen("rectbarn.out","w");
   int n,m,p,i,j,k,x,y,ans;
   fscanf(in,"%d%d%d",&n,&m,&p);
   memset(a,0,sizeof(a));
   for (i=1;i<=p;i++)
   {
      fscanf(in,"%d%d",&x,&y);
      a[x][y]=1;
   }
   for (i=1;i<=m;i++)
      l[i]=1,r[i]=m,h[i]=0;
   ans=0;
   for (i=1;i<=n;i++)
   {
      k=1;
      for (j=1;j<=m;j++)
         if (!a[i][j])
         {
            h[j]++;
            if (k>l[j])
               l[j]=k;
         }
         else
         {
            h[j]=0;
            l[j]=1;
            r[j]=m;
            k=j+1;
         }
      k=m;
      for (j=m;j>=1;j--)
         if (!a[i][j])
         {
            if (k<r[j])
               r[j]=k;
            if (h[j]*(r[j]-l[j]+1)>ans)
               ans=h[j]*(r[j]-l[j]+1);
         }
         else
            k=j-1;
   }
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
