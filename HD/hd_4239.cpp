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
        String a="PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV";
        while (T-->0)
        {
            int id=nextInt();
            char op=next().charAt(0);
            int num=nextInt();
            char pre=next().charAt(0);
            String ans="";
            for (int i=0;i<a.length();i++)
                if (a.charAt(i)==op)
                    ans+=trans(i,5);
            ans+=trans(num,11);
            ans+=pre=='F'?"0":"1";
            writer.println(id+" "+calc(ans).toPlainString());
        }
        reader.close();
        writer.close();
    }
    String trans(int x,int n)
    {
        String ret="";
        for (int i=0;i<n;i++)
        {
            ret=(x&1)+ret;
            x>>=1;
        }
        return(ret);
    }
    BigDecimal calc(String ans)
    {
        BigDecimal ret=ans.charAt(0)=='1'?BigDecimal.ONE.negate():BigDecimal.ZERO,now=BigDecimal.ONE;
        for (int i=1;i<17;i++)
        {
            now=now.divide(BigDecimal.valueOf(2));
            if (ans.charAt(i)=='1')
                ret=ret.add(now);
        }
        if (ret.signum()==0)
            ret=BigDecimal.ZERO;
        ret=ret.stripTrailingZeros();
        if (ret.scale()==0)
            ret=ret.setScale(1);
        return(ret);
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

