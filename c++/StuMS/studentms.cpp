#include "studentms.h"

#include <string.h>
#include <fstream>
#include <string.h>
#include <conio.h>//��getch();
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
        cout<<"����һ����ϵͳ����ѧ����Ϣ���������롣"<<endl;
    }else
    {
        string id, name, degree, major;
        while(f >> id >> name >> degree >> major)
        {
            StudentInfo info(id, name, degree, major);
            m_infoList.push_back(info);
        }
        f.close();
        cout<<"\t\t��ȡѧ����Ϣ�ɹ�!"<<endl;
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
    cout<<"����������������������  ��   ѧ �� �� �� �� ϵ ͳ     ��  ����������������������"<<endl;
    cout<<"��������������������         ��������         �������������������"<<endl;
    cout<<"��������������������  ��         1.����ѧ����Ϣ         ��  �������������������"<<endl;
    cout<<"��������������������  ��         2.��ѯѧ����Ϣ         ��  �������������������"<<endl;
    cout<<"��������������������  ��         3.�޸�ѧ����Ϣ         ��  �������������������"<<endl;
    cout<<"��������������������  ��         4.ɾ��ѧ����Ϣ         ��  �������������������"<<endl;
    cout<<"��������������������  ��         5.��ʾѧ����Ϣ         ��  �������������������"<<endl;
    cout<<"��������������������  ��         0.��ȫ�˳���ϵͳ       ��  �������������������"<<endl;

    cout<<"\n\t\t\n\t\t��ѡ��";
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

        cout<<"���������ʼ����";
        getch();
    }

    m_isQuit = false;
    return 0;
}

void StudentMS::addInfo(void)
{
    string id, name, degree, major;
    cout<<"\t\t������ѧ��ѧ�ţ�";  cin>>id;
    cout<<"\t\t������ѧ��������";  cin>>name;
    cout<<"\t\t������ѧ��רҵ��";  cin>>degree;
    cout<<"\t\t������ѧ���༶��";  cin>>major;
    if(!id.empty() && !name.empty() && !degree.empty() && !major.empty())
    {
        StudentInfo info(id, name, degree, major);
        m_infoList.push_back(info);
    }
}

void StudentMS::findInfo(void)
{
    string id;
    cout<<"\t\t������ѧ��ѧ��<UG18-101>��";  cin>>id;
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
    cout<<"\t\t������ѧ��ѧ��<UG18-101>��";  cin>>id;
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
    cout << "\t| ѧ��        | ����           |  �꼶        | רҵ           |" << endl;
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
    cout<<"����������������������  ��     ѧ �� �� Ϣ �� ��      ��  ����������������������"<<endl;
    cout<<"��������������������         ��������         �������������������"<<endl;
    cout<<"��������������������  ��         1.�޸�ѧ������         ��  �������������������"<<endl;
    cout<<"��������������������  ��         2.�޸�ѧ���꼶         ��  �������������������"<<endl;
    cout<<"��������������������  ��         3.�޸�ѧ��רҵ         ��  �������������������"<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<"\n\t\t\n\t\t��ѡ���޸�ѡ�";

    string var;
    cin>>m_index;
    switch(m_index)
    {
    case 1: cout<<"\t\t�������µ�ѧ�����ƣ�";  cin >> var; m_iter->setName(var); break;
    case 2: cout<<"\t\t�������µ�ѧ���꼶��";  cin >> var; m_iter->setDegree(var); break;
    case 3: cout<<"\t\t�������µ�ѧ��רҵ��";  cin >> var; m_iter->setMajor(var); break;
    default: break;
    }
}
