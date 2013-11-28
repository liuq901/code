/*
ID: liuq9011
LANG: C++
TASK: milk3
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int m,n,t,a[26],f[26][26][26];
int main()
{
   in=fopen("milk3.in","r");
   out=fopen("milk3.out","w");
   void search(int,int,int);
   int i,flag;
   fscanf(in,"%d%d%d",&m,&n,&t);
   memset(a,0,sizeof(a));
   memset(f,0,sizeof(f));
   f[0][0][t]=1;
   a[t]=1;
   search(0,0,t);
   flag=0;
   for (i=0;i<=20;i++)
      if (a[i])
      {
         if (flag)
            fprintf(out," ");
         fprintf(out,"%d",i);
         flag=1;
      }
   fprintf(out,"\n");
   fclose(in),fclose(out);
   return(0);
}
void search(int x,int y,int z)
{
   int i,j,k,s;
   i=x,j=y,k=z;
   s=n-j;
   if (i<s)
      j+=i,i=0;
   else
      i-=s,j=n;
   if (!f[i][j][k])
   {
      if (i==0)
         a[k]=1;
      f[i][j][k]=1;
      search(i,j,k);
   }
   i=x,j=y,k=z;
   s=t-k;
   if (i<s)
      k+=i,i=0;
   else
      i-=s,k=t;
   if (!f[i][j][k])
   {
      if (i==0)
         a[k]=1;
      f[i][j][k]=1;
      search(i,j,k);
   }
   i=x,j=y,k=z;
   s=m-i;
   if (j<s)
      i+=j,j=0;
   else
      j-=s,i=m;
   if (!f[i][j][k])
   {
      if (i==0)
         a[k]=1;
      f[i][j][k]=1;
      search(i,j,k);
   }
   i=x,j=y,k=z;
   s=t-k;
   if (j<s)
      k+=j,j=0;
   else
      j-=s,k=t;
   if (!f[i][j][k])
   {
      if (i==0)
         a[k]=1;
      f[i][j][k]=1;
      search(i,j,k);
   }
   i=x,j=y,k=z;
   s=m-i;
   if (k<s)
      i+=k,k=0;
   else
      k-=s,i=m;
   if (!f[i][j][k])
   {
      if (i==0)
         a[k]=1;
      f[i][j][k]=1;
      search(i,j,k);
   }
   i=x,j=y,k=z;
   s=n-j;
   if (k<s)
      j+=k,k=0;
   else
      k-=s,j=n;
   if (!f[i][j][k])
   {
      if (i==0)
         a[k]=1;
      f[i][j][k]=1;
      search(i,j,k);
   }
}
