
#define _CRT_SECURE_NO_WARNINGS

//////////////////////////////////////////////////////////////////use getcstr()where needed
///////////////////////////////////////add id
#include <iostream>
#include <fstream>

#include <cstring>


#include <string>

#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
//#include "Time.h"
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
        delete[] m_dataFilename;///////////////////////////////////////////???????????????????????????????/y doesnt crash
        if (dataFilename)
        {
            m_dataFilename = new char[strlen(dataFilename) + 1];
            strcpy(m_dataFilename, dataFilename);
        }
        load();

    }

    PreTriage::~PreTriage()//////
    {
       // cout << "                                                                          destructor is called      " << endl;

        ofstream fout(m_dataFilename);////?????????????????????????????????????????????????????????y skipped????


        cout << "Saving Average Wait Times," << endl
            << "   COVID Test: " << m_averCovidWait << endl
            << "   Triage: " << m_averTriageWait << endl
            << "Saving m_lineup..." << endl;
        fout << m_averCovidWait << ", " << m_averTriageWait << endl;


        for (int i = 0; /*m_lineup[i]*/i < m_lineupSize; i++)
        {
            cout << i+1 << "- ";
            m_lineup[i]->csvWrite() << endl;            //Patient
            m_lineup[i]->csvWrite(fout) << endl;                   //why doesnt show with fout????
        }
        //     cout << "m_lineupSize/~                                                                " << m_lineupSize << endl;

  


         //All the Patients pointed by the elements of the m_lineup array are deleted.
         //    data file name is deleted.
         //    the confirmation massage "done!" is printed on the screen at the end.

        for (int i = 0; /*m_lineup[i]*/i < m_lineupSize/*<maxNoOfPatients? m_lineupSize: maxNoOfPatients*/; i++)
        {
            delete m_lineup[i];

        }


        //    delete[] m_lineup;
        delete[] m_dataFilename;
        m_dataFilename = nullptr;
        cout << "done!" << endl;
    }

    const Time PreTriage::getWaitTime(const Patient& p) const/////////
    {
        //  cout << "                                                                          getWaitTime is called      " << endl;

        int i(0);
        unsigned count(-1);
        Time ret;
        for (i = 0; m_lineup[i]; i++)
        {
            if (p.type() == m_lineup[i]->type()) count++;////////////// y not *=            
        }

        if (p.type() == 'C')  ret = m_averCovidWait * count;
        else ret = m_averTriageWait * count;
        return Time(ret);///or just ret????
    }



    void PreTriage::setAverageWaitTime(const Patient& p)//bugyyyyyyyyyyyyyyyyyyyyyyy
    {
        //  cout << "                                                                          setAverageWaitTime is called      " << endl;

        int ct = getTime();
        int ptt = (Time)p;
        int ptn = p.number();
        int awt(-1);
        awt = ((ct - ptt) + (awt * (ptn - 1))) / ptn;
        if (p.type() == 'C')    awt = m_averCovidWait;
        else awt = m_averTriageWait;

    

    }
   


    void PreTriage::removePatientFromLineup(int index)// i ended up removing []?????
    {
        //     cout << "                                                                          removePatientFromLineup is called      " << endl;

        removeDynamicElement(m_lineup, index, m_lineupSize);//size?????
    }



    int PreTriage::indexOfFirstInLine(char type) const
    {
        //   cout << "                                                                          indexOfFirstInLine is called      " << endl;

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

        for(int i = 0; i < maxNoOfPatients && /*fin.fail()*/fin/*      */; i++)///////?????????????????????????????????
        {
            //char ch;
            fin >> ch;
            if(ch == 'C')  ptr = new CovidPatient();              
            if(ch == 'T')  ptr = new TriagePatient();
            if(ptr)
            {
                ptr->fileIO(true);
                //fin >> *ptr;
                ptr->csvRead(fin);

                ptr->fileIO(false);
                m_lineup[i] = ptr;
                m_lineupSize++;
            }
        }
        if (m_lineupSize >= 100)
            cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
        else if(m_lineupSize == 0)
            cout << "No data or bad data file!" << endl;
        if(m_lineupSize > 0)
            cout << m_lineupSize << " Records imported..." << endl;
        cout << endl;
    }
 

    void PreTriage::reg()
    {
     //   cout << "                                                                          reg is called      " << endl;

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
                            //terminates the function


        m_lineup[m_lineupSize]->setArrivalTime();
        cout << "Please enter patient information: " << endl;
        //(you might need to set the patient not to do File IO)///////////////////////////?????????
        m_lineup[m_lineupSize]->fileIO(false);
        //extract the patient from cin???????????????
      //  cin >> *m_lineup[m_lineupSize];
        m_lineup[m_lineupSize]->read(/*cin*/);
        cin.clear();
        cout << endl
            << "******************************************" << endl;
        m_lineup[m_lineupSize]->write();        //???????????????????????????????????????????????????????????
        cout << "Estimated Wait Time: "
            << getWaitTime(*m_lineup[m_lineupSize]) << endl
            << "******************************************" << endl << endl;
        m_lineupSize++;


    }


    void PreTriage::admit()
    {
     //   cout << "                                                                          admit is called      " << endl;

        int selec(0);
        m_pMenu >> selec;
        char typ(0);

        if (selec == 1) (typ = 'C');///????????
        else if (selec == 2) (typ = 'T');
        else if (selec == 0) exit(0);

        int idx = indexOfFirstInLine(typ);
        if (idx == -1) exit(0);
        cout << endl
            << "******************************************" << endl;
        //   set the patient not to do File IO???????????????????????????????????????
        m_lineup[idx]->fileIO(false);
        cout << "Calling for ";
        //                    insert the patient into cout?????
        m_lineup[idx]->write();
        cout << "******************************************" << endl << endl;
        setAverageWaitTime(*m_lineup[idx]);
        removePatientFromLineup(idx);
    //    cout << "m_lineupSize /admit                                                               " << m_lineupSize << endl;

    }

    void PreTriage::run(void)
    {
      //  cout << "                                                                          run is called      " << endl;

        int selec(0);
        do {

            m_appMenu >> selec;
            if (selec == 0) return;///?????????????????????wat else?????????????????????????????????????????
            if (selec == 1) reg();
            if (selec == 2) admit();

        } while (selec != 0);

    }

}