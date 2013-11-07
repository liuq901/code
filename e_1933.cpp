#include <cstdio>
#include <string>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double x;
        char buf[10];
        scanf("%lf%s",&x,buf);
        string s=buf;
        static int id=0;
        printf("%d ",++id);
        if (s=="kg")
            printf("%.4f lb\n",x*2.2046);
        else if (s=="lb")
            printf("%.4f kg\n",x*0.4536);
        else if (s=="l")
            printf("%.4f g\n",x*0.2642);
        else
            printf("%.4f l\n",x*3.7854);
    }
    return(0);
}

