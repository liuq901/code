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
        h%=12;
        int x=h*60+m,y=m*12;
        int ans=abs(x-y);
        if (ans>=360)
            ans=720-ans;
        if (ans&1)
            printf("%d/2\n",ans);
        else
            printf("%d\n",ans/2);
    }
    return(0);
}

