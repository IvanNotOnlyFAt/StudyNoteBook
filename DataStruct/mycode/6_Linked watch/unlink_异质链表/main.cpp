#include <iostream>

using namespace std;

#include "person.h"
#include "schoollist.h"
#include "student.h"
#include "staff.h"
#include "teacher.h"

#include "assistant.h"

int main()
{
    Assistant ass(004,"����",19850101,5,"19850101");
    Student stu(001,"��һ",19850101,0,3);
    Staff sta(002,"����",19701212,1,"����");
    Teacher tea(003,"����",19500212,0,500);

    SchoolList testList;
    testList.Insert((Person *)&stu);
    testList.Insert((Person *)&sta);
    testList.Insert((Person *)&tea);
    testList.Insert((Person *)&ass);

    cout <<"Before Test Remove function:" <<endl;
    testList.print();

    cout <<"\n\nAfter Test Remove function:" <<endl;
    testList.Remove(002);
    testList.print();

    return 0;
}
