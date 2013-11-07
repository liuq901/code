#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[1000010],b[1000010];
int main()
{
   void init();
   init();
   while (1)
   {
      int l,r;
      scanf("%d%d",&l,&r);
      if (l==-1 && r==-1)
         break;
      printf("%d %d ",l,r);
      l=max(l,1),r=max(r,1);
      printf("%d %d\n",a[r]-a[l-1],b[r]-b[l-1]);
   }
   system("pause");
   return(0);
}
bool f[1000010];
void init()
{
   f[0]=f[1]=true;
   for (int i=2;i<=1000;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=1000000;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=1000000;i++)
   {
      a[i]=a[i-1],b[i]=b[i-1];
      if (f[i])
         continue;
      a[i]++;
      b[i]+=i==2 || i%4==1;
   }
}
