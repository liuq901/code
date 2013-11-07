#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int m=260;
struct data
{
    ll ans,L,R,num,a[m*2+10];
    int n;
    bool kind[m*2+10];
    data *next;
};
data *head;
void init()
{
    head=new(data);
    head->ans=head->R=0;
    head->L=head->num=1;
    head->n=1;
    head->kind[1]=0;
    head->a[1]=1;
    head->next=NULL;
}
void update(data *k)
{
    k->L=k->R=k->ans=k->num=0;
    for (int i=1;i<=k->n;i++)
    {
        k->num+=k->a[i];
        if (k->kind[i]==0)
            k->L+=k->a[i];
        else
        {
            ll now=min(k->L,k->a[i]);
            k->ans+=now;
            k->L-=now;
            k->R+=k->a[i]-now;
        }
    }
}
void insert(bool type,int where,int count)
{
    data *k;
    for (k=head;where>k->num;k=k->next)
        where-=k->num;
    int t;
    ll tmp=0;
    for (int i=1;i<=k->n;i++)
    {
        tmp+=k->a[i];
        if (tmp>=where)
        {
            t=i;
            break;
        }
    }
    if (where==0)
        t=0;
    if (t!=0 && k->kind[t]==type)
        k->a[t]+=count;
    else if (tmp==where || t==0)
    {
        for (int i=k->n;i>=t+1;i--)
        {
            k->kind[i+1]=k->kind[i];
            k->a[i+1]=k->a[i];
        }
        k->kind[t+1]=type;
        k->a[t+1]=count;
        k->n++;
    }
    else
    {
        for (int i=k->n;i>=t+1;i--)
        {
            k->kind[i+2]=k->kind[i];
            k->a[i+2]=k->a[i];
        }
        k->kind[t+1]=type;
        k->a[t+1]=count;
        k->kind[t+2]=k->kind[t];
        k->a[t+2]=tmp-where;
        k->a[t]-=k->a[t+2];
        k->n+=2;
    }
    if (k->n>=2*m)
    {
        data *p=new(data);
        p->next=k->next;
        k->next=p;
        p->n=k->n-m;
        k->n=m;
        for (int i=1;i<=p->n;i++)
        {
            p->a[i]=k->a[i+m];
            p->kind[i]=k->kind[i+m];
        }
        update(p);
    }
    update(k);
} 
ll getans()
{
    ll ans=0,L=0;
    for (data *k=head;k!=NULL;k=k->next)
    {
        ll now=min(L,k->R);
        ans+=k->ans+now;
        L+=k->L-now;
    }
    return(ans);
}
void del(data *k)
{
    if (k->next!=NULL)
        del(k->next);
    delete(k);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        init();
        int n;
        scanf("%d",&n);
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=1;i<=n;i++)
        {
            int type,where,count;
            scanf("%d%d%d",&type,&where,&count);
            insert(type,where,count);
            printf("%lld\n",getans());
        }
        del(head);
    }
    return(0);
}

