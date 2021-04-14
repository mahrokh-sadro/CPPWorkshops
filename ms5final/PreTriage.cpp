
/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
Version 1.0
Author	Mahrokh Sadrolodabaee
Id 159436195
msadrolodabaee@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2021/4/10  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "utils.h"

using namespace std;
namespace sdds {
    
    PreTriage::PreTriage(const char* dataFilename)
        :
        m_averCovidWait{ 15 },
        m_averTriageWait{ 5 },
        m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
        m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)

    {
        if (dataFilename)
        {
            m_dataFilename = new char[strlen(dataFilename) + 1];
            strcpy(m_dataFilename, dataFilename);
        }
        load();

    }

    PreTriage::~PreTriage()
    {

        ofstream fout(m_dataFilename);
        cout << "Saving Average Wait Times," << endl
            << "   COVID Test: " << m_averCovidWait << endl
            << "   Triage: " << m_averTriageWait << endl
            << "Saving m_lineup..." << endl;
        fout << m_averCovidWait << "," << m_averTriageWait << endl;

        for (int i = 0; i < m_lineupSize; i++)
        {
            cout << i+1 << "- ";
            m_lineup[i]->csvWrite() << endl;          
            m_lineup[i]->csvWrite(fout) << endl;                  
        }
        for (int i = 0; i < m_lineupSize; i++)
        {
            delete m_lineup[i];
        }
        delete[] m_dataFilename;
        m_dataFilename = nullptr;
        cout << "done!" << endl;
    }

    const Time PreTriage::getWaitTime(const Patient& p) const
    {

        int i(0);
        unsigned count(-1);
        Time ret;
        for (i = 0; m_lineup[i]; i++)
        {
            if (p.type() == m_lineup[i]->type()) count++;           
        }

        if (p.type() == 'C')  ret = m_averCovidWait * count;
        else ret = m_averTriageWait * count;
        return Time(ret);
    }

    void PreTriage::setAverageWaitTime(const Patient& p)
    {
        Time CT = getTime();
        Time PTT = (Time)p;
        Time AWT = p.type() == 'C' ? m_averCovidWait : m_averTriageWait;
        unsigned int PTN = p.number();
        AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;
        if (p.type() == 'C')    m_averCovidWait = AWT;
        else                    m_averTriageWait = AWT;
    } 

    void PreTriage::removePatientFromLineup(int index)
    {
        removeDynamicElement(m_lineup, index, m_lineupSize);
    }

    int PreTriage::indexOfFirstInLine(char type) const
    {
        int idx(-1);
        for (int i = 0; m_lineup[i]; i++)
        {
            if (m_lineup[i]->type() == type)
            {
                idx = i;
                break;
            }
        }
        return idx;
    }
    void PreTriage::load()
    {
        cout << "Loading data..." << endl;
        ifstream fin(m_dataFilename);
        fin >> m_averCovidWait;
        fin.ignore();
        fin >> m_averTriageWait;
        fin.ignore();
        Patient *ptr = nullptr;
        char ch(0);

        for(int i = 0; i < maxNoOfPatients && fin; i++)
        {
            ch='m';
            ptr = nullptr;

            fin >> ch;
            if(ch == 'C')  ptr = new CovidPatient();              
            if(ch == 'T')  ptr = new TriagePatient();
            if(ptr)
            {
                ptr->fileIO(true);
                fin >> *ptr; 
                ptr->fileIO(false);
                m_lineup[m_lineupSize++] = ptr;
            }
        }
        if (fin)
            cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
        if(m_lineupSize == 0)
            cout << "No data or bad data file!" << endl;
        else 
            cout << m_lineupSize << " Records imported..." << endl;
        cout << endl;
    }
 

    void PreTriage::reg()
    {

        if (m_lineupSize >= maxNoOfPatients)
        {
            cout << "Line up full!" << endl;
            return;
        }

        int selec;
        m_pMenu >> selec;
        if (selec == 1)                         m_lineup[m_lineupSize] = new CovidPatient;
        else if (selec == 2)                    m_lineup[m_lineupSize] = new TriagePatient;
        else if (selec == 0)                    return;

        m_lineup[m_lineupSize]->setArrivalTime();
        cout << "Please enter patient information: " << endl;
        m_lineup[m_lineupSize]->fileIO(false);
        cin >> *m_lineup[m_lineupSize];
        cin.clear();
        cout << endl
            << "******************************************" << endl;
        cout << *m_lineup[m_lineupSize];
        cout << "Estimated Wait Time: "
            << getWaitTime(*m_lineup[m_lineupSize]) << endl
            << "******************************************" << endl << endl;
        m_lineupSize++;

    }

    void PreTriage::admit()
    {

        int selec(0);
        m_pMenu >> selec;
        char typ(0);

        if (selec == 1) (typ = 'C');
        else if (selec == 2) (typ = 'T');
        else if (selec == 0) exit(0);

        int idx = indexOfFirstInLine(typ);
        if (idx == -1) exit(0);
        cout << endl
            << "******************************************" << endl;
        m_lineup[idx]->fileIO(false);
        cout << "Calling for ";
        cout << *m_lineup[idx];
        cout << "******************************************" << endl << endl;
        setAverageWaitTime(*m_lineup[idx]);
        removePatientFromLineup(idx);
    }

    void PreTriage::run(void)
    {
        int selec(0);
        do {
            m_appMenu >> selec;
            if (selec == 1) reg();
            if (selec == 2) admit();
            if (selec == 0) return;
        } while (selec != 0);

    }

}