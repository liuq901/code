/*
Java:
import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
    int S,T,n,tot,b[],a[][];
    void add(int x,int y,int z)
    {
        a[++tot][0]=y;
        a[tot][1]=z;
        a[tot][2]=b[x];
        b[x]=tot;
        a[++tot][0]=x;
        a[tot][1]=0;
        a[tot][2]=b[y];
        b[y]=tot;
    }
    int f[],q[];
    boolean in[];
    void bfs()
    {
        f=new int[n+10];
        q=new int[n+10];
        in=new boolean[n+10];
        int l=0,r=1;
        q[1]=S;
        f[S]=1<<30;
        while (l!=r)
        {
            l=l==n+5?1:l+1;
            int x=q[l];
            in[x]=false;
            for (int i=b[x];i!=0;i=a[i][2])
            {
                int y=a[i][0];
                if (a[i][1]>0 && Math.min(f[x],a[i][1])>f[y])
                {
                    f[y]=Math.min(f[x],a[i][1]);
                    if (!in[y])
                    {
                        in[y]=true;
                        r=r==n+1?1:r+1;
                        q[r]=y;
                    }
                }
            }
        }
    }
    int d[];
    boolean build()
    {
        d=new int[n+10];
        int l,r;
        q[l=r=1]=S;
        d[S]=1;
        while (l<=r)
        {
            int x=q[l++];
            for (int i=b[x];i!=0;i=a[i][2])
            {
                int y=a[i][0];
                if (d[y]!=0 || a[i][1]==0)
                    continue;
                d[y]=d[x]+1;
                q[++r]=y;
                if (y==T)
                    return(true);
            }
        }
        return(false);
    }
    int dinic(int x,int flow)
    {
        if (x==T)
            return(flow);
        int k=flow;
        for (int i=b[x];i!=0;i=a[i][2])
        {
            int y=a[i][0];
            if (d[y]!=d[x]+1 || a[i][1]==0)
                continue;
            int t=dinic(y,Math.min(k,a[i][1]));
            k-=t;
            a[i][1]-=t;
            a[i^1][1]+=t;
            if (k==0)
                break;
        }
        if (k==flow)
            d[x]=-1;
        return(flow-k);
    }
    void run() throws Exception
    {
        int test=nextInt();
        while (test-->0)
        {
            int id=nextInt();
            n=nextInt();
            int m=nextInt();
            S=nextInt();
            T=nextInt();
            b=new int[n+10];
            a=new int[m*2+10][3];
            tot=1;
            S++;
            T++;
            for (int i=1;i<=m;i++)
            {
                int x=nextInt(),y=nextInt(),z=nextInt();
                x++;
                y++;
                add(x,y,z);
            }
            bfs();
            int ans=0;
            while (build())
                ans+=dinic(S,1<<30);
            writer.println(id+" "+String.format("%.3f",((double)ans)/f[T]));
        }
        reader.close();
        writer.close();
    }
    public static void main(String args[]) throws Exception
    {
        (new Main()).run();
    }
    BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer=new PrintWriter(System.out);
    StringTokenizer tokenizer=null;
    String next() throws Exception
    {
        for (;tokenizer==null || !tokenizer.hasMoreTokens();)
            tokenizer=new StringTokenizer(reader.readLine());
        return(tokenizer.nextToken());
    }
    int nextInt() throws Exception
    {
        return(Integer.parseInt(next()));
    }
}
*/
int main(){}

