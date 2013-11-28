#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct EllysReversals
{
    bool same(string a,string b)
    {
        if (a.size()!=b.size())
            return(false);
        int n=a.size();
        if (n%2==1 && a[n-1]!=b[n-1])
            return(false);
        if (n%2==1)
        {
            n--;
            a.erase(a.begin()+n);
            b.erase(b.begin()+n);
        }
        vector <string> s,t;
        for (int i=0;i<a.size();i+=2)
        {
            string p="lq";
            p[0]=a[i],p[1]=a[i+1];
            sort(p.begin(),p.end());
            s.push_back(p);
            p[0]=b[i],p[1]=b[i+1];
            sort(p.begin(),p.end());
            t.push_back(p);
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return(s==t);
    }
    int getMin(vector <string> words)
    {
        vector <string> a;
        a=words;
        bool f[60]={0};
        for (int i=0;i<a.size();i++)
        {
            if (f[i])
                continue;
            for (int j=i+1;j<a.size();j++)
            {
                if (f[j])
                    continue;
                if (same(a[i],a[j]))
                {
                    f[i]=f[j]=true;
                    break;
                }
            }
        }
        return(count(f,f+a.size(),false));
    }
};
int main(){}

