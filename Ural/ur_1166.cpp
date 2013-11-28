#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const char c[]=" A23456789TJQK";
const int limit=2;
struct card
{
    int value;
    char suit;
    bool joker;
    card(){}
    card(char *s)
    {
        int len=strlen(s);
        if (len==1)
            joker=true;
        else if (s[0]=='*')
        {
            *this=card(s+1);
            joker=true;
        }
        else
        {
            joker=false;
            if (s[0]=='T')
                value=10;
            else if (s[0]=='J')
                value=11;
            else if (s[0]=='Q')
                value=12;
            else if (s[0]=='K')
                value=13;
            else if (s[0]=='A')
                value=1;
            else
                value=s[0]-'0';
            if (len==3)
                suit=s[2];
            else
                suit=s[1];
        }
    }
    bool check(const card &a) const
    {
        return(value!=12 && value==a.value || suit==a.suit);
    }
    bool skip() const
    {
        return(value==6 || value==7 || value==1 || value==13 && suit=='S');
    }
    void print() const
    {
        if (joker)
            printf("*");
        printf("%c%c",c[value],suit);
        if (value==12)
            printf("%c",suit);
    }
};
vector <card> skip,ans;
int cnt[260];
bool dfs(const card &prev,const vector <card> &a)
{
    if (a.empty())
    {
        printf("YES\n");
        for (int i=0;i<ans.size();i++)
        {
            ans[i].print();
            printf("%c",i==ans.size()-1?'\n':' ');
        }
        return(true);
    }
    for (int i=0;i<a.size();i++)
    {
        card now=a[i];
        if (now.joker)
        {
            for (int j=0;j<skip.size();j++)
            {
                now=skip[j];
                now.joker=true;
                if (prev.check(now))
                {
                    ans.push_back(now);
                    vector <card> b=a;
                    b.erase(b.begin()+i);
                    if ((now.suit==prev.suit || cnt[prev.suit]<=limit) && dfs(now,b))
                        return(true);
                    ans.pop_back();
                }
            }
        }
        else if ((now.skip() || a.size()==1) && prev.check(now))
        {
            cnt[now.suit]--;
            ans.push_back(now);
            vector <card> b=a;
            b.erase(b.begin()+i);
            if ((now.suit==prev.suit || cnt[prev.suit]<=limit) && dfs(now,b))
                return(true);
            cnt[now.suit]++;
            ans.pop_back();
        }
    }
    return(false);
}
void init(char ch)
{
    card tmp;
    tmp.suit=ch;
    tmp.value=6;
    skip.push_back(tmp);
    tmp.value=7;
    skip.push_back(tmp);
    tmp.value=1;
    skip.push_back(tmp);
    if (ch=='S')
    {
        tmp.value=13;
        skip.push_back(tmp);
    }
}
int main()
{
    init('S');
    init('C');
    init('D');
    init('H');
    vector <card> a;
    char buf[10];
    while (scanf("%s",buf)==1)
        a.push_back(card(buf));
    card now=a.back();
    a.pop_back();
    for (int i=0;i<a.size();i++)
        if (!a[i].joker)
            cnt[a[i].suit]++;
    if (!dfs(now,a))
        printf("NO\n");
    return(0);
}

