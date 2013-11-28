#include <cstdio>
#include <cstdlib>
int ans[300];
int main()
{
   void multi(int),divide(int);
   int n,a[151];
   scanf("%d",&n);
   int s=0;
   bool flag=true;
   for (int i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      if (a[i]==0)
         flag=false;
      s+=a[i];
   }
   ans[0]=ans[1]=1;
   for (int i=1;i<=n-2;i++)
      multi(i);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=a[i]-1;j++)
         divide(j);
   if (s!=2*(n-1) || !flag && n>1)
   {
      ans[0]=1;
      ans[1]=0;
   }
   for (int i=ans[0];i>=1;i--)
      printf("%d",ans[i]);
   printf("\n");
   system("pause");
   return(0);
}
void multi(int p)
{
   int x=0;
   for (int i=1;i<=ans[0];i++)
   {
      ans[i]=ans[i]*p+x;
      x=ans[i]/10;
      ans[i]%=10;
   }
   while (x!=0)
   {
      ans[0]++;
      ans[ans[0]]=x%10;
      x/=10;
   }
}
void divide(int p)
{
   int x=0;
   for (int i=ans[0];i>=1;i--)
   {
      int s=ans[i]+10*x;
      ans[i]=s/p;
      x=s%p;
   }
   while (ans[ans[0]]==0 && ans[0]>1)
      ans[0]--;
}
