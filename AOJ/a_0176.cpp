#include <cstdio>
const int p=0xff;
const int a[]={0,0,0,0,p,p,p,p};
const int b[]={0,0,p,p,0,0,p,p};
const int c[]={0,p,0,p,0,p,0,p};
const char *ans[]={"black","blue","lime","aqua","red","fuchsia","yellow","white"};
inline int sqr(int x)
{
    return(x*x);
}
int main()
{
    int x,y,z;
    while (scanf(" #%02x%02x%02x",&x,&y,&z)==3)
    {
        int best=1<<30,id;
        for (int i=0;i<8;i++)
        {
            int now=sqr(x-a[i])+sqr(y-b[i])+sqr(z-c[i]);
            if (now<best)
            {
                best=now;
                id=i;
            }
        }
        printf("%s\n",ans[id]);
    }
    return(0);
}

