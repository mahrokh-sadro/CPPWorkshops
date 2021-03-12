//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 02.14.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#ifndef SDDS_BOX_H
#define SDDS_BOX_H



namespace sdds
{
    class Label
    {
        char* m_label; // pointer to the dma // a one - line text with an unknown size
        char m_frame[9]; // The frame is dictated by series of 8 characters in a Cstring.
    public:
        void setToDefault();
        void setLable(const char* theLable);
        void setFrame(const char* theFrame); // mine
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg,
            const char* content);
        ~Label();
        void readLabel();
        //void readFrame();       // mine
        //int lenOflabel();
        std::ostream& printLabel() const;
    };
}
#endif // !SDDS_BOX_H