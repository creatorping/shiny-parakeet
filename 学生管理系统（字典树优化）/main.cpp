#include<string.h>
#include<algorithm>
#include<iostream>
#include<windows.h>
#include<math.h>
#include<stdio.h>
#include<fstream>
using namespace std;
void qingping()
{
    system("cls");
}
void tingdun(int x)
{
    for(int i=x; i>0; i--)
    {
        cout<<"��ȴ�:"<<i<<endl;
        Sleep(1000);
    }
}
class ID
{
private:
    char id[15],pass[15];
    int status;
public:
    ID()
    {
        status=1;
        id[0]='\0';
        pass[0]='\0';
    }
    void id_print()
    {
        cout<<"�˺ų���Ӧ�ô���5С��13"<<endl;
        cout<<"�����������˺�:";
        scanf("%s",id);
        if(strlen(id)<6||strlen(id)>12)
        {
            id_print();
        }
    }
    void pass_print()
    {
        cout<<"���볤��Ӧ�ô���5С��13"<<endl;
        cout<<"��������������:";
        scanf("%s",pass);
        if(strlen(pass)<6||strlen(pass)>12)
        {
            pass_print();
        }
    }
    void print()
    {
        cout<<"�������˺�:";
        scanf("%s",id);
        if(strlen(id)<6||strlen(id)>12)
        {
            id_print();
        }
        cout<<"����������:";
        scanf("%s",pass);;
        if(strlen(pass)<6||strlen(pass)>12)
        {
            pass_print();
        }
    }
    int operator =(ID& a)
    {
        if(!strcmp(id,a.id)&&!strcmp(pass,a.pass)&&a.status==1)
        {
            return 2;
        }
        else if(!strcmp(id,a.id)&&!strcmp(pass,a.pass))
        {
            return 1;
        }
        else if(!strcmp(id,a.id))
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    void out()
    {
        printf("%s %s\n",id,pass);
    }
};
char num[50];
class staff
{
protected:
    char name[50],number[50],old[50];
public:
    void sscan()
    {
        cout<<"����������:";
        cin>>name;
        cout<<"��������:";
        cin>>number;
        cout<<"���������䣺";
        cin>>old;
    }
    virtual void scan() {};
    virtual void print() {};
    void sprint()
    {
        cout<<"\t\t\t"<<"����:"<<name<<"  ���:"<<number<<"  ����:"<<old;
    }
    char cpy_num()
    {
        strcpy(num,number);
    }
};
class teacher:public staff
{
private:
    char department[50],professional[50],professor[50];
public:
    teacher *next;
    void scan()
    {
        this->sscan();
        cout<<"���������ڲ���:";
        cin>>department;
        cout<<"��������ѧרҵ:";
        cin>>professional;
        cout<<"������Ŀǰְ��:";
        cin>>professor;
    }
    void print()
    {
        this->sprint();
        cout<<" ����:"<<department<<" רҵ:"<<professional<<" ְ��:"<<professor<<endl;
    }
    friend void bianji_teacher(char *a,teacher *b,int x);
};
void bianji_teacher(char *a,teacher *b,int x)
{
    if(x==1)
        strcpy(b->number,a);
    else if(x==2)
        strcpy(b->name,a);
    else if(x==3)
        strcpy(b->old,a);
    else if(x==4)
        strcpy(b->department,a);
    else if(x==5)
        strcpy(b->professional,a);
    else if(x==6)
        strcpy(b->professor,a);
    else
        return ;
}
class te_and_cl:public staff
{
private:
    char status[50],department[50],professional[50],professor[50];
public:
    te_and_cl *next;
    void scan()
    {
        this->sscan();
        cout<<"���������ڲ���:";
        cin>>department;
        cout<<"��������ѧרҵ:";
        cin>>professional;
        cout<<"������Ŀǰְ��:";
        cin>>professor;
        cout<<"������������ò:";
        cin>>status;
    }
    void print()
    {
        this->sprint();
        cout<<" ����:"<<department<<" רҵ:"<<professional<<" ְ��:"<<professor<<" ������ò:"<<status<<endl;
    }
    int operator =(te_and_cl& a)
    {
        return strcmp(number,a.number);
    }
    void copy_tea_cle(te_and_cl &a)
    {
        strcpy(name,a.name);
        strcpy(number,a.number);
        strcpy(old,a.old);
        strcpy(status,a.status);
        strcpy(department,a.department);
        strcpy(professional,a.professional);
        strcpy(professor,a.professor);
    }
    friend void bianji_tea_cle(char *a,te_and_cl* b,int x);
};
void bianji_tea_cle(char *a,te_and_cl* b,int x)
{
    if(x==1)
        strcpy(b->number,a);
    else if(x==2)
        strcpy(b->name,a);
    else if(x==3)
        strcpy(b->old,a);
    else if(x==4)
        strcpy(b->department,a);
    else if(x==5)
        strcpy(b->professional,a);
    else if(x==6)
        strcpy(b->professor,a);
    else if(x==7)
        strcpy(b->status,a);
    else
        return ;
}
class laber:public staff
{
private:
    char lab[50],job[50];
public:
    laber *next;
    void scan()
    {
        this->sscan();
        cout<<"����������ʵ����:";
        cin>>lab;
        cout<<"������Ŀǰְ��:";
        cin>>job;
    }
    void print()
    {
        this->sprint();
        cout<<" ����ʵ����:"<<lab<<" Ŀǰְ��:"<<job<<endl;
    }
    int operator =(laber& a)
    {
        return strcmp(number,a.number);
    }
    void copy_laber(laber &a)
    {
        strcpy(name,a.name);
        strcpy(number,a.number);
        strcpy(old,a.old);
        strcpy(lab,a.lab);
        strcpy(job,a.job);
    }
    friend void bianji_laber(char *a,laber* b,int x);
};
void bianji_laber(char *a,laber* b,int x)
{
    if(x==1)
        strcpy(b->number,a);
    else if(x==2)
        strcpy(b->name,a);
    else if(x==3)
        strcpy(b->old,a);
    else if(x==4)
        strcpy(b->lab,a);
    else if(x==5)
        strcpy(b->job,a);
    else
        return ;
}
class clerical:public staff
{
private:
    char job[50],status[50];
public:
    clerical *next;
    void scan()
    {
        this->sscan();
        cout<<"������Ŀǰְ��:";
        cin>>job;
        cout<<"������������ò:";
        cin>>status;
    }
    void print()
    {
        this->sprint();
        cout<<" Ŀǰְ��:"<<job<<" ������ò:"<<status<<endl;
    }
    int operator =(clerical& a)
    {
        return strcmp(number,a.number);
    }
    void copy_clerical(clerical &a)
    {
        strcpy(name,a.name);
        strcpy(number,a.number);
        strcpy(old,a.old);
        strcpy(job,a.job);
        strcpy(status,a.status);
    }
    friend void bianji_clerical(char *a,clerical* b,int x);
};
void bianji_clerical(char *a,clerical* b,int x)
{
    if(x==1)
        strcpy(b->number,a);
    else if(x==2)
        strcpy(b->name,a);
    else if(x==3)
        strcpy(b->old,a);
    else if(x==4)
        strcpy(b->status,a);
    else if(x==5)
        strcpy(b->job,a);
    else
        return ;
}
int zhanghao();
int idcin()
{
    int n;
    ID a,b;
    cout<<"���������ѡ��:";
    cin>>n;
    if(n==1)
    {
        a.print();
        fstream ff("zhanghao.txt",ios::in|ios::out|ios::binary);
        if(!ff)
        {
            cout<<"���ļ�����"<<endl;
            tingdun(3);
            return zhanghao();
        }
        while(ff.read((char*)&b,sizeof(b)))
        {
            if((a=b)>0)
            {
                ff.close();
                return (a=b);
            }
        }
        ff.close();
        cout<<"�˺Ż����벻��ȷ,������ѡ��:"<<endl;
        tingdun(3);
        qingping();
        zhanghao();
    }
    else if(n==2)
    {
        cout<<"������Ҫע����˺ź�����"<<endl;
        a.print();
        fstream ff("zhanghao.txt",ios::in|ios::out|ios::binary);
        if(!ff)
        {
            cout<<"���ļ�����"<<endl;
            tingdun(3);
            return zhanghao();
        }
        while(ff.read((char*)&b,sizeof(b)))
        {
            if((a=b))
            {
                ff.close();
                cout<<"\t\t\t\t\t\t"<<"************"<<endl;
                cout<<"\t\t\t\t\t\t"<<"*�˺��Ѵ���*"<<endl;
                cout<<"\t\t\t\t\t\t"<<"************"<<endl;
                tingdun(3);
                return zhanghao();
            }
        }
        ff.close();
        fstream f("zhanghao.txt",ios::in|ios::out|ios::binary);
        if(!f)
        {
            cout<<"���ļ�����"<<endl;
            tingdun(3);
            return zhanghao();
        }
        f.seekg(0,ios::end);
        f.write((char* )&a,sizeof(a));
        f.close();
        qingping();
        cout<<"\t\t\t"<<"                                                            "<<endl;
        cout<<"\t\t\t"<<"                   ************************                 "<<endl;
        cout<<"\t\t\t"<<"                   *       ע��ɹ�       *                 "<<endl;
        cout<<"\t\t\t"<<"                   ************************                 "<<endl;
        cout<<"\t\t\t"<<"                                                            "<<endl;
        tingdun(3);
        qingping();
        return zhanghao();
    }
    else
    {
        cout<<"������������������"<<endl;
        return idcin();
    }
}
int zhanghao()
{
    qingping();
    cout<<"\t\t\t"<<"************************************************************"<<endl;
    cout<<"\t\t\t"<<"*                  ************************                *"<<endl;
    cout<<"\t\t\t"<<"*                  *1.��½:    2.ע���˺�:*                *"<<endl;
    cout<<"\t\t\t"<<"*                  ************************                *"<<endl;
    cout<<"\t\t\t"<<"************************************************************"<<endl;
    return idcin();
}
struct tree
{
    tree *next[10];
    int v;
    teacher *_1;
    laber *_2;
    clerical *_3;
    te_and_cl *_4;
    tree()
    {
        for(int i=0; i<10; i++)
        {
            next[i]=NULL;
        }
        _1=NULL;
        _2=NULL;
        _3=NULL;
        _4=NULL;
        v=0;
    }
};
int x1=0,x2=0,x3=0,x4=0;
teacher *p1;
laber *p2;
clerical *p3;
te_and_cl *p4;
staff *p5;
tree root;
void creat_tree(char *str,int x)
{
    tree *p,*head=&root;
    while(*str)
    {
        int di=*str-'0';
        if(head->next[di]==NULL)
        {
            p=new tree;
            head->next[di]=p;
        }
        head=head->next[di];
        str++;
    }
    head->v=x;
    if(x==1)
    {
        head->_1=p1;
    }
    else if(x==2)
    {
        head->_2=p2;
    }
    else if(x==3)
    {
        head->_3=p3;
    }
    else if(x==4)
    {
        head->_4=p4;
    }
}
int find_tree(char *str)
{
    tree *head=&root;
    while(*str)
    {
        int di=*str-'0';
        if(head->next[di]==NULL)
            return 0;
        head=head->next[di];
        str++;
    }
    if(head->v==1)
    {
        p1=head->_1;
        return 1;
    }
    else if(head->v==2)
    {
        p2=head->_2;
        return 2;
    }
    else if(head->v==3)
    {
        p3=head->_3;
        return 3;
    }
    else if(head->v==4)
    {
        p4=head->_4;
        return 4;
    }
    return 0;
}
int dfs_tree(tree *head,int x)
{
    for(int di=0; di<10; di++)
    {
        if(head->next[di])
            dfs_tree(head->next[di],x);
    }
    if(x==1&&head->v==1)
    {
        p5=head->_1;
        p5->print();
    }
    else if(x==2&&head->v==2)
    {
        p5=head->_2;
        p5->print();
    }
    else if(x==3&&head->v==3)
    {
        p5=head->_3;
        p5->print();
    }
    else if(x==4&&head->v==4)
    {
        p5=head->_4;
        p5->print();
    }
}
int save_tree(tree *head)
{
    for(int di=0; di<10; di++)
    {
        if(head->next[di])
            save_tree(head->next[di]);
    }
    if(head->v==1)
    {
        fstream f1("teacher.txt",ios::in|ios::out|ios::binary);
        f1.seekg(0,ios::end);
        f1.write((char*)head->_1,sizeof(teacher));
        f1.close();
    }
    else if(head->v==2)
    {
        fstream f2("laber.txt",ios::in|ios::out|ios::binary);
        f2.seekg(0,ios::end);
        f2.write((char*)head->_2,sizeof(laber));
        f2.close();
    }
    else if(head->v==3)
    {
        fstream f3("clerical.txt",ios::in|ios::out|ios::binary);
        f3.seekg(0,ios::end);
        f3.write((char*)head->_3,sizeof(clerical));
        f3.close();
    }
    else if(head->v==4)
    {
        fstream f4("te_and_cl.txt",ios::in|ios::out|ios::binary);
        f4.seekg(0,ios::end);
        f4.write((char*)head->_4,sizeof(te_and_cl));
        f4.close();
    }
}
void delete_tree(tree *head)
{
    for(int di=0; di<10; di++)
    {
        if(head->next[di])
            delete_tree(head->next[di]);
        delete head->next[di];
    }
    if(head->_1)
    {
        delete head->_1;
    }
    if(head->_2)
    {
        delete head->_2;
    }
    if(head->_3)
    {
        delete head->_3;
    }
    if(head->_4)
    {
        delete head->_4;
    }
}
void find_jiemian()
{
    cout<<"������Ҫ���ҵ���Ա���:";
}
void find_people()
{
    find_jiemian();
    char a[50];
    cin>>a;
    int x;
    x=find_tree(a);
    if(x==1)
    {
        cout<<"\t\t\t"<<"��ʦ"<<endl;
        p5=p1;
        p5->print();
    }
    else if(x==2)
    {
        cout<<"\t\t\t"<<"ʵ��Ա"<<endl;
        p5=p2;
        p5->print();
    }

    else if(x==3)
    {
        cout<<"\t\t\t"<<"������Ա"<<endl;
        p5=p3;
        p5->print();
    }

    else if(x==4)
    {
        cout<<"\t\t\t"<<"��ʦ��������Ա"<<endl;
        p5=p4;
        p5->print();
    }

    else
    {
        cout<<"\t\t\t"<<"********************"<<endl;
        cout<<"\t\t\t"<<"*û����������Ա��Ϣ*"<<endl;
        cout<<"\t\t\t"<<"********************"<<endl;
    }
}
void Show_people()
{
    cout<<"*******"<<endl;
    cout<<"*��ʦ:*"<<endl;
    cout<<"*******"<<endl;
    dfs_tree(&root,1);
    cout<<"*********"<<endl;
    cout<<"*ʵ��Ա:*"<<endl;
    cout<<"*********"<<endl;
    dfs_tree(&root,2);
    cout<<"***********"<<endl;
    cout<<"*������Ա:*"<<endl;
    cout<<"***********"<<endl;
    dfs_tree(&root,3);
    cout<<"*****************"<<endl;
    cout<<"*��ʦ��������Ա:*"<<endl;
    cout<<"*****************"<<endl;
    dfs_tree(&root,4);
}
void add_jiemian()
{
    cout<<"\t\t\t"<<"**************************************************"<<endl;
    cout<<"\t\t\t"<<"*            *ѡ����Ҫ��ӵ���Ա������:*         *"<<endl;
    cout<<"\t\t\t"<<"*1.��ʦ  2.ʵ����Ա  3.������Ա  4.��ʦ��������Ա*"<<endl;
    cout<<"\t\t\t"<<"**************************************************"<<endl;
}
void add_teacher()
{
    p1=new teacher;
    p5=p1;
    p5->scan();
    p5->cpy_num();
    if(find_tree(num))
    {
        cout<<"\t\t\t"<<"********************************"<<endl;
        cout<<"\t\t\t"<<"*��Ŵ��ڣ������ظ������ͬ���*"<<endl;
        cout<<"\t\t\t"<<"********************************"<<endl;
        return ;
    }
    creat_tree(num,1);
    x1++;
    cout<<"\t\t\t"<<"*��ӳɹ�*"<<endl;
}
void add_laber()
{
    p2=new laber;
    p5=p2;
    p5->scan();
    p5->cpy_num();
    if(find_tree(num))
    {
        cout<<"\t\t\t"<<"********************************"<<endl;
        cout<<"\t\t\t"<<"*��Ŵ��ڣ������ظ������ͬ���*"<<endl;
        cout<<"\t\t\t"<<"********************************"<<endl;
        return ;
    }
    creat_tree(num,2);
    x2++;
    cout<<"\t\t\t"<<"*��ӳɹ�*"<<endl;
}
void add_clerical()
{
    p3=new clerical;
    p5=p3;
    p5->scan();
    p5->cpy_num();
    if(find_tree(num))
    {
        cout<<"\t\t\t"<<"********************************"<<endl;
        cout<<"\t\t\t"<<"*��Ŵ��ڣ������ظ������ͬ���*"<<endl;
        cout<<"\t\t\t"<<"********************************"<<endl;
        return ;
    }
    creat_tree(num,3);
    x3++;
    cout<<"\t\t\t"<<"*��ӳɹ�*"<<endl;
}
void add_tea_cle()
{
    p4=new te_and_cl;
    p5=p4;
    p5->scan();
    p5->cpy_num();
    if(find_tree(num))
    {
        cout<<"\t\t\t"<<"********************************"<<endl;
        cout<<"\t\t\t"<<"*��Ŵ��ڣ������ظ������ͬ���*"<<endl;
        cout<<"\t\t\t"<<"********************************"<<endl;
        return ;
    }
    creat_tree(num,4);
    x4++;
    cout<<"\t\t\t"<<"*��ӳɹ�*"<<endl;
}
void add_people()
{
    qingping();
    int n;
    add_jiemian();
    cout<<"���������ѡ��:";
    cin>>n;
    if(n==1)
    {
        add_teacher();
    }
    else if(n==2)
    {
        add_laber();
    }
    else if(n==3)
    {
        add_clerical();
    }
    else if(n==4)
    {
        add_tea_cle();
    }
    else
    {
        cout<<"û�д�ѡ�����������:"<<endl;
        add_people();
    }
}
void delete_people()
{
    char a[50];
    int x;
    cout<<"������Ҫɾ����Ա�ı��:"<<endl;
    cin>>a;
    x=find_tree(a);
    if(x==1)
        x1--;
    else if(x==2)
        x2--;
    else if(x==3)
        x3--;
    else if(x==4)
        x4--;
    else
    {
        cout<<"û���ҵ���Ա��Ϣ"<<endl;
        return ;
    }
    cout<<"\t\t\t"<<"********"<<endl;
    cout<<"\t\t\t"<<"ɾ���ɹ�"<<endl;
    cout<<"\t\t\t"<<"********"<<endl;
    creat_tree(a,0);
}
void bianji_jiaoshi(char *a)
{
    teacher b,root,*head,*p;
    cout<<"\t\t\t"<<"****************************"<<endl;
    cout<<"\t\t\t"<<"*1.���      2.����  3.����*"<<endl;
    cout<<"\t\t\t"<<"*4.����ϵ��  5.רҵ  6.ְ��*"<<endl;
    cout<<"\t\t\t"<<"****************************"<<endl;
    cout<<"��ѡ��Ҫ�޸ĵ���Ϣ:";
    int n,flag=0;
    cin>>n;
    if(n>6)
    {
        cout<<"û�д���,������ȷ����Ϣ"<<endl;
        return ;
    }
    cout<<"������Ҫ�޸ĺ����Ϣ:";
    char z[50];
    cin>>z;
    bianji_teacher(z,p1,n);
    creat_tree(a,1);
    cout<<"\t\t\t"<<"�޸ĳɹ�"<<endl;
}
void bianji_tea_cle(char *a)
{
    te_and_cl b,root,*head,*p;
    cout<<"\t\t\t"<<"************************************"<<endl;
    cout<<"\t\t\t"<<"*1.���      2.����      3.����    *"<<endl;
    cout<<"\t\t\t"<<"*4.���ڲ���  5.��ѧרҵ  6.Ŀǰְ��*"<<endl;
    cout<<"\t\t\t"<<"*7.������ò                        *"<<endl;
    cout<<"\t\t\t"<<"************************************"<<endl;
    cout<<"��ѡ��Ҫ�޸ĵ���Ϣ:";
    int n,flag=0;
    cin>>n;
    if(n>7)
    {
        cout<<"û�д���,������ȷ����Ϣ"<<endl;
        return ;
    }
    cout<<"������Ҫ�޸ĺ����Ϣ:";
    char z[50];
    cin>>z;
    bianji_tea_cle(z,p4,n);
    creat_tree(a,4);
    cout<<"\t\t\t"<<"�޸ĳɹ�"<<endl;
}
void bianji_laber(char *a)
{
    laber b,root,*head,*p;
    cout<<"\t\t\t"<<"**********************************"<<endl;
    cout<<"\t\t\t"<<"*1.���        2.����      3.����*"<<endl;
    cout<<"\t\t\t"<<"*4.����ʵ����  5.Ŀǰְ��        *"<<endl;
    cout<<"\t\t\t"<<"**********************************"<<endl;
    cout<<"��ѡ��Ҫ�޸ĵ���Ϣ:";
    int n,flag=0;
    cin>>n;
    if(n>5)
    {
        cout<<"û�д���,������ȷ����Ϣ"<<endl;
        return ;
    }
    cout<<"������Ҫ�޸ĺ����Ϣ:";
    char z[50];
    cin>>z;
    bianji_laber(z,p2,n);
    creat_tree(a,2);
    cout<<"\t\t\t"<<"�޸ĳɹ�"<<endl;
}
void bianji_clerical(char *a)
{
    clerical b,root,*head,*p;
    cout<<"\t\t\t"<<"**********************************"<<endl;
    cout<<"\t\t\t"<<"*1.���        2.����      3.����*"<<endl;
    cout<<"\t\t\t"<<"*4.������ò  5.Ŀǰְ��          *"<<endl;
    cout<<"\t\t\t"<<"**********************************"<<endl;
    cout<<"��ѡ��Ҫ�޸ĵ���Ϣ:";

    int n,flag=0;
    cin>>n;
    if(n>5)
    {
        cout<<"û�д���,������ȷ����Ϣ"<<endl;
        return ;
    }
    cout<<"������Ҫ�޸ĺ����Ϣ:";
    char z[50];
    cin>>z;
    bianji_clerical(z,p3,n);
    creat_tree(a,3);
    cout<<"\t\t\t"<<"�޸ĳɹ�"<<endl;
}
void bianji_people()
{
    char a[50];
    int x;
    cout<<"������Ҫ�޸�ְԱ�ı��:";
    cin>>a;
    x=find_tree(a);
    if(x==1)
    {
        cout<<"\t\t\t"<<"**********************************************************"<<endl;
        cout<<"\t\t\t"<<"��ʦ"<<endl;
        p5=p1;
        p5->print();
        cout<<"\t\t\t"<<"**********************************************************"<<endl;
        bianji_jiaoshi(a);
    }
    else if(x==2)
    {
        cout<<"\t\t\t"<<"**********************************************************"<<endl;
        cout<<"\t\t\t"<<"ʵ��Ա"<<endl;
        p5=p2;
        p5->print();
        cout<<"\t\t\t"<<"**********************************************************"<<endl;
        bianji_laber(a);
    }
    else if(x==3)
    {
        cout<<"\t\t\t"<<"**********************************************************"<<endl;
        cout<<"\t\t\t"<<"������Ա"<<endl;
        p5=p3;
        p5->print();
        cout<<"\t\t\t"<<"**********************************************************"<<endl;
        bianji_clerical(a);
    }
    else if(x==4)
    {
        cout<<"\t\t\t"<<"**********************************************************"<<endl;
        cout<<"\t\t\t"<<"��ʦ��������Ա"<<endl;
        p5=p4;
        p5->print();
        cout<<"\t\t\t"<<"**********************************************************"<<endl;
        bianji_tea_cle(a);
    }
    else
    {
        cout<<"δ�ҵ�ְԱ���"<<endl;
    }
}
void tongji_people()
{
    cout<<"\t\t\t"<<"**************************************************************************************"<<endl;
    cout<<"\t\t\t"<<"��ǰ��ʦ����:"<<x1<<"\n\t\t\t��ʦ��������Ա����:"<<x4<<"\n\t\t\tʵ��Ա����:"<<x2<<"\n\t\t\t������Ա����:"<<x3<<endl;
    cout<<"\t\t\t"<<"������:"<<x1+x2+x3+x4<<endl;
    cout<<"\t\t\t"<<"**************************************************************************************"<<endl;
}
int caidan(int x);
void clean_file()
{
    fstream f1("te_and_cl.txt",ios::out|ios::binary);
    f1.close();
    fstream f2("teacher.txt",ios::out|ios::binary);
    f2.close();
    fstream f3("laber.txt",ios::out|ios::binary);
    f3.close();
    fstream f4("clerical.txt",ios::out|ios::binary);
    f4.close();
}
void fanhui(int x)
{
    cout<<"�Ƿ񷵻ز˵�Y/N?"<<endl;
    string n;
    cin>>n;
    if(n=="Y"||n=="y")
    {
        qingping();
        caidan(x);
    }
    else if(n=="N"||n=="n")
    {
        clean_file();
        save_tree(&root);
        delete_tree(&root);
        return ;
    }
    else
    {
        cout<<"������������������:"<<endl;
        return fanhui(x);
    }
}
void caidanjiemian(int x)
{
    if(x==1)
    {
        cout<<"\t\t\t"<<"**********************************************"<<endl;
        cout<<"\t\t\t"<<"*                   &�û��˺�&                *"<<endl;
        cout<<"\t\t\t"<<"*0.�˳�ϵͳ   1.��ѯ��Ա��Ϣ   2.��ʾ��Ա��Ϣ *"<<endl;
        cout<<"\t\t\t"<<"***********************************************"<<endl;
    }
    else
    {
        cout<<"\t\t\t"<<"*************************************************"<<endl;
        cout<<"\t\t\t"<<"*                  &����Ա�˺�&                 *"<<endl;
        cout<<"\t\t\t"<<"*1.��ѯ��Ա��Ϣ   2.��ʾ��Ա��Ϣ  3.�����Ա��Ϣ*"<<endl;
        cout<<"\t\t\t"<<"*4.�༭��Ա��Ϣ   5.ɾ����Ա��Ϣ  6.ͳ����Ա��Ϣ*"<<endl;
        cout<<"\t\t\t"<<"*                 0.�˳�ϵͳ                    *"<<endl;
        cout<<"\t\t\t"<<"*************************************************"<<endl;
    }
}
int caidan(int x)
{
    qingping();
    int n;
    caidanjiemian(x);
    cout<<"������ѡ��Ĳ���:";
    cin>>n;
    if(n==1)
    {
        find_people();
        fanhui(x);
    }
    else if(n==2)
    {
        Show_people();
        fanhui(x);
    }
    else if(n==3&&x==2)
    {
        add_people();
        fanhui(x);
    }
    else if(n==4&&x==2)
    {
        bianji_people();
        fanhui(x);
    }
    else if(n==5&&x==2)
    {
        delete_people();
        fanhui(x);
    }
    else if(n==6&&x==2)
    {
        tongji_people();
        fanhui(x);
    }
    else if(n==0)
    {
        clean_file();
        save_tree(&root);
        delete_tree(&root);
    }
    else
    {
        cout<<"�޴�ѡ�����������"<<endl;
    }
}
void read_teacher()
{
    fstream ff("teacher.txt",ios::in|ios::out|ios::binary);
    if(!ff)
    {
        return ;
    }
    while(ff.read((char*)p1,sizeof(teacher)))
    {
        x1++;
        p1->cpy_num();
        creat_tree(num,1);
        p1=new teacher;
    }
    ff.close();
}
void read_laber()
{
    fstream ff("laber.txt",ios::in|ios::binary);
    if(!ff)
    {
        return ;
    }
    while(ff.read((char*)p2,sizeof(laber)))
    {
        x2++;
        p2->cpy_num();
        creat_tree(num,2);
        p2=new laber;
    }
    ff.close();
}
void read_clerical()
{
    fstream ff("clerical.txt",ios::in|ios::binary);
    if(!ff)
    {
        return ;
    }
    while(ff.read((char*)p3,sizeof(clerical)))
    {
        x3++;
        p3->cpy_num();
        creat_tree(num,3);
        p3=new clerical;
    }
    ff.close();
}
void read_tea_cle()
{
    fstream ff("te_and_cl.txt",ios::in|ios::binary);
    if(!ff)
    {
        return ;
    }
    while(ff.read((char*)p4,sizeof(te_and_cl)))
    {
        x4++;
        p4->cpy_num();
        creat_tree(num,4);
        p4=new te_and_cl;
    }
    ff.close();
}

int main()
{
//�����ļ���ʹ����������
//    fstream f("zhanghao.txt",ios::out|ios::binary);
//    f.close();
//    clean_file();
    p1=new teacher;
    p2=new laber;
    p3=new clerical;
    p4=new te_and_cl;
    read_teacher();
    read_laber();
    read_clerical();
    read_tea_cle();
    int x;
    x=zhanghao();
    caidan(x);
}
