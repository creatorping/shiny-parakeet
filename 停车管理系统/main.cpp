
#include<bits/stdc++.h>
using namespace std;
int maxn,num,qum,money;
struct mad
{
    int f;//����״̬1��ʾ���룬2��ʾ�뿪��
    int month;
    int day;
    int hour;
    mad *next;
    mad()
    {
        this->next=NULL;
    }
};
map<string,int>mp;
map<string,mad>pp;
int f[15]= {0,31,30,31,30,31,30,31,31,30,31,30,31}; //�·ݶ�Ӧ������
struct node//���Ľṹ��
{
    string str;
    node *next;
    int month,day,hour;
    pri_car()
    {
        printf("\t\t\t�����복�����ƺ���");
        cin>>str;
        printf("\t\t\t��ǰʱ�䣨xx���£���xx���գ���xx��Сʱ��\n");
        printf("\t\t\t������(24Сʱ��):");
        scanf("%d��%d��%d",&month,&day,&hour);
    }
    node()
    {
        this->next=NULL;
    }
};
vector<node*>A;
void jilu(node *a,int f)
{
    mad *q=new mad,*p;
    q->month=a->month;
    q->day=a->day;
    q->hour=a  ->hour;
    q->f=f;
    p=&pp[a->str];
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
}
void out()
{
    mad *p;
    for(map<string,mad>::iterator it=pp.begin(); it!=pp.end(); it++)
    {
        printf("***********************************");
        printf("���ƺ�Ϊ��");
        cout<<it->first<<endl;
        printf("�ĳ���ͣ�ż�¼Ϊ\n");
        p=&it->second;
        while(p->next!=NULL)
        {
            p=p->next;
            if(p->f==1)
            {
                printf("%d:%d:%d",p->month,p->day,p->hour);
                printf("����\n");
            }
            if(p->f==2)
            {
                printf("%d:%d:%d",p->month,p->day,p->hour);
                printf("�뿪\n");
            }
        }
        printf("***********************************\n");
    }
}
void init()//��ʼ��
{
    num=qum=0;
    printf("\t\t\t*************************\n");
    printf("\t\t\t������ͣ�������ͣ������");
    scanf("%d",&maxn);
    printf("\t\t\t������ÿСʱͣ���շ�");
    scanf("%d",&money);
}
void to_stack(node *head,node *p)//��ջ
{
    p->next=head->next;
    head->next=p;
    mp[p->str]=1;
    num++;
    printf("\t\t\t���ź�Ϊ");
    cout<<p->str;
    printf("�ĳ�������ͣ����\n");
}
void pop_stack(node *head)//��ջ
{
    node *p=head->next;
    head->next=head->next->next;
    num--;
    mp[p->str]=0;
    printf("\t\t\t���ź�Ϊ");
    cout<<p->str;
    printf("�ĳ����뿪ͣ����\n");
}
node* top_stack(node *head)//����ջ��
{
    if(head->next!=NULL)
        return head->next;
    printf("\t\t\tͣ����û�г���\n");
    return NULL;
}
void to_queue(node *head,node *p)//�����
{
    while(head->next!=NULL)
        head=head->next;
    head->next=p;
    mp[p->str]=2;
    printf("\t\t\t���ź�Ϊ");
    cout<<p->str;
    qum++;
    printf("�ĳ�������Ⱥ���\n");
}
node* front_queue(node *head)//���ض���ͷ
{
    if(head->next!=NULL)
        return head->next;

    printf("\t\t\t�Ⱥ���û�г���");
}
void pop_queue(node *head)//������
{
    node *p=head->next;
    head->next=head->next->next;
    mp[p->str]=0;
    printf("\t\t\t���ź�Ϊ");
    cout<<p->str;
    qum--;
    printf("�ĳ����뿪�Ⱥ���\n");
    free(p);//�ڴ����
}
void add_car(node *sta,node *que)//�����³���
{
    node *p=new node;
    p->pri_car();
    if(mp[p->str])
    {
        printf("\t\t\t�����Ѵ���\n");
        return ;
    }
    if(maxn>num)
    {
        to_stack(sta,p);
        jilu(p,1);
    }
    else
    {
        printf("\t\t\tͣ�������������������жӵȴ�\n");
        to_queue(que,p);
    }
}
int cal_time(node *a,node *b)//����ʱ��
{
    int ans=0;
    for(int i=b->month; i<a->month; i++)
    {
        ans+=f[i];
    }
    ans=ans-b->day+a->day;
    ans*=24;
    ans=ans+(a->hour-b->hour);
    if(ans==0)
        return 1;
    return ans;
}
void leave_car(node *sta,node *que)//�����뿪
{
    int M;
    node p,*q;
    p.pri_car();
    if(mp[p.str]==1)
    {
        while(top_stack(sta)->str!=p.str)
        {
            A.push_back(top_stack(sta));
            pop_stack(sta);
        }
        M=cal_time(&p,top_stack(sta));
        jilu(&p,2);
        pop_stack(sta);
        for(int i=A.size()-1; i>=0; i--)
        {
            to_stack(sta,A[i]);
        }
        if(qum>0)
        {
            q=front_queue(que);
            pop_queue(que);
            to_stack(sta,q);
        }
        printf("\t\t\t����ͣ�Ź�%dСʱ��Ӧ�շ���Ϊ��%d\n",M,M*money);
    }
    else if(mp[p.str]==2)
    {
        while(que->next->str!=p.str)
            que=que->next;
        printf("\t\t\t���ƺ�Ϊ");
        cout<<p.str;
        printf("�ĳ����뿪�Ⱥ���");
        mp[p.str]=0;
        que->next=que->next->next;
    }
    else
    {
        printf("\t\t\tδ��ͣ�����͵Ⱥ����ҵ�����\n");
    }
}
int caidan()//�˵�
{
    system("cls");//����
    int n;
    printf("\t\t\t******************************************************\n");
    printf("\t\t\t******************************************************\n");
    printf("\t\t\t**             ��ӭ����ͣ������ϵͳ                 **\n");
    printf("\t\t\t**             ��������Ҫѡ��Ĺ���                 **\n");
    printf("\t\t\t**             1.�����µĳ���                       **\n");
    printf("\t\t\t**             2.�����뿪                           **\n");
    printf("\t\t\t**             3.ͳ�Ƴ���                           **\n");
    printf("\t\t\t**             4.��ʷ��¼                           **\n");
    printf("\t\t\t**             5.�˳�ϵͳ                           **\n");
    printf("\t\t\t******************************************************\n");
    printf("\t\t\t******************************************************\n");
    printf("\t\t\t*������:");
    scanf("%d",&n);
    return n;
}
void tongji_car(node *sta,node *que)//ͳ�Ƴ���
{
    int a=0,b=0;
    for(map<string,int>::iterator it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second==1)
            a++;
        if(it->second==2)
            b++;
    }
    printf("ͣ����������Ϊ%d\t\t�Ⱥ���������Ϊ%d\n",a,b);
    printf("ͣ��������Ϊ:\n");
    while(sta->next!=NULL)
    {
        sta=sta->next;
        printf("******************************************************\n");
        printf("���ƺ�Ϊ��");
        cout<<sta->str<<endl;
        printf("ͣ��ʱ��Ϊ");
        printf("%d:%d:%d\n",sta->month,sta->day,sta->hour);
        printf("******************************************************\n");
    }
    printf("\n��������Ϊ:\n");
    while(que->next!=NULL)
    {
        printf("******************************************************\n");
        que=que->next;
        printf("���ƺ�Ϊ��");
        cout<<que->str<<endl;
        printf("ͣ��ʱ��Ϊ");
        printf("%d:%d:%d\n",que->month,que->day,que->hour);
        printf("******************************************************\n");

    }
    return ;
}
int main()
{
    init();
    node sta,que;
    int n;
l:
    n=caidan();
    switch(n)
    {
    case 1:
        add_car(&sta,&que);
        getchar();
        printf("\t&&&&&&&&&&&&\n");
        printf("\t&�س�������&\n");
        printf("\t&&&&&&&&&&&&");
        getchar();
        goto l;
    case 2:
        leave_car(&sta,&que);
        getchar();
        printf("\t&&&&&&&&&&&&\n");
        printf("\t&�س�������&\n");
        printf("\t&&&&&&&&&&&&");
        getchar();
        goto l;
    case 3:
        tongji_car(&sta,&que);
        getchar();
        printf("\t&&&&&&&&&&&&\n");
        printf("\t&�س�������&\n");
        printf("\t&&&&&&&&&&&&");
        getchar();
        goto l;
    case 4:
        out();
        getchar();
        printf("\t&&&&&&&&&&&&\n");
        printf("\t&�س�������&\n");
        printf("\t&&&&&&&&&&&&");
        getchar();
        goto l;
    case 5:
        break;
    default:
        printf("��������\n");
        getchar();
        printf("\t&&&&&&&&&&&&\n");
        printf("\t&�س�������&\n");
        printf("\t&&&&&&&&&&&&");
        getchar();
        goto l;
    }
}
