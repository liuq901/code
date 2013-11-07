/*
ID: liuq9011
LANG: C++
TASK: heritage
*/
#include <cstdio>
FILE *in,*out;
int a[30],b[30];
int main()
{
   in=fopen("heritage.in","r");
   out=fopen("heritage.out","w");
   void work(int,int,int,int);
   char ch;
   int n,i;
   n=0;
   while (1)
   {
      fscanf(in,"%c",&ch);
      if (ch=='\n')
         break;
      n++;
      a[n]=ch-'A';
   }
   for (i=1;i<=n;i++)
   {
      fscanf(in,"%c",&ch);
      b[i]=ch-'A';
   }
   work(1,n,1,n);
   fprintf(out,"\n");
   fclose(in),fclose(out);
   return(0);
}
void work(int l,int r,int x,int y)
{
   int i,k,p;
   if (l>r || x>y)
      return;
   if (l==r)
   {
      fprintf(out,"%c",a[l]+'A');
      return;
   }
   k=b[x];
   for (i=l;i<=r;i++)
      if (a[i]==k)
      {
         p=i;
         break;
      }
   work(l,p-1,x+1,x+p-l);
   work(p+1,r,x+p-l+1,y);
   work(p,p,x,x);
}
