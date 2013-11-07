/*
ID: liuq9011
LANG: C++
TASK: crypt1
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int ans,a[11],f[11];
int main()
{
   in=fopen("crypt1.in","r");
   out=fopen("crypt1.out","w");
   void work(int,int,int,int,int);
   int n,i,j,k,l,x,y;
   fscanf(in,"%d",&n);
   memset(f,0,sizeof(f));
   for (i=1;i<=n;i++)
   {
      fscanf(in,"%d",&a[i]);
      f[a[i]]=1;
   }
   ans=0;
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
         for (k=1;k<=n;k++)
            for (x=1;x<=n;x++)
               for (y=1;y<=n;y++)
                  work(i,j,k,x,y);
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
void work(int x1,int x2,int x3,int y1,int y2)
{
   int check(int,int);
   int s1,s2,s3,s4,s5;
   s1=100*a[x1]+10*a[x2]+a[x3];
   s2=10*a[y1]+a[y2];
   s3=s1*a[y2];
   s4=s1*a[y1];
   s5=s3+10*s4;
   if (check(s3,3) && check(s4,3) && check(s5,4))
      ans++;
}
int check(int x,int n)
{
   int i;
   int b[10];
   for (i=1;i<=n;i++)
   {
      b[i]=x%10;
      if (!f[b[i]])
         return(0);
      x/=10;
   }
   if (x!=0)
      return(0);
   if (b[n]==0)
      return(0);
   return(1);
}
