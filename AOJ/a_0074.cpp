#include <cstdio>
int main()
{
    while (1)
    {
        int h,m,s;
        scanf("%d%d%d",&h,&m,&s);
        if (h==-1 && m==-1 && s==-1)
            break;
        s=-s;
        m=-m;
        h=2-h;
        if (s<0)
        {
            m--;
            s+=60;
        }
        if (m<0)
        {
            h--;
            m+=60;
        }
        printf("%02d:%02d:%02d\n",h,m,s);
        h*=3,m*=3,s*=3;
        if (s>=60)
        {
            m+=s/60;
            s%=60;
        }
        if (m>=60)
        {
            h+=m/60;
            m%=60;
        }
        printf("%02d:%02d:%02d\n",h,m,s);
    }
    return(0);
}

