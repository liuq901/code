/*
ID: liuq9011
LANG: C++
TASK: holstein
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int n,m,ans,b[26],a[1001][26],c[1001],f[1001],flag[1001];
int main()
{
   in=fopen("holstein.in","r");
   out=fopen("holstein.out","w");
   void search(int,int);
   int i,j;
   fscanf(in,"%d",&m);
   for (i=1;i<=m;i++)
      fscanf(in,"%d",&b[i]);
   fscanf(in,"%d",&n);
   for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
         fscanf(in,"%d",&a[i][j]);
   ans=1000000;
   memset(f,0,sizeof(f));
   for (i=1;i<=n;i++)
   {
      f[i]=1;
      for (j=1;j<=m;j++)
         c[j]=a[i][j];
      search(1,i);
      f[i]=0;
   }
   fprintf(out,"%d",ans);
   for (i=1;i<=n;i++)
      if (flag[i])
         fprintf(out," %d",i);
   fprintf(out,"\n");
   fclose(in),fclose(out);
   return(0);
}
void search(int k,int t)
{
   int i,j,ff;
   if (k>ans)
      return;
   ff=1;
   for (i=1;i<=m;i++)
      if (c[i]<b[i])
      {
         ff=0;
         break;
      }
   if (ff)
      if (k<ans)
      {
         ans=k;
         memset(flag,0,sizeof(flag));
         for (i=1;i<=n;i++)
            if (f[i])
               flag[i]=1;
         return;
      }
   for (i=t+1;i<=n;i++)
   {
      f[i]=1;
      for (j=1;j<=m;j++)
         c[j]+=a[i][j];
      search(k+1,i);
      f[i]=0;
      for (j=1;j<=m;j++)
         c[j]-=a[i][j];
   }
}
