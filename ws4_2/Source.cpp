//
//void Label::setToDefault() {
//	m_label = nullptr;
//	m_frame = nullptr;
//}
//
//void Label::setLable(const char* theLable) {
//
//	delete[] m_label;
//	m_label = new char[strlen(theLable) + 1];
//	strcpy(m_label, theLable);
//	//m_label[strlen(theLable)] = 0;
//
//}
//
//void Label::setFrame(const char* theFrame) {
//	/*m_frame[0] = 0;
//	strcpy(m_frame, theFrame);
//	m_frame[8] = 0;*/
//	delete[] m_frame;
//	m_frame = new char[strlen(theFrame) + 1];
//	strcpy(m_frame, theFrame);
//	//m_frame[strlen(theFrame)] = 0;
//}
//
//
////Creates an empty label and defaults the frame to "+-+|+-+|"
//Label::Label() {
//	setToDefault();
//	setFrame("+-+|+-+|");
//
//}
////Creates an empty label and sets the frame to the frameArg argument.
//
//Label::Label(const char* frameArg) {
//	setToDefault();
//	setFrame(frameArg);
//}
//
///*Creates a Label with the frame set to frameArg and the content of
//	the Label set to the corresponding argument.Note that you must
//	keep the content dynamically even though it should never be more
//	than 70 characters.*/
//Label::Label(const char* frameArg, const char* content) {
//	setToDefault();
//	setFrame(frameArg);
//	setLable(content);
//
//}
//
//
////Makes sure there is no memory leak when the label goes out of scope.
//Label::~Label() {
//	delete[] m_label;
//	delete[] m_frame;
//	m_label = nullptr;
//	m_frame = nullptr;
//}
//
///*Reads the label from console up to 70 characters and stores it in the
//	Label as shown in the Execution sample*/
//void Label::readLabel() {//
//		
//	char inputLabel[71];    
//	cin.getline(inputLabel,71);
//	setLable(inputLabel);		
//	
//}
//void Label::readFrame() {		// ref of obj ? ? ? ? ?
//
//	char inputFrame[9];
//	cin.getline(inputFrame,9);
//	setFrame(inputFrame);
//}
//
//
////////////////when we call a function without . notation
//
//
//Prints the label by drawing the frame around the content ad shown in
//		the Execution sample.Note that no newline is printed after the last
//		line and cout is returned at the end.



//
//Label::Label()
//{
//	
//	m_label = new char[71];
//	strcpy(m_label, "");
//
//	strcpy(m_frame, "+-+|+-+|");
//	
//
//}