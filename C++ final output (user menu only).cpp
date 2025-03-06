#include <iostream>
#include <limits>
#include <vector>
using namespace std;

struct Subject {
    string name;
    int score;
    bool hasScore = false;
};

void displayScores(const vector<Subject>& students) {
    cout << "\nUpdated List of Scores:\n";
    cout << "------------------------------------------------\n";
    cout << "| Subject Name        | Score |\n";
    cout << "------------------------------------------------\n";
    for (const auto& student : students) {
        cout << "| " << student.name;
        cout << string(20 - student.name.length(), ' ') << "| " << student.score << " |\n";
    }
    cout << "------------------------------------------------\n";
}

void addScore(vector<Subject>& students) {
    Subject student;
    cout << "Enter subject name: ";
    cin.ignore(); 
    getline(cin, student.name); 

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
    // Display updated list of scores after adding a new one
    displayScores(students);
}

void deleteScore(vector<Subject>& students) {
    cout << "Delete Exam Score\n";
}

void viewScores(const vector<Subject>& students) {
    cout << "View Exam Scores\n";
}

void searchScore(const vector<Subject>& students) {
    cout << "Search Exam Score\n";
}
int main() {
    vector<Subject> students;
    int choice;

    do {
        cout << "                                EXAM PERFORMANCE ANALYZER & TRACKER";
        cout << "\n===============================================================================================\n";
        cout << "\n";
        cout << "1. Add Score\n";
        cout << "2. Delete Score\n";
        cout << "3. View Scores\n";
        cout << "4. Search Score\n";
        cout << "5. Exit\n";
        cout << "\n===============================================================================================\n";
        cout << "Choose an option: ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice! Please enter a number between 1-5: ";
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
            	searchScore(students);
            	break;
            case 5:
                cout << "Thank you for using the program!\n";
                break;
        }
    } while (choice != 5);

    return 0;
}