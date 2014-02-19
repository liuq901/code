#include <cstdio>
const double a[]={1.1,0.6,0.2,-1};
int l[4],r[4];
int get(double x)
{
    for (int i=0;i<4;i++)
        if (x>=a[i])
            return(i);
}
int main()
{
    double x,y;
    while (scanf("%lf%lf",&x,&y)==2)
        l[get(x)]++,r[get(y)]++;
    for (int i=0;i<4;i++)
        printf("%d %d\n",l[i],r[i]);
    return(0);
}

