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
    int select = 0, bianhao = 0, cz = 0;//select表示当前的选择，bianhao代表以输入系统的学生人数
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
    cout << "   欢迎来到教务管理系统" << endl;
    cout << "*********************************" << endl;
    cout << "*****1.输入学生信息         *****" << endl;
    cout << "*****2.输出学生信息         *****" << endl;
    cout << "*****3.查询学生信息         *****" << endl;
    cout << "*****4.查询平均成绩         *****" << endl;
    cout << "*****5.查找平均分最高的学生 *****" << endl;
    cout << "*****6.按平均成绩降序排列   *****" << endl;
    cout << "*****0.退出/返回            *****" << endl;
    cout << "*********************************" << endl;
}

void input(struct student* p, int bianhao)
{
    int num1;
    string name1;
    int grade1[3];
    p += bianhao;
    cout << "请输入该学生的学号" << endl;
    cin >> num1;
    p->num = num1;
    cout << "请输入该学生的姓名" << endl;
    cin >> name1;
    p->name = name1;
    cout << "请输入该学生的成绩" << endl;
    for (int i = 0;i < 3;i++)
        cin >> grade1[i];
    for (int i = 0;i < 3;i++)
        p->grade[i] = grade1[i];
    cout << "添加成功" << endl;
    system("pause");
    system("cls");
}

void output(struct student* p, int bianhao)
{
    cout << "目前已录入的学生信息" << endl;
    for (int i = 0;i < bianhao;i++)
    {
        cout << "姓名" << p->name << " " << "学号" << p->num
            << " " << "成绩";
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
    cout << "请输入学号" << endl;
    cin >> cz;
    for (int i = 0;i < bianhao;i++)
    {
        if (p->num == cz)
        {
            cout << "姓名" << p->name << " " << "学号" << p->num
                << " " << "成绩";
            for (int j = 0;j < 3;j++)
                cout << p->grade[j] << " ";
            a = 1;
            break;
        }
        p++;
    }
    if (a == 0)
        cout << "暂未录入此人的信息" << endl;
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
        cout << "学号：" << p->num << "的学生的平均成绩：";
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
    cout << "学号:" << p->num << " " << "姓名:"
        << p->name << " " << "的同学平均分最高 ";
    cout << "平均成绩:" << max << endl;
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
    cout << "按平均成绩降序排列" << endl;
    for (int i = 0;i < bianhao;i++)
    {
        cout << "姓名" << p->name << " " << "学号" << p->num
            << " " << "成绩";
        for (int j = 0;j < 3;j++)
            cout << p->grade[j] << " ";
        cout << "平均成绩为" << p->pjcj;
        cout << endl;
        p++;
    }
    system("pause");
    system("cls");
}