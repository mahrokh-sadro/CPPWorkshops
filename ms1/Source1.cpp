//#include <bits/stdc++.h>
//using namespace std;
//
////function to check if the current input is valid or not
//int checkInput(string input)
//{
//    //return 1 for valid input
//    //return -1 for invalid input
//    //return 0 for input containing character after number
//    int num;
//    //using inbuilt function stoi that converts the string into number
//    try {
//        num = stoi(input);
//
//        //checking if the input contains only digits
//        for (int i = 0; i < input.size(); i++)
//        {
//
//            if (input[i] > '9' || input[i] < '0')
//                return 0;
//        }
//        //valid integer return 1
//        return 1;
//    }
//    catch (exception e)
//    {
//        return -1;
//    }
//}
//int getInt(const char* prompt) {
//    if (prompt) cout << prompt;
//    bool done = false;
//    int num;
//    while (!done) {
//
//        string input;
//
//        //taking input
//        getline(cin, input);
//
//        int queryAnswer = checkInput(input);//checking the input
//        //cout<<queryAnswer<<endl;
//        if (queryAnswer == -1)
//            cout << "Bad integer value, try again: ";
//        else if (queryAnswer == 0)
//        {
//            cout << "Enter only an integer, try again: ";
//        }
//        else {
//            num = stoi(input);//converting string input into integer
//
//            if (num < 10 || num>20)
//            {
//
//                cout << "Value must be between 10 and 20: ";
//            }
//            else
//                done = true;
//        }
//
//    }
//
//    return num;
//
//}

//
//int getInt(void)
//{
//
//	char x; //declaring variable x which is a char type
//	int Value = 0;// declaring Value variable which is an integer and initializing it into a safe state
//	scanf("%d%c", &Value, &x);// prompt the user to enter an input
//
//	while (x != '\n') /*if the char part of the Value is not a new line,
//							 the input is not a valid integer*/
//	{
//		clearKeyboard();// calling the clearKeyboard function to clear the input buffer
//		printf("*** INVALID INTEGER *** <Please enter an integer>: ");//printout the error
//		scanf("%d%c", &Value, &x);// prompt the user to input again
//
//	}
//
//	return Value;// if the input is a valid integer,return  the input
//
//}



   /*   if (prompt)  cout << prompt;
                  int i = 0; char nl = 0;
                  int check = 0;
                  do { check = scanf("%d%c", &i, &nl);
                  if (check == 0) {
                      cout << "Bad integer value, try again: ";
                      clear();
                      continue;
                  }
                  if (nl != '\n')   {
                      cout << "Enter only an integer, try again: ";
                      clear();
                  }
                  }
                  while (nl != '\n');
                  return i;
              }*/



//int getInt(void) {
//    int ivalue;
//    char next = 'G';
//    //get a double from keyboard and return it to the caller program
//    scanf("%d%c", &ivalue, &next);
//    while (next != '\n') {
//        flushKeyboard();
//        printf("Invalid integer value, try again: ");
//        scanf("%d%c", &ivalue, &next);
//    }
//    return ivalue;
//}
//
//int getLimitedInt(int minValid, int maxValid) {
//    int ivalue = getInt();
//    while (ivalue<minValid || ivalue > maxValid) {
//        printf("Out of range value, (%d<=value<=%d): ", minValid, maxValid);
//        ivalue = getInt();
//    }
//    return ivalue;
//}
