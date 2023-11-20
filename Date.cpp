#include <iostream>
#include <regex>


using namespace std;

    //leap year function declaration
bool leap(int year);

//isValidDate function declaration
bool isValidDate(string date);

int main()
{

   // making random dates
    string date1 ="2023-02-30";
    string date2 ="2019-07-20";
    string date3 ="2018-02-29";
    string date4 ="2020-02-29";
    string date5 ="2023-13-01";
    string date6 ="10-21-2023";


        cout << "Testing function:\n";


    cout<<endl;

    //testing which dates are valid

        cout << "Date: " << date1 << ", Valid: " << (isValidDate(date1) ? "Yes" : "No") << "\n";
        cout << "Date: " << date2 << ", Valid: " << (isValidDate(date2) ? "Yes" : "No") << "\n";
        cout << "Date: " << date3 << ", Valid: " << (isValidDate(date3) ? "Yes" : "No") << "\n";
        cout << "Date: " << date4 << ", Valid: " << (isValidDate(date4) ? "Yes" : "No") << "\n";
        cout << "Date: " << date5 << ", Valid: " << (isValidDate(date5) ? "Yes" : "No") << "\n";
        cout << "Date: " << date6 << ", Valid: " << (isValidDate(date6) ? "Yes" : "No") << "\n";

    return 0;
}





//leap year checker
bool leap(int year){
return (year % 4 == 0);
}


//isValid date in assinment
bool isValidDate(string date){

//this is so i can put it in the pattern "YYYY-MM-DD"
        regex datePattern("^\\d{4}-\\d{2}-\\d{2}");

// changing string to int and checking respective location

        if(regex_match(date, datePattern)){
            int year = stoi(date.substr(0,4));
            int month = stoi(date.substr(5,2));
            int day = stoi(date.substr(8,2));


if (year >= 1 && month >= 1 && month <= 12) {
            // Checking February
            if (month == 2) {
                if (day <= 29 && leap(year)) {
                    //cout << "Valid date." << endl;
                    return true;
                } else if (day <= 28 && !leap(year)) {
                    //cout << "Valid date." << endl;
                    return true;
                }


                //checking days of the month
            } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day <= 30) {
                //cout << "Valid date." << endl;
                return true;
            } else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day <= 31) {
                //cout << "Valid date." << endl;
                return true;
            }
        }
    }

    //cout << "Invalid date." << endl;
    return false;
}

