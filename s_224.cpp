#include <cstdio>
#include <cstdlib>
int n,k,ans,a[11],b[21],c[21];
int main()
{
   void search(int,int);
   int i;
   scanf("%d%d",&n,&k);
   ans=0;
   search(0,0);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void search(int x,int t)
{
   int i;
   if (t==k)
   {
      ans++;
      return;
   }
   if (x==n)
      return;
   search(x+1,t);
   for (i=1;i<=n;i++)
   {
      if (a[i])
         continue;
      if (b[x+i+1])
         continue;
      if (c[x+10-i])
         continue;
      a[i]=1;
      b[x+i+1]=1;
      c[x+10-i]=1;
      search(x+1,t+1);
      a[i]=0;
      b[x+i+1]=0;
      c[x+10-i]=0;
   }
}
