#include <iostream>
#include <limits>

using namespace std;

struct Student {
    string name;
    double score;
    bool hasScore = false;
};

void addScore(Student& student) {
    cout << "Enter student name: ";
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
    cout << "Score added successfully!\n";
}

void deleteScore(Student& student) {
    if (!student.hasScore) {
        cout << "No score to delete.\n";
        return;
    }

    student.score = 0;
    student.hasScore = false;
    cout << "Score deleted successfully.\n";
}

void viewScore(const Student& student) {
    if (!student.hasScore) {
        cout << "No score recorded yet.\n";
        return;
    }

    cout << "Score: " << student.score <<endl;
}

// Function to search for a student's score by name
void searchScore(const Student& student) {
    if (!student.hasScore) {
        cout << "No scores found.\n";
        return;
    }

    cout << "Score: " << student.score << endl;
}

int main() {
    Student student;
    int choice;

    do {
        cout << "\n===== Exam Score Tracker =====\n";
        cout << "1. Add Score\n";
        cout << "2. Delete Score\n";
        cout << "3. View All Scores\n";
        cout << "4. Search Score\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice! Please enter a number between 1 and 5: ";
            cin >> choice;
        }

        switch (choice) {
            case 1:
                addScore(student);
                break;
            case 2:
                deleteScore(student);
                break;
            case 3:
                viewScore(student);
                break;
            case 4:
                searchScore(student);
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
        }
    } while (choice != 5);

    return 0;
}