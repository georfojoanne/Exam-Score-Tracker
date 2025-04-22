#include <iostream>
#include <limits>
#include <vector>
using namespace std;

const int PASSING_SCORE = 50;

struct Subject {
    string name;
    int score;
    bool hasScore = false;
};

void displayScores(const vector<Subject>& students) {
    if (students.empty()) {
        cout << "\nNo scores available.\n";
        return;
    }
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
    bool isDuplicate;
    
    cin.ignore();
    do {
        isDuplicate = false;
        cout << "Enter subject name: ";
        getline(cin, student.name);
        
        for (const auto& s : students) {
            if (s.name == student.name) {
                cout << "Error: Subject name already exists! Please enter a different subject name.\n";
                isDuplicate = true;
                break;
            }
        }
    } while (isDuplicate);

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

void updateScore(vector<Subject>& students) {
    if (students.empty()) {
        cout << "\nNo scores available to update.\n";
        return;
    }
    
    cout << "Enter subject name to update: ";
    cin.ignore();
    string subjectName;
    getline(cin, subjectName);

    for (auto& student : students) {
        if (student.name == subjectName) {
            int choice;
            cout << "What would you like to update?\n1. Subject Name\n2. Score\nChoose an option: ";
            cin >> choice;
            
            if (choice == 1) {
                cout << "Enter new subject name: ";
                cin.ignore();
                getline(cin, student.name);
            } else if (choice == 2) {
                cout << "Enter new exam score: ";
                cin >> student.score;
                while (cin.fail() || student.score < 0 || student.score > 100) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid score! Please input score between 0-100: ";
                    cin >> student.score;
                }
            } else {
                cout << "Invalid choice!\n";
                return;
            }
            
            cout << "Score updated successfully!\n";
            displayScores(students);
            return;
        }
    }
    cout << "Subject not found!\n";
}

void deleteScore(vector<Subject>& students) {
    if (students.empty()) {
        cout << "\nNo scores available to delete.\n";
        return;
    }
    
    cout << "Enter subject name to delete: ";
    cin.ignore();
    string subjectName;
    getline(cin, subjectName);

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->name == subjectName) {
            students.erase(it);
            cout << "Score deleted successfully!\n";
            displayScores(students);
            return;
        }
    }
    cout << "Subject not found!\n";
}

void viewScores(const vector<Subject>& students) {
    if (students.empty()) {
        cout << "\nNo scores available.\n";
        return;
    }

    displayScores(students);

    Subject highest = students[0];
    Subject lowest = students[0];
    for (const auto& student : students) {
        if (student.score > highest.score) highest = student;
        if (student.score < lowest.score) lowest = student;
    }

    cout << "\nScore Summary:\n";
    cout << "------------------------------------------------\n";
    cout << "| Category          | Subject Name          | Score |\n";
    cout << "------------------------------------------------\n";
    cout << "| Highest Score    | " << highest.name << string(20 - highest.name.length(), ' ') << "| " << highest.score << " |\n";
    cout << "| Lowest Score     | " << lowest.name << string(20 - lowest.name.length(), ' ') << "| " << lowest.score << " |\n";
    cout << "------------------------------------------------\n";
    
	cout << "\nPassing Score: " << PASSING_SCORE << "\n";


	cout << "\nSubjects that passed:\n";
	bool hasPassed = false;
	for (const auto& student : students) {
    	if (student.score >= PASSING_SCORE) {
        cout << "- " << student.name << " (" << student.score << ")\n";
        hasPassed = true;
   	 }
	}
		if (!hasPassed) cout << "No subjects passed.\n";

	cout << "\nSubjects that failed:\n";
	bool hasFailed = false;
	for (const auto& student : students) {
    	if (student.score < PASSING_SCORE) {
        cout << "- " << student.name << " (" << student.score << ")\n";
        hasFailed = true;
    	}
	}
		if (!hasFailed) cout << "No subjects failed.\n";

    string tips[] = {
    "Review your mistakes and learn from them!",
    "Practice makes perfect. Keep solving problems!",
    "Stay organized and manage your study time well!",
    "Take regular breaks to improve concentration!",
    "Use active recall and spaced repetition techniques!"
	};

cout << "\nStudy Tip: " << tips[rand() % 5] << "\n";

}



void searchScore(const vector<Subject>& students) {
    if (students.empty()) {
        cout << "\nNo scores available to search.\n";
        return;
    }

    cout << "Enter subject name to search: ";
    cin.ignore();
    string subjectName;
    getline(cin, subjectName);

    for (const auto& student : students) {
        if (student.name == subjectName) {
            cout << "\nSubject found!\n";
            cout << "-------------------------\n";
            cout << "Subject: " << student.name << "\n";
            cout << "Score:   " << student.score << "\n";
            cout << "Status:  " << (student.score >= PASSING_SCORE ? "Passed" : "Failed") << "\n";
            cout << "-------------------------\n";
            return;
        }
    }

    cout << "Subject not found!\n";
}


int main() {
    vector<Subject> students;
    int choice;

    do {
        cout << "                                EXAM PERFORMANCE ANALYZER & TRACKER";
        cout << "\n===============================================================================================\n";
        cout << "\n";
        cout << "1. Add Score\n";
        cout << "2. Update Score\n";
        cout << "3. Delete Score\n";
        cout << "4. View Scores\n";
        cout << "5. Search Score\n";
        cout << "6. Exit\n";
        cout << "\n===============================================================================================\n";
        cout << "Choose an option: ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice! Please enter a number between 1-6: ";
            cin >> choice;
        }

        switch (choice) {
            case 1:
                addScore(students);
                break;
            case 2:
            	updateScore(students);
            	break;
            case 3:
                deleteScore(students);
                break;
            case 4:
                viewScores(students);
                break;
            case 5:
                searchScore(students);
                break;
            case 6:
                cout << "Thank you for using the program!\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
