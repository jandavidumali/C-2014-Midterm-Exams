#include <iostream>
using namespace std;
void retry();
class Investor{
	
	private:
		string lastName;
		string firstName;
		string middleInitial;
		float inputAmount;
		float salesAmount;
		float invested;
		int shares;
		string choice;
	
		
	public:
		
		Investor(string apelyido, string pangalan, string gitna, float pera, string pinili,float tinda,float puhunan,int hati){
			
			lastName = apelyido;
			firstName = pangalan;
			middleInitial = gitna;
			inputAmount = pera;
			choice = pinili;
			salesAmount=tinda;
			invested=puhunan;
			shares=hati;
		}
		
		void setFirstName(string pangalan){
			
			firstName = pangalan;
		}
		void setLastName(string apelyido){
			
			lastName = apelyido;
		}
		void setMiddle(string gitna){
			
			middleInitial = gitna;
		}
		void setPera(float pera){
			
			inputAmount = pera;
		}
		void setChoice(string pinili){
			
			choice = pinili;
		}
		string getChoice(){
			if(choice=="SALEF"or choice=="salef"){
				return "Save and Learn Equity Fund";
			}
			else if(choice=="SALFIF" or choice=="salfif"){
				return "Save and Learn Fixed Income Fund";
			}
			else if(choice=="SALBF" or choice=="salbf"){
				return "Save and Learn Balance Fund";
			}
		}
		void compute(){
			
			if(choice=="SALEF"or choice=="salef"){
				if(inputAmount <= 99999.99 && inputAmount >= 1000){
					salesAmount = 0.02*inputAmount;
					invested = inputAmount - salesAmount;
					shares = invested / 5.8624;
				} else if (inputAmount <= 499999.99 && inputAmount >= 100000){
					salesAmount = 0.015*inputAmount;
					invested = inputAmount - salesAmount;
					shares = invested / 5.8624;
				} else if (inputAmount <= 1999999.99 && inputAmount >= 500000){
					salesAmount = 0.01*inputAmount;
					invested = inputAmount - salesAmount;
					shares = invested / 5.8624;
				} else if (inputAmount >= 2000000){
					salesAmount = 0.005*inputAmount;
					invested = inputAmount - salesAmount;
					shares = invested / 5.8624;
				}
			}
			else if(choice=="SALFIF" or choice=="salfif"){
				if(inputAmount <= 99999.99 && inputAmount >= 1000){
					salesAmount = 0.02*inputAmount;
					invested = inputAmount - salesAmount;
					shares = invested / 2.2071;
				} else if (inputAmount <= 499999.99 && inputAmount >= 100000){
					salesAmount = 0.015*inputAmount;
					invested = inputAmount - salesAmount;
					shares = invested / 2.2071;
				} else if (inputAmount <= 1999999.99 && inputAmount >= 500000){
					salesAmount = 0.01*inputAmount;
					invested = inputAmount - salesAmount;
					shares = invested / 2.2071;
				} else if (inputAmount >= 2000000){
					salesAmount = 0.005*inputAmount;
					invested = inputAmount - salesAmount;
					shares = invested / 2.2071;
				}
			}
			else if(choice=="SALBF" or choice=="salbf"){
				if(inputAmount <= 99999.99 && inputAmount >= 1000){
					salesAmount = 0.02*inputAmount;
					invested = inputAmount - salesAmount;
					shares = invested / 2.9335;
				} else if (inputAmount <= 499999.99 && inputAmount >= 100000){
					salesAmount = 0.015*inputAmount;
					invested = inputAmount - salesAmount;
					shares = invested / 2.9335;
				} else if (inputAmount <= 1999999.99 && inputAmount >= 500000){
					salesAmount = 0.01*inputAmount;
					invested = inputAmount - salesAmount;
					shares = invested / 2.9335;
				} else if (inputAmount >= 2000000){
					salesAmount = 0.005*inputAmount;
					invested = inputAmount - salesAmount;
					shares = invested / 2.9335;
				}
			}
			
			
		}
		void showDetails(){
			float nSALEF = 5.8624;
			float nSALFIF = 2.2071;
			float nSALBF = 2.9335;
			cout << "\n\nInvestment Fund Type is: " << getChoice() << endl;
			cout << "Amount Invested: PHP " << inputAmount << endl;
			if(choice=="SALEF"or choice=="salef"){
				cout << "NAVPS: PHP " << nSALEF << endl;
			}
			else if(choice=="SALFIF" or choice=="salfif"){
				cout << "NAVPS: PHP " << nSALFIF << endl;
			}
			else if(choice=="SALBF" or choice=="salbf"){
				cout << "NAVPS: PHP " << nSALBF << endl;
			}
			cout << "Sales Load Amount: PHP " << salesAmount << endl;
			cout << "Net Amount Invested: PHP " << invested << endl;
			cout << "Total Shares Bought: " << shares << endl;
		}
};


main(){
	string apelyido;
	string mystream;
	string pangalan;
	string gitna;
	float pera;
	string pinili;
	
	Investor inv1(" "," "," ",0," ",0,0,0);
	cout<<"Enter Last Name: "<<endl;
	cin>>apelyido;
	inv1.setLastName(apelyido);
	cout<<"Enter First Name: "<<endl;
	cin>>pangalan;
	inv1.setFirstName(pangalan);
	cout<<"Enter Middle Initial: "<<endl;
	cin>>gitna;
	inv1.setMiddle(gitna);
	cout<<"Enter Mutual Fund Type: "<<endl;
	cin>>pinili;
	if(pinili!="SALEF"&& pinili!="salef"&& pinili!="SALFIF" && pinili!="salfif" && pinili!="SALBF" && pinili!="salbf"){
		cout<<"Invalid Mutual Fund Type";
		retry();	
			
	}
	else{
	inv1.setChoice(pinili);
		
	}
	cout<<"Enter Investment Amount: "<<endl;
	cin>>pera;
	if(pera<=0 or pera<1000){
		cout<<"Invalid Amount";
		retry();
	}
	else{
	inv1.setPera(pera);
		
	}
	inv1.compute();
	inv1.showDetails();
	retry();
}
void retry(){
	char choice;
	cout<<"\n\t\t\tDo you want to continue[Y/N]: ";
	cin>>choice;
	 if(choice=='Y' or choice=='y'){
	 	system("cls");
		 main();
	 }
	 else if(choice=='N' or choice=='n'){
		cout<<"\n\t\t\tThank you for using this application";
		 exit(0);
	 }
	 else{
	 	cout<<"\n\t\t\tInvalid choice.";
	 	retry();
	 }
	
}
