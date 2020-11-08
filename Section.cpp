#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Section {
//Declaring private variables
  private:
  int sectionId;
  double section_grades[20];
  int number_of_students;
  int i = 0;

  public:
    //Public constructor
    Section() {
     sectionId = 0;
     number_of_students = 0;
     for (i = 0; i < 20; i++) {
       section_grades[i] = 0;
      }
    }
	
//Public constructor with parameters
  Section(int sec, int num) {
    sectionId = sec;
    number_of_students = num;
    double grade;
    cout << "\n************ Section: " << sectionId << "************\n";
    for (i = 0; i < number_of_students; i++) {
      cout << "Enter student:" << i + 1 << " Grade: ";
      scanf("%lf", & grade);
      section_grades[i] = grade;
    }

  }
  //Getter and setter functions
  void setSectionId(int secID) {
    if (secID > 0 && secID < 100) {
      sectionId = secID;
    }
  }
  int getSectionId() {
    return sectionId;
  }

  void setNumber_of_students(int num) {
    if (num > 0 && num < 21) {
      number_of_students = num;
    }
  }

  void set_grade(int i, double g) {
    section_grades[i] = g;
  }

  double get_grade(int i) {
    if (i >= 0 && i < number_of_students - 1) {
      return section_grades[i];
    }
  }

  void updateGrade(int i, double value) {
    if (i >= 0 && i < number_of_students - 1) {
      section_grades[i] = section_grades[i] + value;
    }
  }

  double get_average_grade() {
    double sum = 0;
    for (i = 0; i < number_of_students; i++) {
      sum = sum + section_grades[i];
    }
    double average = sum / number_of_students;
  }

  bool hasHigherGrade(Section s2) {
    if (this -> get_average_grade() > s2.get_average_grade())
      return true;
    else
      return false;
  }
  //Function to print information about section
  void print() {
    cout << "\n************ Section: " << sectionId << "************\n";
    for (i = 0; i < number_of_students; i++) {
      cout << "Student Number:" << i + 1 << " Grade is: " << floor(section_grades[i]) << "\n";
    }
  }

};

int main() {
  int sec;
  int no_of_stud1;
  int no_of_stud2;

  Section s1;
  cout << "Enter Section ID: ";
  cin >> sec;
  cout << "Enter the number of students: ";
  cin >> no_of_stud1;
  s1.setSectionId(sec);
  s1.setNumber_of_students(no_of_stud1);

  cout << "\n\nEnter Section ID: ";
  cin >> sec;
  cout << "Enter the number of students: ";
  cin >> no_of_stud2;

  Section s2(sec, no_of_stud2);

  double gradeval;

  cout << "\n************ Section: 1************\n";
  for (int i = 0; i < no_of_stud1; i++) {
    cout << "Enter student:" << i + 1 << " Grade:";
    cin >> gradeval;
    s1.set_grade(i, gradeval);
  }

  s2.updateGrade(0, 5);

  s1.updateGrade(2, -1);

  s1.print();
  s2.print();

  bool flag = s1.hasHigherGrade(s2);

  if (flag == true) {
    cout << "\nAvg Section 1 > Avg Section 2";
  } else {
    cout << "\nAvg Section 1 < Avg Section 2";
  }
  return 0;
}
