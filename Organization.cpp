#include <iostream>
using namespace std;

class Organization
{
	//Declaring five private variables
	private:
	int orgId = 0;
	string name;
	string email;
	int noOfEmpl;
	string employee[10];

	public:
		//Public constructor
		Organization() 
		{
			noOfEmpl = 0;
			for (int i = 0; i < 10; i++)
			{
				employee[i] = " ";
			}
		}

	//Public constructor with parameters
	Organization(int org, string p_name, string mail)
	{
		orgId = org;
		name = p_name;
		email = mail;
		noOfEmpl = 0;
		for (int i = 0; i < 10; i++)
		{
			employee[i] = " ";
		}
	}
	//Public destructor
	~Organization()
	{
		cout << "\n\nOrganization ID:-" << orgId;
		cout << "\nOrganization Name:-" << name;
	}
	
	//Getter and Setter functions
	void setOId(int orgId)
	{
		this->orgId = orgId;
	}
	void setOName(string name)
	{
		this->name = name;
	}
	void setOEmail(string email)
	{
		this->email = email;
	}
	int getOId()
	{
		return orgId;
	}
	string getOName()
	{
		return name;
	}
	string getOEmail()
	{
		return email;
	}
	int getNoOfEmployee()
	{
		return noOfEmpl;
	}
	string getEmployee(int b)
	{
		return employee[b];
	}
	
	//Function to add new employee in the array
	void addnewContract(string b)
	{
		if (noOfEmpl < 10)
		{
			for (int i = 0; i < 10; i++)
			{
				if (employee[i] == " ")
				{
					employee[i] = b;
					break;
				}
			}
			noOfEmpl++;
		}
		else
		{
			cout << "You reach the limit";
		}
	}
	
	//Function to remove an employee in the array
	void removeContract(string b)
	{
		for (int i = 0; i < 10; i++)
		{
			if (employee[i] == b)
			{
				for (int j = i; j < 9; j++)
				{
					employee[j] = employee[j + 1];
				}
				employee[9] = " ";
				noOfEmpl--;
				break;
			}
		}
	}
	
	bool hasMoreThan(int b)
	{
		if (noOfEmpl > b)
			return true;
		else
			return false;
	}

	bool hasMoreEmp(Organization a)
	{
		if (this->noOfEmpl > a.noOfEmpl)
			return true;
		else
			return false;
	}
	
	//Function to print the details of the organization
	void print()
	{
		cout << "\n\nOrganization ID:-" << orgId;
		cout << "\nOrganization Name:-" << name;
		cout << "\nOrganization Email:-" << email;
		cout << "\nNumber of Employees:-" << noOfEmpl;
	}
};

//Function outside organization class to print the list of the employees
void printEmployeeList(Organization org)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "\n" << org.getEmployee(i);
	}
}
int main()
{
	Organization org1;
	Organization org2(56982, "ORG 1", "ORG1 @ G M A L. COM");

	org1.print();
	org2.print();

	org1.addnewContract("Emp1");
	org1.addnewContract("Emp2");
	org1.addnewContract("Emp3");
	org1.addnewContract("Emp4");

	org2.addnewContract("Emp3");
	org2.addnewContract("EmpA");
	org2.addnewContract("EmpB");
	org2.addnewContract("EmpC");
	org2.addnewContract("EmpD");
	org2.addnewContract("EmpE");

	org2.removeContract("EmpA");

	org2.print();

	printEmployeeList(org2);
	return 0;
}
