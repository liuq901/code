#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[10001];
int main()
{
   void build(int);
   int n,i,j,t;
   int f[10001],g[10001];
   scanf("%d",&n);
   build(n);
   memset(f,26,sizeof(f));
   f[0]=0;
   for (i=1;i<=a[0];i++)
      for (j=0;j<=n-a[i];j++)
         if (f[j]+1<f[j+a[i]])
         {
            f[j+a[i]]=f[j]+1;
            g[j+a[i]]=j;
         }
   if (f[n]<20000000 && f[n]!=0)
   {
      printf("%d\n",f[n]);
      t=n;
      for (i=1;i<=f[n]-1;i++)
      {
         printf("%d ",t-g[t]);
         t=g[t];
      }
      printf("%d\n",t);
   }
   else
      printf("0\n");
   system("pause");
   return(0);
}
void build(int n)
{
   int i,j;
   int b[10001],f[10001];
   memset(f,0,sizeof(f));
   f[1]=1;
   for (i=2;i<=n;i++)
   {
      if (f[i])
         continue;
      j=1;
      while (1)
      {
         j++;
         if (i*j>n)
            break;
         f[i*j]=1;
      }
   }
   b[0]=0;
   for (i=1;i<=n;i++)
      if (!f[i])
      {
         b[0]++;
         b[b[0]]=i;
      }
   a[0]=0;
   for (i=1;i<=b[0];i++)
      if (!f[i])
      {
         a[0]++;
         a[a[0]]=b[i];
      }
}
