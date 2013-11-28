/*
ID: liuq9011
LANG: C++
TASK: money
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("money.in","r");
   out=fopen("money.out","w");
   int i,j,n,v,t;
   long long f[10001];
   fscanf(in,"%d%d",&v,&n);
   memset(f,0,sizeof(f));
   f[0]=1;
   for (i=1;i<=v;i++)
   {
      fscanf(in,"%d",&t);
      for (j=t;j<=n;j++)
         f[j]+=f[j-t];
   }
   fprintf(out,"%lld\n",f[n]);
   fclose(in),fclose(out);
   return(0);
}
