#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
struct player
{
    int num,year,pos;
    string name;
    void print()
    {
        char ch;
        if (pos==0)
            ch='G';
        else if (pos==1)
            ch='D';
        else if (pos==2)
            ch='M';
        else
            ch='S';
        printf("%d %s %c\n",num,name.c_str(),ch);
    }
};
inline bool operator <(const player &a,const player &b)
{
    return(a.pos<b.pos || a.pos==b.pos && a.num<b.num);
}
char buf[100000];
player a[30],ans[30];
int tot;
player get(char *buf)
{
    stringstream sin(buf);
    player ret;
    char ch;
    sin>>ret.num>>ret.name>>ch;
    if (ch=='G')
        ret.pos=0;
    else if (ch=='D')
        ret.pos=1;
    else if (ch=='M')
        ret.pos=2;
    else
        ret.pos=3;
    string s;
    ret.year=0;
    while (sin>>s)
    {
        int l,r;
        sscanf(s.c_str(),"%d-%d",&l,&r);
        ret.year+=r-l+1;
    }
    return(ret);
}
bool choose(int id,int num)
{
    for (int i=1;i<=22;i++)
    {
        if (a[i].pos==id)
        {
            ans[++tot]=a[i];
            num--;
        }
        if (num==0)
            return(true);
    }
    return(false);
}
int main()
{
    while (1)
    {
        gets(buf);
        if (buf[0]=='0')
            break;
        for (int i=1;i<=22;i++)
        {
            a[i]=get(buf);
            gets(buf);
        }
        sort(a+1,a+23);
        int def,mid,str;
        sscanf(buf,"%d-%d-%d",&def,&mid,&str);
        tot=0;
        if (!choose(0,1) || !choose(1,def) || !choose(2,mid) || !choose(3,str))
            printf("IMPOSSIBLE TO ARRANGE\n");
        else
        {
            int k=1;
            for (int i=1;i<=11;i++)
                if (ans[k].year<ans[i].year || ans[k].year==ans[i].year && ans[k].num<ans[i].num)
                    k=i;
            ans[k].print();
            for (int i=1;i<=11;i++)
                if (i!=k)
                    ans[i].print();
        }
        printf("\n");
    }
    return(0);
}

