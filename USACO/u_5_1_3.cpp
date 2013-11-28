/*
ID: liuq9011
LANG: C++
TASK: theme
*/
#include <cstdio>
FILE *in,*out;
int ans,a[5001];
int main()
{
   in=fopen("theme.in","r");
   out=fopen("theme.out","w");
   int work(int,int);
   int n,i,x;
   fscanf(in,"%d",&n);
   for (i=1;i<=n;i++)
      fscanf(in,"%d",&a[i]);
   ans=1;
   for (i=1;i<=n-1;i++)
   {
      x=work(i,n);
      if (x>ans)
         ans=x;
   }
   if (ans<5)
      ans=0;
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
int work(int i,int j)
{
   int x;
   if (i==1)
      return(1);
   if (a[i]-a[i-1]==a[j]-a[j-1])
   {
      x=work(i-1,j-1);
      if (x+1>j-i)
         return(1);
      else
      {
         if (x+1>ans)
            ans=x+1;
         return(x+1);
      }
   }
   else
   {
      work(i-1,j-1);
      return(1);
   }
}
