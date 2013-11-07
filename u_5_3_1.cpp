/*
ID: liuq9011
LANG: C++
TASK: milk4
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int p,q,s,x,a[101],b[101],f[20001],g[20001];
int main()
{
   in=fopen("milk4.in","r");
   out=fopen("milk4.out","w");
   int search(int,int);
   int i,j,t;
   fscanf(in,"%d",&q);
   fscanf(in,"%d",&p);
   for (i=1;i<=p;i++)
      fscanf(in,"%d",&a[i]);
   for (i=1;i<=p-1;i++)
      for (j=i+1;j<=p;j++)
         if (a[i]>a[j])
            t=a[i],a[i]=a[j],a[j]=t;
   for (i=1;i<=p;i++)
   {
      s=x=0;
      if (search(0,i))
         break;
   }
   fprintf(out,"%d",s);
   for (i=1;i<=s;i++)
      fprintf(out," %d",b[i]);
   fprintf(out,"\n");
   fclose(in),fclose(out);
   return(0);
}
int search(int t,int k)
{
   int work(int);
   int i,y;
   if (t==k)
   {
      memset(f,0,sizeof(f));
      memset(g,0,sizeof(g));
      f[0]=g[0]=1;
      if (work(q))
         return(1);
      else
         return(0);
   }
   for (i=x+1;i<=p;i++)
   {
      s++;
      b[s]=a[i];
      y=x;
      x=i;
      if (search(t+1,k))
         return(1);
      s--;
      x=y;
   }
   return(0);
}
int work(int x)
{
   int i;
   if (g[x])
      return(f[x]);
   g[x]=1;
   for (i=1;i<=s;i++)
      if (x>=b[i] && work(x-b[i]))
      {
         f[x]=1;
         break;
      }
   return(f[x]);
}
