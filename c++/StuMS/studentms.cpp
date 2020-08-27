#include "studentms.h"

#include <string.h>
#include <fstream>
#include <string.h>
#include <conio.h>//用getch();
#include <cstdlib>
#include <algorithm>
#include <iomanip>

StudentMS::StudentMS()
{
    m_index = 0;
    m_isQuit = false;
    openFile();
}

StudentMS::~StudentMS()
{
    saveFile();
}

void StudentMS::openFile()
{
    fstream f("./data/student.txt");
    if(!f){
        cout<<"这是一个新系统，无学生信息。请先输入。"<<endl;
    }else
    {
        string id, name, degree, major;
        while(f >> id >> name >> degree >> major)
        {
            StudentInfo info(id, name, degree, major);
            m_infoList.push_back(info);
        }
        f.close();
        cout<<"\t\t读取学生信息成功!"<<endl;
    }
}

void StudentMS::saveFile()
{
    fstream f("./data/student.txt", ios_base::out | ios::trunc);
    if(!f){
        cout<<""<<endl;
    }else
    {
        for(StudentInfoList::iterator it = m_infoList.begin();
                it != m_infoList.end(); it++)
        {
            f << it->getID() << "\t\t" << it->getName() << "\t\t"
                << it->getDegree() << "\t\t" << it->getMajor() <<'\n';
        }

        f.close();
    }

}

void StudentMS::showMenu()
{
    cout<<"********************************************************************************"<<endl;
    cout<<"〓〓〓〓〓〓〓〓〓〓〓  ☆   学 籍 管 理 子 系 统     ☆  〓〓〓〓〓〓〓〓〓〓〓"<<endl;
    cout<<"〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓"<<endl;
    cout<<"〓〓〓〓〓〓〓〓〓★  ☆         1.增加学生信息         ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
    cout<<"〓〓〓〓〓〓〓〓〓★  ☆         2.查询学生信息         ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
    cout<<"〓〓〓〓〓〓〓〓〓★  ☆         3.修改学生信息         ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
    cout<<"〓〓〓〓〓〓〓〓〓★  ☆         4.删除学生信息         ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
    cout<<"〓〓〓〓〓〓〓〓〓★  ☆         5.显示学生信息         ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
    cout<<"〓〓〓〓〓〓〓〓〓★  ☆         0.安全退出子系统       ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;

    cout<<"\n\t\t\n\t\t请选择：";
}

int StudentMS::execSystem(void)
{
    while(!m_isQuit)
    {
        system("cls");
        this->showMenu();
        cin>>m_index;
        switch(m_index)
        {
        case 0: m_isQuit=true; saveFile(); break;
        case 1: addInfo(); break;
        case 2: findInfo(); break;
        case 3: modifyInfo(); break;
        case 4: deleteInfo(); break;
        case 5: showInfos(); break;
        }

        cout<<"按任意键开始……";
        getch();
    }

    m_isQuit = false;
    return 0;
}

void StudentMS::addInfo(void)
{
    string id, name, degree, major;
    cout<<"\t\t请输入学生学号：";  cin>>id;
    cout<<"\t\t请输入学生姓名：";  cin>>name;
    cout<<"\t\t请输入学生专业：";  cin>>degree;
    cout<<"\t\t请输入学生班级：";  cin>>major;
    if(!id.empty() && !name.empty() && !degree.empty() && !major.empty())
    {
        StudentInfo info(id, name, degree, major);
        m_infoList.push_back(info);
    }
}

void StudentMS::findInfo(void)
{
    string id;
    cout<<"\t\t请输入学生学号<UG18-101>：";  cin>>id;
    for(StudentInfoList::iterator it = m_infoList.begin();
                it != m_infoList.end(); it++)
    {
        if(it->getID() == id)
        {
            m_iter = it;
        }
    }

    m_iter->display();
}

void StudentMS::deleteInfo(void)
{
    string id;
    cout<<"\t\t请输入学生学号<UG18-101>：";  cin>>id;
    for(StudentInfoList::iterator it = m_infoList.begin();
                it != m_infoList.end(); it++)
    {
        if(it->getID() == id)
        {
            it->display();
            it = m_infoList.erase(it);
        }
    }
}

void StudentMS::showInfos(void)
{
    system("cls");
    cout << "\t+-------------+----------------+--------------+----------------+" << endl;
    cout << "\t| 学号        | 姓名           |  年级        | 专业           |" << endl;
    cout << "\t+-------------+----------------+--------------+----------------+" << endl;
    for(StudentInfoList::iterator it = m_infoList.begin();
                it != m_infoList.end(); it++)
    {
        cout << "\t| " << setw(12) << left << it->getID()
             << "| " << setw(15) << it->getName()
             << "| " << setw(13) << it->getDegree()
             << "| " << setw(15) << right << it->getMajor() << "|" << endl;
    }
    cout << "\t+-------------+----------------+--------------+----------------+" << endl;
}

void StudentMS::modifyInfo(void)
{
    findInfo();
    cout<<"********************************************************************************"<<endl;
    cout<<"〓〓〓〓〓〓〓〓〓〓〓  ☆     学 生 信 息 修 改      ☆  〓〓〓〓〓〓〓〓〓〓〓"<<endl;
    cout<<"〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓"<<endl;
    cout<<"〓〓〓〓〓〓〓〓〓★  ☆         1.修改学生名称         ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
    cout<<"〓〓〓〓〓〓〓〓〓★  ☆         2.修改学生年级         ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
    cout<<"〓〓〓〓〓〓〓〓〓★  ☆         3.修改学生专业         ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<"\n\t\t\n\t\t请选择修改选项：";

    string var;
    cin>>m_index;
    switch(m_index)
    {
    case 1: cout<<"\t\t请输入新的学生名称：";  cin >> var; m_iter->setName(var); break;
    case 2: cout<<"\t\t请输入新的学生年级：";  cin >> var; m_iter->setDegree(var); break;
    case 3: cout<<"\t\t请输入新的学生专业：";  cin >> var; m_iter->setMajor(var); break;
    default: break;
    }
}
