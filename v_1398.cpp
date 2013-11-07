#include <cstdio>
#include <cstdlib>
int a[301],b[301],c[301];
int i,j;
int main()
{
   int n,x,y;
   void change(); 
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      scanf("%d%d",&x,&y);
      b[i]=a[i]+x+y;
      c[i]=i;
   }
   for (i=1;i<=n-1;i++)
      for (j=i+1;j<=n;j++)
      {
         if (b[i]<b[j])
            change();
         if (b[i]==b[j] && a[i]<a[j])
            change();
         if (b[i]==b[j] && a[i]==a[j] && c[i]>c[j]) 
            change();
      }
   for (i=1;i<=5;i++)
      printf("%d %d\n",c[i],b[i]);
   system("pause");
   return(0);
}
void change()
{
   int t;
   t=a[i],a[i]=a[j],a[j]=t;
   t=b[i],b[i]=b[j],b[j]=t;
   t=c[i],c[i]=c[j],c[j]=t;
}
