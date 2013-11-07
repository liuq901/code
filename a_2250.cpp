#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,T,a[1010],b[1010],c[1010];
int main()
{
   bool check(int);
   while (1)
   {
      scanf("%d%d",&n,&T);
      if (!n && !T)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d%d%d",&a[i],&b[i],&c[i]);
      int l=1,r=n,ans;
      while (l<=r)
      {
         int mid=l+r>>1;
         if (check(mid))
            r=mid-1,ans=mid;
         else
            l=mid+1;
      }
      int p=0;
      for (int i=1;i<=20;i++)
         if (check(ans-i))
            p=i;
      printf("%d\n",ans-p);
   }
   system("pause");
   return(0);
}
int state[1010],time[1010];
bool check(int num)
{
   if (num<0)
      return(false);
   memset(state,0,sizeof(state));
   for (int i=1;i<=n;i++)
      time[i]=c[i]-1;
   int sum=0,tot=num;
   for (int i=0;i<=T;i++)
   {
      for (int j=1;j<=n;j++)
      {
         if (state[j]==-1)
            continue;
         time[j]++;
         if (!state[j] && time[j]==c[j])
         {
            state[j]=2;
            time[j]=0;
         }
         if (state[j]==1 && time[j]==a[j])
         {
            state[j]=-1;
            sum++;
            tot++;
            if (sum==n)
               return(true);
         }
      }
      for (int j=1;j<=n;j++)
      {
         if (state[j]!=2)
            continue;
         if (tot)
         {
            state[j]=1;
            time[j]=0;
            tot--;
         }
         else if (time[j]==b[j])
            state[j]=time[j]=0;
      }
   }
   return(false);
}
