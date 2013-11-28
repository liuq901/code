#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[21];
bool f[21][9000],g[21][9000];
int main()
{
   bool get(int,int);
   while (1)
   {
      scanf("%d",&n);
      if (n==0)
         break;
      int s;
      scanf("%d",&s);
      for (int i=1;i<=2*n;i++)
         scanf("%d",&a[i]);
      memset(g,false,sizeof(g));
      if (get(1,s))
         printf("1\n");
      else 
         printf("0\n");
   }
   system("pause");
   return(0);
}
bool get(int x,int t)
{
   if (x>2*n)
      x=1;
   if (g[x][t])
      return(f[x][t]);
   g[x][t]=true;
   if (t==0)
      f[x][t]=true;
   else if (t==1)
      f[x][t]=false;
   else
   {
      int sum=min(a[x],t);
      f[x][t]=false;
      for (int i=1;i<=sum;i++)
         if (!get(x+1,t-i))
         {
            f[x][t]=true;
            break;
         }
   }
   return(f[x][t]);
}
