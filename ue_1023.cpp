#include <cstdio>
inline int calc(int x)
{
    return((x>=60)+(x>=70)+(x>=80)+(x>=90));
}
int main()
{
    int n;
    scanf("%d",&n);
    int s1=0,s2=0;
    for (int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        s1+=x,s2+=x*calc(y);
    }
    printf("%.2f\n",double(s2)/s1);
    return(0);
}

