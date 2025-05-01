#include <iostream>
#include <string>
using namespace std;

class Items{
	private:
		string name;
		string id;
		int quantity = 0;
	public:	Items(string name_, string id_, int quantity_): name(name_), id(id_), quantity(quantity_){}
		string getName(){	return name;	}
		string getID(){		return id;	}
		int getQuantity(){	return quantity;}

		void setQuantity(int x){
			quantity = x;
		}

};


class Inventory{
	private: 
	int count = 0;
	Items* items[100];
	Inventory(): count(0) {}
	Inventory(const Inventory&) = delete; 
	public: 
	
	static Inventory& getInstance(){
		static Inventory instance;
		return instance;
	}
	
	
	bool isDuplicateId(string input){
		for(int i=0;i<count;i++){
			if(input == items[i]->getID());
					return true;
		}
		return false;
	}
	
	void addItem(string name, string id, int quantity){
		Items* item = new Items(name,id,quantity);
		items[count++] = item;
		cout<<"Item Added Successfully."<<endl;
	}
	
	void listItem(){
		cout<<"INVENTORY LIST"<<endl;
		cout<<"=================================="<<endl;
		cout<<"Name\tID\tPrice\tQuantity"<<endl;
						for(int i=0;i<count;i++){
						cout<<items[i]->getName()<<"\t"<<items[i]->getID()<<"\t"<<items[i]->getQuantity()<<endl;
		}
	}

	void deleteItem(string input){
	string key = input;	
		
		if(count == 0){
					cout<<"No Items On Inventory"<<endl;
			return;
		}
		
	
		for(int i = 0;i<count;i++){
					if(key == items[i]->getID()){
						delete items[i];
						count--;
						cout<<"Item Successfully Deleted."<<endl;
						return;
			}
		}	
		cout<<"Item Not Found"<<endl;	
	}
			
	
	void removeItem(string input){
		string key = input;
		if(count == 0){
			cout<<"No Items on inventory"<<endl;
			return;
		}
		
		cout<<"Remove/Buy Item: ";
		for(int i=0;i<count;i++){
			if(key == items[i]->getID()){
				string input;
			cout<<"Enter Quantity of Item To Remove: ";
			getline(cin,input);
			int quant = stoi(input);
			bool valid =  false;
		
								if(quant > items[i]->getQuantity()){
										cout<<"Error: Request Exceeds Current Quantity ["<<quant<<"/"<<items[i]->getQuantity()<<"]"<<endl;
										cout<<"New Input: ";
										getline(cin, input);
										quant = stoi(input);
										continue;
								}
			
			items[i]->setQuantity(items[i]->getQuantity()-quant);
			}
		}
		
		
		cout<<"Error:ID Not Found."<<endl;
		return;
	}
	
	
	void addQuantity(string input){
		string key = input;
		string input_;
		for(int i=0;i<count;i++){
			if(key == items[i]->getID()){
				cout<<"Enter Quantity of "<<items[i]->getName()<<" to add"<<endl;
				cout<<"Quantity: ";
				getline(cin, input_);
				int quant = stoi(input_);
				items[i]->setQuantity(quant);
			}
		}
		
	}
		
	
};

Inventory& inventory = Inventory::getInstance();

string setName(){
	string input;
	cout<<"Item Name: ";
	getline(cin, input);
	//ADD CONDITIONALS
	return input;
}

string setID(){
	string input;
	cout<<"Item ID: ";
	getline(cin, input);
	//ADD CONDITIONALS
	return input;
}

int setQuantity(){
	string input;
	int quant;
	cout<<"Quantity: ";
	getline(cin,input);
	//ADD CONDITIONALS
	quant = stoi(input);
	return quant;
}

void readyItem(){
	cout<<"Add Item"<<endl;
	inventory.addItem(setName(),setID(),setQuantity());
	
}