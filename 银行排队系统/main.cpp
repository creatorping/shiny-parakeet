#include<algorithm>
#include<string.h>
#include<stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;
int IDx=0;
string re_string(int n,int vis);
void color(short x)	//自定义函根据参数改变颜色
{
    if(x>=0 && x<=15)//参数在0-15的范围颜色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色
    else//默认的颜色白色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void color(short x,short y)	//自定义函根据参数改变颜色
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x | y);
}
void gotoxy(int x, int y)//光标移动
{
    HANDLE hout;
    COORD cor;
    hout=GetStdHandle(STD_OUTPUT_HANDLE);
    cor.X=y;
    cor.Y=x;
    SetConsoleCursorPosition(hout,cor);
}
string xinxi_time()
{
    string a;
    time_t t;
    struct tm * lt;
    time (&t);//获取Unix时间戳。
    lt = localtime (&t);//转为时间结构。
    a+=re_string(lt->tm_hour,0)+":"+re_string(lt->tm_min,0)+":"+re_string(lt->tm_sec,0)+"  ";
    return a;
}
struct xinxi//信息类
{
    string str;
    int cx,cy;
    xinxi *next;
    xinxi()
    {
        this->next=NULL;
    }
    xinxi(string str)
    {
        this->next=NULL;
        this->str+=xinxi_time();
        this->str+=str;
        this->cx=15;
        this->cy=0;
    }
    xinxi(string str,int cx)
    {
        this->next=NULL;
        this->str+=xinxi_time();
        this->str+=str;
        this->cx=cx;
        this->cy=0;
    }
    xinxi(string str,int cx,int cy)
    {
        this->next=NULL;
        this->str+=xinxi_time();
        this->str+=str;
        this->cx=cx;
        this->cy=cy;
    }
};
xinxi xhead,*xp;
void add_xinxi(xinxi *head,xinxi *p)//添加信息
{
    p->next=head->next;
    head->next=p;
}
struct chuang//柜台类
{
    int statu,sum,ID;
} win[10];

struct people//用户类
{
    int ID;
    bool vip;
    people *next;
    people()
    {
        this->next=NULL;
    }
    people(int vip)
    {
        this->vip=vip;
        this->next=NULL;
        this->ID=IDx++;
    }
};
people head0,head1,*p;

void queue_push(people *head,people *p)//往队列种插入数据
{
    while(head->next!=NULL)
        head=head->next;
    head->next=p;
}

void queue_pop(people *head)//弹出队列头
{
    head->next=head->next->next;
}
people* queue_front(people *head)//返回队列头
{
    return head->next;
}
int re_ID()//查找当前队列优先用户，从vip队列先找
{

    if(queue_front(&head1)!=NULL)
    {
        p=queue_front(&head1);
        queue_pop(&head1);
        return p->ID;

    }

    else if(queue_front(&head0)!=NULL)
    {
        p=queue_front(&head0);
        queue_pop(&head0);
        return p->ID;

    }
    else
        return -1;
}
string re_string(int n,int vis)//用一个整数返回一个字符串
{
    string a,b;
    int m=n;

    while(n)
    {
        a+=n%10+'0';
        n/=10;
    }
    if(vis==0)
    {
        if(m==0)
            return "0";
        for(int i=a.length()-1; i>=0; i--)
        {
            b+=a[i];
        }
    }

    else
    {
        if(m==0)
            return "0000000";
        for(int i=6; i>=a.length(); i--)
            b+="0";
        for(int i=a.length()-1; i>=0; i--)
        {
            b+=a[i];
        }
    }

    return b;
}

void TMD(int v)//v号柜台呼叫用户
{
    int ver=win[v].statu;
    switch(ver)
    {
    case 1:
        break;
    case 0:
        if(win[v].sum>=3)
        {
            win[v].sum=0;
            break;
        }
        else if(win[v].sum==0)
        {
            win[v].ID=re_ID();
            if(win[v].ID==-1)
                break;
        }
        win[v].sum++;
        xp=new xinxi("请"+re_string(win[v].ID,1)+"号用户到"+re_string(v,0)+"柜台办理业务");
        if(win[v].sum==1)
            xp->cx=2;
        else if(win[v].sum==2)
            xp->cx=6;
        else
            xp->cx=4;
        add_xinxi(&xhead,xp);
    }
}
void xinxi_appear(int h)//把信息显示到页面中
{
    xp=&xhead;
    for(int i=11; i<=h&&xp->next!=NULL; i++,xp=xp->next)
    {
        gotoxy(i,2);
        color(xp->next->cx,8);
        cout<<xp->next->str;
    }
}
void people_appear(int h)//用户队列显示
{
    p=&head1;
    for(int i=7; i<=h&&p->next!=NULL; p=p->next,i++)
    {
        gotoxy(i,73);
        color(4);
        cout<<re_string(p->next->ID,1);
    }
    p=&head0;
    for(int i=7; i<=h&&p->next!=NULL; p=p->next,i++)
    {
        gotoxy(i,82);
        color(7);
        cout<<re_string(p->next->ID,1);
    }
}
void MMP(int v)//用户呼叫
{
    if(win[v].statu==0&&win[v].sum>0)
    {
        win[v].statu=1;
        win[v].sum=0;
        xp=new xinxi(re_string(v,0)+"号窗口开始为"+re_string(win[v].ID,1)+"号用户服务",1,8);
        add_xinxi(&xhead,xp);
    }
    else if(win[v].statu==1)
    {
        win[v].statu=0;
        win[v].sum=0;
        xp=new xinxi(re_string(v,0)+"号窗口为"+re_string(win[v].ID,1)+"号用户服务结束",3,8);
        add_xinxi(&xhead,xp);
    }
}
void win_appear()//柜台状态显示
{
    for(int j=11,v=1; v<=5; j+=9,v++)
    {
        gotoxy(3,j);
        if(win[v].statu==1)
        {
            color(4,8);
            cout<<"工作中";
        }
        else
        {
            color(2,8);
            cout<<"等待中";
        }
    }
    for(int j=11,v=1; v<=5; j+=9,v++)
    {
        gotoxy(7,j);
        if(win[v].statu==1)
        {
            color(13);
            cout<<re_string(win[v].ID,1);
        }
        else
        {
            color(8);
            cout<<"暂无";
        }
    }
}
void system_time()//输出系统时间
{
    time_t t;
    struct tm * lt;
    time (&t);//获取Unix时间戳。
    lt = localtime (&t);//转为时间结构。
    color(15);
    gotoxy(7,58);
    printf ("%d:%d:%d\n",lt->tm_hour, lt->tm_min, lt->tm_sec);//输出结果
}
void jiemian()//界面
{
    int h=25;
    system("cls");
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //获得标准输出设备句柄
    CONSOLE_CURSOR_INFO cci;        //定义光标信息结构体
    GetConsoleCursorInfo(handle_out, &cci);     //获得当前光标信息
    cci.bVisible = false;       //设置光标为不可见
    SetConsoleCursorInfo(handle_out, &cci);
    color(7);
    printf("╔════════════════════════════════════════════════════════════════════════════════════════╗\n"
           "║                                        银行排号系统                                    ║\n"
           "╠════════╦════════╦════════╦════════╦════════╦════════╦════════════════╦═════════════════╣\n"
           "║工作状态║        ║        ║        ║        ║        ║    银行状态    ║       队列      ║\n"
           "╠════════╣════════╣════════╣════════╣════════╣════════╣════════════════╣════════╦════════╣\n"
           "║窗口编号║一号窗口║二号窗口║三号窗口║四号窗口║五号窗口║                ║ VIP用户║普通用户║\n"
           "╠════════╣════════╣════════╣════════╣════════╣════════╣════════════════╣════════╣════════╣\n"
           "║服务目标║        ║        ║        ║        ║        ║                ║        ║        ║\n"
           "╠════════╩════════╩════════╩════════╩════════╩════════╩════════════════╣        ║        ║\n"
           "║                               消息记录                               ║        ║        ║\n"
           "╠══════════════════════════════════════════════════════════════════════╣        ║        ║\n"
           "║                                                                      ║        ║        ║\n"
           "║                                                                      ║        ║        ║\n"
           "║                                                                      ║        ║        ║\n"
           "║                                                                      ║        ║        ║\n"
           "║                                                                      ║        ║        ║\n"
           "║                                                                      ║        ║        ║\n"
           "║                                                                      ║        ║        ║\n"
           "║                                                                      ║        ║        ║\n"
           "║                                                                      ║        ║        ║\n"
           "║                                                                      ║        ║        ║\n"
           "║                                                                      ║        ║        ║\n"
           "║                                                                      ║        ║        ║\n"
           "║                                                                      ║        ║        ║\n"
           "║                                                                      ║        ║        ║\n"
           "║                                                                      ║        ║        ║\n"
           "╚══════════════════════════════════════════════════════════════════════╩════════╩════════╝\n");
    xinxi_appear(h);
    people_appear(h);
    win_appear();
    system_time();
}
void save()//储存文件
{
    xp=&xhead;
    ofstream fp;
    fp.open("xinxi.txt",ios::out);
    while(xp->next!=NULL)
    {
        fp<<xp->next->str<<endl;
        xp=xp->next;
    }
    fp.close();
}
int main()
{
    while(1)
    {
        jiemian();
        Sleep(1000);
        if(kbhit())
        {
            char ch=getche();
            switch(ch)
            {
            case'o':
                p=new people(0);
                xp=new xinxi("编号为"+re_string(p->ID,1)+"的普通用户开始排队");
                add_xinxi(&xhead,xp);
                queue_push(&head0,p);
                break;
            case'v':
                p=new people(1);
                xp=new xinxi("编号为"+re_string(p->ID,1)+"的vip用户开始排队",12);
                add_xinxi(&xhead,xp);
                queue_push(&head1,p);
                break;
            case'1':
                TMD(1);
                break;
            case'2':
                TMD(2);
                break;
            case'3':
                TMD(3);
                break;
            case'4':
                TMD(4);
                break;
            case'5':
                TMD(5);
                break;
            case'q':
                MMP(1);
                break;
            case'w':
                MMP(2);
                break;
            case'e':
                MMP(3);
                break;
            case'r':
                MMP(4);
                break;
            case't':
                MMP(5);
                break;
            }
            save();
        }
    }

}
