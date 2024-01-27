#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;
int main()
{  char choice;
    char gender;
    short int age;
    string reservationCode, name;
            cout << "\n\t*****\t\t" << endl;
        cout << "Wellcome to Wired Hotel" << endl
             << "-----------------------" << endl;
        cout << "\tPress 1, For user" << endl
             << "\tPress 2, For hotel staff" << endl;
        cin >> choice;

        for (int c = 1; (choice != '2' && choice != '1') && c <= 5; c++)
        { // If the input is neither '1' nor '2', gives trials up to 5 times
            cout << "Wellcome to Wired Hotel" << endl
                 << "Please enter" << endl
                 << "\t1, For user " << endl
                 << "\t2, For hotelstaff" << endl;
            cin >> choice;
        }

        if (choice == '1')
        {
        labelnameError: // If name error occur
            cout << "Wellcome to registration page" << endl;
            cout << "Please Sign Up" << endl;

            int c = 1;
            bool invalidname;
            do
            {
                invalidname = false;
                cout << "\tFull name(more than 3 letter and only alphabet): ";
                cin.ignore();
                getline(cin, name);

                for (int j = 0; j < name.size(); j++)
                { // Loop for validating the name
                    if (isalpha(name[j]) == false && name[j] != ' ')
                    {
                        invalidname = true;
                        break;
                    }
                }
                c++;
            } while ((name.size() < 4 || invalidname) && c <= 3);
            if (name.size() < 4 || invalidname) // If the input is still invalid more than 3 times, exit
                return 0;

            cout << "\tAge: ";
            cin >> age;
            for (int c = 1; c < 4 && (age > 120 || age < 0); c++)
            { // Loop for validating the age
                cout << "Please enter valid age: ";
                cin >> age;
            }
            if (age > 120 || age < 0) // If the input is still invalid more than 3 times, exit
                return 0;
            cout << "\tGender(m/f): ";
            cin >> gender;
            gender = toupper(gender); // Convert character into it's Uppercase equivalent
            for (int c = 1; c < 4 && (gender != 'M' && gender != 'F'); c++)
            { // Loop for validating the age
                cout << "Please enter a valid gender(m/f): ";
                cin >> gender;
                gender = toupper(gender);
            }
            if (gender != 'M' && gender != 'F') // If the input is still invalid more than 3 times, exit
                return 0;

        // Accept reservation code
        labelreservationcode:
            int reservationcount(0);
            bool invalidReservationcode = false;
            do
            {
                invalidReservationcode = false;
                cout << "\tReservation code((0-9)xxxxxx): ";
                cin >> reservationCode;
                if (reservationCode.size() != 6)
                { // Validating the lenght of the input code
                    invalidReservationcode = true;
                    reservationcount++;
                }
                else
                {
                    for (int i = 0; i < reservationCode.size(); i++)
                    { // Validating if the input if digit or not
                        if (isdigit(reservationCode[i]) == false)
                        {
                            invalidReservationcode = true;
                            reservationcount++;
                            break;
                        }
                    }
                }
                if (invalidReservationcode && reservationcount == 3) // If the input is still invalid more than 3 times, exit
                    return 0;
            } while (invalidReservationcode && reservationcount < 3);
}
}
