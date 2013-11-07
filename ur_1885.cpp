#include <cstdio>
int main()
{
    int h,t,v,x;
    scanf("%d%d%d%d",&h,&t,&v,&x);
    if (h<=t*x)
        printf("%.10f %.10f\n",0.0,double(h)/x);
    else
        printf("%.10f %.10f\n",double(h-x*t)/(v-x),double(t));
    return(0);
}

