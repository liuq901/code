#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
ll f[30][60];
int a[30];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      for (int i=1;i<=26;i++)
         scanf("%d",&a[i]);
      memset(f,0,sizeof(f));
      f[0][0]=1;
      for (int i=1;i<=26;i++)
         for (int j=0;j<=50;j++)
            for (int k=0;k<=a[i];k++)
            {
               if (k*i>j)
                  break;
               f[i][j]+=f[i-1][j-k*i];
            }
      ll ans=0;
      for (int i=1;i<=50;i++)
         ans+=f[26][i];
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
