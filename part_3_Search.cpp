#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;
int main()
{   string OceanviewName[60], poolsideName[50], gardenName[40];
    int OceanviewAge[60], poolsideAge[50], gardenAge[40];
    string OceanviewReservationCode[60], poolsideReservationCode[50], gardenReservationCode[40];
    char genderOceanviewName[60], genderPoolsideName[50], gendergardenName[40];
    short int ageOceanviewName[60],agePoolsideName[50],ageGardenName[40];
    bool OceanviewReserved[60]{false}, poolsideReserved[50]{false}, gardenReserved[40]{false};
    int countocean(0), countPool(0), countgarden(0);
    char choice;
    char gender;
    short int age;
    string reservationCode, name;
        
    do
    {
     
        else if (choice == '2')
        {
        labelchoice: // If an error occurs concerning choices
            cout << "Press 1, for hotel rooms status" << endl
                 << "Press 2, for searching patron(by name)" << endl
                 << "Press 3, for search by reservation code" << endl;
            cin >> choice;
            if (choice == '1')
            {
                if ((countocean == 0 && countPool == 0 && countgarden == 0))
                { // check if no room is reserved
                    cout << "No room is reserved yet" << endl;
                }
                else
                { // Display all reserved rooms with name of the person
                    cout << setw(5) << "\nCatogory\t Room number" << setw(22) << " Name " << endl;
                    for (int i = 0; i < countocean; i++)
                    {
                        cout << setw(5) << "Oceanside\t room number " << i + 1 << setw(22) << OceanviewName[i] << endl;
                    }
                    for (int i = 0; i < countPool; i++)
                    {
                        cout << setw(5) << "Poolside\t room number " << i + 61 << setw(10) << setw(20) << poolsideName[i] << endl;
                    }
                    for (int i = 0; i < countgarden; i++)
                    {
                        cout << setw(5) << "Garden side\t room number " << i + 111 << setw(10) << setw(20) << gardenName[i] << endl;
                    }
                }
            }
            else if (choice == '2')
            {



                cout << "Enter full name of patron: ";
                string forsearch;
                bool isfound(false);

                cin.ignore();
                getline(cin, forsearch);

                for (int i = 0; i < countocean; i++)
                { // Checking for the patron name if he/she has reserved ocean view room
                    if (OceanviewName[i] == forsearch)
                    {
                        cout << forsearch << " has reservered ocean side Room number " << i + 1 << endl;
                        isfound = true; // Set isfound to true when the patron is found
                        i = countocean;  // To Exit the loop since the patron is found
                    }
                }
                for (int i = 0; i < countPool; i++)
                {                // Checking for the patron name if he/she has reserved pool side room
                    if (isfound) // To Exit the loop if the patron is already found in a previous category
                        i = countPool;
                    if (poolsideName[i] == forsearch)
                    {
                        cout << forsearch << " has reservered pool side Room number " << i + 61 << endl;
                        isfound = true; // Set isfound to true when the patron is found
                        i = countPool;   // To Exit the loop since the patron is found
                    }
                }
                for (int i = 0; i < countgarden; i++)
                {                // Checking for the patron name if he/she has reserved garden view room
                    if (isfound) // Exit the loop if the patron is already found in a previous category
                        i = countgarden;
                    if (gardenName[i] == forsearch)
                    {
                        cout << forsearch << " has reservered garden side Room number " << i + 111 << endl;
                        isfound = true; // Set isfound to true when the patron is found
                        i = countgarden; // Exit the loop since the patron is found
                    }
                }
                if (!isfound)
                { // If patron name is not found in any category
                    cout << "Patron with the name " << forsearch << " not found in any category." << endl;
                }
            }

            else if (choice == '3')
            {
            labelreservationcode2:
                int reservationcount(0);
                bool invalidReservationcode = false;
                do
                {
                    invalidReservationcode = false;
                    cout << "Reservation code((0-9)xxxxxx): ";
                    cin >> reservationCode;
                    if (reservationCode.size() != 6)
                    {
                        invalidReservationcode = true;
                        reservationcount++;
                    }
                    else
                    {
                        for (int i = 0; i < reservationCode.size(); i++)
                        {
                            if (isdigit(reservationCode[i]) == false)
                            {

                                invalidReservationcode = true;
                                reservationcount++;
                               break;
                            }
                        }
                    }
                    if (invalidReservationcode && reservationcount == 3)
                        return 0;
                } while (invalidReservationcode && reservationcount < 3);
                bool isfound(false);
                for (int i = 0; i < countocean; i++)
                {
                    if (OceanviewReservationCode[i] == reservationCode)
                    { // Check each character in the reservation code
                        cout << "Name: " << OceanviewName[i] << endl;
                        cout << "Age: " << OceanviewAge[i] << endl;
                        cout << "Gender: " << genderOceanviewName[i] << endl;
                        cout << "Room number: " << i + 1 << endl;
                        isfound = true;
                        i = countocean; // To exit the loop since the reservation code is found
                        continue;
                    }
                    if (OceanviewReservationCode[i] != reservationCode)
                    { // Checking if the reservation code is not found in the ocean view category
                        isfound = false;
                        cout << "Reservation code not found, please enter the correct code" << endl;
                        goto labelreservationcode2;
                    }
                }
                for (int i = 0; i < countPool; i++)
                {
                    if (isfound) // To Exit the loop if the patron is already found in a previous category
                        i = countPool;
                    if (poolsideReservationCode[i] == reservationCode)
                    { // Check each character in the reservation code
                        cout << "Name: " << poolsideName[i] << endl;
                        cout << "Age: " << poolsideAge[i] << endl;
                        cout << "Gender: " << genderPoolsideName[i] << endl;
                        cout << "Room number: " << i + 61 << endl;
                        isfound = true;
                        i = countPool; // To exit the loop since the reservation code is found
                        continue;
                    }
                    if (poolsideReservationCode[i] != reservationCode)
                    { // Checking if the reservation code is not found in the pool side category
                        isfound = false;
                        cout << "Reservation code not found, please enter the correct code" << endl;
                        goto labelreservationcode2;
                    }
                }
                for (int i = 0; i < countgarden; i++)
                {
                    if (isfound) // To Exit the loop if the patron is already found in a previous category
                        i = countgarden;
                    if (gardenReservationCode[i] == reservationCode)
                    { // Check each character in the reservation code
                        cout << "Name: " << gardenName[i] << endl;
                        cout << "Age: " << gardenAge[i] << endl;
                        cout << "Gender: " << gendergardenName[i] << endl;
                        cout << "Room number: " << i + 111 << endl;
                        isfound = true;
                        i = countgarden; // To exit the loop since the reservation code is found
                        continue;
                    }
                    if (gardenReservationCode[i] != reservationCode)
                    { // Checking if the reservation code is not found in the garden view category
                        isfound = false;
                        cout << "Reservation code not found, please enter the correct code" << endl;
                        goto labelreservationcode2;
                    }
                }
            }
            else
            { // If the reservation code in not foun in any category
                cout << "Reservation code not found, please enter the correct code" << endl;
                goto labelchoice;
            }
        }
        cout << "\nDo you want to continue(press y to conutinue): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
