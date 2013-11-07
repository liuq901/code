#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,a[26],sg[26];
int main()
{
   void init(),work(int);
   init();
   while (1)
   {
      scanf("%d",&n);
      if (!n)
         break;
      int x=0;
      for (int i=1;i<=n;i++)
      {
         scanf("%d",&a[i]);
         if (a[i]&1)
            x^=sg[n-i];
      }
      work(x);
   }
   system("pause");
   return(0);
}
void init()
{
   bool f[100];
   sg[0]=0;
   for (int i=1;i<=22;i++)
   {
      memset(f,0,sizeof(f));
      for (int j=0;j<i;j++)
         for (int k=j;k<i;k++)
            f[sg[j]^sg[k]]=true;
      int k=0;
      while (f[k])
         k++;
      sg[i]=k;
   }
}
void work(int x)
{
   static int id=0;
   id++;
   for (int i=1;i<=n;i++)
   {
      if (!a[i])
         continue;
      for (int j=i+1;j<=n;j++)
         for (int k=j;k<=n;k++)
            if (!(x^sg[n-i]^sg[n-j]^sg[n-k]))
            {
               printf("Game %d: %d %d %d\n",id,i-1,j-1,k-1);
               return;
            }
   }
   printf("Game %d: -1 -1 -1\n",id);
}
