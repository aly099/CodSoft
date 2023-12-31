#include <iostream>
#include <string>

using namespace std;
const int MAX_TASKS = 10;
string tasks[MAX_TASKS];
bool completed[MAX_TASKS] = { false };

int taskCount = 0;

void addTask(const string& description) 
{
    if (taskCount < MAX_TASKS) 
    {
        tasks[taskCount] = description;
        taskCount++;
    }
    else 
    {
        cout << "Task limit reached." << endl;
    }
}

void viewTasks() 
{
    cout << "Tasks:" << endl;
    for (int i = 0; i < taskCount; i++) 
    {
        cout << (i + 1) << ". " << (completed[i] ? "[x] " : "[ ] ") << tasks[i] << endl;
    }
}

void markAsCompleted(int index) 
{
    if (index >= 1 && index <= taskCount) 
    {
        completed[index - 1] = true;
        cout << "Task marked as completed." << endl;
    }
    else 
    {
        cout << "Invalid task index." << endl;
    }
}

void removeTask(int index) 
{
    if (index >= 1 && index <= taskCount) 
    {
        for (int i = index - 1; i < taskCount - 1; i++) 
        {
            tasks[i] = tasks[i + 1];
            completed[i] = completed[i + 1];
        }
        taskCount--;
        cout << "Task removed." << endl;
    }
    else 
    {
        cout << "Invalid task index." << endl;
    }
}

int main() 
{
    int choice, index;
    string description;

    while (true) 
    {
        cout << "_________________________" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "_________________________" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) 
        {
        case 1:
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, description);
            addTask(description);
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            cout << "Enter task index to mark as completed: ";
            cin >> index;
            markAsCompleted(index);
            break;
        case 4:
            cout << "Enter task index to remove: ";
            cin >> index;
            removeTask(index);
            break;
        case 5:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
