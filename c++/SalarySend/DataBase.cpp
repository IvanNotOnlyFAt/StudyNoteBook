#include "database.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Person.h"
#include "string.h"
using namespace std;
int flag = 0;

char *myitoa(char *a,int n)
{
    int i = 0;
    int j = 0;
    char tmp = 0;
    char k;


    while(n > 0)
    {
        a[i] = (n % 10) + '0';
        n = n / 10;
        i ++;
    }
    a[i] = '\0';
    k = i ;
    for(j = 0; j < k/2 ; j ++)
    {
        tmp = a[j];
        a[j] = a[k - j - 1];
        a[k - j - 1] = tmp;
    }
    return a;
}

int myatoi(char *p)
{
    int num = 0;
	while(*p != '\0')
	{
		num = (*p - '0') + 10 * num;
		p ++;
	}
	return num;
}



int selet(void* para, int n_column, char ** column_value, char ** column_name)
{
    for(int i = 8; i > 0; i --)
    {
        cout.width(strlen(column_name[n_column - i]));
        cout << left  << column_name[n_column - i] <<  "|";
    }
    cout << endl;

    for(int j = 8; j > 0; j --)
    {
        cout.width(strlen(column_name[n_column - j]));
        if(column_value[n_column - j] != NULL)
        {
             cout << left <<column_value[n_column - j];
        }else
        {
            cout << "  ";
        }
        cout << "|";
    }
    cout << endl;
}

int display(void* para, int n_column, char ** column_value, char ** column_name)
{
    ofstream file("employeeinfo.txt",ios::app);
    Link *link = (Link*)para;
    if(flag == 0)
    {
        flag = 1;
        for(int i = 8; i > 0; i --)
        {
            file.width(30);
            cout.width(strlen(column_name[n_column - i]));
            file << left  << column_name[n_column - i] <<  "|";
            cout << left  << column_name[n_column - i] <<  "|";

        }
            cout << endl;
            file << endl;
    }

    if((column_value[4] != NULL) && (column_value[5] != NULL))
    {
        string number,name;
        number.append(column_value[0]);
        name.append(column_value[1]);
        Person *p = new HourEmployee(number,name,myatoi(column_value[2]),myatoi(column_value[4]),myatoi(column_value[5]));
        link->insertNode(p);
    }
    if((column_value[3] != NULL) && (column_value[6] == NULL))
    {
        string number,name;
        number.append(column_value[0]);
        name.append(column_value[1]);
        Person *p = new FixEmployee(number,name,myatoi(column_value[2]),myatoi(column_value[3]));
        link->insertNode(p);
    }
    if((column_value[3] != NULL) && (column_value[6] != NULL) &&(column_value[7] != NULL))
    {
        string number,name;
        number.append(column_value[0]);
        name.append(column_value[1]);
        Person *p = new PaidComissionEmployee(number,name,myatoi(column_value[2]),myatoi(column_value[3]),myatoi(column_value[6]),myatoi(column_value[6]));
        link->insertNode(p);
    }
    if((column_value[3] == NULL) && (column_value[6] != NULL) &&(column_value[7] != NULL))
    {
        string number,name;
        number.append(column_value[0]);
        name.append(column_value[1]);
        Person *p = new CommissionEmployee(number,name,myatoi(column_value[2]),myatoi(column_value[6]),myatoi(column_value[7]));
        link->insertNode(p);
    }

    for(int j = 8; j > 0; j --)
    {
        file.width(30);
        cout.width(strlen(column_name[n_column - j]));
        if(column_value[n_column - j] != NULL)
        {
             file << left <<column_value[n_column - j];
             cout << left <<column_value[n_column - j];
        }else
        {
            file << " ";
            cout << "  ";
        }
        cout << "|";
        file << "|";
    }
      cout << endl;
      file << endl;

    return 0;
}

DataBase::DataBase()
{
    int ok;
    char *error = NULL;
    flag = 0;
    ok = sqlite3_open("./DataBase/database.db",&m_db);
    if(ok == SQLITE_OK)
    {
//        cout << "数据库打开成功！" << endl;
    }else
    {
//        cout << "数据库打开失败！" << endl;
    }

    ok = sqlite3_exec(m_db,"create table EmployeeSalary"
                      "(Number varchar(10), "
                       "Name   varchar(10), "
                       "Age    int,"
                       "FixSalary int,"
                       "Hour   int,"
                       "HourSalary int,"
                       "Commission int,"
                       "CommissionSalary int,"
                       "primary key (Number));",NULL,NULL,&error);

    if(ok != 0)
    {
//         printf("插入失败，%s\n",error);
    }
}

DataBase::~DataBase()
{
    sqlite3_close(m_db);
//    cout << "数据库关闭" << endl;
};

bool DataBase::insetHourEmPloyee(HourEmployee* pe)
{
    int ok;
    char *error = NULL;
    char temp[20] = {0};
    string age = myitoa(temp,pe->getAge());
    temp[20] = {0};
    string hour = myitoa(temp,pe->getHour());
    temp[20] = {0};
    string hourSalary = myitoa(temp,pe->getHourSalary());
    string sql;
    sql.append("Insert Into EmployeeSalary(Number,Name,Age,Hour,HourSalary) values").append("('").append(pe->getNumber()).append("','")
    .append(pe->getName()).append("',").append(age).append(",").append(hour).append(",").append(hourSalary).append(")");

    char *mysql = (char*)sql.data();

    ok = sqlite3_exec(m_db,mysql,NULL,NULL,&error);
    if(ok != 0)
    {
        cout << "注册失败(员工已存在或输入格式错误)" << endl;
        return false;
    }else
    {
        cout << "注册成功！" << endl;
        return true;
    }
}

bool DataBase::insetFixEmployee(FixEmployee* pe)
{
    int ok;
    char *error = NULL;
    char temp[20] = {0};
    string age = myitoa(temp,pe->getAge());
    temp[20] = {0};
    string fixSalary = myitoa(temp,pe->getFixSalary());
    string sql;
    sql.append("Insert Into EmployeeSalary(Number,Name,Age,FixSalary) values").append("('").append(pe->getNumber()).append("','")
    .append(pe->getName()).append("',").append(age).append(",").append(fixSalary).append(")");
//    cout << sql << endl;
    char *mysql = (char*)sql.data();

    ok = sqlite3_exec(m_db,mysql,NULL,NULL,&error);
    if(ok != 0)
    {
       cout << "注册失败(员工已存在或输入格式错误)" << endl;
       return false;
    }else
    {
        cout << "注册成功！" << endl;
        return true;
    }
}
bool DataBase::insetCommissionEmployee(CommissionEmployee* pe)
{
    int ok;
    char *error = NULL;
    char temp[20] = {0};
    string age = myitoa(temp,pe->getAge());
    temp[20] = {0};
    string Commission = myitoa(temp,pe->getCommission());
    temp[20] = {0};
    string CommissionSalary = myitoa(temp,pe->getCommissionSalary());
    string sql;
    sql.append("Insert Into EmployeeSalary(Number,Name,Age,Commission,CommissionSalary) values").append("('").append(pe->getNumber()).append("','")
    .append(pe->getName()).append("',").append(age).append(",").append(Commission).append(",").append(CommissionSalary).append(")");
//    cout << sql << endl;
    char *mysql = (char*)sql.data();

    ok = sqlite3_exec(m_db,mysql,NULL,NULL,&error);
    if(ok != 0)
    {
        cout << "注册失败(员工已存在或输入格式错误)" << endl;
        return false;
    }else
    {
        cout << "注册成功！" << endl;
        return true;
    }
}
bool DataBase::insetPaidCommissionEmployee(PaidComissionEmployee* pe)
{
    int ok;
    char *error = NULL;
    char temp[20] = {0};
    string age = myitoa(temp,pe->getAge());
    temp[20] = {0};
    string baseSalary = myitoa(temp,pe->getFixSalary());
    temp[20] = {0};
    string comission = myitoa(temp,pe->getCommission());
    temp[20] = {0};
    string comissionSalary = myitoa(temp,pe->getCommissionSalary());
    string sql;
    sql.append("Insert Into EmployeeSalary(Number,Name,Age,Commission,CommissionSalary,FixSalary) values").append("('").append(pe->getNumber()).append("','")
    .append(pe->getName()).append("',").append(age).append(",").append(baseSalary).append(",").append(comission)
    .append(",").append(comissionSalary).append(")");
//    cout << sql << endl;
    char *mysql = (char*)sql.data();

    ok = sqlite3_exec(m_db,mysql,NULL,NULL,&error);
    if(ok != 0)
    {
        cout << "注册失败(员工已存在或输入格式错误)" << endl;
        return false;
    }else
    {
        cout << "注册成功！" << endl;
        return true;
    }
}

Link *DataBase::printEmployeeInfo(void)
{
    ofstream file("employeeinfo.txt",ios::out);
    file.clear();
    flag = 0;
    char *error;
    int ok;
    Link *link = new Link;
    void *para = link;

    ok = sqlite3_exec(m_db,"select * from EmployeeSalary",display,para,&error);
    if(ok != 0)
    {
        printf("%s\n",error);
    }
    return link;
}


 void DataBase::selectEmployee(string number)
 {
    char *error;
    int ok;
    string sql;
    sql.append("select * from EmployeeSalary where Number = '").append(number).append("'");
    char *mysql = (char*)sql.data();
    ok = sqlite3_exec(m_db,mysql,selet,NULL,&error);
    if(ok != 0)
    {
        printf("%s\n",error);
    }
 }

bool DataBase::deleteEmployee(string number)
{
    char *error;
    int ok;
    string sql;
    sql.append("delete from EmployeeSalary where Number = '").append(number).append("'");
    char *mysql = (char*)sql.data();
    ok = sqlite3_exec(m_db,mysql,NULL,NULL,&error);
    if(ok != 0)
    {
//        printf("注销失败!(注销员工不存在)\n");
//        return false;
    }else
    {
        cout << "注销成功！" << endl;
        return true;
    }
}






