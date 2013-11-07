#include <cstdio>
#include <cstdlib>
#include <cstring>
int ans,a[7],p[6][7];
int main()
{
   void init(),work(int);
   int t;
   scanf("%d",&t);
   init();
   while (t--)
   {
      memset(a,0,sizeof(a));
      for (int i=1;i<=12;i++)
      {
         int x;
         scanf("%d",&x);
         a[x]++;
      }
      ans=0;
      for (int i=1;i<=5;i++)
         work(i);
      printf("%d\n",ans/24);
   }
   system("pause");
   return(0);
}
void init()
{
   p[1][0]=1,p[1][1]=12;
   p[2][0]=6,p[2][4]=3;
   p[3][0]=3,p[3][2]=6;
   p[4][0]=6,p[4][1]=2,p[4][2]=5;
   p[5][0]=8,p[5][3]=4;
}
int sum;
void work(int n)
{
   void search(int,int);
   sum=0;
   search(1,n);
   ans+=sum*p[n][0];
}
void search(int dep,int n)
{
   if (dep==13)
   {
      sum++;
      return;
   }
   int t=6;
   while (!p[n][t])
      t--;
   if (!t)
      return;
   for (int i=1;i<=6;i++)
   {
      if (a[i]<t)
         continue;
      p[n][t]--;
      a[i]-=t;
      search(dep+t,n);
      p[n][t]++;
      a[i]+=t;
   }
}
