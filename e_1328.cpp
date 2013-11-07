#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int n,a[3],f[1001];
   bool t[1001];
   scanf("%d%d%d%d",&a[0],&a[1],&a[2],&n);
   for (int i=0;i<=1000;i++)
   {
      memset(t,false,sizeof(t));
      for (int j=1;j<=(i+1)/2;j++)
         for (int k=0;k<3;k++)
         {
            int x=j-1,y=i-j-a[k]+1;
            if (y>=0)
               t[f[x]^f[y]]=true;
         }
      int j=0;
      while (t[j])
         j++;
      f[i]=j;
   }
   for (int i=1;i<=n;i++)
   {
      int l;
      scanf("%d",&l);
      if (f[l]!=0)
         printf("1\n");
      else
         printf("2\n");
   }
   system("pause");
   return(0);
}
