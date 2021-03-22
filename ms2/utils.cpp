#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>//???

#include <string>
#include <cstring>
#include "utils.h"

#include <cstdio>

using namespace std;
namespace sdds {

	int getInt(const char* prompt) {
		if (prompt) cout << prompt;
		int val(0);
		bool done = false;
		do
		{
			done = false;
			cin >> val;
			if (cin.fail())
			{
				cout << "Bad integer value, try again: ";
				cin.clear();
				cin.ignore(1000, '\n');
				done = true;

			}
			else
			{
				if (getchar() != '\n')//make it better
				{
					cout << "Enter only an integer, try again: ";
					cin.clear();
					cin.ignore(1000, '\n');
					done = true;
				}

			}

		} while (done);
	  return val;

	}

    int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) {

        cout << prompt;
        int val = 0;
        bool done = false;

        do
        {
            done = false;
            cin >> val;
            if (cin.fail())
            {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
                done = true;
            }
            else
            {

                if (getchar() != '\n') {
                    cout << "Enter only an integer, try again: ";
                    cin.ignore(1000, '\n');
                    done = true;
                }
                else if (val > max || val < min)
                {
                    if (!showRangeAtError)
                    {
                        cout << errorMessage;
                        done = true;
                    }
                    else {
                        cout << errorMessage << " [" << min << " <= value <= " << max << "]: ";
                        done = true;
                    }
                }
            }
        } while (done);
        return val;
    }








}


