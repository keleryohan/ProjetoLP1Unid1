#include <string>
#include <iostream>
#include <vector>
using namespace std;
#ifndef Employee_h
#define Employee_h
#ifndef Company_h
#define Company_h

class Employee {
public:
	string name;
	string cpf;
	float salary;
	string date;
	
	//void printall();
  Employee(string n, float s, string d);
};
#endif


class Company {
public:
	string name;
	string cnpj;
	//TEST : 
	vector<Employee> employee; // Vector of employees

	Company(string n, string c);
	//void printall();
};
#endif