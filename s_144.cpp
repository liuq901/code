#include <cstdio>
#include <cstdlib>
int main()
{
   double x,y,z,t,ans;
   scanf("%lf%lf%lf",&x,&y,&z);
   t=(y-x)*60;
   ans=(t-z)*(t-z);
   ans/=t*t;
   printf("%.7lf\n",1-ans);
   system("pause");
   return(0);
}
