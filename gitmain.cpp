#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayToDoList(const vector<string>& toDoList) {
    if (toDoList.empty()) {
        cout << "Your to-do list is empty!\n";
    } else {
        cout << "\nYour To-Do List:\n";
        for (size_t i = 0; i < toDoList.size(); ++i) {
            cout << i + 1 << ". " << toDoList[i] << "\n";
        }
    }
}

void addTask(vector<string>& toDoList) {
    cout << "Enter the task you want to add: ";
    string task;
    cin.ignore();
    getline(cin, task);
    toDoList.push_back(task);
    cout << "Task added successfully!\n";
}

void removeTask(vector<string>& toDoList) {
    if (toDoList.empty()) {
        cout << "Your to-do list is empty! No task to remove.\n";
        return;
    }

    cout << "Enter the number of the task you want to remove: ";
    size_t taskNumber;
    cin >> taskNumber;

    if (taskNumber == 0 || taskNumber > toDoList.size()) {
        cout << "Invalid task number!\n";
    } else {
        toDoList.erase(toDoList.begin() + static_cast<std::vector<string>::difference_type>(taskNumber - 1));
        cout << "Task removed successfully!\n";
    }
}

int main() {
    vector<string> toDoList;
    int choice;

    do {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. View To-Do List\n";
        cout << "2. Add Task\n";
        cout << "3. Remove Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayToDoList(toDoList);
                break;
            case 2:
                addTask(toDoList);
                break;
            case 3:
                removeTask(toDoList);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
