#include <iostream>
#include <string>
using namespace std;
bool adminControl = false;

class User{
	private:
		
	protected:	
		bool isAdmin = false;
		string username;
		string password;
	public:
		User(string username_, string password_) : username(username_), password(password_){} 
		
	virtual void displayAccess() {}
		
		string getName(){
			return username;
		}
		string getPassword(){
			return password;
		}
};


class Employee: public User{
	private:
		bool isAdmin = false;
	public: 
	Employee(string x, string y): User(x,y) {}
	
	void displayAccess() override{
		cout<<"Access Granted"<<endl;
		cout<<"User: "<<username<<endl;
		cout<<"Role: Employee"<<endl;
	}
		
};


class Admin: public User{
	private:
		bool isAdmin = true;
	public: 
	Admin(string x, string y): User(x,y) {}
		void displayAccess() override{
		cout<<"Access Granted"<<endl;
		cout<<"User: "<<username<<endl;
		cout<<"Role: Admin"<<endl;
	}
	
	
};		

class AccountManager{
	private: 
		User* user;
	public:
		void setUser(User* user){
			this->user = user;	
		}
	
		void displayUser(){
			user->displayAccess();
		}
	
	
};
AccountManager manager;

Admin* admin = new Admin("ADMIN","ADMIN");
Employee* employee = new Employee("AAA","AAA");

void login(){
string username;
string password;

	 cout<<"Enter Username: ";
	 getline(cin, username);
	 cout<<"Enter Password: ";
	 getline(cin, password);
		
		if(username == admin->getName() && password == admin->getPassword()){
			admin->displayAccess();
			adminControl = true;
		}
		else if(username == employee->getName() && password == employee->getPassword()){
			employee->displayAccess();
			
		}
		else{
			cout<<"Error: Username/Password is Incorrect."<<endl;
		}
		
}