#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
char a[1000010];
bool Sqrt(int &n)
{
    int x=int(sqrt(double(n)));
    for (int i=x+2;i>=x-2;i--)
        if (i*i==n)
        {
            n=i;
            return(true);
        }
    return(false);
}
int main()
{
    scanf("%s",a);
    int len=strlen(a),m=0;
    for (int i=0;i<len;i++)
        m+=a[i]=='Q';
    bool flag=true;
    if (!Sqrt(m))
        flag=false;
    else if (m!=0)
    {
        int l,r;
        for (int i=0;i<len;i++)
            if (a[i]=='Q')
            {
                l=i;
                break;
            }
        for (int i=len-1;i>=0;i--)
            if (a[i]=='Q')
            {
                r=len-i-1;
                break;
            }
        if (l&1 || r&1)
            flag=false;
        else
        {
            string s;
            for (int i=0;i<l>>1;i++)
                s+="H";
            int tot=0;
            for (int i=l;i<len;i++)
            {
                s+=a[i];
                if (a[i]=='Q')
                {
                    tot++;
                    if (tot==m)
                        break;
                }
            }
            for (int i=0;i<r>>1;i++)
                s+="H";
            if (s.size()*m+s.size()-m!=len)
                flag=false;
            else
            {
                string t;
                for (int i=0;i<s.size();i++)
                    t+=s[i]=='H'?"H":s;
                flag=t==a;
            }
        }
    }
    printf("%s\n",flag?"Yes":"No");
    return(0);
}

