/*
ID: liuq9011
LANG: C++
TASK: rockers
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int ans,n,m,t,a[26],f[26];
int main()
{
   in=fopen("rockers.in","r");
   out=fopen("rockers.out","w");
   void search(int);
   int i;
   fscanf(in,"%d%d%d",&n,&t,&m);
   for (i=1;i<=n;i++)
      fscanf(in,"%d",&a[i]);
   memset(f,0,sizeof(f));
   ans=0;
   search(0);
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
void search(int x)
{
   void work();
   if (x==n+1)
   {
      work();
      return;
   }
   search(x+1);
   f[x]=1;
   search(x+1);
   f[x]=0;
}
void work()
{
   int i,s,p,q;
   s=0;
   p=1;
   q=t;
   for (i=1;i<=n;i++)
   {
      if (!f[i])
         continue;
      s++;
      if (a[i]<=q)
         q-=a[i];
      else
      {
         p++;
         q=t-a[i];
      }
      if (p>m || q<0)
         return;
   }
   if (s>ans)
      ans=s;
}
