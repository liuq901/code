#include <cstdio>
bool leap(int y)
{
    if (y%400==0)
        return(true);
    if (y%100==0)
        return(false);
    return(y%4==0);
}
int get(int y,int m)
{
    if (m==2)
        return(28+leap(y));
    if (m==4 || m==6 || m==9 || m==11)
        return(30);
    return(31);
}
int main()
{
    int y,m,d;
    scanf("%d%d%d",&y,&m,&d);
    int ans=0;
    for (int i=1;i<m;i++)
        ans+=get(y,i);
    printf("%d\n",ans+d);
    return(0);
}

