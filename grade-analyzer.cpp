#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

//function prototypes
void inputMarks(vector<double> &marks, int numStudents);
double calculateAverage(const vector<double> &marks);
double findHighest(const vector<double> &marks);
double findLowest(const vector<double> &marks);
double calculatePassRate(const vector<double> &marks, double passingGrade = 60.0);
void displaySummary(const vector<double> &marks);

int main() {
    cout << "====================================\n";
    cout << "   SMART STUDENT GRADE ANALYZER    \n";
    cout << "====================================\n\n";
    
    int numStudents;
    
    //get number of students with input validation
    do {
        cout << "Enter the number of students: ";
        cin >> numStudents;
        
        if (cin.fail() || numStudents <= 0) {
            cout << "Invalid input. Please enter a positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (numStudents <= 0);
    
    //vector to store marks
    vector<double> marks;
    
    inputMarks(marks, numStudents);
    
    //display summary
    displaySummary(marks);
    
    cout << "\nThank you for using the Grade Analyzer!\n";
    
    return 0;
}

void inputMarks(vector<double> &marks, int numStudents) {
    cout << "\n--- Enter Student Marks ---\n";
    
    double mark;
    for (int i = 0; i < numStudents; i++) {
        do {
            cout << "Enter mark for student " << (i + 1) << " (0-100): ";
            cin >> mark;
            
            if (cin.fail() || mark < 0 || mark > 100) {
                cout << "Invalid mark. Please enter a value between 0 and 100.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (mark < 0 || mark > 100);
        
        marks.push_back(mark);
    }
}

double calculateAverage(const vector<double> &marks) {
    if (marks.empty()) return 0;
    
    double sum = 0;
    for (double mark : marks) {
        sum += mark;
    }
    return sum / marks.size();
}

double findHighest(const vector<double> &marks) {
    if (marks.empty()) return 0;
    
    double highest = marks[0];
    for (double mark : marks) {
        if (mark > highest) {
            highest = mark;
        }
    }
    return highest;
}

double findLowest(const vector<double> &marks) {
    if (marks.empty()) return 0;
    
    double lowest = marks[0];
    for (double mark : marks) {
        if (mark < lowest) {
            lowest = mark;
        }
    }
    return lowest;
}

double calculatePassRate(const vector<double> &marks, double passingGrade) {
    if (marks.empty()) return 0;
    
    int passed = 0;
    for (double mark : marks) {
        if (mark >= passingGrade) {
            passed++;
        }
    }
    return (static_cast<double>(passed) / marks.size()) * 100;
}

void displaySummary(const vector<double> &marks) {
    cout << "\n====================================\n";
    cout << "           GRADE SUMMARY            \n";
    cout << "====================================\n\n";
    
    //display all marks
    cout << "Individual Marks:\n";
    cout << "-----------------\n";
    for (size_t i = 0; i < marks.size(); i++) {
        cout << "Student " << setw(2) << (i + 1) << ": " 
             << fixed << setprecision(2) << setw(6) << marks[i] << "\n";
    }
    
    //calculate statistics
    double average = calculateAverage(marks);
    double highest = findHighest(marks);
    double lowest = findLowest(marks);
    double passRate = calculatePassRate(marks);
    
    cout << "\nStatistics:\n";
    cout << "-----------\n";
    cout << "Average Score : " << fixed << setprecision(2) << average << "\n";
    cout << "Highest Score : " << fixed << setprecision(2) << highest << "\n";
    cout << "Lowest Score  : " << fixed << setprecision(2) << lowest << "\n";
    cout << "Pass Rate     : " << fixed << setprecision(2) << passRate << "%\n";
    
    cout << "\nGrade Distribution:\n";
    cout << "------------------\n";
    
    int aCount = 0, bCount = 0, cCount = 0, dCount = 0, fCount = 0;
    
    for (double mark : marks) {
        if (mark >= 90) aCount++;
        else if (mark >= 80) bCount++;
        else if (mark >= 70) cCount++;
        else if (mark >= 60) dCount++;
        else fCount++;
    }
    
    cout << "A (90-100): " << aCount << " student(s)\n";
    cout << "B (80-89) : " << bCount << " student(s)\n";
    cout << "C (70-79) : " << cCount << " student(s)\n";
    cout << "D (60-69) : " << dCount << " student(s)\n";
    cout << "F (0-59)  : " << fCount << " student(s)\n";
    
    cout << "\n====================================\n";
}
