#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
const int N=110;
struct kill
{
    int t,x,y;
    kill(){}
    kill(int t,int x,int y):t(t),x(x),y(y){}
};
inline bool operator <(const kill &a,const kill &b)
{
    return(a.t<b.t);
}
map <string,int> M;
kill a[N];
int f[N],b[N][2];
string s[N];
char buf[10000];
int hash(const string &S)
{
    if (!M.count(S))
    {
        int id=M.size()+1;
        M[S]=id;
        s[id]=S;
    }
    return(M[S]);
}
void FB(int id)
{
    printf("%s just drew First Blood!\n",s[id].c_str());
}
bool check(int x,int y)
{
    if (x==-1)
        return(false);
    return(y-x<=14);
}
void work(int id,int t)
{
    if (f[id]>=3)
        printf("%s ",s[id].c_str());
    if (f[id]==3)
        printf("has a Killing Spree!\n");
    else if (f[id]==4)
        printf("is Dominating!\n");
    else if (f[id]==5)
        printf("has a Mega Kill!\n");
    else if (f[id]==6)
        printf("is Unstoppable!\n");
    else if (f[id]==7)
        printf("is Wicked Sick!\n");
    else if (f[id]==8)
        printf("has a Monster Kill!!!\n");
    else if (f[id]==9)
        printf("is Godlike!\n");
    else if (f[id]>=10)
        printf("is Beyond Godlike! Somebody kill him!!\n");
    if (check(b[id][1],t))
        if (check(b[id][0],b[id][1]))
            printf("%s just got a Triple Kill!\n",s[id].c_str());
        else
            printf("%s just got a Double Kill!\n",s[id].c_str());
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int min,sec,n=0;
        M.clear();
        while (scanf("%d:%d",&min,&sec)==2)
        {
            scanf("%s",buf);
            int x=hash(buf);
            scanf("%*s%s",buf);
            int y=hash(buf);
            a[++n]=kill(min*60+sec,x,y);
        }
        sort(a+1,a+n+1);
        memset(f,0,sizeof(f));
        memset(b,-1,sizeof(b));
        for (int i=1;i<=n;i++)
        {
            if (i==1)
                FB(a[i].x);
            f[a[i].x]++;
            f[a[i].y]=0;
            work(a[i].x,a[i].t);
            b[a[i].x][0]=b[a[i].x][1];
            b[a[i].x][1]=a[i].t;
        }
        scanf("%*s");
        printf("\n");
    }
    return(0);
}

