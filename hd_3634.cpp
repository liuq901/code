#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
struct rect
{
   int x1,y1,x2,y2,value;
};
bool operator <(rect a,rect b)
{
   return(a.value<b.value);
}
rect a[100];
set <int> p;
map <int,int> x,y;
typedef set <int>::iterator data;
typedef map <int,int>::iterator Data;
typedef long long ll;
int X[100],Y[100],value[100][100];
int main()
{
   int t,id=0;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2,&a[i].value);
      sort(a+1,a+n+1);
      x.clear(),y.clear();
      p.clear();
      for (int i=1;i<=n;i++)
         p.insert(a[i].x1),p.insert(a[i].x2);
      int t=0;
      for (data k=p.begin();k!=p.end();k++)
         x[*k]=++t;
      p.clear();
      for (int i=1;i<=n;i++)
         p.insert(a[i].y1),p.insert(a[i].y2);
      t=0;
      for (data k=p.begin();k!=p.end();k++)
         y[*k]=++t;
      int N=x.size(),M=y.size();
      for (Data k=x.begin();k!=x.end();k++)
         X[k->second]=k->first;
      for (Data k=y.begin();k!=y.end();k++)
         Y[k->second]=k->first;
      memset(value,0,sizeof(value));
      for (int i=1;i<=n;i++)
         for (int j=x[a[i].x1]+1;j<=x[a[i].x2];j++)
            for (int k=y[a[i].y1]+1;k<=y[a[i].y2];k++)
               value[j][k]=a[i].value;
      ll ans=0;
      for (int i=2;i<=N;i++)
         for (int j=2;j<=M;j++)
            ans+=ll(value[i][j])*(X[i]-X[i-1])*(Y[j]-Y[j-1]);
      cout<<"Case "<<++id<<": "<<ans<<endl;
   }
   system("pause");
   return(0);
}
