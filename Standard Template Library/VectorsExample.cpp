

#include<iostream>
#include<vector>

using namespace std;

class Hassala{

	
public:

	vector<int> mySavings;

	void addSaving(int amount){

		mySavings.push_back(amount);

	}

	int getAmount(){

		int amount  = mySavings.back();
		mySavings.pop_back();
		return amount;
	}

	void printSavings(){
		if(mySavings.empty()){
			cout<<"You dont have savings yet";
		}
		for(int i=0; i<mySavings.size(); ++i){
			cout<<mySavings[i]<<", ";
		}
		cout<<"\n";
	}

};


int main(){

/*
	int i = 5; //work for 10 iterations
	int saveAmount = 0;


	Hassala hassaletMenna;
	char answer;
	while(i-- >0){
		cout<<"Your savings:\n";
		hassaletMenna.printSavings();

		cout<<"How much money would you like to save?";
		cin>>saveAmount;

		hassaletMenna.addSaving(saveAmount);


		cout<<"Would you like to take out some money? [y/n]";
		cin>>answer;
		if(answer == 'y'){
			hassaletMenna.getAmount();
		}
	}

	cout<<"Element at index 3 is "<<hassaletMenna.mySavings.at(3)<<endl;
	*/

	vector<int> v(5);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	cout<<"Vector in ascending order:\n";
	for(vector<int>::iterator itr =  v.begin(); itr != v.end(); itr ++){

		cout<<(*itr)<<", ";
	}

	

#include<iostream>
#include<vector>

using namespace std;

class Hassala{

	
public:

	vector<int> mySavings;

	void addSaving(int amount){

		mySavings.push_back(amount);

	}

	int getAmount(){

		int amount  = mySavings.back();
		mySavings.pop_back();
		return amount;
	}

	void printSavings(){
		if(mySavings.empty()){
			cout<<"You dont have savings yet";
		}
		for(int i=0; i<mySavings.size(); ++i){
			cout<<mySavings[i]<<", ";
		}
		cout<<"\n";
	}

};


int main(){

/*
	int i = 5; //work for 10 iterations
	int saveAmount = 0;


	Hassala hassaletMenna;
	char answer;
	while(i-- >0){
		cout<<"Your savings:\n";
		hassaletMenna.printSavings();

		cout<<"How much money would you like to save?";
		cin>>saveAmount;

		hassaletMenna.addSaving(saveAmount);


		cout<<"Would you like to take out some money? [y/n]";
		cin>>answer;
		if(answer == 'y'){
			hassaletMenna.getAmount();
		}
	}

	cout<<"Element at index 3 is "<<hassaletMenna.mySavings.at(3)<<endl;
	*/

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	cout<<"Vector in ascending order:\n";
	for(vector<int>::iterator itr =  v.begin(); itr != v.end(); itr ++){

		cout<<(*itr)<<", ";
	}

	cout<<"\nVector in desscending order:\n";
	for(vector<int>::reverse_iterator itr =  v.rbegin(); itr != v.rend(); itr ++){

		cout<<(*itr)<<", ";
	}


	return 0;
}






	return 0;
}
