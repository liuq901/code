#include <cstdio>
#include <cstdlib>
#include <cstring>
int b[10];
bool f[60];
int main()
{
   void search(int,int);
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      memset(f,0,sizeof(f));
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         f[x]=true;
      }
      static bool first=true;
      if (!first)
         printf("\n");
      first=false;
      search(1,1);
   }
   system("pause");
   return(0);
}
void search(int dep,int begin)
{
   if (dep==7)
   {
      for (int i=1;i<6;i++)
         printf("%d ",b[i]);
      printf("%d\n",b[6]);
      return;
   }
   for (int i=begin;i<50;i++)
      if (f[i])
      {
         b[dep]=i;
         f[i]=false;
         search(dep+1,i);
         f[i]=true;
      }
}
