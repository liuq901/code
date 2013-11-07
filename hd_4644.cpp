#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct state
{
    static int tot;
    static state S[260000];
    int length;
    state *parent,*go[26];
    state *extend(state *start,int token)
    {
        state *node(int length);
        state *p=this;
        state *np=node(length+1);
        while (p && !p->go[token])
        {
            p->go[token]=np;
            p=p->parent;
        }
        if (!p)
            np->parent=start;
        else
        {
            state *q=p->go[token];
            if (p->length+1==q->length)
                np->parent=q;
            else
            {
                state *nq=node(p->length+1);
                memcpy(nq->go,q->go,sizeof(q->go));
                nq->parent=q->parent;
                np->parent=q->parent=nq;
                while (p && p->go[token]==q)
                {
                    p->go[token]=nq;
                    p=p->parent;
                }
            }
        }
        return(np);
    }
};
int state::tot;
state state::S[260000];
state *node(int length)
{
    state *ret=state::S+state::tot;
    state::tot++;
    memset(ret->go,0,sizeof(ret->go));
    ret->length=length;
    ret->parent=NULL;
    return(ret);
}
state *start;
void init(char *s,int len)
{
    state::tot=0;
    start=node(0);
    state *p=start;
    for (int i=0;i<len;i++)
        p=p->extend(start,s[i]-'a');
}
bool check(char *s)
{
    int len=strlen(s);
    state *p=start;
    if (p==NULL)
        return(false);
    for (int i=0;i<len;i++)
    {
        int x=s[i]-'a';
        if (p->go[x]==NULL)
            return(false);
        p=p->go[x];
    }
    return(true);
}
char s[100100],buf[2000010];
int b[260],a[100100],to[100100];
int main()
{
    while (scanf("%s",buf)==1)
    {
        int len=strlen(buf);
        memcpy(s,buf,sizeof(char)*len);
        sort(s,s+len);
        memset(b,0,sizeof(b));
        for (int i=len-1;i>0;i--)
        {
            to[i]=b[s[i]];
            b[s[i]]=i;
        }
        int pos;
        for (int i=0;i<len;i++)
        {
            a[i]=b[buf[i]];
            b[buf[i]]++;
            if (buf[i]=='$')
                pos=i;
        }
        for (int i=0;i<len;i++)
        {
            s[i]=buf[pos];
            pos=a[pos];
        }
        reverse(s,s+len);
        init(s,len-1);
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",buf);
            printf("%s\n",check(buf)?"YES":"NO");
        }
    }
    return(0);
}

