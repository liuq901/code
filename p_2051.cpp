#include <cstdio>
#include <set>
using namespace std;
struct data
{
    int id,now,t;
    data(int id,int t):id(id),now(t),t(t){}
    void next()
    {
        now+=t;
    }
};
bool operator <(data a,data b)
{
    return(a.now<b.now || a.now==b.now && a.id<b.id);
}
set <data> s;
char buf[10000];
int main()
{
    while (1)
    {
        scanf("%s",buf);
        if (buf[0]=='#')
            break;
        int x,y;
        scanf("%d%d",&x,&y);
        s.insert(data(x,y));
    }
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        data tmp=*s.begin();
        s.erase(s.begin());
        printf("%d\n",tmp.id);
        tmp.next();
        s.insert(tmp);
    }
    return(0);
}

