#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
using namespace std;
struct data
{
   int id,time;
   data(int id,int time):id(id),time(time){}
};
bool operator <(data a,data b)
{
   return(a.time<b.time || a.time==b.time && a.id<b.id);
}
map <data,int> a;
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      a.clear();
      while (1)
      {
         string s;
         cin>>s;
         if (s=="Register")
         {
            int x,y;
            scanf("%d%d",&x,&y);
            a[data(x,y)]=y;
         }
         else if (s=="Run")
         {
            int n;
            scanf("%d",&n);
            static int id=0;
            if (id)
               printf("\n");
            printf("test case %d:\n",++id);
            for (int i=1;i<=n;i++)
            {
               printf("%d\n",a.begin()->first.id);
               data p=a.begin()->first;
               int q=a.begin()->second;
               p.time+=q;
               a.erase(a.begin());
               a[p]=q;
            }
            break;
         }
      }
   }
   system("pause");
   return(0);
}
