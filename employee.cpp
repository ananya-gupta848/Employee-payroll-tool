#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to hold employee details
struct Employee {
    int id;
    string name;
    double basicSalary;
    double hra;   // House Rent Allowance
    double da;    // Dearness Allowance
    double tax;   // Tax deduction
    double netSalary;
};


// Function to calculate net salary
double calculateNetSalary(double basic, double hra, double da, double tax) {
    return (basic + hra + da) - tax;
}

// Function to add a new employee
void addEmployee(vector<Employee> &employees) {
    Employee e;
    cout << "Enter Employee ID: ";
    cin >> e.id;
    cout << "Enter Employee Name: ";
    cin.ignore();
    getline(cin, e.name);
    cout << "Enter Basic Salary: ";
    cin >> e.basicSalary;
    cout << "Enter HRA (House Rent Allowance): ";
    cin >> e.hra;
    cout << "Enter DA (Dearness Allowance): ";
    cin >> e.da;
    cout << "Enter Tax Deduction: ";
    cin >> e.tax;

    // Calculate net salary
    e.netSalary = calculateNetSalary(e.basicSalary, e.hra, e.da, e.tax);

    employees.push_back(e);
    cout << " Employee added successfully!\n";
}

// Function to display all employees
void displayEmployees(const vector<Employee> &employees) {
    if (employees.empty()) {
        cout << " No employee records found.\n";
        return;
    }
    cout << "\n--- Employee Payroll Records ---\n";
    for (const auto &e : employees) {
        cout << "ID: " << e.id << ", Name: " << e.name
             << ", Basic: " << e.basicSalary
             << ", HRA: " << e.hra
             << ", DA: " << e.da
             << ", Tax: " << e.tax
             << ", Net Salary: " << e.netSalary << endl;
    }
}

// Function to search employee by ID
void searchEmployee(const vector<Employee> &employees) {
    int id;
    cout << "Enter Employee ID to search: ";
    cin >> id;

    for (const auto &e : employees) {
        if (e.id == id) {
            cout << " Employee Found!\n";
            cout << "ID: " << e.id << ", Name: " << e.name
                 << ", Net Salary: " << e.netSalary << endl;
            return;
        }
    }
    cout << " Employee with ID " << id << " not found.\n";
}

// Function to update employee details
void updateEmployee(vector<Employee> &employees) {
    int id;
    cout << "Enter Employee ID to update: ";
    cin >> id;

    for (auto &e : employees) {
        if (e.id == id) {
            cout << "Enter new Basic Salary: ";
            cin >> e.basicSalary;
            cout << "Enter new HRA: ";
            cin >> e.hra;
            cout << "Enter new DA: ";
            cin >> e.da;
            cout << "Enter new Tax Deduction: ";
            cin >> e.tax;

            // Recalculate net salary
            e.netSalary = calculateNetSalary(e.basicSalary, e.hra, e.da, e.tax);

            cout << " Employee record updated successfully!\n";
            return;
        }
    }
    cout << " Employee with ID " << id << " not found.\n";
}

int main() {
    vector<Employee> employees; // dynamic list of employees
    int choice;

    do {
        cout << "\n--- Employee Payroll Tool ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee by ID\n";
        cout << "4. Update Employee Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(employees); break;
            case 2: displayEmployees(employees); break;
            case 3: searchEmployee(employees); break;
            case 4: updateEmployee(employees); break;
            case 5: cout << " Exiting program...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
