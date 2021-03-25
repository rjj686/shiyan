#include<iostream>
#include<string>
#define MAX 10
using namespace std;
void tishi();
void input(struct student* p, int bianhao);
void output(struct student* p, int bianhao);
void chazhao(struct student* p, int bianhao);
void pinjun(struct student* p, int bianhao);
void pinjunmax(struct student* p, int bianhao);
void sort(struct student* p, int bianhao);

struct student
{
    int num;
    string name;
    int grade[3];
    float pjcj=0;
};

int main()
{
    int select = 0, bianhao = 0, cz = 0;//select��ʾ��ǰ��ѡ��bianhao����������ϵͳ��ѧ������
    student Student[MAX];
    while (1)
    {
        tishi();
        cin >> select;
        switch (select)
        {
        case 1:
            input(Student, bianhao);
            bianhao++;
            break;
        case 2:
            output(Student, bianhao);
            break;
        case 3:
            chazhao(Student, bianhao);
            break;
        case 4:
            pinjun(Student, bianhao);
            break;
        case 5:
            pinjunmax(Student, bianhao);
            break;
        case 6:
            sort(Student, bianhao);
            break;
        case 0:
            return 0;
        }
    }
    system("pause");
    return 0;
}

void tishi()
{
    cout << "*********************************" << endl;
    cout << "   ��ӭ�����������ϵͳ" << endl;
    cout << "*********************************" << endl;
    cout << "*****1.����ѧ����Ϣ         *****" << endl;
    cout << "*****2.���ѧ����Ϣ         *****" << endl;
    cout << "*****3.��ѯѧ����Ϣ         *****" << endl;
    cout << "*****4.��ѯƽ���ɼ�         *****" << endl;
    cout << "*****5.����ƽ������ߵ�ѧ�� *****" << endl;
    cout << "*****6.��ƽ���ɼ���������   *****" << endl;
    cout << "*****0.�˳�/����            *****" << endl;
    cout << "*********************************" << endl;
}

void input(struct student* p, int bianhao)
{
    int num1;
    string name1;
    int grade1[3];
    p += bianhao;
    cout << "�������ѧ����ѧ��" << endl;
    cin >> num1;
    p->num = num1;
    cout << "�������ѧ��������" << endl;
    cin >> name1;
    p->name = name1;
    cout << "�������ѧ���ĳɼ�" << endl;
    for (int i = 0;i < 3;i++)
        cin >> grade1[i];
    for (int i = 0;i < 3;i++)
        p->grade[i] = grade1[i];
    cout << "��ӳɹ�" << endl;
    system("pause");
    system("cls");
}

void output(struct student* p, int bianhao)
{
    cout << "Ŀǰ��¼���ѧ����Ϣ" << endl;
    for (int i = 0;i < bianhao;i++)
    {
        cout << "����" << p->name << " " << "ѧ��" << p->num
            << " " << "�ɼ�";
        for (int j = 0;j < 3;j++)
            cout << p->grade[j] << " ";
        cout << endl;
        p++;
    }
    system("pause");
    system("cls");
}

void chazhao(struct student* p, int bianhao)
{
    int cz; bool a = 0;
    cout << "������ѧ��" << endl;
    cin >> cz;
    for (int i = 0;i < bianhao;i++)
    {
        if (p->num == cz)
        {
            cout << "����" << p->name << " " << "ѧ��" << p->num
                << " " << "�ɼ�";
            for (int j = 0;j < 3;j++)
                cout << p->grade[j] << " ";
            a = 1;
            break;
        }
        p++;
    }
    if (a == 0)
        cout << "��δ¼����˵���Ϣ" << endl;
    system("pause");
    system("cls");
}

void pinjun(struct student* p, int bianhao)
{
    for (int i = 0;i < bianhao;i++)
    {
        float sum = 0;
        for (int j = 0;j < 3;j++)
            sum = p->grade[j] + sum;
        p->pjcj = sum / 3;
        cout << "ѧ�ţ�" << p->num << "��ѧ����ƽ���ɼ���";
        cout << p->pjcj << endl;
        p++;
    }
    system("pause");
    system("cls");
}

void pinjunmax(struct student* p, int bianhao)
{
    int m = 0;
    float max = p->pjcj;
    for (int i = 0;i < bianhao;i++)
    {
        float sum = 0;
        for (int j = 0;j < 3;j++)
            sum = p->grade[j] + sum;
        p->pjcj = sum / 3;
        p++;
    }
    p -= bianhao;
    for (int k = 0;k < bianhao;k++)
    {
        if (max < p->pjcj)
        {
            max = p->pjcj;
            m++;
        }
        p++;
    }
    p -= bianhao;
    p += m;
    cout << "ѧ��:" << p->num << " " << "����:"
        << p->name << " " << "��ͬѧƽ������� ";
    cout << "ƽ���ɼ�:" << max << endl;
    system("pause");
    system("cls");
}

void sort(struct student* p, int bianhao)
{
    student stu;
    for (int i = 0;i < bianhao;i++)
    {
        float sum = 0;
        for (int j = 0;j < 3;j++)
            sum = p->grade[j] + sum;
        p->pjcj = sum / 3;
        p++;
    }
    p -= bianhao;
    for (int i = 0;i < bianhao-1;i++)
    {
        for (int j = 0;j < bianhao - i - 1;j++)
        {
            if ((p + j)->pjcj < (p + j + 1)->pjcj)
            {
                stu =*(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = stu;
            }
        }
    }
    cout << "��ƽ���ɼ���������" << endl;
    for (int i = 0;i < bianhao;i++)
    {
        cout << "����" << p->name << " " << "ѧ��" << p->num
            << " " << "�ɼ�";
        for (int j = 0;j < 3;j++)
            cout << p->grade[j] << " ";
        cout << "ƽ���ɼ�Ϊ" << p->pjcj;
        cout << endl;
        p++;
    }
    system("pause");
    system("cls");
}