#include <iostream>
#include "Link.h"
#include "Node.h"
#include "DataBase.h"
#include "Person.h"
#include "FixEmployee.h"
#include "HourEmployee.h"
#include "CommissionEmployee.h"
#include "PaidComissionEmployee.h"
#include <fstream>

using namespace std;

int main()
{

    Link *link = new Link;
    DataBase db;
    char n = 0;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>��ӭʹ�ù��ʷ���ϵͳ<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"  << endl;
start:
    cout << "ע��Ա��(A)           " <<"ע��Ա��(B)              "<<"�鿴����Ա����Ϣ(C)    "  << endl;
    cout << "����Ա��(D)           " <<"������Ϣ(E)              "<<"��            ��(F)    "  <<endl << endl;
    cout << "��ѡ����Ӧ����ĸ:";

    char number[20] = {0};
    char name[20] = {0};
    char type[20] = {0};
    int age = 0;
    int hour = 0;
    int commission = 0;
    int salary = 0;
    int commissionSalary = 0;


    cin >> n;
    cout << endl;
    if(n == 'A')
    {
        cin.ignore();
        cout << "��������Ա������:�ӵ�Ա��<H> ��нԱ��<I> Ӷ��Ա��<J> ��нӶ��Ա��<K> �˳�<L>" << endl;
        cin >> n;
        if(n == 'H')
        {
            cout << "������Ա����:";
            cin.ignore();
            cin.get(number,20);
            cin.ignore();
            cout << "������Ա������:";
            cin.get(name,20);
            cin.ignore();
            cout << "����������:";
            cin >> age;
            cin.ignore();
            cout << "�����빤��ʱ��(h):";
            cin >> hour;
            cin.ignore();
            cout << "������ÿСʱн��:";
            cin >> salary;
            cin.ignore();

            HourEmployee *pe = new HourEmployee(name,number,age,hour,salary);
            bool isOK = db.insetHourEmPloyee(pe);
            if(!isOK)
            {
                delete pe;
            }
            goto start;
        }else if(n == 'I')
        {
            cout << "������Ա����:";
            cin.ignore();
            cin.get(number,20);
            cin.ignore();
            cout << "������Ա������:";
            cin.get(name,20);
            cin.ignore();
            cout << "����������:";
            cin >> age;
            cin.ignore();
            cout << "������н��:";
            cin >> salary;
            cin.ignore();
            FixEmployee *pe = new FixEmployee(name,number,age,salary);
            bool isOK = db.insetFixEmployee(pe);
            if(!isOK)
            {
                delete pe;
            }
            goto start;
        }else if(n == 'J')
        {
             cout << "������Ա����:";
            cin.ignore();
            cin.get(number,20);
            cin.ignore();
            cout << "������Ա������:";
            cin.get(name,20);
            cin.ignore();
            cout << "����������:";
            cin >> age;
            cin.ignore();
            cout << "��������Ŀ����:";
            cin >> commission;
            cin.ignore();
            cout << "��������Ŀнˮ:";
            cin >> commissionSalary;
            cin.ignore();
            CommissionEmployee *pe = new CommissionEmployee(name,number,age,commission,commissionSalary);
            bool isOK = db.insetCommissionEmployee(pe);
            if(!isOK)
            {
                delete pe;
            }
            goto start;
        }else if(n == 'K')
        {
            cout << "������Ա����:";
            cin.ignore();
            cin.get(number,20);
            cin.ignore();
            cout << "������Ա������:";
            cin.get(name,20);
            cin.ignore();
            cout << "����������:";
            cin >> age;
            cin.ignore();
            cout << "�������������:";
            cin >> salary;
            cin.ignore();
            cout << "��������Ŀ����:";
            cin >> commission;
            cin.ignore();
            cout << "��������Ŀнˮ:";
            cin >> commissionSalary;
            cin.ignore();
            PaidComissionEmployee *pe = new PaidComissionEmployee(name,number,age,salary,commission,commissionSalary);
            bool isOK = db.insetPaidCommissionEmployee(pe);
            if(!isOK)
            {
                delete pe;
            }
            goto start;
        }else if(n == 'L')
        {
            goto start;
        }else{
                cin.ignore();
                cout << "����������������룡" << endl << endl;
                cout << "---------------" << endl;
                goto start;
            }
    }else if(n == 'B')
    {
        cin.ignore();
        cout << "������ע��Ա���ţ�";
        cin.get(number,20);
        string id;
        id.append(number);
        db.deleteEmployee(id);
        goto start;
    }else if(n == 'C')
    {
        cin.ignore();
        link = db.printEmployeeInfo();
        link->traverse();
        goto start;
    }else if(n == 'D')
    {
        cin.ignore();
        cout << "������Ա����:" << endl;
        cin.get(number,20);
        cin.ignore();
        string id1;
        id1.append(number);
        db.selectEmployee(id1);
        goto start;
    }else if(n == 'E')
    {
        cin.ignore();
        db.printEmployeeInfo();
        cout << "����Ա����Ϣ�Ѵ��浽�ļ���employeeinfo.txt����" << endl << endl;
        goto start;
    }else if(n == 'F')
    {
        return 0;
    }else
    {
        cout << "����" << endl << endl;
    }

}
