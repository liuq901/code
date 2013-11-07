#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct team
{
   string name;
   int solved,time;
};
bool operator <(team a,team b)
{
   return(a.solved>b.solved || a.solved==b.solved && (a.time<b.time || a.time==b.time && a.name<b.name));
}
team a[1010];
int main()
{
   int n,m;
   while (scanf("%d%d",&n,&m)==2)
   {
      for (int i=1;i<=n;i++)
      {
         cin>>a[i].name;
         a[i].solved=a[i].time=0;
         for (int j=1;j<=m;j++)
         {
            int t;
            scanf("%d",&t);
            if (t)
            {
               a[i].solved++;
               a[i].time+=t;
               int x;
               scanf("%d",&x);
               a[i].time+=(x-1)*20;
            }
         }
      }
      sort(a+1,a+n+1);
      for (int i=1;i<=n;i++)
         printf("rank = %d , name = %s , solve = %d , time = %d\n",i,a[i].name.c_str(),a[i].solved,a[i].time);
   }
   system("pause");
   return(0);
}
