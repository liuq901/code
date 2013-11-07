#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
typedef long long ll;
int k,a[19];
int main()
{
   ll calc(ll);
   int m;
   while (scanf("%d%d",&k,&m)==2)
   {
      a[0]=0;
      ll l=m,r=1LL<<60,ans=0;
      while (m)
      {
         a[++a[0]]=m%10;
         m/=10;
      }
      reverse(a+1,a+a[0]+1);
      while (l<=r)
      {
         ll mid=l+r>>1;
         ll p=calc(mid);
         if (p==k)
            ans=mid,r=mid-1;
         else if (p>k)
            r=mid-1;
         else
            l=mid+1;
      }
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
ll up;
ll calc(ll mid)
{
   ll count(int,ll);
   ll ret=0;
   up=0;
   for (int i=1;i<=a[0];i++)
   {
      ret+=count(a[i]-1,mid);
      if (ret>k)
         return(ret);
      up=up*10+a[i];
   }
   return(ret+a[0]);
}
ll count(int t,ll limit)
{
   ll ret=0,l,r;
   if (!up)
      l=1;
   else
      l=up*10;
   r=up*10+t;
   if (l>r)
      return(0);
   while (1)
   {
      if (l<0 || r<0)
         break;
      if (l>limit)
         break;
      ret+=(min(limit,r)-l+1);
      if (ret>k)
         return(ret);
      l=l*10,r=r*10+9;
   }
   return(ret);
}
