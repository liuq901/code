#include <cstdio>
#include <utility>
#include <string>
#include <set>
#include <map>
using namespace std;
struct state
{
    int id,pos;
    state(int id,int pos):id(id),pos(pos){}
};
set <state> b;
map <string,int> M;
int a[10010],in[10010];
string s[10010];
char buf[100000];
inline bool operator <(const state &u,const state &v)
{
    return(a[u.id]>a[v.id] || a[u.id]==a[v.id] && u.pos>v.pos);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        M.clear();
        for (int i=1;i<=n;i++)
        {
            scanf("%s%d",buf,&a[i]);
            M[buf]=i;
            s[i]=buf;
        }
        int Q;
        scanf("%d",&Q);
        b.clear();
        for (int i=1;i<=Q;i++)
        {
            scanf("%s",buf);
            if (buf[0]=='g')
            {
                if (b.empty())
                {
                    printf("<empty>\n");
                    continue;
                }
                printf("%s\n",s[b.begin()->id].c_str());
                b.erase(b.begin());
            }
            else
            {
                char op=buf[0];
                scanf("%s",buf);
                int id=M[buf];
                if (op=='a')
                {
                    b.insert(state(id,i));
                    in[id]=i;
                }
                else
                {
                    set <state>::iterator k=b.find(state(id,in[id]));
                    b.erase(k);
                }
            }
        }
    }
    return(0);
}

