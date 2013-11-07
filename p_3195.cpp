#include <cstdio>
#include <sstream>
#include <vector>
using namespace std;
vector <int> a,b,c;
char buf[1000000];
int main()
{
    while (gets(buf))
    {
        a.clear();
        stringstream sin(buf);
        int tmp;
        while (sin>>tmp)
            a.push_back(tmp);
        if (a.empty())
            break;
        b.clear();
        c.clear();
        c.push_back(1<<30);
        bool flag=true;
        for (int i=0;i<a.size();i++)
            if (a[i]<0)
            {
                b.push_back(-a[i]);
                c.push_back(-a[i]);
            }
            else
            {
                if (c.empty() || b.empty() || b.back()!=a[i])
                {
                    flag=false;
                    break;
                }
                b.pop_back();
                c.pop_back();
                if (c.empty() || c.back()<=a[i])
                {
                    flag=false;
                    break;
                }
                c.back()-=a[i];
            }
        if (!b.empty())
            flag=false;
        printf("%s\n",flag?":-) Matrioshka!":":-( Try again.");
    }
    return(0);
}

