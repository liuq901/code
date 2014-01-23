#include <cstdio>
struct date
{
    int y,m,d;
    date(){}
    date(int y,int m,int d):y(y),m(m),d(d){}
    bool in()
    {
        return(scanf("%d%d%d",&y,&m,&d)==3);
    }
};
inline bool operator <=(const date &a,const date &b)
{
    return(a.y<b.y || a.y==b.y && (a.m<b.m || a.m==b.m && a.d<=b.d));
}
const date meiji(1868,9,8);
const date taisho(1912,7,30);
const date showa(1926,12,25);
const date heisei(1989,1,8);
int main()
{
    date now;
    while (now.in())
        if (heisei<=now)
            printf("heisei %d %d %d\n",now.y-heisei.y+1,now.m,now.d);
        else if (showa<=now)
            printf("showa %d %d %d\n",now.y-showa.y+1,now.m,now.d);
        else if (taisho<=now)
            printf("taisho %d %d %d\n",now.y-taisho.y+1,now.m,now.d);
        else if (meiji<=now)
            printf("meiji %d %d %d\n",now.y-meiji.y+1,now.m,now.d);
        else
            printf("pre-meiji\n");
    return(0);
}

