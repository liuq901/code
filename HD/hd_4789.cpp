#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
const int N=50010,inf=1<<30;
struct Submit
{
    int team,problem,time,result;
    void in();
};
struct Team
{
    int penalty,state[26];
    vector <int> solved,frozen;
    vector <Submit> frozenSubmit[26];
    string name;
    void deal(const Submit &s,int frozenTime)
    {
        int id=s.problem;
        if (state[id]>0)
            return;
        if (s.time<frozenTime)
        {
            if (s.result==2)
                return;
            if (s.result==1)
                state[id]--;
            else
            {
                state[id]*=-1;
                state[id]++;
                solved.push_back(s.time);
                penalty+=s.time+(state[id]-1)*20;
                sort(solved.begin(),solved.end(),greater <int>());
            }
        }
        else
        {
            if (frozenSubmit[id].empty())
                frozen.push_back(id);
            frozenSubmit[id].push_back(s);
        }
    }
    void init(const string &s)
    {
        penalty=0;
        memset(state,0,sizeof(state));
        solved.clear();
        frozen.clear();
        for (int i=0;i<26;i++)
            frozenSubmit[i].clear();
        name=s;
    }
    void print(int rank,int m)
    {
        printf("%s %d %d %d",name.c_str(),rank,solved.size(),penalty);
        for (int i=0;i<m;i++)
        {
            printf(" ");
            if (!frozenSubmit[i].empty())
                printf("%d/%d",state[i],frozenSubmit[i].size());
            else if (state[i]==0)
                printf(".");
            else if (state[i]==1)
                printf("+");
            else if (state[i]>1)
                printf("+%d",state[i]-1);
            else
                printf("%d",state[i]);
        }
        printf("\n");
    }
};
inline bool operator <(const Team &a,const Team &b)
{
    if (a.solved.size()!=b.solved.size())
        return(a.solved.size()>b.solved.size());
    if (a.penalty!=b.penalty)
        return(a.penalty<b.penalty);
    return(a.solved<b.solved || a.solved==b.solved && a.name>b.name);
}
Team team[N];
map <string,int> M;
int hash(const string &s)
{
    if (!M.count(s))
    {
        int id=M.size();
        M[s]=id;
        team[id].init(s);
    }
    return(M[s]);
}
void Submit::in()
{
    char ch[5],buf[30],res[10];
    scanf("%s%s%d%s",buf,ch,&time,res);
    team=hash(buf);
    problem=ch[0]-'A';
    result=res[0]=='E'?2:res[0]=='N'?1:0;
}
inline bool operator <(const Submit &a,const Submit &b)
{
    return(a.time<b.time || a.time==b.time && a.result>b.result);
}
vector <Submit> submit;
struct TeamID
{
    int id;
    TeamID(int x=0):id(x){}
};
inline bool operator <(const TeamID &a,const TeamID &b)
{
    return(team[b.id]<team[a.id]);
}
TeamID a[100010];
void scoreboard(int m)
{
    int n=M.size();
    for (int i=0;i<n;i++)
        a[i].id=i;
    sort(a,a+n);
    reverse(a,a+n);
    for (int i=0;i<n;i++)
        team[a[i].id].print(i+1,m);
}
set <TeamID> S;
void unfrozen()
{
    int n=M.size();
    for (int i=0;i<n;i++)
    {
        sort(team[i].frozen.begin(),team[i].frozen.end(),greater <int>());
        S.insert(TeamID(i));
    }
    while (!S.empty())
    {
        int id=S.begin()->id;
        Team &now=team[id];
        S.erase(S.begin());
        if (!now.frozen.empty())
        {
            int t=now.frozen.back();
            now.frozen.pop_back();
            for (int i=0;i<now.frozenSubmit[t].size();i++)
                now.deal(now.frozenSubmit[t][i],inf);
            now.frozenSubmit[t].clear();
            S.insert(TeamID(id));
            set <TeamID>::iterator k=S.find(TeamID(id));
            if (k!=S.begin())
                printf("%s %s %d %d\n",now.name.c_str(),team[(--k)->id].name.c_str(),now.solved.size(),now.penalty);
        }
    }
}
int main()
{
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        int n,m,frozen,T;
        scanf("%d%d%d%d",&n,&m,&T,&frozen);
        submit.clear();
        M.clear();
        for (int i=1;i<=n;i++)
        {
            Submit temp;
            temp.in();
            submit.push_back(temp);
        }
        sort(submit.begin(),submit.end());
        for (int i=0;i<submit.size();i++)
            team[submit[i].team].deal(submit[i],frozen);
        static int id=0;
        printf("Case #%d:\n",++id);
        scoreboard(m);
        unfrozen();
        scoreboard(m);
    }
    return(0);
}

