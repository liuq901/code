/*
ID: liuq9011
LANG: C++
TASK: rect1
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int x,y,n,m,f,ans[1010],a[1010][10];
int main()
{
   in=fopen("rect1.in","r");
   out=fopen("rect1.out","w");
   void search(int,int,int,int,int);
   int i,j;
   fscanf(in,"%d%d%d",&x,&y,&n);
   m=0;
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=5;j++)
         fscanf(in,"%d",&a[i][j]);
      if (m<a[i][5])
         m=a[i][5];
   }
   a[0][1]=a[0][2]=0;
   a[0][3]=x;
   a[0][4]=y;
   a[0][5]=1;
   memset(ans,0,sizeof(ans));
   for (i=n;i>=0;i--)
   {
      f=a[i][5];
      search(a[i][1],a[i][2],a[i][3],a[i][4],i+1);
   }
   for (i=1;i<=m;i++)
      if (ans[i]!=0)
         fprintf(out,"%d %d\n",i,ans[i]);
   fclose(in),fclose(out);
   return(0);
}
void search(int x1,int y1,int x2,int y2,int t)
{
   while (t<=n && (x2<=a[t][1] || x1>=a[t][3] || y2<=a[t][2] || y1>=a[t][4]))
      t++;
   if (t>n)
   {
      ans[f]+=(x2-x1)*(y2-y1);
      return;
   }
   if (x1<a[t][1])
   {
      search(x1,y1,a[t][1],y2,t+1);
      x1=a[t][1];
   }
   if (x2>a[t][3])
   {
      search(a[t][3],y1,x2,y2,t+1);
      x2=a[t][3];
   }
   if (y1<a[t][2])
      search(x1,y1,x2,a[t][2],t+1);
   if (y2>a[t][4])
      search(x1,a[t][4],x2,y2,t+1);
}
