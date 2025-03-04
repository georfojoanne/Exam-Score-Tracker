#include <iostream>
#include <limits>
#include <vector>
using namespace std;

struct Subject {
    string name;
    int score;
    bool hasScore = false;
};

void addScore(vector<Subject>& scores) {
    Subject score;
    cout << "Enter subject name: ";
    cin.ignore(); 
    getline(cin, score.name); 

    cout << "Enter exam score: ";
    cin >> score.score;

    while (cin.fail() || score.score < 0 || score.score > 100) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid score! Please input score between 0-100: ";
        cin >> score.score;
    }

    scores.hasScore = true;
    students.push_back(student); //adds a subject to the list
    cout << "Score added successfully!\n";
}

void deleteScore(vector<Subject>& scores) {
    cout << "Delete Exam Score\n";
}

void viewScores(const vector<Subject>& scores) {
    cout << "View Exam Scores\n";
}

void searchScore(const vector<Subject>& scores) {
    cout << "Search Exam Score\n";
}
int main() {
    vector<Subject> score;
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

        // Validate the input
        while (cin.fail() || choice < 1 || choice > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears input buffer until newline
            cout << "Invalid choice! Please enter a number between 1-5: ";
            cin >> choice;
        }

        switch (choice) {
            case 1:
                addScore(score);
                break;
            case 2:
                deleteScore(score);
                break;
            case 3:
                viewScores(score);
                break;
            case 4:
            	searchScore(score);
            	break;
            case 5:
                cout << "Thank you for using the program!\n";
                break;
        }
    } while (choice != 5);

    return 0;
}