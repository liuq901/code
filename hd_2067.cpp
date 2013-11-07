#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
   ll a[40][40];
   a[0][0]=0,a[0][1]=1,a[1][1]=2;
   for (int i=2;i<=35;i++)
   {
      a[i][0]=1;
      for (int j=1;j<i-1;j++)
         a[i][j]=a[i][j-1]+a[i-1][j];
      a[i][i-1]=a[i][i-2]+a[i-1][i-1]/2;
      a[i][i]=2*a[i][i-2]+a[i-1][i-1];
   }
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (n==-1)
         break;
      static int id=0;
      cout<<++id<<" "<<n<<" "<<a[n][n]<<endl;
   }
   system("pause");
   return(0);
}
