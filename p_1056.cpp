#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int CHARSET=2,BASE='0',MAX_NODE=100;
struct Trie
{
    int tot,root,child[MAX_NODE][CHARSET];
    bool flag[MAX_NODE];
    Trie()
    {
        memset(child[1],0,sizeof(child[1]));
        flag[1]=false;
        root=tot=1;
    }
    void insert(const char *str)
    {
        int *cur=&root;
        for (const char *p=str;*p;++p)
        {
            cur=&child[*cur][*p-BASE];
            if (*cur==0)
            {
                *cur=++tot;
                memset(child[tot],0,sizeof(child[tot]));
                flag[tot]=false;
            }
        }
        flag[*cur]=true;
    }
    bool query(const char *str)
    {
        int *cur=&root;
        for (const char *p=str;*p && *cur;++p)
            cur=&child[*cur][*p-BASE];
        for (int i=0;i<CHARSET;i++)
            if (child[*cur][i])
                return(true);
        return(false);
    }
};
char buf[110];
string s[110];
Trie a;
int main()
{
    while (gets(buf))
    {
        if (strlen(buf)==0)
            break;
        a=Trie();
        a.insert(buf);
        int tot;
        s[tot=0]=buf;
        while (gets(buf))
        {
            if (strlen(buf)==1 && buf[0]=='9')
                break;
            a.insert(buf);
            s[++tot]=buf;
        }
        bool flag=true;
        for (int i=0;i<=tot;i++)
            if (a.query(s[i].c_str()))
            {
                flag=false;
                break;
            }
        static int id=0;
        printf("Set %d is ",++id);
        if (!flag)
            printf("not ");
        printf("immediately decodable\n");
    }
    return(0);
}

