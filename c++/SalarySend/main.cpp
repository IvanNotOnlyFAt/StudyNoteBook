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
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>欢迎使用工资发放系统<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"  << endl;
start:
    cout << "注册员工(A)           " <<"注销员工(B)              "<<"查看所有员工信息(C)    "  << endl;
    cout << "查找员工(D)           " <<"保存信息(E)              "<<"退            出(F)    "  <<endl << endl;
    cout << "请选择相应的字母:";

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
        cout << "请输入新员工类型:钟点员工<H> 定薪员工<I> 佣金员工<J> 带薪佣金员工<K> 退出<L>" << endl;
        cin >> n;
        if(n == 'H')
        {
            cout << "请输入员工号:";
            cin.ignore();
            cin.get(number,20);
            cin.ignore();
            cout << "请输入员工姓名:";
            cin.get(name,20);
            cin.ignore();
            cout << "请输入年龄:";
            cin >> age;
            cin.ignore();
            cout << "请输入工作时间(h):";
            cin >> hour;
            cin.ignore();
            cout << "请输入每小时薪资:";
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
            cout << "请输入员工号:";
            cin.ignore();
            cin.get(number,20);
            cin.ignore();
            cout << "请输入员工姓名:";
            cin.get(name,20);
            cin.ignore();
            cout << "请输入年龄:";
            cin >> age;
            cin.ignore();
            cout << "请输入薪资:";
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
             cout << "请输入员工号:";
            cin.ignore();
            cin.get(number,20);
            cin.ignore();
            cout << "请输入员工姓名:";
            cin.get(name,20);
            cin.ignore();
            cout << "请输入年龄:";
            cin >> age;
            cin.ignore();
            cout << "请输入项目个数:";
            cin >> commission;
            cin.ignore();
            cout << "请输入项目薪水:";
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
            cout << "请输入员工号:";
            cin.ignore();
            cin.get(number,20);
            cin.ignore();
            cout << "请输入员工姓名:";
            cin.get(name,20);
            cin.ignore();
            cout << "请输入年龄:";
            cin >> age;
            cin.ignore();
            cout << "请输入基础工资:";
            cin >> salary;
            cin.ignore();
            cout << "请输入项目个数:";
            cin >> commission;
            cin.ignore();
            cout << "请输入项目薪水:";
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
                cout << "输入错误请重新输入！" << endl << endl;
                cout << "---------------" << endl;
                goto start;
            }
    }else if(n == 'B')
    {
        cin.ignore();
        cout << "请输入注销员工号：";
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
        cout << "请输入员工号:" << endl;
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
        cout << "上述员工信息已储存到文件“employeeinfo.txt”中" << endl << endl;
        goto start;
    }else if(n == 'F')
    {
        return 0;
    }else
    {
        cout << "错误！" << endl << endl;
    }

}
