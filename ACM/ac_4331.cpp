#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <set>
using namespace std;
vector <pair <int,int> > request[3610];
vector <int> move[60],time[60];
int run,pos,a[60];
bool open,stop;
multiset <int> S;
void init()
{
    for (int i=0;i<=3600;i++)
        request[i].clear();
    for (int i=1;i<=50;i++)
    {
        move[i].clear();
        time[i].clear();
    }
    S.clear();
    memset(a,0,sizeof(a));
    run=0;
    open=false;
    stop=true;
}
bool outside()
{
    for (int i=0;i<move[pos].size();i++)
        if (run==1 && move[pos][i]>pos || run==-1 && move[pos][i]<pos)
            return(true);
    return(false);
}
bool have(int run)
{
    if (run==1)
    {
        for (int i=pos+1;i<=50;i++)
            if (!move[i].empty())
                return(true);
    }
    else
        for (int i=pos-1;i;i--)
            if (!move[i].empty())
                return(true);
    return(false);
}
void changeState()
{
    for (int i=1;i<=50;i++)
        if (i!=pos && a[i])
            return;
    if (outside() || have(run))
        return;
    run=-run;
    if (outside() || have(run))
        return;
    run=0;
}
int getDir()
{
    if (S.empty())
        return(0);
    int t=*S.begin();
    bool up,down;
    up=down=false;
    for (int i=0;i<move[pos].size();i++)
    {
        if (time[pos][i]==t && move[pos][i]>pos)
            up=true;
        if (time[pos][i]==t && move[pos][i]<pos)
            down=true;
    }
    if (up)
        return(1);
    if (down)
        return(-1);
    for (int i=pos+1;i<=50;i++)
        for (int j=0;j<move[i].size();j++)
            if (time[i][j]==t)
                return(1);
    for (int i=pos-1;i;i--)
        for (int j=0;j<move[i].size();j++)
            if (time[i][j]==t)
                return(-1);
    return(0);
}
void Open(int t)
{
    printf("%02d:%02d The elevator door is opening.\n",t/60,t%60);
    open=true;
}
void Close(int t)
{
    printf("%02d:%02d The elevator door is closing.\n",t/60,t%60);
    open=false;
}
void Move(int t)
{
    printf("%02d:%02d The elevator starts to move %s from floor %d.\n",t/60,t%60,run==1?"up":"down",pos);
    stop=false;
}
void Stop(int t)
{
    printf("%02d:%02d The elevator stops at floor %d.\n",t/60,t%60,pos);
    stop=true;
}
void GoIn(int t)
{
    int tot=0;
    for (int i=0;i<move[pos].size();i++)
        if (run==1 && move[pos][i]>pos || run==-1 && move[pos][i]<pos)
        {
            tot++;
            a[move[pos][i]]++;
            S.erase(S.find(time[pos][i]));
            move[pos].erase(move[pos].begin()+i);
            time[pos].erase(time[pos].begin()+i);
            i--;
        }
    printf("%02d:%02d %d people enter the elevator.\n",t/60,t%60,tot);
}
void GoOut(int t)
{
    printf("%02d:%02d %d people leave the elevator.\n",t/60,t%60,a[pos]);
    a[pos]=0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        init();
        int n;
        scanf("%d%d",&pos,&n);
        for (int i=1;i<=n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            request[x].push_back(make_pair(y,z));
        }
        static int id=0;
        printf("Case %d:\n",++id);
        for (int t=0;t<=3600;t++)
        {
            for (int i=0;i<request[t].size();i++)
            {
                move[request[t][i].first].push_back(request[t][i].second);
                time[request[t][i].first].push_back(t);
                S.insert(t);
            }
            if (run==0)
                run=getDir();
            if (open)
            {
                if (a[pos]!=0)
                    GoOut(t);
                else if (outside())
                    GoIn(t);
                else
                    Close(t);
            }
            else if (a[pos]!=0 || outside())
            {
                if (!stop)
                    Stop(t);
                Open(t);
            }
            else if (run)
            {
                if (stop)
                    Move(t);
                pos+=run;
                changeState();
            }
        }
        printf("\n");
    }
    return(0);
}

