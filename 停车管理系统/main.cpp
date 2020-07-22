
#include<bits/stdc++.h>
using namespace std;
int maxn,num,qum,money;
struct mad
{
    int f;//车辆状态1表示进入，2表示离开。
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
int f[15]= {0,31,30,31,30,31,30,31,31,30,31,30,31}; //月份对应的天数
struct node//车的结构体
{
    string str;
    node *next;
    int month,day,hour;
    pri_car()
    {
        printf("\t\t\t请输入车辆车牌号码");
        cin>>str;
        printf("\t\t\t当前时间（xx（月）：xx（日）：xx（小时）\n");
        printf("\t\t\t请输入(24小时制):");
        scanf("%d：%d：%d",&month,&day,&hour);
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
        printf("车牌号为：");
        cout<<it->first<<endl;
        printf("的车辆停放记录为\n");
        p=&it->second;
        while(p->next!=NULL)
        {
            p=p->next;
            if(p->f==1)
            {
                printf("%d:%d:%d",p->month,p->day,p->hour);
                printf("进入\n");
            }
            if(p->f==2)
            {
                printf("%d:%d:%d",p->month,p->day,p->hour);
                printf("离开\n");
            }
        }
        printf("***********************************\n");
    }
}
void init()//初始化
{
    num=qum=0;
    printf("\t\t\t*************************\n");
    printf("\t\t\t请输入停车场最大停车数量");
    scanf("%d",&maxn);
    printf("\t\t\t请输入每小时停车收费");
    scanf("%d",&money);
}
void to_stack(node *head,node *p)//入栈
{
    p->next=head->next;
    head->next=p;
    mp[p->str]=1;
    num++;
    printf("\t\t\t车排号为");
    cout<<p->str;
    printf("的车辆放入停车场\n");
}
void pop_stack(node *head)//出栈
{
    node *p=head->next;
    head->next=head->next->next;
    num--;
    mp[p->str]=0;
    printf("\t\t\t车排号为");
    cout<<p->str;
    printf("的车辆离开停车场\n");
}
node* top_stack(node *head)//返回栈顶
{
    if(head->next!=NULL)
        return head->next;
    printf("\t\t\t停车场没有车辆\n");
    return NULL;
}
void to_queue(node *head,node *p)//入队列
{
    while(head->next!=NULL)
        head=head->next;
    head->next=p;
    mp[p->str]=2;
    printf("\t\t\t车排号为");
    cout<<p->str;
    qum++;
    printf("的车辆放入等候区\n");
}
node* front_queue(node *head)//返回队列头
{
    if(head->next!=NULL)
        return head->next;

    printf("\t\t\t等候区没有车辆");
}
void pop_queue(node *head)//出队列
{
    node *p=head->next;
    head->next=head->next->next;
    mp[p->str]=0;
    printf("\t\t\t车排号为");
    cout<<p->str;
    qum--;
    printf("的车辆离开等候区\n");
    free(p);//内存回收
}
void add_car(node *sta,node *que)//加入新车辆
{
    node *p=new node;
    p->pri_car();
    if(mp[p->str])
    {
        printf("\t\t\t车辆已存在\n");
        return ;
    }
    if(maxn>num)
    {
        to_stack(sta,p);
        jilu(p,1);
    }
    else
    {
        printf("\t\t\t停车场已满，将车放入列队等待\n");
        to_queue(que,p);
    }
}
int cal_time(node *a,node *b)//计算时间
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
void leave_car(node *sta,node *que)//车辆离开
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
        printf("\t\t\t车辆停放共%d小时，应收费用为：%d\n",M,M*money);
    }
    else if(mp[p.str]==2)
    {
        while(que->next->str!=p.str)
            que=que->next;
        printf("\t\t\t车牌号为");
        cout<<p.str;
        printf("的车辆离开等候区");
        mp[p.str]=0;
        que->next=que->next->next;
    }
    else
    {
        printf("\t\t\t未在停车场和等候区找到车辆\n");
    }
}
int caidan()//菜单
{
    system("cls");//清屏
    int n;
    printf("\t\t\t******************************************************\n");
    printf("\t\t\t******************************************************\n");
    printf("\t\t\t**             欢迎来到停车管理系统                 **\n");
    printf("\t\t\t**             请输入你要选择的功能                 **\n");
    printf("\t\t\t**             1.加入新的车辆                       **\n");
    printf("\t\t\t**             2.车辆离开                           **\n");
    printf("\t\t\t**             3.统计车辆                           **\n");
    printf("\t\t\t**             4.历史纪录                           **\n");
    printf("\t\t\t**             5.退出系统                           **\n");
    printf("\t\t\t******************************************************\n");
    printf("\t\t\t******************************************************\n");
    printf("\t\t\t*请输入:");
    scanf("%d",&n);
    return n;
}
void tongji_car(node *sta,node *que)//统计车辆
{
    int a=0,b=0;
    for(map<string,int>::iterator it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second==1)
            a++;
        if(it->second==2)
            b++;
    }
    printf("停车场车辆数为%d\t\t等候区车辆数为%d\n",a,b);
    printf("停车场车辆为:\n");
    while(sta->next!=NULL)
    {
        sta=sta->next;
        printf("******************************************************\n");
        printf("车牌号为：");
        cout<<sta->str<<endl;
        printf("停放时间为");
        printf("%d:%d:%d\n",sta->month,sta->day,sta->hour);
        printf("******************************************************\n");
    }
    printf("\n候车区车辆为:\n");
    while(que->next!=NULL)
    {
        printf("******************************************************\n");
        que=que->next;
        printf("车牌号为：");
        cout<<que->str<<endl;
        printf("停放时间为");
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
        printf("\t&回车键继续&\n");
        printf("\t&&&&&&&&&&&&");
        getchar();
        goto l;
    case 2:
        leave_car(&sta,&que);
        getchar();
        printf("\t&&&&&&&&&&&&\n");
        printf("\t&回车键继续&\n");
        printf("\t&&&&&&&&&&&&");
        getchar();
        goto l;
    case 3:
        tongji_car(&sta,&que);
        getchar();
        printf("\t&&&&&&&&&&&&\n");
        printf("\t&回车键继续&\n");
        printf("\t&&&&&&&&&&&&");
        getchar();
        goto l;
    case 4:
        out();
        getchar();
        printf("\t&&&&&&&&&&&&\n");
        printf("\t&回车键继续&\n");
        printf("\t&&&&&&&&&&&&");
        getchar();
        goto l;
    case 5:
        break;
    default:
        printf("输入有误\n");
        getchar();
        printf("\t&&&&&&&&&&&&\n");
        printf("\t&回车键继续&\n");
        printf("\t&&&&&&&&&&&&");
        getchar();
        goto l;
    }
}
