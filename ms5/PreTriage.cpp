#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <fstream>

#include <cstring>
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
        m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit",2),
        m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage",2)
       
	    {
            delete[] m_dataFilename;//???????????????????????????????????????????????????????????????????
            if (dataFilename)
            {
                m_dataFilename = new char[strlen(dataFilename) + 1];
                strcpy(m_dataFilename, dataFilename);
            }
            load();
    //        cout << "m_lineupSize/const                                                            " << m_lineupSize << endl;

	    }


  

    PreTriage::~PreTriage()//////
    {
        ofstream fout(m_dataFilename);////?????????????????????????????????????????????????????????y skipped????
  
            cout << "Saving Average Wait Times," << endl
                << "  COVID Test: " << m_averCovidWait << endl
                << "  Triage: " << m_averTriageWait << endl
                << "Saving m_lineup..." << endl;
            fout << m_averCovidWait << ", " << m_averTriageWait << endl;


            for (int i = 0; /*m_lineup[i]*/i < m_lineupSize; i++)
            {
                cout << 1 << "- ";
                m_lineup[i]->csvWrite() << endl;
                m_lineup[i]->csvWrite(fout) << endl;                                         //why doesnt show with fout????
            }
           


            //All the Patients pointed by the elements of the m_lineup array are deleted.
            //    data file name is deleted.
            //    the confirmation massage "done!" is printed on the screen at the end.

            for (int i = 0; /*m_lineup[i]*/i < m_lineupSize; i++)
            {
                

                delete m_lineup[i];
                
            }



       // m_lineup[0]=0;
        delete[] m_dataFilename;
        m_dataFilename=nullptr;
        cout << "done!"<<endl;
    }

   

    const Time PreTriage::getWaitTime(const Patient& p) const/////////
    {
        int i(0);
        unsigned count(-1);/////////////////////////////////////////////////////////////////////////////////-1?
        Time ret;
        for (i = 0; m_lineup[i]; i++)
        {
            if (p.type() == m_lineup[i]->type()) count++;////////////// y not *=            
        }
      
        if (p.type() == 'C')  ret = m_averCovidWait * count;
        else ret = m_averTriageWait * count;
        return Time(ret);///or just ret????
    }

  

    void PreTriage::setAverageWaitTime(const Patient& p)
    {
        int ct = getTime();
        int ptt=(Time)p;
        int ptn=p.number();
        int awt(-1);

        if (p.type() == 'C')    awt = m_averCovidWait;
        else awt = m_averTriageWait;

        awt = ((ct - ptt) + (awt * (ptn - 1))) / ptn;

    }



    void PreTriage::removePatientFromLineup(int index)//why i ended up removing []?????
    {
        removeDynamicElement(m_lineup, index, m_lineupSize);//size or max?????
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
        if (fin) 
        {
            fin >> m_averCovidWait;//reading fom afile
            fin.ignore();
            fin >> m_averTriageWait;
            fin.ignore();
        }

    
       
       // m_lineup[i]
       // int count(0);
       // int Tcount(0);
        int i(0);
        Patient* ptr(nullptr);
        for (i = 0; i < maxNoOfPatients && fin; i++)
        {
            if (getchar() == 'C')
            {
                ptr = new CovidPatient();///()????
                // count++;
            }
            if (getchar() == 'T')

            {
                ptr = new TriagePatient();
                //count++;
            }


            if (ptr)
            {
                ptr->fileIO(true);//using file
                ptr->csvRead();////////???????????
                //cin >> *ptr;
                ptr->fileIO(false);//console
                //        copy the patient pointer to the lineup array of pointers??????????????????????????
              //  int idx=nex
                m_lineup[m_lineupSize] = ptr;
                m_lineupSize ++;


            }
        }

        if (m_lineupSize >= 100)
        {
            cout << "Warning: number of records exceeded 100" << endl
                << "100 Records imported...";
        }
        else if (m_lineupSize ==0) cout << "No data or bad data file!";
        else     cout<< m_lineupSize <<" Records imported...";
        cout << endl << endl;
    //    cout << "m_lineupSize/load                                                                 " << m_lineupSize << endl;

    }
                     
 
    void PreTriage::reg()
    {
        if (m_lineupSize >= maxNoOfPatients)
        {
            cout << "Line up full!" << endl;
            exit(0);
        }

        int selec;
        m_pMenu >> selec;
     

        if (selec == 1)                         m_lineup[m_lineupSize] = new CovidPatient;

        else if (selec == 2)                    m_lineup[m_lineupSize] = new TriagePatient;
    

        else if (selec == 0)             
            return;                  //terminates the function

       
        m_lineup[m_lineupSize]->setArrivalTime();
        cout << "Please enter patient information: "<<endl;
        //(you might need to set the patient not to do File IO)///////////////////////////?????????
        m_lineup[m_lineupSize]->fileIO(false);
        //extract the patient from cin???????????????
      //  cin >> *m_lineup[m_lineupSize];
        m_lineup[m_lineupSize]->read(/*cin*/);
        cout << endl
            << "******************************************" << endl;
        m_lineup[m_lineupSize]->write();        //???????????????????????????????????????????????????????????
        cout << "Estimated Wait Time: "
            << getWaitTime(*m_lineup[m_lineupSize]) << endl
            << "******************************************" << endl << endl;
        m_lineupSize++;

    //    cout << "m_lineupSize  /reg                                                               " << m_lineupSize << endl;

    
    }


    void PreTriage::admit()
    {
        int selec(0);
        m_pMenu>>selec;
        char typ(0);

        if (selec == 1) (typ = 'C');///????????
        else if(selec == 2) (typ = 'T');
        else if (selec == 0) exit(0);

        int idx=indexOfFirstInLine(typ);
        if (idx == -1) exit(0);
        cout << endl
            << "******************************************" << endl;
            //   set the patient not to do File IO???????????????????????????????????????
        m_lineup[idx]->fileIO(false);
        cout << "Calling for ";
        //                    insert the patient into cout?????
             m_lineup[idx]->write();
        cout << "******************************************" << endl<<endl;
        setAverageWaitTime(*m_lineup[idx]);
        removePatientFromLineup(idx);
   //    cout << "m_lineupSize /admit                                                               " << m_lineupSize << endl;

    }

    void PreTriage::run(void)
    {
        int selec(0);
        do {

            m_appMenu>>selec;
            if (selec == 0) return;
            if (selec == 1) reg();
            if (selec == 2) admit();

        } while (selec != 0);
       
    }



}
