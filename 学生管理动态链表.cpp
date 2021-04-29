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
student* head;//����Ϊȫ�ַ������
int main()
{
    int select;
    cout << "������Ҫ�����ѧ������" << endl;
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
    cout << "��������������������������������" << endl;
    cout << "��1.ɾ��ѧ����Ϣ��" << endl;
    cout << "�ǩ�����������������������������" << endl;
    cout << "��2.���ѧ����Ϣ��" << endl;
    cout << "�ǩ�����������������������������" << endl;
    cout << "��3.����ѧ����Ϣ��" << endl;
    cout << "�ǩ�����������������������������" << endl;
    cout << "�� 0.�˳�/����  ��" << endl;
    cout << "��������������������������������" << endl;
    cout << "Ŀǰϵͳ����" << num << "����" << endl;
}
student* create()//��������
{
    student* head = new student;//����ͷ�ڵ�
    input(head);//ͷ�ڵ����ݳ�Ա��ֵ
    head->next = NULL;//ͷ�ڵ�Ĭ��ָ���
    student* p1 = head;//��¼��һ���ڵ�
    for (int i = 1;i < num;i++)
    {
        student* p = new student;//�����½ڵ�
        cout << "�������" << i + 1 << "��ѧ������Ϣ" << endl;
        input(p);//���ݳ�Ա��ֵ
        p1->next = p;//�ڵ�����
        p->next = NULL;//�½ڵ��ַָ��NULL;
        p1 = p;//��¼��һ���ڵ�
    }
    return head;
}

void input(struct student* p)
{
    cout << "�������ѧ����ѧ��" << endl;
    cin >> p->num;
    cout << "�������ѧ��������" << endl;
    cin >> p->name;
    cout << "�������ѧ���ĳɼ�" << endl;
    for (int i = 0;i < 3;i++)
        cin >> p->grade[i];
    cout << "��ӳɹ�" << endl;
    qingping();
}

void print(struct student* p)
{
    if (num == 0)
    {
        cout << "ϵͳδ�����κ�ѧ����Ϣ" << endl;
    }
    else
    {
        cout << "Ŀǰ��¼���ѧ����Ϣ" << endl;
        for (int i = 0;i < num;i++)
        {
                cout << "����" << p->name << " " << "ѧ��" << p->num << " " << "�ɼ�";
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
    cout << "��ǰϵͳ����" << num << "��ѧ��" << endl;
    cout << "����Ҫɾ���ڼ���ѧ��" << endl;
    cin >> a;
    if (a == 1)//��ɾ���Ľڵ���ͷ�ڵ�
    {
        p1 = head;
        head = head->next;
        delete p1;//�ͷ�ͷ�ڵ��ڴ�
    }
    else
    {
        p1 = head;//��p1ָ�������������
        p2 = head;//��¼ɾ���ڵ��ǰһ�ڵ�
        p3 = head;////��¼ɾ���Ľڵ�,�������ȳ�ʼ��Ϊhead
        for (int i = 0;i < a;i++)//��ɾ���Ľڵ�ĺ�һ�ڵ��׵�ַȡ��,����ɾ���ڵ��ǰһ���ڵ��ס
        {
            if (i == a - 2)
            {
                p2 = p1;//��¼ɾ���ڵ��ǰһ�ڵ�
                p3 = p1->next;//��¼ɾ���Ľڵ�
                if (p3->next == NULL)
                {
                    p2->next = NULL;
                    break;
                }
            }
            p1 = p1->next;//��¼ɾ���ڵ�ĺ�һ�ڵ�
        }
        if(p2->next!=NULL)
          p2->next = p1;//�����������ڵ�
        delete p3;//�ͷ�ɾ���Ľڵ��ڴ�   
    }
    num--;
}

void insert()
{
    int select;student* p1 = head, * p2 = head;//��p1ָ�������������
    cout << "ѡ�����ĸ�ѧ����������µ�ѧ��" << endl;
    cin >> select;
    for (int i = 0;i < select;i++)//
    {
        if (i == select - 2)
        {
            p2 = p1->next;//��¼����ڵ�
            if (p2->next == NULL)
                break;
        }
        p1 = p1->next;//��¼����ڵ�ĺ�һ�ڵ�
    }
    student *xin= new student;
    if (p2->next == NULL)//��ʱѡ����β�ڵ�����
        xin->next = NULL;
    else//����β�ڵ�����
        xin->next = p1;
    cout << "��Ϊ�²����ѧ����ֵ" << endl;
    input(xin);//���ݳ�Ա��ֵ
    p2->next = xin; //����
    num++;
}

void qingping()
{
    system("pause");
    system("cls");
}