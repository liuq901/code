/*
ID: liuq9011
LANG: C++
TASK: fence
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int n,m,x,y,s,a[501][501],f[501],t[501];
int main()
{
   in=fopen("fence.in","r");
   out=fopen("fence.out","w");
   void search(int);
   int i;
   fscanf(in,"%d",&m);
   n=0;
   memset(a,0,sizeof(a));
   memset(f,0,sizeof(f));
   for (i=1;i<=m;i++)
   {
       fscanf(in,"%d%d",&x,&y);
       f[x]++;
       f[y]++;
       a[x][y]++;
       a[y][x]++;
       if (x>n)
          n=x;
       if (y>n)
          n=y;
   }
   x=y=0;
   for (i=1;i<=n;i++)
   {
      if (f[i]%2==1 && x!=0)
      {
         y=i;
         break;
      }
      if (f[i]%2==1 && x==0)
         x=i;
   }
   if (x==0)
      x=y=1;
   s=0;
   search(x);
   for (i=s;i>=1;i--)
      fprintf(out,"%d\n",t[i]);
   fclose(in),fclose(out);
   return(0);
}
void search(int k)
{
   int i;
   for (i=1;i<=n;i++)
      if (a[k][i]>0)
      {
         a[k][i]--;
         a[i][k]--;
         search(i);
      }
   s++;
   t[s]=k;
}
