#include <cstdio>
#include <string>
using namespace std;
char buf[100000];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",buf);
        string s=buf,protocol,host,port,path;
        s+='/';
        port=path="<default>";
        for (int i=0;i<s.size();i++)
            if (s.substr(i,3)=="://")
            {
                protocol=s.substr(0,i);
                s=s.substr(i+3);
                break;
            }
        for (int i=0;i<s.size();i++)
            if (s[i]==':' || s[i]=='/')
            {
                host=s.substr(0,i);
                s=s.substr(i);
                break;
            }
        if (s[0]!=':')
            s=s.substr(1);
        else
            for (int i=1;i<s.size();i++)
                if (s[i]=='/')
                {
                    port=s.substr(1,i-1);
                    s=s.substr(i+1);
                    break;
                }
        if (!s.empty())
            path=s.substr(0,s.size()-1);
        static int id=0;
        printf("URL #%d\n",++id);
        printf("Protocol = %s\n",protocol.c_str());
        printf("Host     = %s\n",host.c_str());
        printf("Port     = %s\n",port.c_str());
        printf("Path     = %s\n\n",path.c_str());
    }
    return(0);
}

