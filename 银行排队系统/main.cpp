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
void color(short x)	//�Զ��庯���ݲ����ı���ɫ
{
    if(x>=0 && x<=15)//������0-15�ķ�Χ��ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//ֻ��һ���������ı�������ɫ
    else//Ĭ�ϵ���ɫ��ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void color(short x,short y)	//�Զ��庯���ݲ����ı���ɫ
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x | y);
}
void gotoxy(int x, int y)//����ƶ�
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
    time (&t);//��ȡUnixʱ�����
    lt = localtime (&t);//תΪʱ��ṹ��
    a+=re_string(lt->tm_hour,0)+":"+re_string(lt->tm_min,0)+":"+re_string(lt->tm_sec,0)+"  ";
    return a;
}
struct xinxi//��Ϣ��
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
void add_xinxi(xinxi *head,xinxi *p)//�����Ϣ
{
    p->next=head->next;
    head->next=p;
}
struct chuang//��̨��
{
    int statu,sum,ID;
} win[10];

struct people//�û���
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

void queue_push(people *head,people *p)//�������ֲ�������
{
    while(head->next!=NULL)
        head=head->next;
    head->next=p;
}

void queue_pop(people *head)//��������ͷ
{
    head->next=head->next->next;
}
people* queue_front(people *head)//���ض���ͷ
{
    return head->next;
}
int re_ID()//���ҵ�ǰ���������û�����vip��������
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
string re_string(int n,int vis)//��һ����������һ���ַ���
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

void TMD(int v)//v�Ź�̨�����û�
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
        xp=new xinxi("��"+re_string(win[v].ID,1)+"���û���"+re_string(v,0)+"��̨����ҵ��");
        if(win[v].sum==1)
            xp->cx=2;
        else if(win[v].sum==2)
            xp->cx=6;
        else
            xp->cx=4;
        add_xinxi(&xhead,xp);
    }
}
void xinxi_appear(int h)//����Ϣ��ʾ��ҳ����
{
    xp=&xhead;
    for(int i=11; i<=h&&xp->next!=NULL; i++,xp=xp->next)
    {
        gotoxy(i,2);
        color(xp->next->cx,8);
        cout<<xp->next->str;
    }
}
void people_appear(int h)//�û�������ʾ
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
void MMP(int v)//�û�����
{
    if(win[v].statu==0&&win[v].sum>0)
    {
        win[v].statu=1;
        win[v].sum=0;
        xp=new xinxi(re_string(v,0)+"�Ŵ��ڿ�ʼΪ"+re_string(win[v].ID,1)+"���û�����",1,8);
        add_xinxi(&xhead,xp);
    }
    else if(win[v].statu==1)
    {
        win[v].statu=0;
        win[v].sum=0;
        xp=new xinxi(re_string(v,0)+"�Ŵ���Ϊ"+re_string(win[v].ID,1)+"���û��������",3,8);
        add_xinxi(&xhead,xp);
    }
}
void win_appear()//��̨״̬��ʾ
{
    for(int j=11,v=1; v<=5; j+=9,v++)
    {
        gotoxy(3,j);
        if(win[v].statu==1)
        {
            color(4,8);
            cout<<"������";
        }
        else
        {
            color(2,8);
            cout<<"�ȴ���";
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
            cout<<"����";
        }
    }
}
void system_time()//���ϵͳʱ��
{
    time_t t;
    struct tm * lt;
    time (&t);//��ȡUnixʱ�����
    lt = localtime (&t);//תΪʱ��ṹ��
    color(15);
    gotoxy(7,58);
    printf ("%d:%d:%d\n",lt->tm_hour, lt->tm_min, lt->tm_sec);//������
}
void jiemian()//����
{
    int h=25;
    system("cls");
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //��ñ�׼����豸���
    CONSOLE_CURSOR_INFO cci;        //��������Ϣ�ṹ��
    GetConsoleCursorInfo(handle_out, &cci);     //��õ�ǰ�����Ϣ
    cci.bVisible = false;       //���ù��Ϊ���ɼ�
    SetConsoleCursorInfo(handle_out, &cci);
    color(7);
    printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n"
           "�U                                        �����ź�ϵͳ                                    �U\n"
           "�d�T�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n"
           "�U����״̬�U        �U        �U        �U        �U        �U    ����״̬    �U       ����      �U\n"
           "�d�T�T�T�T�T�T�T�T�g�T�T�T�T�T�T�T�T�g�T�T�T�T�T�T�T�T�g�T�T�T�T�T�T�T�T�g�T�T�T�T�T�T�T�T�g�T�T�T�T�T�T�T�T�g�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g�T�T�T�T�T�T�T�T�j�T�T�T�T�T�T�T�T�g\n"
           "�U���ڱ�ŨUһ�Ŵ��ڨU���Ŵ��ڨU���Ŵ��ڨU�ĺŴ��ڨU��Ŵ��ڨU                �U VIP�û��U��ͨ�û��U\n"
           "�d�T�T�T�T�T�T�T�T�g�T�T�T�T�T�T�T�T�g�T�T�T�T�T�T�T�T�g�T�T�T�T�T�T�T�T�g�T�T�T�T�T�T�T�T�g�T�T�T�T�T�T�T�T�g�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g�T�T�T�T�T�T�T�T�g�T�T�T�T�T�T�T�T�g\n"
           "�U����Ŀ��U        �U        �U        �U        �U        �U                �U        �U        �U\n"
           "�d�T�T�T�T�T�T�T�T�m�T�T�T�T�T�T�T�T�m�T�T�T�T�T�T�T�T�m�T�T�T�T�T�T�T�T�m�T�T�T�T�T�T�T�T�m�T�T�T�T�T�T�T�T�m�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g        �U        �U\n"
           "�U                               ��Ϣ��¼                               �U        �U        �U\n"
           "�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g        �U        �U\n"
           "�U                                                                      �U        �U        �U\n"
           "�U                                                                      �U        �U        �U\n"
           "�U                                                                      �U        �U        �U\n"
           "�U                                                                      �U        �U        �U\n"
           "�U                                                                      �U        �U        �U\n"
           "�U                                                                      �U        �U        �U\n"
           "�U                                                                      �U        �U        �U\n"
           "�U                                                                      �U        �U        �U\n"
           "�U                                                                      �U        �U        �U\n"
           "�U                                                                      �U        �U        �U\n"
           "�U                                                                      �U        �U        �U\n"
           "�U                                                                      �U        �U        �U\n"
           "�U                                                                      �U        �U        �U\n"
           "�U                                                                      �U        �U        �U\n"
           "�U                                                                      �U        �U        �U\n"
           "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�m�T�T�T�T�T�T�T�T�m�T�T�T�T�T�T�T�T�a\n");
    xinxi_appear(h);
    people_appear(h);
    win_appear();
    system_time();
}
void save()//�����ļ�
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
                xp=new xinxi("���Ϊ"+re_string(p->ID,1)+"����ͨ�û���ʼ�Ŷ�");
                add_xinxi(&xhead,xp);
                queue_push(&head0,p);
                break;
            case'v':
                p=new people(1);
                xp=new xinxi("���Ϊ"+re_string(p->ID,1)+"��vip�û���ʼ�Ŷ�",12);
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
