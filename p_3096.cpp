#include <cstdio>
#include <string>
#include <set>
using namespace std;
char buf[100];
set <string> m;
int main()
{
    while (1)
    {
        scanf("%s",buf);
        string s=buf;
        if (s=="*")
            break;
        bool flag=true;
        for (int i=1;i<s.size();i++)
        {
            m.clear();
            for (int j=0;j<s.size();j++)
            {
                if (i+j>=s.size())
                    break;
                string now;
                now+=s[j];
                now+=s[i+j];
                if (m.count(now))
                {
                    flag=false;
                    goto out;
                }
                m.insert(now);
            }
        }
out:
        printf("%s is ",s.c_str());
        if (!flag)
            printf("NOT ");
        printf("surprising.\n");
    }
    return(0);
}

