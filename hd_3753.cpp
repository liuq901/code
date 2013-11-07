#include <cstdio>
#include <cstring>
#include <vector>
#include <sstream>
using namespace std;
int len[200],p[200];
vector <string> s[1010];
char buf[100000];
int main()
{
    int T;
    scanf("%d",&T);
    gets(buf);
    while (T--)
    {
        memset(len,0,sizeof(len));
        int n=0,m=0;
        while (1)
        {
            gets(buf);
            if (string(buf)=="@")
                break;
            s[++n].clear();
            stringstream sin(buf);
            string tmp;
            while (sin>>tmp)
            {
                s[n].push_back(tmp);
                len[s[n].size()-1]=max(len[s[n].size()-1],int(tmp.size()));
            }
            m=max(m,int(s[n].size()));
        }
        p[0]=0;
        for (int i=1;i<m;i++)
            p[i]=p[i-1]+len[i-1]+1;
        for (int i=1;i<=n;i++)
        {
            int now=0;
            for (int j=0;j<s[i].size();j++)
            {
                for (int k=now;k<p[j];k++)
                    printf(" ");
                printf("%s",s[i][j].c_str());
                now=p[j]+s[i][j].size();
            }
            printf("\n");
        }
    }
    return(0);
}

