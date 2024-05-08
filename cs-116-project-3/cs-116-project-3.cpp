//Include the Standard Library
#include <iostream>
// Include the string library
#include <string>
//include using namespace std if you don't want to keep writing std
#include <vector>
using namespace std;


string getName()
{
    string result;
    cout << "What assignment group will you be calculating: ";
    cin >> result;
    return result;
}

float requestIntFromUser(string promt)
{
    string input;
    char* foo;
    float result;
    cout << promt;
    //check if valid input
    do
    {
       // stores the user input in the variable input
        cin >> input;

        result = strtof(input.c_str(), &foo);
        if (foo == input.c_str())
        {
            cout << "Invalid input must be a number." << endl;
            // Ask the user the message
            cout << "Please Enter a number followed by the enter key: ";
        }
    } while  (foo == input.c_str());

    return result;
    
}

float requestAFloat(string name, int iter, int min, float max)
{
    string input;
    char* foo;
    float result;
     /*
        TO DO!
        ADD a while loop around the message, so that it repeats whenever you don't get a valid number.
        ALSO ADD AN ERROR MESSAGE WHEN the user input is invalid

    */
    do
    {
        cout << "Please Enter the grade for " << name << " " << iter << " followed by the enter key: ";

        // stores the user input in the variable input
        cin >> input;
   
        result = strtof(input.c_str(), &foo);
        if (foo == input.c_str())
        {
            cout << "Invalid input. Grade must be a number between " << min << " and " << max << "." << endl;
            // Ask the user the message

        }
    }
    while (result < min || result > max || foo == input.c_str());
    
    return result;
}

double calculateAverage(string name, int count, int totalGrade, float extraC, int grade_weight)
 {
        
    double result;
    double accumulator;
    float max;
    int i;//loop iteration number
    result = 0;
    max = totalGrade * (1 + (extraC / 100));
    int smallest_index = 0;
    vector<float> grades;
   
    bool is_midterm = name == "Midterm" || name == "midterm";
    for (i = 0; i < count; i += 1)
    {
        grades.push_back(requestAFloat(name, i+1, 0, max));

        if (grades[i] < grades[smallest_index])
        {
            smallest_index = i;
        }
    }
    for (i = 0, accumulator = 0; i < count; i += 1)
    {
        if ((i != smallest_index && !is_midterm) || is_midterm)
        {
            accumulator += grades[i];
        }
            
    }
    if (is_midterm)
    {
        result = accumulator / (count * totalGrade);
    }
    else
    {
        result = accumulator / ((count - 1) * totalGrade);
    }
    return result * (grade_weight);
}



double requestAssignmentDetails()
{
    string assignmentName;
    int numberOfAssignments;
    int totalAssignmentGrade;
    float precentageofExtraCredit;
    float totalGradeWeight;
    assignmentName = getName();
    numberOfAssignments = requestIntFromUser("Please Enter the number of assignment associated with " + assignmentName + ": ");
    totalAssignmentGrade = requestIntFromUser("Please Enter the maximum grade possible for " + assignmentName + ": ");
    precentageofExtraCredit = requestIntFromUser("Please Enter the percent of possible extra credit for " + assignmentName + ": ");
    totalGradeWeight = requestIntFromUser("Please Enter the percentage of total grade for " + assignmentName + ": ");

    return calculateAverage(assignmentName, numberOfAssignments, totalAssignmentGrade, precentageofExtraCredit, totalGradeWeight);
}

double calculateGrade(vector<float> grades)
{
    double result = 0;
    for (int i = 0; i < grades.size(); i += 1)
    {
        result += grades[i];
    }
    return result;
}


int main()
{
    double gradeTotal;
    vector<float> assignment_groups;
    int count;
    cout << "Hello, the purpose of this program is to calculate your grade precentage!\n";
    cout << "How many assignment groups do you want to include? : ";
    cin >> count;
    for (int i = 0; i < count; i += 1)
    {
        assignment_groups.push_back(requestAssignmentDetails());

    }

    gradeTotal = calculateGrade(assignment_groups);
    //calling functions to figure out what the values aught to be


    printf("Your total grade precentage in the class is %.2f%% !\n", gradeTotal);
}



