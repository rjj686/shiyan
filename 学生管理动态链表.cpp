#include<iostream>
#include<string>
using namespace std;
struct student* create();
void input(struct student* p);
void print(struct student* p);
void del();
void insert();
void qingping();
void tishi();

struct student
{
	int num;
	string name;
	int grade[3];
	student* next ;
};

int num;
student* head;//声明为全局方便操作
int main()
{
    int select;
    cout << "请输入要输入的学生数量" << endl;
    cin >> num;
    head = create();
    while (true)
    {
        tishi();
        cin >> select; 
        switch (select)
        {
        case 0:
            return 0;
        case 1:
            del();
            qingping();
            break;
        case 2:
            print(head);
            qingping();
            break;
        case 3:
            insert();
            break;
        }
    }
	return 0;
}

void tishi() {
    cout << "┏━━━━━━━━━━━━━━┓" << endl;
    cout << "┃1.删除学生信息┃" << endl;
    cout << "┣━━━━━━━━━━━━━━┫" << endl;
    cout << "┃2.输出学生信息┃" << endl;
    cout << "┣━━━━━━━━━━━━━━┫" << endl;
    cout << "┃3.插入学生信息┃" << endl;
    cout << "┣━━━━━━━━━━━━━━┫" << endl;
    cout << "┃ 0.退出/返回  ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━┛" << endl;
    cout << "目前系统共有" << num << "个人" << endl;
}
student* create()//建立链表
{
    student* head = new student;//创建头节点
    input(head);//头节点数据成员赋值
    head->next = NULL;//头节点默认指向空
    student* p1 = head;//记录上一个节点
    for (int i = 1;i < num;i++)
    {
        student* p = new student;//创建新节点
        cout << "请输入第" << i + 1 << "个学生的信息" << endl;
        input(p);//数据成员赋值
        p1->next = p;//节点连接
        p->next = NULL;//新节点地址指向NULL;
        p1 = p;//记录上一个节点
    }
    return head;
}

void input(struct student* p)
{
    cout << "请输入该学生的学号" << endl;
    cin >> p->num;
    cout << "请输入该学生的姓名" << endl;
    cin >> p->name;
    cout << "请输入该学生的成绩" << endl;
    for (int i = 0;i < 3;i++)
        cin >> p->grade[i];
    cout << "添加成功" << endl;
    qingping();
}

void print(struct student* p)
{
    if (num == 0)
    {
        cout << "系统未储存任何学生信息" << endl;
    }
    else
    {
        cout << "目前已录入的学生信息" << endl;
        for (int i = 0;i < num;i++)
        {
                cout << "姓名" << p->name << " " << "学号" << p->num << " " << "成绩";
            for (int j = 0;j < 3;j++)
                cout << p->grade[j] << " ";
            cout << endl;
            p= p->next;
        }
    }
}

void del()
{
    int a;student* p1,*p2,*p3;
    cout << "当前系统共有" << num << "个学生" << endl;
    cout << "请问要删除第几个学生" << endl;
    cin >> a;
    if (a == 1)//当删除的节点是头节点
    {
        p1 = head;
        head = head->next;
        delete p1;//释放头节点内存
    }
    else
    {
        p1 = head;//用p1指针访问整个链表
        p2 = head;//记录删除节点的前一节点
        p3 = head;////记录删除的节点,两个都先初始化为head
        for (int i = 0;i < a;i++)//将删除的节点的后一节点首地址取出,并将删除节点的前一个节点记住
        {
            if (i == a - 2)
            {
                p2 = p1;//记录删除节点的前一节点
                p3 = p1->next;//记录删除的节点
                if (p3->next == NULL)
                {
                    p2->next = NULL;
                    break;
                }
            }
            p1 = p1->next;//记录删除节点的后一节点
        }
        if(p2->next!=NULL)
          p2->next = p1;//连接这两个节点
        delete p3;//释放删除的节点内存   
    }
    num--;
}

void insert()
{
    int select;student* p1 = head, * p2 = head;//用p1指针访问整个链表
    cout << "选择在哪个学生后面插入新的学生" << endl;
    cin >> select;
    for (int i = 0;i < select;i++)//
    {
        if (i == select - 2)
        {
            p2 = p1->next;//记录插入节点
            if (p2->next == NULL)
                break;
        }
        p1 = p1->next;//记录插入节点的后一节点
    }
    student *xin= new student;
    if (p2->next == NULL)//此时选择在尾节点后插入
        xin->next = NULL;
    else//不在尾节点后插入
        xin->next = p1;
    cout << "请为新插入的学生赋值" << endl;
    input(xin);//数据成员赋值
    p2->next = xin; //连接
    num++;
}

void qingping()
{
    system("pause");
    system("cls");
}