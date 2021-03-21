////
////
////
////
////////unsigned Stats::occurrence(double min, double max, std::ostream& ostr)
////////{
////////    int Counter = 0;
////////    if (m_filename)
////////    {
////////        ostr << endl << fixed << setprecision(m_precision);
////////        for (int i = 0; i < m_noOfLines; i++)
////////        {
////////            if (m_number[i] >= min && m_number[i] <= max)
////////            {
////////                ostr << right << setw(m_columnWidth) << m_number[i];
////////                if ((Counter + 1) % m_noOfColumns == 0)
////////                    ostr << endl;
////////                Counter++;
////////            }
////////        }
////////        if (Counter % m_noOfColumns != 0)
////////            ostr << endl;
////////        ostr << "Total of " << Counter << " numbers are between " << min << " and " << max << endl;
////////    }
////////    return Counter;
////////}
////////
////
////
//////void Stats::loadNumbers()
//////{
//////    if (m_filename)
//////    {
//////        ifstream fin;
//////        string str;
//////        int i = 0;
//////
//////
//////
//////        delete[] m_number;
//////        m_number = new double[m_noOfLines];
//////
//////
//////
//////        fin.open(m_filename);
//////        if (fin.is_open())
//////            while (getline(fin, str, ','))
//////            {
//////                m_number[i] = stod(str);
//////                i++;
//////            }
//////        fin.close();
//////    }
//////}
////
////
////
//////void Stats::loadNums() {
//////	m_noOfNums = 0;
//////	ifstream file(m_filename);
//////	if (file.good())
//////	{
//////		string line;
//////		getline(file, line);
//////
//////		double n;
//////		string num;
//////
//////
//////
//////		ifstream f(m_filename);
//////		while (getline(f, num, ',')) ++m_noOfNums;
//////
//////
//////
//////
//////
//////
//////		m_arr = new double[m_noOfNums];
//////		stringstream ss2(line);
//////		int idx = 0;
//////		while (getline(ss2, num, ','))
//////		{
//////
//////
//////			n = stod(num);
//////			m_arr[idx] = n;
//////			idx++;
//////		}
//////
//////
//////
//////
//////		file.close();
//////	}
//////}
////
////
////
////
////unsigned Stats::occurrence(double min, double max, std::ostream& ostr)
////{
////    int Counter = 0;
////    if (*this)
////    {
////        ostr << endl << fixed << setprecision(m_precision);
////        for (int i = 0; i < m_noOfNums; i++)
////        {
////            if (m_arr[i] >= min && m_arr[i] <= max)
////            {
////                ostr << right << setw(m_columnWidth) << m_arr[i];
////                if ((Counter + 1) % m_noOfColumns == 0)
////                    ostr << endl;
////                Counter++;
////            }
////        }
////        if (Counter % m_noOfColumns != 0)
////            ostr << endl;
////        ostr << "Total of " << Counter << " numbers are between " << min << " and " << max << endl;
////    }
////    return Counter;
////}
////
//std::ostream& Stats::view(std::ostream& ostr) const {
//	if (*this) {
//		ostr << m_filename << endl;
//		for (int i = 0; m_filename[i]; i++) ostr << "=";
//		ostr << endl;
//		/*for (unsigned i = 0; i < m_noOfNumbers; i++) {
//			ostr << ;
//		}*/
//		for (unsigned int i = 0; i < m_noOfNumbers; i += 15)
//		{
//			for (unsigned int j = i; j < 15 + i && j < 51; j++)
//			{
//				cout << 88 << "\t";
//			}
//			cout << endl;
//		}
//
//	}
//	return ostr;
//
//}
//
