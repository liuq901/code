#include <cstdio>
#include <algorithm>
using namespace std;
struct data
{
    int score,win,lose,id;
};
inline bool operator <(const data &a,const data &b)
{
    if (a.score!=b.score)
        return(a.score>b.score);
    if (a.win!=b.win)
        return(a.win>b.win);
    return(a.lose<b.lose || a.lose==b.lose && a.id<b.id);
}
data a[20];
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
        {
            a[i].score=a[i].win=a[i].lose=0;
            a[i].id=i;
        }
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if (z==1)
            {
                a[x].score+=3,a[y].score--;
                a[x].win++,a[y].lose++;
            }
            else if (z==-1)
            {
                a[y].score+=3,a[x].score--;
                a[y].win++,a[x].lose++;
            }
            else
                a[x].score++,a[y].score++;
        }
        sort(a+1,a+n+1);
        for (int i=1;i<=n;i++)
            printf("%d ",a[i].id);
        printf("\n");
    }
    return(0);
}

