#include <cstdio>
#include <cstdlib>
int n,m,b[101],q[101];
int main()
{
   void search(int,int);
   int i,j,t,p;
   int a[101];
   while (1)
   {
      scanf("%d",&n);
      if (n==0)
         break;
      for (i=1;i<=n;i++)
         scanf("%d",&a[i]);
      scanf("%d",&m);
      for (i=1;i<=n-1;i++)
         for (j=i+1;j<=n;j++)
            if (a[i]>a[j])
               t=a[i],a[i]=a[j],a[j]=t;
      t=1;
      p=a[1];
      b[1]=a[1];
      for (i=2;i<=n;i++)
      {
         if (a[i]==p)
            continue;
         t++;
         b[t]=a[i];
         p=a[i];
      }
      n=t;
      for (i=1;i<=n-m+1;i++)
      {
         q[1]=b[i];
         search(i,1);
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
void search(int x,int t)
{
   int i;
   if (t==m)
   {
      for (i=1;i<=m-1;i++)
         printf("%d ",q[i]);
      printf("%d\n",q[m]);
      return;
   }
   for (i=x+1;i<=n;i++)
   {
      if (i+m-t>n+1)
         break;
      q[t+1]=b[i];
      search(i,t+1);
   }
}
