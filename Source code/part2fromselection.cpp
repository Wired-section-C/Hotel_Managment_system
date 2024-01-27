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
            // Checking if the reservation number is unique oceanview rooms
            for (int i = 0; i < countocean; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (reservationCode[j] != OceanviewReservationCode[i][j])
                        break;
                    if (reservationCode[5] == OceanviewReservationCode[i][5])
                    {
                        cout << "please enter unique reservation Code" << endl;
                        goto labelreservationcode;
                    }
                }
            }
            // Checking if the reservation number is unique poolside rooms
            for (int i = 0; i < countPool; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (reservationCode[j] != poolsideReservationCode[i][j])
                        break; // to out from loop
                    if (reservationCode[5] == poolsideReservationCode[i][5])
                    {
                        cout << "please enter unique reservation Code" << endl;
                        goto labelreservationcode;
                    }
                }
            }
            // Checking if the reservation number is unique garden view rooms
            for (int i = 0; i < countgarden; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (reservationCode[j] != gardenReservationCode[i][j])
                        break;
                    if (reservationCode[5] == gardenReservationCode[i][5])
                    {
                        cout << "please enter unique reservation Code" << endl;
                        goto labelreservationcode;
                    }
                }
            }
            cout << "\n   Sucessfully registered!" << endl
                 << "\nWellcome " << name << endl
                 << "Please select typr of room you want to reserve" << endl;
        labelReservation: // If registration error occur
            cout << "  Press 1, For Oceanview room" << endl
                 << "\t2, For poolside" << endl
                 << "\t3, For garden room" << endl;
            char roomChoice;
            cin >> roomChoice;
        labelroomback:
            if (roomChoice == '1')
            {
                if (countocean == 60)
                {              // Check if all ocean view rooms are fully booked
                labelaltenate: // If an error occurs concerning alternative choices
                    cout << "We apologize ocean view is totally booked!" << endl
                         << "Do you like another room next catagory(y/n): ";
                    cin >> choice;
                    if (choice == 'y')
                    { // Check for available rooms in other categories
                        if (poolsideReserved[49] == false){
                            roomChoice = '2';
                            goto labelroomback;
                        }
                            
                        else if (gardenReserved[39] == false){
                            roomChoice = '3';
                            goto labelroomback;
                        }
                        else
                        { // if no available rooms are found
                            cout << "Sorry we couldn't find free room";
                            return 0;
                        }
                    }
                    if (choice == 'n')
                        return 0;
                    if (choice != 'y' && choice != 'n') // If the input is neither y nor n
                        goto labelaltenate;
                }
                else
                {
                    OceanviewName[countocean] = name; // Reserve an Ocean View room(registering )
                    OceanviewAge[countocean] = age;
                    genderOceanviewName[countocean] = gender;
                    OceanviewReservationCode[countocean] = reservationCode;
                    OceanviewReserved[countocean] = true;
                    countocean++;
                    cout << "   Reserved sucessfully!" << endl
                         << "Reserved catagory: "
                         << "Ocean side room " << endl
                         << "Room number: " << countocean << endl;
                }
            }
            else if (roomChoice == '2')
            {
                if (countPool == 50)
                {               // Check if all pool side rooms are fully booked
                labelaltenate2: // If an error occurs concerning alternative choices
                    cout << "We apologize pool view is totally booked" << endl
                         << "do you like another room next catagory(y/n): ";
                    cin >> choice;
                    if (choice == 'y') // Check for available rooms in other categories
                        if (gardenReserved[39] == false){
                            roomChoice = '3';
                            goto labelroomback;
                        }
                        else if (OceanviewReserved[59] == false){
                            roomChoice = '1';
                            goto labelroomback;
                        }
                        else
                        {
                            cout << "Sorry we couln't find free room"; // if no available rooms are found
                            return 0;
                        }
                    if (choice == 'n')
                        return 0;
                    if (choice != 'y' && choice != 'n') // If the input is neither y nor n
                        goto labelaltenate2;
                }
                else
                {
                    poolsideName[countPool] = name; // Reserve an Pool side room(registering)
                    poolsideAge[countPool] = age;
                    genderPoolsideName[countPool] = gender;
                    poolsideReservationCode[countPool] = reservationCode;
                    poolsideReserved[countPool] = true;
                    countPool++;
                    cout << "   Resereved sucessfully" << endl
                         << "Reserved catagory: "
                         << "Poolside room " << endl
                         << "Room number: " << countPool + 60 << endl;
                }
            }
            else if (roomChoice == '3')
            {
                if (countgarden == 40)
                {               // Check if all garden view rooms are fully booked
                labelaltenate3: // If an error occurs concerning alternative choices
                    cout << "We apologize garden view is totally booked" << endl
                         << "Do you like another room next catagory(y/n): ";
                    cin >> choice;
                    if (choice == 'y') // Check for available rooms in other categories
                        if (poolsideReserved[49] == false){
                            roomChoice = '2';
                            goto labelroomback;
                        }
                        else if (OceanviewReserved[59] == false){
                            roomChoice = '1';
                            goto labelroomback;
                        }
                        else
                        { // if no available rooms are found
                            cout << "Sorry we couldn't find free room";
                            return 0;
                        }
                    if (choice == 'n')
                        return 0;
                    if (choice != 'y' && choice != 'n') // If the input is neither y nor n
                        goto labelaltenate3;
                } // Reserve an Garden view room(registering)
                else
                {
                    gardenName[countgarden] = name;
                    gardenAge[countgarden] = age;
                    gendergardenName[countgarden] = gender;
                    gardenReservationCode[countgarden] = reservationCode;
                    gardenReserved[countgarden] = true;
                    countgarden++;
                    cout << "   Reserved sucessfully" << endl
                         << "Reserved catagory: "
                         << "Garden side room " << endl
                         << "Room number: " << countgarden + 110 << endl;
                }
            }
            else // If input is different from 1,2 or 3
                goto labelReservation;
         }return 0; }
        