#include <iostream>
#include <string>
using namespace std;
bool adminControl = false;

class User{
	private:
		
	protected:	
		int userCount = 1;
		bool isAdmin = false;
		string username;
		string password;
	public:
		User(string username_, string password_, bool isAdmin_) : username(username_), password(password_), isAdmin(isAdmin_{} 
		
	virtual void displayAccess() {}
		
		int returnCount(){
			return userCount;
		}
		void addCount(){
			userCount++;
		}
		void removeCount(){
			userCount--;
		}
	
		string getName(){
		return username;
	}
	
		string getPass(){
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







void login(){
string username;
string password;


	 cout<<"Enter Username: ";
	 getline(cin, username);
	 cout<<"Enter Password: ";
	 getline(cin, password);
		
}
