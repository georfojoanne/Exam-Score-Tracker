#include <iostream>
#include <limits>
#include <vector>
#include <iomanip> 

using namespace std;

struct Subject {
    string name;
    double score;
    bool hasScore = false;
};

void addScore(vector<Subject>& students) {
    Subject student;
    cout << "Enter subject name: ";
    cin.ignore(); //skips the next character input
    getline(cin, student.name); //basahon ang entire line

    cout << "Enter exam score: ";
    cin >> student.score;

    while (cin.fail() || student.score < 0 || student.score > 100) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid score! Please input score between 0-100: ";
        cin >> student.score;
    }

    student.hasScore = true;
    students.push_back(student); 
    cout << "Score added successfully!\n";
}

void deleteScore(vector<Subject>& students) {
    if (students.empty()) {
        cout << "No scores to delete.\n";
        return;
    }

    string name;
    cout << "Enter the subject name of the score to delete: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    for (auto& student : students) {
        if (student.name == name && student.hasScore) {
            student.score = 0;
            student.hasScore = false;
            found = true;
            cout << "Score for " << name << " deleted successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "No score found for " << name << ".\n";
    }
}

void viewScores(const vector<Subject>& students) {
    if (students.empty()) {
        cout << "No scores recorded yet.\n";
        return;
    }

    cout << "\n========================================= SCORE TABLE =========================================\n";
    cout << left << setw(20) << "Subject Name" << "| " << setw(10) << "Score\n";
    cout << "--------------------------------------------\n";
    for (const auto& student : students) {
        if (student.hasScore) {
            cout << left << setw(20) << student.name << "| " << setw(10) << student.score << endl; //ika run kay formal ang output
        }
    }
    cout << "==============================================\n";
}

void searchScores(vector<Subject>& students) {
    if (students.empty()) {
        cout << "Cannot be found.\n";
        return; 
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string searchName;
    cout << "Enter the subject name you want to search for: ";
    getline(cin, searchName);

    bool found = false;

    cout << "\n========================================= SCORE TABLE =========================================\n";
    cout << left << setw(20) << "Subject Name" << "| " << setw(10) << "Score\n";
    cout << "--------------------------------------------\n";

    for (const auto& student : students) {
        if (student.name == searchName && student.hasScore) {
            cout << left << setw(20) << student.name << "| " << setw(10) << student.score << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Cannot be found.\n";
    }
    cout << "==============================================\n";
}


int main() {
    vector<Subject> students;
    int choice;

    do {
        cout << "                               EXAM PERFORMANCE ANALYZER & TRACKER";
        cout << "\n===============================================================================================\n";
        cout << "\n";
        cout << "1. Add Score\n";
        cout << "2. Delete Score\n";
        cout << "3. View Scores\n";
        cout << "4. Search Subject\n";
        cout << "5. Exit\n";
        cout << "\n===============================================================================================\n";
        cout << "Choose an option: ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears input buffer until newline
            cout << "Invalid choice! Please enter a number between 1 and 5: ";
            cin >> choice;
        }

        switch (choice) {
            case 1:
                addScore(students);
                break;
            case 2:
                deleteScore(students);
                break;
            case 3:
                viewScores(students);
                break;
            case 4:
            	searchScores(students);
            	break;
            case 5:
                cout << "Thank you for using the program!\n";
                break;
        }
    } while (choice != 5);

    return 0;
}