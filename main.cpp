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
	cout<<"[1]\tUpdate Item Quantities"<<endl;
	cout<<"[2]\tRemove Item Quantities"<<endl;
	if(adminControl == true){
	cout<<"[3]\tAdd New Items"<<endl;
	cout<<"[4]\tDelete Items from Inventory"<<endl;
	}
	
	
}

int main(){
	
	menu();
	
	
	
	delete admin;
	delete employee;
	return 0;
}