#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[1500];
int main()
{
   int calc(int,int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      memset(a,0,sizeof(a));
      for (int i=1;i<=n;i++)
      {
         int x1,y1,x2,y2;
         scanf("%d:%d %d:%d",&x1,&y1,&x2,&y2);
         int p=calc(x1,y1),q=calc(x2,y2);
         for (int j=p;j<=q;j++)
            a[j]++;
      }
      int ans=-1,begin,end;
      for (int i=0;i<1440;i++)
         if (a[i]>ans)
         {
            ans=a[i];
            begin=i;
         }
      for (int i=begin;i<1440;i++)
      {
         if (a[i]!=ans)
            break;
         end=i;
      }
      int x1,y1,x2,y2;
      x1=begin/60,y1=begin%60,x2=end/60,y2=end%60;
      printf("%02d:%02d %02d:%02d\n",x1,y1,x2,y2);
   }
   system("pause");
   return(0);
}
int calc(int h,int m)
{
   return(h*60+m);
}
