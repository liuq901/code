#include <algorithm>
using namespace std;
struct FoxPlayingGame
{
   double theMax(int nA,int nB,int paramA,int paramB)
   {
      double A=paramA/1000.0,B=paramB/1000.0,ans=nA*A,now=ans;
      for (int i=1;i<=nB;i++)
      {
         now*=B;
         ans=max(ans,now);
      }
      return(ans);
   }
};
int main(){}
