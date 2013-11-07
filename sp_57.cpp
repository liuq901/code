#include <cstdio>
#include <cstdlib>
#include <cstring>
int t,a[100001],l[100001],r[100001],f[100001];
bool flag[100001];
int main()
{
   int find(int),search(int);
   for (int test=1;test<=10;test++)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      f[0]=-1<<30;
      t=0;
      for (int i=1;i<=n;i++)
      {
         int k=find(a[i]);
         if (k==t)
         {
            t++;
            f[t]=a[i];
         }
         else if (a[i]<f[k+1])
            f[k+1]=a[i];
         l[i]=k+1;
      }
      f[0]=1<<30;
      t=0;
      for (int i=n;i>=1;i--)
      {
         int k=search(a[i]);
         if (k==t)
         {
            t++;
            f[t]=a[i];
         }
         else if (a[i]>f[k+1])
            f[k+1]=a[i];
         r[i]=k+1;
      }
      memset(flag,0,sizeof(flag));
      int sum=0;
      for (int i=1;i<=n;i++)
         if (l[i]+r[i]==t+1)
         {
            sum++;
            flag[a[i]]=true;
         }
      printf("%d\n",sum);
      t=0;
      for (int i=1;i<=n;i++)
         if (flag[i])
         {
            t++;
            printf("%d",i);
            if (t==sum)
            {
               printf("\n");
               break;
            }
            printf(" ");
         }
   }
   system("pause");
   return(0);
}
int find(int x)
{
   int l=0,r=t,ans;
   while (l<=r)
   {
      int mid=l+r>>1;
      if (f[mid]<x)
      {
         l=mid+1;
         ans=mid;
      }
      else
         r=mid-1;
   }
   return(ans);
}
int search(int x)
{
   int l=0,r=t,ans;
   while (l<=r)
   {
      int mid=l+r>>1;
      if (f[mid]>x)
      {
         l=mid+1;
         ans=mid;
      }
      else
         r=mid-1;
   }
   return(ans);
}
