#include <string>
using namespace std;

//base class employee
class Employee {

protected:
  string name;
  int age, vacationDays;
  double weeklySalary, healthCareContributions;

public:
    //consturctor for employee
  Employee(string name, int age) {
    this->name = name;
    this->age = age;
    weeklySalary = 0.0;
    vacationDays = 0;
    healthCareContributions = 0.0;
    }

    //virtual function for weekly salary
    virtual double calculateWeeklySalary() = 0;
    //virtual function for healthcare contributions
    virtual double calculateHealthCareContributions() = 0;
    //virtual function for vacation days
    virtual int calculateVacationDays() = 0;
    //name of employee
    virtual string getName() { return this->name; }
    //age of employee
    virtual int getAge() { return this->age; }
};

//create a derived class
class Professional : public Employee {

private:
  double monthlySalary;
  int daysVacation;

public:
    //constructor for professional
    Professional(string name, int age, double monthly) : Employee(name, age) {
      monthlySalary = monthly;
      daysVacation = 30;
    }

    //weekly salary calculation
    double calculateWeeklySalary() {
      return (monthlySalary / 4);
    }

    //healthcare contribution calculation
    double calculateHealthCareContributions() {
      return ((monthlySalary * 0.10) / 4);
    }

    //vacation day calculation
    int calculateVacationDays() {
      return daysVacation;
    }

    //print employee information for professional
    void print() {
      cout << endl << "Name: " << getName() << endl;
      cout << "Age: " << getAge() << endl;
      cout << "Weekly Salary: " << calculateWeeklySalary() << endl;
      cout << "Healthcare Contributions: " << calculateHealthCareContributions() << endl;
      cout << "Vacation Days: " << calculateVacationDays() << endl;
    }
};

//derived class for nonprofessional
class Nonprofessional : public Employee {

private:
  double hourlyRate;
  int hoursWorked;

public:
    //consturctor for nonprofessional
    Nonprofessional(string name, int age, double rate, int hours) : Employee(name, age) {
      hourlyRate = rate;
      hoursWorked = hours;
    }

    //weekly salary calculation
    double calculateWeeklySalary() {
      return (hourlyRate * hoursWorked);
    }

    //healthcare contribution calculation
    double calculateHealthCareContributions() {
      return (hourlyRate * hoursWorked * 0.05);
    }

    //vacation days calculation
    int calculateVacationDays() {
      return (hoursWorked / 10);
    }

    //print employee infomation for nonprofessional 
    void print() {
      cout << endl << "Name: " << getName() << endl;
      cout << "Age: " << getAge() << endl;
      cout << "Weekly Salary: " << calculateWeeklySalary() << endl;
      cout << "Healthcare Contributions: " << calculateHealthCareContributions() << endl;
      cout << "Vacation Days: " << calculateVacationDays() << endl;
    }
};