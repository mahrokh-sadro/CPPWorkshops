

#ifndef SDDS_PRETRIAGE_H_
#define SDDS_PRETRIAGE_H_

#include "Patient.h"
#include "Time.h"
#include "Menu.h"

namespace sdds {
    const int maxNoOfPatients = 100;
    class PreTriage {
        Time
            m_averCovidWait,//the average wait time for COVID test
            m_averTriageWait;//Triage per patient
        Patient* m_lineup[maxNoOfPatients]{};
        char* m_dataFilename = nullptr;
        int m_lineupSize = 0;
        Menu
            m_appMenu,
            m_pMenu;
        void reg();
        void admit();
        const Time getWaitTime(const Patient& p)const;
        void setAverageWaitTime(const Patient& p);
        void removePatientFromLineup(int index);
        int indexOfFirstInLine(char type) const;
        void load();
    public:
        PreTriage(const char* dataFilename);
        ~PreTriage();
        void run(void);
    };
}

#endif
