#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[260],b[260],c[260];
int main()
{
   void count();
   int n,i,j;
   scanf("%d",&n);
   if (n==1)
      printf("1\n");
   else if (n==2)
      printf("2\n");
   else
   {
      memset(a,0,sizeof(a));
      memset(b,0,sizeof(b));
      a[0]=a[1]=b[0]=1;
      b[1]=2;
      for (i=3;i<=n;i++)
      {
         count();
         for (j=0;j<=c[0];j++)
         {
            a[j]=b[j];
            b[j]=c[j];
         }
      }
      for (i=c[0];i>=1;i--)
         printf("%d",c[i]);
      printf("\n");
   }
   system("pause");
   return(0);
}
void count()
{
   int i,x,y;
   x=0;
   for (i=1;i<=a[0];i++)
   {
      a[i]=a[i]*2+x;
      x=a[i]/10;
      a[i]%=10;
   }
   while (x!=0)
   {
      a[0]++;
      a[a[0]]=x%10;
      x/=10;
   }
   memset(c,0,sizeof(c));
   c[1]=1;
   x=0;
   if (b[0]>a[0])
      y=b[0];
   else
      y=a[0];
   for (i=1;i<=y;i++)
   {
      c[i]+=a[i]+b[i]+x;
      x=c[i]/10;
      c[i]%=10;
   }
   c[0]=y;
   while (x!=0)
   {
      c[0]++;
      c[c[0]]=x%10;
      x/=10;
   }
}
