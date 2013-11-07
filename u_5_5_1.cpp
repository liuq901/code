/*
ID: liuq9011
LANG: C++
TASK: picture
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
const int p=10000;
int n,ans,a[10001][4],b[10001][4];
int main()
{
   in=fopen("picture.in","r");
   out=fopen("picture.out","w");
   void work(int[][4]);
   int x1,y1,x2,y2,i;
   fscanf(in,"%d",&n);
   for (i=1;i<=n;i++)
   {
      fscanf(in,"%d%d%d%d",&x1,&y1,&x2,&y2);
      a[i][0]=x1+p;
      a[i][1]=x2-1+p;
      a[i][2]=y1+p;
      a[i][3]=0;
      a[i+n][0]=x1+p;
      a[i+n][1]=x2-1+p;
      a[i+n][2]=y2+p;
      a[i+n][3]=1;
      b[i][0]=y1+p;
      b[i][1]=y2-1+p;
      b[i][2]=x1+p;
      b[i][3]=0;
      b[i+n][0]=y1+p;
      b[i+n][1]=y2-1+p;
      b[i+n][2]=x2+p;
      b[i+n][3]=1;
   }
   n*=2;
   ans=0;
   work(a);
   work(b);
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
void work(int a[][4])
{
   void sort(int,int,int[][4]);
   int i,j;
   int f[20001];
   sort(1,n,a);
   memset(f,0,sizeof(f));
   for (i=1;i<=n;i++)
      for (j=a[i][0];j<=a[i][1];j++)
      {
         if (!a[i][3])
         {
            f[j]++;
            if (f[j]==1)
               ans++;
         }
         if (a[i][3])
         {
            f[j]--;
            if (f[j]==0)
               ans++;
         }
      }
}
void sort(int l,int r,int a[][4])
{
   int i,j,x,y;
   int t[4];
   i=l;
   j=r;
   x=a[(l+r)/2][2];
   y=a[(l+r)/2][3];
   while (i<=j)
   {
      while (a[i][2]<x || a[i][2]==x && a[i][3]<y)
         i++;
      while (a[j][2]>x || a[j][2]==x && a[j][3]>y)
         j--;
      if (i<=j)
      {
         memcpy(t,a[i],sizeof(a[i]));
         memcpy(a[i],a[j],sizeof(a[j]));
         memcpy(a[j],t,sizeof(t));
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r,a);
   if (l<j)
      sort(l,j,a);
}
