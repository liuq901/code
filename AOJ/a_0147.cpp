#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int seat[17],eat[100];
queue <int> wait;
inline int arrive_time(int x)
{
    return(x*5);
}
inline int people_num(int x)
{
    return(x%5==1?5:2);
}
inline int eat_time(int x)
{
    return(17*(x%2)+3*(x%3)+19);
}
void leave(int t)
{
    for (int i=0;i<17;i++)
    {
        if (seat[i]==-1)
            continue;
        if (t-eat[seat[i]]==eat_time(seat[i]))
            seat[i]=-1;
    }
}
void arrive(int t)
{
    if (t%5==0 && t/5<100)
        wait.push(t/5);
}
void waiting(int t)
{
    while (!wait.empty())
    {
        int x=wait.front();
        bool flag=false;
        for (int i=0;i<17;i++)
            if (i+people_num(x)<=17 && count(seat+i,seat+i+people_num(x),-1)==people_num(x))
            {
                eat[x]=t;
                fill(seat+i,seat+i+people_num(x),x);
                flag=true;
                wait.pop();
                break;
            }
        if (!flag)
            break;
    }
}
void init()
{
    fill(seat,seat+17,-1);
    for (int i=0;i<10000;i++)
    {
        leave(i);
        arrive(i);
        waiting(i);
    }
}
int main()
{
    init();
    int n;
    while (scanf("%d",&n)==1)
        printf("%d\n",eat[n]-arrive_time(n));
    return(0);
}

