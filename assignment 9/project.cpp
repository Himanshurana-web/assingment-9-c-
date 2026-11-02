#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Expense
{
    int id;
    string date, category, description;
    float amount;
};

Expense e[100];
int n = 0;
float budget = 0;

// Add Expense
void addExpense()
{
    e[n].id = n + 1;

    cout << "\nEnter date: ";
    cin >> e[n].date;

    cout << "Enter category: ";
    cin >> e[n].category;

    cout << "Enter description: ";
    cin >> e[n].description;

    cout << "Enter amount: ";
    cin >> e[n].amount;

    n++;

    cout << "Expense added successfully!\n";
}

// View Expenses
void viewExpenses()
{
    if (n == 0)
    {
        cout << "\nNo expenses found.\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nID: " << e[i].id;
        cout << "\nDate: " << e[i].date;
        cout << "\nCategory: " << e[i].category;
        cout << "\nDescription: " << e[i].description;
        cout << "\nAmount: Rs. " << e[i].amount << endl;
    }
}

// Category-wise Expense
void categoryExpense()
{
    string cat;
    float total = 0;

    cout << "\nEnter category: ";
    cin >> cat;

    for (int i = 0; i < n; i++)
    {
        if (e[i].category == cat)
            total += e[i].amount;
    }

    cout << "Total " << cat << " expense: Rs. "
         << total << endl;
}

// Monthly Report
void monthlyReport()
{
    float total = 0;

    for (int i = 0; i < n; i++)
        total += e[i].amount;

    cout << "\nTotal Expense: Rs. " << total << endl;
    cout << "Budget: Rs. " << budget << endl;
    cout << "Remaining: Rs. " << budget - total << endl;
}

// Search Expense
void searchExpense()
{
    int id, found = 0;

    cout << "\nEnter Expense ID: ";
    cin >> id;

    for (int i = 0; i < n; i++)
    {
        if (e[i].id == id)
        {
            cout << "\nDate: " << e[i].date;
            cout << "\nCategory: " << e[i].category;
            cout << "\nAmount: Rs. " << e[i].amount << endl;

            found = 1;
            break;
        }
    }

    if (found == 0)
        cout << "Expense not found.\n";
}

// Save Expenses
void saveData()
{
    ofstream file("expenses.txt");

    for (int i = 0; i < n; i++)
    {
        file << e[i].id << " "
             << e[i].date << " "
             << e[i].category << " "
             << e[i].description << " "
             << e[i].amount << endl;
    }

    file.close();
    cout << "\nData saved successfully!\n";
}

// Main
int main()
{
    int choice = 0;

    cout << "===== SMART DIGITAL EXPENSE TRACKER =====\n";

    while (choice != 8)
    {
        cout << "\n1. Add Expense";
        cout << "\n2. View Expenses";
        cout << "\n3. Category-wise Expense";
        cout << "\n4. Monthly Report";
        cout << "\n5. Set Budget";
        cout << "\n6. Search Expense";
        cout << "\n7. Save Data";
        cout << "\n8. Exit";

        cout << "\n\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addExpense();
            break;

        case 2:
            viewExpenses();
            break;

        case 3:
            categoryExpense();
            break;

        case 4:
            monthlyReport();
            break;

        case 5:
            cout << "Enter monthly budget: Rs. ";
            cin >> budget;
            cout << "Budget set successfully!\n";
            break;

        case 6:
            searchExpense();
            break;

        case 7:
            saveData();
            break;

        case 8:
            saveData();
            cout << "\nThank you!\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }
    }

    return 0;
}