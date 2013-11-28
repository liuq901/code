#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
bool f[10010];
int a[10010];
int main()
{
   void init();
   bool check(int,int,int);
   init();
   for (int i=1;i<=a[0];i++)
      for (int j=i+1;j<=a[0];j++)
      {
         int k=(a[j]<<1)-a[i];
         if (k<10000 && !f[k] && check(a[i],a[j],k))
            printf("%d%d%d\n",a[i],a[j],k);
      }
   system("pause");
   return(0);
}
void init()
{
   f[1]=true;
   int n=10000;
   for (int i=2;i*i<=n;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=n;j++)
         f[i*j]=true;
   }
   for (int i=1000;i<n;i++)
      if (!f[i])
         a[++a[0]]=i;
}
bool check(int x,int y,int z)
{
   vector <int> a,b,c;
   for (int i=0;i<4;i++)
   {
      a.push_back(x%10);
      b.push_back(y%10);
      c.push_back(z%10);
      x/=10,y/=10,z/=10;
   }
   sort(a.begin(),a.end());
   sort(b.begin(),b.end());
   sort(c.begin(),c.end());
   for (int i=0;i<4;i++)
      if (a[i]!=b[i] || a[i]!=c[i])
         return(false);
   return(true);
}
