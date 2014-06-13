#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n,N,M,W,H;
char buf[1000000],ans[100][100];
struct piece
{
    vector <string> a;
    int x0,y0,x1,y1,x2,y2,x3,y3;
    bool up,down,left,right;
    void init()
    {
        x0=-1;
        for (int i=0;i<a.size();i++)
            for (int j=0;j<a[i].size();j++)
                if (a[i][j]!='.')
                {
                    if (x0==-1)
                        x0=i,y0=j;
                    x1=i,y1=j;
                }
        x2=-1;
        for (int j=0;j<a[0].size();j++)
            for (int i=0;i<a.size();i++)
                if (a[i][j]!='.')
                {
                    if (x2==-1)
                        x2=i,y2=j;
                    x3=i,y3=j;
                }
        up=getup();
        down=getdown();
        left=getleft();
        right=getright();
    }
    bool getup()
    {
        for (int i=0;i<a.size();i++)
            for (int j=0;j<a[i].size();j++)
                if (a[i][j]!='.')
                {
                    for (int k=0;k<H;k++)
                        if (a[i][j+k]=='.')
                            return(false);
                    return(true);
                }
        return(false);
    }
    bool getdown()
    {
        for (int i=a.size()-1;i>=0;i--)
            for (int j=0;j<a[i].size();j++)
                if (a[i][j]!='.')
                {
                    for (int k=0;k<H;k++)
                        if (a[i][j+k]=='.')
                            return(false);
                    return(true);
                }
        return(false);
    }
    bool getleft()
    {
        for (int j=0;j<a[0].size();j++)
            for (int i=0;i<a.size();i++)
                if (a[i][j]!='.')
                {
                    for (int k=0;k<W;k++)
                        if (a[i+k][j]=='.')
                            return(false);
                    return(true);
                }
        return(false);
    }
    bool getright()
    {
        for (int j=a[0].size()-1;j>=0;j--)
            for (int i=0;i<a.size();i++)
                if (a[i][j]!='.')
                {
                    for (int k=0;k<W;k++)
                        if (a[i+k][j]=='.')
                            return(false);
                    return(true);
                }
        return(false);
    }
    bool fill(int sx,int sy,int x0,int y0)
    {
        for (int i=0;i<a.size();i++)
            for (int j=0;j<a[i].size();j++)
            {
                if (a[i][j]=='.')
                    continue;
                int x=i-x0+sx,y=j-y0+sy;
                if (x<=0 || x>N || y<=0 || y>M || ans[x][y]!='.')
                    return(false);
                ans[x][y]=a[i][j];
            }
        return(true);
    }
};
piece a[20];
int c1,c2,c3,c4;
vector <int> e1,e2,e3,e4,c;
void find(int &x,int &y)
{
    for (int i=1;i<=N;i++)
        for (int j=1;j<=M;j++)
            if (ans[i][j]=='.')
            {
                x=i,y=j;
                return;
            }
}
void recover(int x)
{
    char ch=x+'A'-1;
    for (int i=1;i<=N;i++)
        for (int j=1;j<=M;j++)
            if (ans[i][j]==ch)
                ans[i][j]='.';
}
bool C()
{
    while (1)
    {
        bool flag=true;
        for (int i=0;i<c.size();i++)
        {
            int x=c[i],x0=-1,y0=-1;
            find(x0,y0);
            if (!a[x].fill(x0,y0,a[x].x0,a[x].y0))
            {
                flag=false;
                break;
            }
        }
        if (flag)
            return(true);
        for (int i=0;i<c.size();i++)
            recover(c[i]);
        if (!next_permutation(c.begin(),c.end()))
            break;
    }
    return(false);
}
bool E4()
{
    while (1)
    {
        bool flag=true;
        for (int i=0;i<e4.size();i++)
        {
            int x=e4[i];
            if (!a[x].fill(N,(i+2)*H,a[x].x1,a[x].y1))
            {
                flag=false;
                break;
            }
        }
        if (flag && C())
            return(true);
        for (int i=0;i<e4.size();i++)
            recover(e4[i]);
        if (!next_permutation(e4.begin(),e4.end()))
            break;
    }
    return(false);
}
bool E3()
{
    while (1)
    {
        bool flag=true;
        for (int i=0;i<e3.size();i++)
        {
            int x=e3[i];
            if (!a[x].fill((i+2)*W,M,a[x].x3,a[x].y3))
            {
                flag=false;
                break;
            }
        }
        if (flag && E4())
            return(true);
        for (int i=0;i<e3.size();i++)
            recover(e3[i]);
        if (!next_permutation(e3.begin(),e3.end()))
            break;
    }
    return(false);
}
bool E2()
{
    while (1)
    {
        bool flag=true;
        for (int i=0;i<e2.size();i++)
        {
            int x=e2[i];
            if (!a[x].fill((i+1)*W+1,1,a[x].x2,a[x].y2))
            {
                flag=false;
                break;
            }
        }
        if (flag && E3())
            return(true);
        for (int i=0;i<e2.size();i++)
            recover(e2[i]);
        if (!next_permutation(e2.begin(),e2.end()))
            break;
    }
    return(false);
}
void E1()
{
    while (1)
    {
        bool flag=true;
        for (int i=0;i<e1.size();i++)
        {
            int x=e1[i];
            if (!a[x].fill(1,(i+1)*H+1,a[x].x0,a[x].y0))
            {
                flag=false;
                break;
            }
        }
        if (flag && E2())
            return;
        for (int i=0;i<e1.size();i++)
            recover(e1[i]);
        next_permutation(e1.begin(),e1.end());
    }
}
void work()
{
    a[c1].fill(1,1,a[c1].x0,a[c1].y0);
    if (n>1)
    {
        a[c2].fill(1,M-H+1,a[c2].x0,a[c2].y0);
        a[c3].fill(N,H,a[c3].x1,a[c3].y1);
        a[c4].fill(N,M,a[c4].x1,a[c4].y1);
    }
    if (n>2)
        E1();
}
int main()
{
    freopen("ascii.in","r",stdin);
    freopen("ascii.out","w",stdout);
    int k;
    scanf("%d%d%d",&k,&H,&W);
    for (int i=1;;i++)
        if (i*i==k)
        {
            n=i;
            break;
        }
    N=n*W;
    M=n*H;
    for (int i=1;i<=k;i++)
    {
        for (int j=1;j<=3*W-2;j++)
        {
            scanf("%s",buf);
            a[i].a.push_back(buf);
        }
        a[i].init();
        if (a[i].up && a[i].left)
            c1=i;
        else if (a[i].up && a[i].right)
            c2=i;
        else if (a[i].down && a[i].left)
            c3=i;
        else if (a[i].down && a[i].right)
            c4=i;
        else if (a[i].up)
            e1.push_back(i);
        else if (a[i].left)
            e2.push_back(i);
        else if (a[i].right)
            e3.push_back(i);
        else if (a[i].down)
            e4.push_back(i);
        else
            c.push_back(i);
    }
    sort(e1.begin(),e1.end());
    sort(e2.begin(),e2.end());
    sort(e3.begin(),e3.end());
    sort(e4.begin(),e4.end());
    sort(c.begin(),c.end());
    memset(ans,'.',sizeof(ans));
    work();
    printf("%d %d\n",M,N);
    for (int i=1;i<=N;i++)
    {
        for (int j=1;j<=M;j++)
            printf("%c",ans[i][j]);
        printf("\n");
    }
    return(0);
}

