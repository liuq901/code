#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int win,lose,draw;
inline ll score()
{
    return(3LL*win+draw);
}
int main()
{
    int goal,miss,n;
    scanf("%d%d%d",&goal,&miss,&n);
    ll s1,s2,s3,s4;
    s1=s2=-1,s3=s4=1LL<<60;
    lose=miss>0;
    win=min(n-lose,goal);
    draw=n-win-lose;
    s1=score();
    if (goal>=miss)
    {
        win=min(n,goal-miss);
        draw=n-win;
        lose=0;
        s2=score();
    }
    win=goal>0;
    lose=min(n-win,miss);
    draw=n-win-lose;
    s3=score();
    if (goal<=miss)
    {
        lose=min(n,miss-goal);
        draw=n-lose;
        win=0;
        s4=score();
    }
    printf("%lld %lld\n",max(s1,s2),min(s3,s4));
    return(0);
}

