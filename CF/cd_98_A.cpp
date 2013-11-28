#include <cstdio>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
set <string> a;
char buf[10];
const int c[7][4]={{0},{2,3,5,6},{6,4,3,1},{5,1,2,4},{2,6,5,3},{6,1,3,4},{4,2,1,5}};
int calc(int x)
{
    return(x<=3?x+3:x-3);
}
void work(string s)
{
    string q;
    q.resize(6);
    for (int i=1;i<=6;i++)
        for (int j=0;j<4;j++)
        {
            int x=i,y=c[i][j],z=c[i][(j+1)%4];
            q[0]=s[x-1],q[1]=s[y-1],q[2]=s[z-1],q[3]=s[calc(x)-1],q[4]=s[calc(y)-1],q[5]=s[calc(z)-1];
            a.insert(q);
        }
}
int main()
{
    scanf("%s",buf);
    string s(buf);
    sort(s.begin(),s.end());
    int ans=0;
    while (1)
    {
        if (!a.count(s))
        {
            ans++;
            work(s);
        }
        if (!next_permutation(s.begin(),s.end()))
            break;
    }
    printf("%d\n",ans);
    return(0);
}

