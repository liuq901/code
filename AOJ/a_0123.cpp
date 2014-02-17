#include <cstdio>
const double a[]={35.5,37.5,40,43,50,55,70};
const double b[]={71,77,83,89,105,116,148};
const char ans[][5]={"AAA","AA","A","B","C","D","E"};
int main()
{
    double x,y;
    while (scanf("%lf%lf",&x,&y)==2)
    {
        bool flag=false;
        for (int i=0;i<7;i++)
            if (x<a[i] && y<b[i])
            {
                printf("%s\n",ans[i]);
                flag=true;
                break;
            }
        if (!flag)
            printf("NA\n");
    }
    return(0);
}

