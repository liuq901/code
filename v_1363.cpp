#include <cstdio>
#include <cstdlib>
int n,i,j,sum,sum0;
int a[261]={0},b[101],d[5];
char c[101];
int main()
{
   void chen(int);
   scanf("%d%*c",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%c",&c[i]);
   }
   for (i=1;i<=n;i++)
   {
      scanf("%d%% %d%% %d%% %d%%%*c",&d[1],&d[2],&d[3],&d[4]);
      switch (c[i])
      {
      case 'A':
         b[i]=d[1];
         break;
      case 'B':
         b[i]=d[2];
         break;
      case 'C':
         b[i]=d[3];
         break;
      case 'D':
         b[i]=d[4];
         break;
      }
      if (b[i]==0)
      {
         printf("0");
         goto last;
      }
   }
   if (b[1]<10)
   {
      a[1]=b[1];
      a[0]=1;
   }
   if (b[1]>=10 && b[1]<=99)
   {
      a[1]=b[1]%10;
      a[2]=b[1]/10;
      a[0]=2;
   }
   if (b[1]==100)
   {
      a[3]=1;
      a[0]=3;
   }
   sum=2;
   for (i=2;i<=n;i++)
   {
      chen(b[i]);
      sum+=2;
   }
   if (a[sum+1]==1)
   {
      printf("1");
      goto last;
   }
   sum0=sum-a[0];
   printf("0.");
   for (i=1;i<=sum0;i++)
      printf("0");
   i=1;
   while (a[i]==0)
      i++;
   for (j=a[0];j>=i;j--)
      printf("%d",a[j]);
last:
   printf("\n");
   system("pause");
   return(0);
}
void chen(int n)
{
   int i,x;
   x=0;
   i=0;
   while (i!=a[0])
   {
      i++;
      a[i]=a[i]*n+x;
      x=a[i]/10;
      a[i]%=10;
   }
   while (x!=0)
   {
      a[0]++;
      a[a[0]]=x%10;
      x/=10;
   }
}
