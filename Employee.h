#pragma once
#include <string>
#include<iostream>
using namespace std;

class Employee {
private:
	string name;
	int age;
	int salary;
	int experience;

public:
	Employee() {
		name = "";
		age = -1;
		salary = -1;
		experience = -1;
	}

	Employee(string n, int a, int s, int e) {
		name = n;
		age = a;
		salary = s;
		experience = e;
	}

	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
	int getSalary() {
		return salary;
	}
	int getExperience() {
		return experience;
	}

	void setName(string n) {
		name = n;
	}

	void setAge(int a) {
		age = a;
	}

	void setSalary(int s) {
		salary = s;
	}

	void setExperience(int e) {
		experience = e;
	}
};