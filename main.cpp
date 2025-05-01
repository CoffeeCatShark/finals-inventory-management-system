#include <iostream>
#include <string>
#include "AccessControl.h"
#include "Inventory.h"

using namespace std;
//readyItem() TO READY ADDING AN ITEM
//inventory.deleteItem()
//inventory.listItem()

void menu(){
		while(!validUser){
		login();
	}
string input;	
	cout<<"INVENTORY MANAGEMENT SYSTEM"<<endl;
	cout<<"=================================="<<endl;
	cout<<"[1]\tView Inventory"<<endl;
	cout<<"[2]\tUpdate Item Quantities"<<endl;
	cout<<"[3]\tRemove Item Quantities"<<endl;
	if(adminControl == true){
	cout<<"[4]\tAdd New Items"<<endl;
	cout<<"[5]\tDelete Items from Inventory"<<endl;
	cout<<"[6]\tPrint Current Inventory"<<endl;
	}
	cout<<"Input: ";
	getline(cin,input);
	
	
}

int main(){
	
	menu();
	
	
	
	delete admin;
	delete employee;
	delete adminAccess;
	delete employeeAccess;
	return 0;
}