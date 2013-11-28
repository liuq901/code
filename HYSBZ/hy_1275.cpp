#include <cstdio>
#include <cstdlib>
#include <cstring>
const int p=1000;
int b[501],c[501],f[301][501],a[301][301][501];
int main()
{
   void cheng(int *,int *,int),gjcheng(int *,int *,int *),chu(int *,int),jia(int *,int *);
   int i,j,k,n;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      a[i][0][0]=1;
      a[i][0][1]=1;
      for (j=1;j<=i;j++)
         cheng(a[i][j],a[i][j-1],i-j+1);
   }
   f[0][0]=1;
   f[0][1]=1;
   for (i=1;i<=n;i++)
   {
      memcpy(f[i],f[i-1],sizeof(f[i-1]));
      for (j=1;j<=i-1;j++)
      {
         cheng(b,a[i-1][j],j+1);
         gjcheng(b,b,f[i-j-1]);
         chu(b,2);
         jia(f[i],b);
         if (j>1 && (j+1)%3!=0)
         {
            gjcheng(b,a[i-1][j],f[i-j-1]);
            chu(b,2);
            jia(f[i],b);
         }
      }
   }
   printf("%d",f[n][f[n][0]]);
   for (i=f[n][0]-1;i>=1;i--)
   {
      j=f[n][i];
      printf("%d",j/100);
      j%=100;
      printf("%d",j/10);
      j%=10;
      printf("%d",j);
   }
   printf("\n");
   system("pause");
   return(0);
}
void cheng(int *ans,int *a,int n)
{
   int i,l;
   int b[501];
   l=a[0];
   memset(b,0,sizeof(b));
   for (i=1;i<=l;i++)
      b[i]=a[i]*n;
   for (i=1;i<=l;i++)
   {
      b[i+1]+=b[i]/p;
      b[i]=b[i]%p;
   }
   while (b[l+1]>0)
   {
      l++;
      b[l+1]=b[l]/p;
      b[l]%=p;
   }
   b[0]=l;
   memcpy(ans,b,sizeof(b));
}
void gjcheng(int *ans,int *a,int *b)
{
   int i,j,l;
   int c[501];
   memset(c,0,sizeof(c));
   for (i=1;i<=a[0];i++)
      for (j=1;j<=b[0];j++)
         c[i+j-1]+=a[i]*b[j];
   l=i+j-1;
   for (i=1;i<=l;i++)
   {
      c[i+1]+=c[i]/p;
      c[i]%=p;
   }
   while (c[l+1]>0)
   {
      l++;
      c[l+1]=c[l]/p;
      c[l]%=p;
   }
   c[0]=l;
   memcpy(ans,c,sizeof(c));
}
void chu(int *a,int n)
{
   int i,j;
   j=0;
   for (i=a[0];i>=1;i--)
   {
      j=j*p+a[i];
      a[i]=j/n;
      j%=n;
   }
   while (a[0]>0 && a[a[0]]==0)
      a[0]--;
}
void jia(int *a,int *b)
{
   int i,x,l;
   l=a[0];
   if (b[0]>l)
      l=b[0];
   x=0;
   for (i=1;i<=l;i++)
   {
      a[i]+=b[i]+x;
      x=a[i]/p;
      a[i]%=p;
   }
   while (x>0)
   {
      l++;
      a[l]=x%p;
      x/=p;
   }
   a[0]=l;
}

