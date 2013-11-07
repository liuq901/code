/*
Java:
import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
    void run() throws Exception
    {
        int T=nextInt();
        long c[][]=new long[21][21];
        for (int i=0;i<=20;i++)
        {
            c[i][0]=c[i][i]=1;
            for (int j=1;j<i;j++)
                c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
        long factor[]=new long[21];
        factor[0]=1;
        for (int i=1;i<=20;i++)
            factor[i]=factor[i-1]*i;
        while (T-->0)
        {
            int id=nextInt(),n=nextInt(),m=nextInt();
            long ans=0;
            if (m==1)
                ans=factor[n-1];
            else
                for (int i=2;i<=m;i++)
                    ans+=c[m-2][i-2]*factor[n-i]*factor[i]/i;
            writer.println(id+" "+ans);
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

