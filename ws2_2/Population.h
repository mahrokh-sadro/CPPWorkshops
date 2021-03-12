//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 1.31.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {

    struct Postalcode {
        char m_postalcode[4];  //it says 3 letter postalcodes
        int m_population;
    };


    bool load(Postalcode& postal);

    bool load(const char filename[]);

    void display(const Postalcode& postal);
    void display();

    void deallocateMemory();
   

}
#endif // SDDS_POPULATION_H_