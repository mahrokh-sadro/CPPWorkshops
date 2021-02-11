 #define _CRT_SECURE_NO_WARNINGS
#include <istream>    ///why
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"


#include <cstring>

#define SDDS_DEBUG

using namespace std;
namespace sdds {

	const double PI(3.14159265);



	/*sets the content name pointer to null,
		height to 13.0, diameter to 10.0, 
		content volume to 0.0 and usable flag to true.*/

	void Canister::setToDefault()	{
		m_contentName = nullptr;
		m_hieght=13.0;
		m_diameter=10.0;
		m_contentVolume=0.0;
		m_usable=true;

	}

	/*Returns true is the content volume is less 
		than 0.00001 CCs.*/
	bool Canister::isEmpty() const	{

		return m_contentVolume < 0.00001;
		
	}

	//Compares the content name of this Canister
	//	with the one received from the argument
	//	C.Using strCmp in cstring.h, it returns
	//	true if both content names are not null
	//	and are identical.Otherwise, it returns false;
	           //showCans("Milk canisters", &C[5], 2);
	bool Canister::hasSameContent(const Canister& C) const { //is ref always an obj? is ref of type class always an obj?
	                                                         //whats the type of C?????C is an object
	                                                      	//compare the name of current obj with the ones for C
		return ((*this).m_contentName && C.m_contentName && strcmp((*this).m_contentName, C.m_contentName)==0);
		
	}


	//Sets the content name of the current Canister.
	//	If the incoming Cstr is not null and the Canister is usable,
	//	it will delete the current content name, allocate memory to the 
	//	length of Cstr(+1 for null) and copies the Cstr into the newly allocated 
	//	memory.Otherwise, it will silently do nothing.

	void Canister::setName(const char* Cstr)	{

		if (Cstr && m_usable == true) {

			delete[] m_contentName;
			
			m_contentName = new char[strlen(Cstr) + 1];
			strcpy(m_contentName, Cstr);
			m_contentName[strlen(Cstr)]=0;
		}
		//Otherwise, it will silently do nothing.

	}



	//By default a Canister is created with the following heightand
	//	diameter: 13.0 x 10.0 with no name and content amount of 0 (empty)
	//Sets the attributes to their default values

	Canister::Canister()	{         //dont call this
#ifdef  SDDS_DEBUG

		cout << "default constructor" << endl;
#endif

		setToDefault();
	}


	//Sets the attributes to their default values(note: reuse code)
	//	Sets the Name to the incoming contentName argument.


	Canister::Canister(const char* contentName)	{ //dont call this , cant call a constructor!!!!
#ifdef  SDDS_DEBUG

		cout << "1 arg constructor" << endl;
#endif


		setToDefault();
		setName(contentName);

	}


	/*Sets the attributes to their default values.

		If the dimensions are within acceptable values :

	it will set the m_heightand m_diameter to the corresponding argument values
		it will set the content volume to 0.
		it will set the content name to the corresponding argument value.

		If any of the dimensions have invalid values, it will set the Canister unusable*/

	/*The smallest Canister can have a height and diameter of 10.0 by 10.0 
		centimetres and the largest one can be 40 by 30 respectively.*/


	Canister::Canister(double hieght, double diameter, const char* contentName)	{//dont call this

#ifdef  SDDS_DEBUG

		cout << "3 arg constructor" << endl;
#endif



		setToDefault();
		if (hieght >= 10 && hieght <= 40 && diameter >= 10 && diameter <= 30) {

			m_hieght = hieght; ///can I     m_hieght(hieght)???? call to a 1-arg function???????even not a moment of creation
			m_diameter = diameter;
			m_contentVolume = 0.00000000001;
			setName(contentName);   ///Im of two minds if Im supposed to do sth like obj.setName(contentName) yyyyy????????
		}                            //arent we calling these stuff on main using dot notation
		else {
			m_usable = false;
		}

	}

	//Deallocates the dynamic memory pointed by the content name attribute.



	Canister::~Canister()	{
#ifdef  SDDS_DEBUG

		cout << "destructor" << endl;

#endif



		delete[] m_contentName;
		m_contentName = nullptr;
	}


	//Clears an unusable Canister back to an empty Canister by :

	//deallocating the memory pointed by the content name attribute
	//	sets the content name attribute to nullptr
	//	sets the content volume attribute to 0.0
	//	set the usable flag attribute to true

	void Canister::clear() {
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;            ////////////////0.00000000000000000000000000000000000000000001
		m_usable = true;
	}

	//returns the capacity as stated in Calculating the capacity
	/*A Canister's capacity (i.e. maximum amount of content it can hold) is calculated as follows:

		PI: 3.14159265  (a global constant double value created in Canister.cpp)
		H : Height
		D : Diameter
		Capacity = PI x(H - 0.267) x(D / 2) x(D / 2)*/

	double Canister::capacity() const {//need conversion to metric???????

		double H(m_hieght);
		double D(m_diameter);
		double capacity = PI * (H - 0.267) * (D / 2) * (D / 2);
		return capacity;
	}


	//returns the content volume attribute

	double Canister::volume() const	{

		return m_contentVolume;
	}

	/*It will set the Content name of the canister using the following rule and then returns the reference of 
		the current object(i.e.* this) :

		If the contentName argument is null it will render the Canister unusable
   else if the Canister is empty it will set the Name to the value pointed by the argument
    else if the name of the Canister is not the same as the contentName argument it will render the Canister unusable.*/


	Canister& Canister::setContent(const char* contentName)	{//we don necessarily need this then?????????????

		if (!contentName) {
			m_usable = false;
		}
		else if (!m_contentVolume) {       //i cant use setName then?       //Canister is empty meaning !m_contentVolume??????
			
		   //am i supposed to check the conditions i have checked for setName???????????????????????
			
			////delete[] m_contentName;///its empty, not needed
			//this->m_contentName = new char[strlen(contentName) + 1];
			//strcpy(this->m_contentName, contentName);
			//this->m_contentName[strlen(contentName)]=0;
			setName(contentName);

		}
		else if (strcmp(/*this->*/m_contentName, contentName) != 0) {
			m_usable = false;
		}
		return *this;
	}


	/*Adds the quantity argument to the content volume of the Canister if the quantity fits in
		the Canister.Otherwise, it will render the Canister unusableand then returns 
		the reference of the current object.
		Use this rule to accomplish the above :
	If the Canister is usableand the quantity is more than zero and if the sum of 
		the quantity and the volume() is less than or equal to the capacity(), add the
		quantity to the content volume, otherwise set usable flag attribute to false.*/


	Canister& Canister::pour(double quantity)	{        //always return *this when the type of function is a reference??????
		//can i use *this???????                         //even when theres no this in codes???
												        //whenever we have ref we have to use this for current obj??????
		if (m_usable == true && quantity > 0 && capacity() >= (quantity + volume())) {
			m_contentVolume += quantity;
		}
		else {
			m_usable = false;
		}
		return *this;
	}


	//Set the content name to the Canister argument using setContent().
	//	if the volume() of the argument is greater than the capacity() minus the volume()


	//		Reduce the content volume of the argument by capacity() minus volume() and then set the content volume to capacity()
	//	else pour the content volume of the argument using pour() method and set the content volume of the argument to 0.0.
	//		return the reference of the current object at the end.

	                                                         //ref is always for obj not attributes
	Canister& Canister::pour(Canister& C)	{               ///I added C on my own,ok????????????????????????????
		                                                    //whenever we have ref we have to use this for current obj??????
		setContent(C.m_contentName);                       //otherwise we dont?wat we were doing before???ws3
		if (C.m_contentVolume > ((*this).capacity() - (*this).volume())) {
			                                                          //the dif between volume() n volumecontent????
			C.m_contentVolume - ((*this).capacity() - (*this).volume());
			(*this).m_contentVolume = (*this).capacity();

		}
		else {
			pour(C.m_contentVolume);
			C.m_contentVolume = 0.000000000000001;
		}
		return *this;
	}

	//Prints all the number values with one digit after the decimal point.
	//	Prints the Canister in the following format :
	//In 7 spaces prints the capacity

	//	"cc ("
	//	height
	//	"x"
	//	diameter
	//	") Canister"
	//	if unusable:
	//" of Unusable content, discard!"
	//	otherwise, if the content name is not null
	//	" of "
	//	in 7 spaces prints the volume
	//	"cc   "
	//	content name
	//	returns the cout at the end.

	std::ostream& Canister::display() const	{
		
		cout << setw(7) << setfill(' ') << fixed << setprecision(1) << capacity() << "cc (" << m_hieght << "x" << m_diameter << ") Canister";

		if (m_usable == false) {

			cout << " of Unusable content, discard!";  //nwline???????
		}
		else if(m_contentName) {//u missed the condition
			cout << " of " << setw(7) << setfill(' ') << fixed << setprecision(1) << volume() << "cc   " << m_contentName;               //newline

		}
		return cout;
	}

	
}