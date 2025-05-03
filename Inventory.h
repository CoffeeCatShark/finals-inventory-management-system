#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool isString(const string& name) {	
    for (char ch : name) {
        if (!isalpha(ch) && ch == ' ') {
            return false;
        }
    }
    return !name.empty(); // Ensure the name is not empty
}

string capital(string input){
	string _input;
	
    for (int i = 0; i < input.length(); i++)
        input[i] = toupper(input[i]);

	return input;
}

int exceptionHandle(){
	bool isValid = false;
	int digit;
	string input;
	while(!isValid){

		try{
		getline(cin,input);
        digit = stoi(input); 
        isValid = true;
		}
		catch (invalid_argument&) {
                        cout << "Invalid input. Please enter a number." << endl;
                        cin.clear();
                        		cout<<"Input: ";
     	}
      catch (out_of_range&) {
    	cerr << "Input too large." << endl;
    	cin.clear();
    			cout<<"Input: ";
    }
	}
	
	return digit;
}


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
		cout<<"Name\tID\tQuantity"<<endl;
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
			cout<<"Enter Quantity of "<<items[i]->getName()<<" To Remove: ";
			int quant = exceptionHandle();
			bool valid =  false;
		
								if(quant > items[i]->getQuantity()){
										cout<<"Error: Request Exceeds Current Quantity ["<<quant<<"/"<<items[i]->getQuantity()<<"]"<<endl;
										cout<<"New Input: ";
										quant = exceptionHandle();
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
				int quant = exceptionHandle();
				items[i]->setQuantity(quant);
			}
		}
		
	}
		
	void initializeInventory(){
		string name;
		string id;
		int quantity;
		
			string text;
			int number;
			string text_[3];
			
		ifstream ReadFile("DoNotDelete.txt");
		getline(ReadFile,text);
		
			try{
				number = stoi(text);
			}
			catch(invalid_argument&){
				
			}
	count = number;		
			
			for(int i=0;i<count;i++){
				for(int x=0;x<3;x++){
					getline(ReadFile,text);
					text_[x] = text;	
							try{
								number = stoi(text_[2]);
							}
							catch(invalid_argument&){
							}
				name = text_[0];
				id = text_[1];
				quantity = number;
				}
				
			cout<<name<<id<<quantity;
			
	Items* item = new Items(name,id,quantity);
	for(int i=0;i<count;i++){
		items[i] = item;
	}
			
			}
	}
	
	
};

Inventory& inventory = Inventory::getInstance();

string setName(){
	bool valid = false;
	string input;
	cout<<"Item Name: ";
	while(!valid)
	{
	getline(cin, input);
	valid = isString(input);
	if(valid == false)
	cout<<"Input Error. Try Again: ";
	}
	input = capital(input);
	return input;
}

string setID(){
	bool valid = false;
	string input;
	cout<<"Item ID: ";
		while(!valid)
	{
	getline(cin, input);
	valid = isString(input);
	if(valid == false)
	cout<<"Input Error. Try Again: ";
	}
	input = capital(input);
	return input;
}

int setQuantity(){
	string input;
	int quant;
	cout<<"Quantity: ";
	quant = exceptionHandle();
	return quant;
}

void deleteConfirm(){
	string input;
	string input_;
	cout<<"Enter ID of Item to Remove: ";
	getline(cin,input);
	cout<<"Are you Sure you want to Delete This Item?[Y/N]: ";
	getline(cin,input_);
	input_ = capital(input_);
	if(input_ == "Y" || input_ == "N"){
		if(input_ == "Y"){
			inventory.deleteItem(input);
		}
		else{
			cout<<"Deletion Cancelled."<<endl;
			return;
		}
	}
	
}

void readyItem(){
	cout<<"Add Item"<<endl;
	inventory.addItem(setName(),setID(),setQuantity());
	
}