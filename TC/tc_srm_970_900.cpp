#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
struct StringsNightmareAgain
{
    struct State
    {
        int length,mi,ma;
        State *parent,*go[2];
        static vector <State *> lq;
        State(int length):length(length),parent(NULL),mi(1<<30),ma(-1)
        {
            memset(go,0,sizeof(go));
            lq.push_back(this);
        }
        State *extend(State *start,int token)
        {
            State *p=this;
            State *np=new State(this->length+1);
            while (p!=NULL && p->go[token]==NULL)
            {
                p->go[token]=np;
                p=p->parent;
            }
            if (p==NULL)
                np->parent=start;
            else
            {
                State *q=p->go[token];
                if (p->length+1==q->length)
                    np->parent=q;
                else
                {
                    State *nq=new State(p->length+1);
                    memcpy(nq->go,q->go,sizeof(q->go));
                    nq->parent=q->parent;
                    np->parent=q->parent=nq;
                    while (p!=NULL && p->go[token]==q)
                    {
                        p->go[token]=nq;
                        p=p->parent;
                    }
                }
            }
            return(np);
        }
    };
    ll UniqueSubstrings(int a,int b,int c,int d,int n)
    {
        string s=gen(a,b,c,d,n);
        State *root=new State(0),*p=root;
        for (int i=s.size()-1;i>=0;i--)
            p=p->extend(root,s[i]-'a');
        p=root;
        for (int i=s.size()-1;i>=0;i--)
        {
            p=p->go[s[i]-'a'];
            p->mi=min(p->mi,i);
            p->ma=max(p->ma,i);
        }
        vector <State *> lq=State::lq;
        sort(lq.begin(),lq.end(),cmp);
        ll ans=0;
        for (int i=0;i<lq.size()-1;i++)
        {
            ans+=max(min(lq[i]->length,lq[i]->ma-lq[i]->mi)-lq[i]->parent->length,0);
            lq[i]->parent->mi=min(lq[i]->parent->mi,lq[i]->mi);
            lq[i]->parent->ma=max(lq[i]->parent->ma,lq[i]->ma);
        }
        return(ans);
    }
    string gen(int a,int b,int c,int d,int n)
    {
        string ret(n,'a');
        for (int i=0;i<a;i++)
        {
            b=(ll(b)*c+d)%n;
            ret[b]='b';
        }
        return(ret);
    }
    static bool cmp(State *a,State *b)
    {
        return(a->length>b->length);
    }
};
vector <StringsNightmareAgain::State *> StringsNightmareAgain::State::lq;
int main(){}

