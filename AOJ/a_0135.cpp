#include <cstdio>
#include <cstdlib>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int h,m;
        scanf("%d:%d",&h,&m);
        int x=h*60+m;
        int y=m*12;
        int delta=abs(x-y);
        if (delta>=360)
            delta=720-delta;
        printf("%s\n",delta<60?"alert":delta<180?"warning":"safe");
    }
    return(0);
}

