#ifndef __STUDENT_MS_H
#define __STUDENT_MS_H

#include "studentinfo.h"

class StudentMS
{
public:
    StudentMS();
    ~StudentMS();

    void openFile();
    void saveFile();
    void showMenu();
    int execSystem(void);

    void addInfo(void);
    void findInfo(void);
    void modifyInfo(void);
    void deleteInfo(void);
    void showInfos(void);
private:
    int m_index;
    bool m_isQuit;

    StudentInfoList m_infoList;
    StudentInfoList::iterator m_iter;
};

#endif // __STUDENT_MS_H
