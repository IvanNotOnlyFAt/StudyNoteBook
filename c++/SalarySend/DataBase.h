#ifndef DATABASE_H
#define DATABASE_H
#include "sqlite3.h"
#include "Link.h"
#include "Person.h"
#include "FixEmployee.h"
#include "HourEmployee.h"
#include "CommissionEmployee.h"
#include "PaidComissionEmployee.h"

class DataBase
{
public:
    DataBase();
    ~DataBase();
    bool insetHourEmPloyee(HourEmployee*);
    bool insetFixEmployee(FixEmployee*);
    bool insetCommissionEmployee(CommissionEmployee*);
    bool insetPaidCommissionEmployee(PaidComissionEmployee*);
    Link *printEmployeeInfo(void);
    void selectEmployee(string);
    bool deleteEmployee(string);
    static Link m_link;

private:
    sqlite3 *m_db;


};



#endif // FIXEMPLOYEE_H
