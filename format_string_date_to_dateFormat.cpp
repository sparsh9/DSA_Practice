#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip> // Include this header for std::setw

using namespace std;

vector<string> preprocessDate(vector<string> dates) {
    vector<string> result;

    for (const string& date : dates) {
        stringstream ss(date);
        string day, month, year;
        ss >> day >> month >> year;

        // Remove "st", "nd", "rd", or "th" from the day
        day.pop_back();

        // Convert month to numeric format
        string monthNum;
        if (month == "Jan") monthNum = "01";
        else if (month == "Feb") monthNum = "02";
        else if (month == "Mar") monthNum = "03";
        else if (month == "Apr") monthNum = "04";
        else if (month == "May") monthNum = "05";
        else if (month == "Jun") monthNum = "06";
        else if (month == "Jul") monthNum = "07";
        else if (month == "Aug") monthNum = "08";
        else if (month == "Sep") monthNum = "09";
        else if (month == "Oct") monthNum = "10";
        else if (month == "Nov") monthNum = "11";
        else if (month == "Dec") monthNum = "12";

        // Create the standard date format with leading zeros for day
        stringstream formattedDate;
        formattedDate << year << "-" << monthNum << "-" << setw(2) << setfill('0') << day;
        result.push_back(formattedDate.str());
    }

    return result;
}