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

    // Check if the subject already exists
    for (const auto& existingStudent : students) {
        if (existingStudent.name == student.name) {
            cout << "Subject " << student.name << " already exists. You can't enter it again.\n";
            return; // Exit the function, don't add the score
        }
    }

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
    displayScores(students);
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
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->name == name) {
            students.erase(it);  // Erase the subject from the vector
            found = true;
            cout << "Subject " << name << " deleted successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "No score found for " << name << ".\n";
    } else {
        displayScores(students);
    }
}

void viewScores(const vector<Subject>& students) {
    cout << "View Exam Scores\n"; 

    if (students.empty()) {
        cout << "No scores available.\n";
        return;
    }

    int highestScore = -1;
    int lowestScore = 101;
    string highestSubject;
    string lowestSubject;

    for (const auto& student : students) {
        if (student.hasScore) {
            if (student.score > highestScore) {
                highestScore = student.score;
                highestSubject = student.name;
            }
            if (student.score < lowestScore) {
                lowestScore = student.score;
                lowestSubject = student.name;
            }
        }
    }

    cout << "Highest score: " << highestSubject << " with " << highestScore << "\n\n";
    cout << "Lowest score: " << lowestSubject << " with " << lowestScore << "\n";

    if (lowestScore < 30) {
        cout << "Study Tip: Focus on basics, ask for help, and practice regularly.\n";
    } else if (lowestScore < 50) {
        cout << "Study Tip: Review weak areas, practice more, and stay organized.\n";
    } else {
        cout << "Study Tip: Keep practicing, challenge yourself, and stay confident.\n";
    }
}

void searchScore(const vector<Subject>& students) {
    cout << "Search Exam Score\n";
}

int main() {
    vector<Subject> students;
    int choice;

    // Display the introductory message only once
    cout << "                                EXAM PERFORMANCE ANALYZER & TRACKER";
    cout << "\n===============================================================================================\n";
    cout << "\n";

    do {
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

        if (choice != 5) {
            char continueChoice;
            cout << "\nDo you want to perform another action? (y/n): ";
            cin >> continueChoice;

            // If the user answers 'n' or something else, exit the loop
            if (continueChoice == 'n' || continueChoice == 'N') {
                choice = 5;  // Set choice to 5 to break out of the loop
            }
        }

    } while (choice != 5);

    return 0;
}