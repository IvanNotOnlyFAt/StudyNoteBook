#include <iostream>
using namespace std;

#include "employee.h"
#include "salariedemployee.h"
#include "commissionemployee.h"
#include "basepluscommissionemployee.h"
#include "hourlyemployee.h"

int main()
{
    SalariedEmployee xiaohong("123456", "xiaohong");
    xiaohong.display();

    CommissionEmployee xiaozhang("987654", "xiaozhang");
    xiaozhang.display();

    BasePlusCommissionEmployee xiaoming("112233", "xiaoming");
    xiaoming.display();

    HourlyEmployee xiaobai("445566", "xiaobai");
    xiaobai.display();

    BasePlusCommissionEmployee xiaohei("778855", "xiaohei");
    xiaohei.display();

    return 0;
}
