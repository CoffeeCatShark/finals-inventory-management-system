#include <iostream>
#include <string>
#include "Inventory.h"
#include "OrderAndCart.h"
#include "AccessControl.h"
using namespace std;
//readyItem() TO READY ADDING AN ITEM
//inventory.deleteItem()
//inventory.listItem()



int main(){

	readyItem();
	readyItem();
	inventory.deleteItem("a");
	inventory.listItem();
	return 0;
}