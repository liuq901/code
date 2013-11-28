#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;
bool have[1010],no[1010];
vector <int> a[1010];
vector <string> b[1010];
char s[100000];
int n;
map <string,int> M;
int calc(int x)
{
    if (no[x] || have[x])
        return(0);
    int cnt=1;
    for (int i=0;i<a[x].size();i++)
    {
        int y=a[x][i];
        cnt+=calc(y);
        if (no[y])
        {
            no[x]=true;
            return(0);
        }
    }
    have[x]=true;
    return(cnt);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        M.clear();
        n=0;
        while (1)
        {
            gets(s);
            if (strlen(s)==0 || s[0]==' ' || s[0]=='#')
                continue;
            if (s[0]=='=')
                break;
            b[++n].clear();
            have[n]=no[n]=false;
            bool flag=true;
            while (flag)
            {
                stringstream sin(s);
                string name;
                flag=false;
                while (sin>>name)
                {
                    int k=-1;
                    for (int i=0;i<name.size();i++)
                        if (!isalpha(name[i]) && !isdigit(name[i]) && name[i]!='.')
                        {
                            k=i;
                            break;
                        }
                    if (k==-1)
                        b[n].push_back(name);
                    else
                    {
                        char ch=name[k];
                        name=name.substr(0,k);
                        if (ch==':')
                            M[name]=n;
                        else
                        {
                            if (name!="")
                                b[n].push_back(name);
                            if (ch=='#')
                                break;
                            if (ch=='\\')
                            {
                                gets(s);
                                flag=true;
                            }
                        }
                    }
                }
            }
        }
        int m,tot=n;
        scanf("%d",&m);
        for (int i=1;i<=m;i++)
        {
            scanf("%s",s);
            if (!M.count(s))
                M[s]=++tot;
            have[M[s]]=true;
            no[M[s]]=false;
        }
        for (int i=1;i<=n;i++)
        {
            if (have[i])
                continue;
            a[i].clear();
            for (int j=0;j<b[i].size();j++)
            {
                if (!M.count(b[i][j]))
                {
                    no[i]=true;
                    break;
                }
                a[i].push_back(M[b[i][j]]);
            }
        }
        static int id=0;
        printf("Case #%d:\n",++id);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            scanf("%*s%s",s);
            if (!M.count(s))
                printf("0\n");
            else
                printf("%d\n",calc(M[s]));
        }
        if (T)
            printf("\n");
    }
    return(0);
}

