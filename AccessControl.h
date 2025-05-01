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
		
};


class Employee: public User{
	private:
		bool isAdmin = false;
	public: 
	Employee(string x, string y): User(x,y) {}
	
	void displayAccess() override{
		cout<<"Access Granted"<<endl;
		cout<<"User: "<<username<<endl;
		cout<<"Role: Administrator"<<endl;
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
		cout<<"Role: Employee"<<endl;
	}
	
	
};		

class AccountManager{
	private: 
		int count = 0;
		User* user;
	public:
		void setUser(User* user){
			this->user = user;	
		}
	
		void displayUser(){
			user->displayAccess();
		}
	
	
};





void login(){
string username;
string password;


	 cout<<"Enter Username: ";
	 getline(cin, username);
	 cout<<"Enter Password: ";
	 getline(cin, password);
		
}