#include <cstdio>
const char a[7][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int zeller(int y,int m,int d)
{
    if (m<=2)
        y--,m+=12;
    int c=y/100;
    y%=100;
    int w=((c>>2)-(c<<1)+y+(y>>2)+(13*(m+1)/5)+d-1)%7;
    if (w<0)
        w+=7;
    return(w);
}
int main()
{
    while (1)
    {
        int m,d;
        scanf("%d%d",&m,&d);
        if (m==0 && d==0)
            break;
        printf("%s\n",a[zeller(2004,m,d)]);
    }
    return(0);
}

