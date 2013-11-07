#include <cstdio>
#include <cstdlib>
typedef long long ll;
ll a[100000];
int ans[100000];
int main()
{
   a[1]=1;
   for (int i=2;i<100000;i++)
      a[i]=a[i-1]+i;
   int L;
   while (scanf("%d",&L)==1)
   {
      int now=1;
      L--;
      ans[0]=0;
      while (L)
      {
         if (a[now+1]<=L)
            now++;
         else if (a[now]>L)
            now--;
         ans[++ans[0]]=now;
         L-=now;
      }
      for (int i=ans[0];i;i--)
         printf("%d ",ans[i]);
      printf("1\n");
   }
   system("pause");
   return(0);
}
