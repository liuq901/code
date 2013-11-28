#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
struct SpeedRadar
{
   double averageSpeed(int min,int max,vector <int> a)
   {
      int s=0,sum=0;
      for (int i=0;i<a.size();i++)
         if (a[i]>=min && a[i]<=max)
            s++,sum+=a[i];
      if (double(a.size())/(a.size()-s)<10)
         return(0);
      return(double(sum)/s);
   }
};
int main()
{
   int min,max;
   scanf("%d%d",&min,&max);
   int x;
   vector <int> a;
   while (scanf("%d",&x)!=EOF)
      a.push_back(x);
   SpeedRadar p;
   printf("%.10lf\n",p.averageSpeed(min,max,a));
   system("pause");
   return(0);
}
