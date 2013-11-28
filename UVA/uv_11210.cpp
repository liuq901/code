#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
const char word[][10]={"","DONG","NAN","XI","BEI","ZHONG","FA","BAI"};
struct mahjong
{
    int x,y;
    mahjong(){}
    mahjong(int x,int y):x(x),y(y){}
    mahjong(char *s)
    {
        if (isdigit(s[0]))
        {
            y=s[0]-'0';
            x=s[1]=='T'?0:s[1]=='S'?1:2;
            return;
        }
        x=3;
        for (int i=1;i<=7;i++)
            if (strcmp(s,word[i])==0)
            {
                y=i;
                break;
            }
    }
    mahjong prev() const
    {
        if (y==1 || x==3 || x==-1)
            return(mahjong(-1,-1));
        return(mahjong(x,y-1));
    }
    mahjong next() const
    {
        if (y==9 || x==3 || x==-1)
            return(mahjong(-1,-1));
        return(mahjong(x,y+1));
    }
    void print() const
    {
        printf(" ");
        if (x!=3)
            printf("%d%c",y,x==0?'T':x==1?'S':'W');
        else
            printf("%s",word[y]);
    }
};
inline bool operator <(const mahjong &a,const mahjong &b)
{
    return(a.x<b.x || a.x==b.x && a.y<b.y);
}
inline bool operator ==(const mahjong &a,const mahjong &b)
{
    return(a.x==b.x && a.y==b.y);
}
bool check(const mahjong &a,const mahjong &b,const mahjong &c)
{
    vector <mahjong> p;
    p.push_back(a);
    p.push_back(b);
    p.push_back(c);
    sort(p.begin(),p.end());
    return(p[0]==p[1] && p[1]==p[2] || p[0].next()==p[1] && p[1].next()==p[2]);
}
bool check(const vector <mahjong> &a)
{
    if (a.size()==0)
        return(true);
    for (int i=1;i<a.size();i++)
        for (int j=i+1;j<a.size();j++)
        {
            if (check(a[0],a[i],a[j]))
            {
                vector <mahjong> b=a;
                b.erase(b.begin()+j);
                b.erase(b.begin()+i);
                b.erase(b.begin());
                if (check(b))
                    return(true);
            }
        }
    return(false);
}
mahjong a[20];
int cnt[4][10];
bool ans[4][10];
void wait(const mahjong &a)
{
    if (a.x==-1 || cnt[a.x][a.y]==0)
        return;
    ans[a.x][a.y]=true;
}
void calc(const mahjong &a,const mahjong &b,const mahjong &c,const mahjong &d)
{
    vector <mahjong> p;
    p.push_back(a);
    p.push_back(b);
    p.push_back(c);
    p.push_back(d);
    for (int i=0;i<p.size();i++)
        for (int j=i+1;j<p.size();j++)
            if (p[i]==p[j])
            {
                int k=0;
                while (k==i || k==j)
                    k++;
                int l=6-i-j-k;
                if (p[k]==p[l])
                    wait(p[k]);
                if (p[k].next()==p[l])
                {
                    wait(p[l].next());
                    wait(p[k].prev());
                }
                if (p[k].prev()==p[l])
                {
                    wait(p[k].next());
                    wait(p[l].prev());
                }
                if (p[k].next().next()==p[l])
                    wait(p[k].next());
                if (p[k].prev().prev()==p[l])
                    wait(p[k].prev());
            }
    for (int i=0;i<p.size();i++)
        for (int j=i+1;j<p.size();j++)
            for (int k=j+1;k<p.size();k++)
                if (check(p[i],p[j],p[k]))
                {
                    int l=6-i-j-k;
                    wait(p[l]);
                }
}
char buf[20][20];
int main()
{
    while (1)
    {
        scanf("%s",buf[1]);
        if (buf[1][0]=='0')
            break;
        for (int i=2;i<=13;i++)
            scanf("%s",buf[i]);
        for (int i=1;i<=13;i++)
            a[i]=mahjong(buf[i]);
        for (int i=0;i<4;i++)
            for (int j=1;j<=9;j++)
                cnt[i][j]=4;
        for (int i=1;i<=13;i++)
            cnt[a[i].x][a[i].y]--;
        memset(ans,0,sizeof(ans));
        for (int i=1;i<=13;i++)
            for (int j=i+1;j<=13;j++)
                for (int k=j+1;k<=13;k++)
                    for (int l=k+1;l<=13;l++)
                    {
                        vector <mahjong> b;
                        for (int p=1;p<=13;p++)
                            if (p!=i && p!=j && p!=k && p!=l)
                                b.push_back(a[p]);
                        if (check(b))
                            calc(a[i],a[j],a[k],a[l]);
                    }
        static int id=0;
        printf("Case %d:",++id);
        bool flag=false;
        for (int i=0;i<=4;i++)
            for (int j=1;j<=9;j++)
                if (ans[i][j])
                {
                    flag=true;
                    mahjong(i,j).print();
                }
        if (!flag)
            printf(" Not ready");
        printf("\n");
    }
    return(0);
}

