import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.StringTokenizer;

import sun.misc.BASE64Encoder;

class MailMessage {

    private String from;
    private String to;
    private String datafrom;
    private String datato;
    private String subject;
    private String content;
    private String date;
    private String user;
    private String password;

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getUser() {
        return user;
    }

    public void setUser(String user) {
        this.user = user;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public String getDatafrom() {
        return datafrom;
    }

    public void setDatafrom(String datafrom) {
        this.datafrom = datafrom;
    }

    public String getDatato() {
        return datato;
    }

    public void setDatato(String datato) {
        this.datato = datato;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public String getFrom() {
        return from;
    }

    public void setFrom(String from) {
        this.from = from;
    }

    public String getSubject() {
        return subject;
    }

    public void setSubject(String subject) {
        this.subject = subject;
    }

    public String getTo() {
        return to;
    }

    public void setTo(String to) {
        this.to = to;
    }

}

public class Main {

    private boolean debug=true;
    BASE64Encoder encode=new BASE64Encoder();//用于加密后发送用户名和密码
    public static void main(String[] args) throws UnknownHostException, IOException {
        // TODO Auto-generated method stub
        MailMessage message=new MailMessage();
        message.setFrom("liuq901@126.com");//发件人
        message.setTo("liuq901@163.com");//收件人
        String server="smtp.126.com";//邮件服务器
        message.setSubject("test");//邮件主题
        message.setContent("test");//邮件内容
        message.setDatafrom("Matt");//发件人，在邮件的发件人栏目中显示
        message.setDatato("Dong");//收件人，在邮件的收件人栏目中显示
        message.setUser("liuq901");//登陆邮箱的用户名
        message.setPassword("7894561230");//登陆邮箱的密码

        Main smtp=new Main(server,25);
        boolean flag;
        flag=smtp.sendMail(message,server);
        if(flag){
            System.out.println("邮件发送成功！");
        }
        else{
            System.out.println("邮件发送失败！");
        }

    }
    private Socket socket;
    public Main(String server,int port) throws UnknownHostException, IOException{
        try{
            socket=new Socket(server,25);
        }catch(SocketException e){
            System.out.println(e.getMessage());
        }catch(Exception e){
            e.printStackTrace();
        }finally{
            System.out.println("已经建立连接!");
        }

    }
    //注册到邮件服务器
    public void helo(String server,BufferedReader in,BufferedWriter out) throws IOException{
        int result;
        result=getResult(in);
        //连接上邮件服务后,服务器给出220应答
        if(result!=220){
            throw new IOException("连接服务器失败");
        }
        result=sendServer("HELO "+server,in,out);
        //HELO命令成功后返回250
        if(result!=250)
        {
            throw new IOException("注册邮件服务器失败！");
        }
    }

    private int sendServer(String str,BufferedReader in,BufferedWriter out) throws IOException{
        out.write(str);
        out.newLine();
        out.flush();
        if(debug)
        {
            System.out.println("已发送命令:"+str);
        }
        return getResult(in);
    }
    public int getResult(BufferedReader in){
        String line="";
        try{
            line=in.readLine();
            if(debug){
                System.out.println("服务器返回状态:"+line);
            }
        }catch(Exception e){
            e.printStackTrace();
        }
        //从服务器返回消息中读出状态码,将其转换成整数返回
        StringTokenizer st=new StringTokenizer(line," ");
        return Integer.parseInt(st.nextToken());
    }

    public void authLogin(MailMessage message,BufferedReader in,BufferedWriter out) throws IOException{
        int result;
        result=sendServer("AUTH LOGIN",in,out);
        if(result!=334){
            throw new IOException("用户验证失败！");
        }

        result=sendServer(encode.encode(message.getUser().getBytes()),in,out);
        if(result!=334){
            throw new IOException("用户名错误！"); 
        }
        result=sendServer(encode.encode(message.getPassword().getBytes()),in,out);

        if(result!=235){
            throw new IOException("验证失败！"); 
        }
    }
    //开始发送消息，邮件源地址
    public void mailfrom(String source,BufferedReader in,BufferedWriter out) throws IOException{
        int result;
        result=sendServer("MAIL FROM:<"+source+">",in,out);
        if(result!=250){
            throw new IOException("指定源地址错误");
        }
    }
    // 设置邮件收件人
    public void rcpt(String touchman,BufferedReader in,BufferedWriter out) throws IOException{
        int result;
        result=sendServer("RCPT TO:<"+touchman+">",in,out);
        if(result!=250){
            throw new IOException("指定目的地址错误！");
        }
    }

    //邮件体
    public void data(String from,String to,String subject,String content,BufferedReader in,BufferedWriter out) throws IOException{
        int result;
        result=sendServer("DATA",in,out);
        //输入DATA回车后,若收到354应答后,继续输入邮件内容
        if(result!=354){
            throw new IOException("不能发送数据");
        }
        out.write("From: "+from);
        out.newLine();
        out.write("To: "+to);
        out.newLine();
        out.write("Subject: "+subject);
        out.newLine();
        out.newLine();
        out.write(content);
        out.newLine();
        //句号加回车结束邮件内容输入
        result=sendServer(".",in,out);
        System.out.println(result);
        if(result!=250)
        {
            throw new IOException("发送数据错误");
        }
    }

    //退出
    public void quit(BufferedReader in,BufferedWriter out) throws IOException{
        int result;
        result=sendServer("QUIT",in,out);
        if(result!=221){
            throw new IOException("未能正确退出");
        }
    }

    //发送邮件主程序
    public boolean sendMail(MailMessage message,String server){
        try{
            BufferedReader in=new BufferedReader(new InputStreamReader(socket.getInputStream()));
            BufferedWriter out=new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
            helo(server,in,out);//HELO命令
            authLogin(message,in,out);//AUTH LOGIN命令
            mailfrom(message.getFrom(),in,out);//MAIL FROM
            rcpt(message.getTo(),in,out);//RCPT
            data(message.getDatafrom(),message.getDatato(),message.getSubject(),message.getContent(),in,out);//DATA
            quit(in,out);//QUIT
        }catch(Exception e){
            e.printStackTrace();
            return false;

        }
        return true;
    }

}

