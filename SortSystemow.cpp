#include <iostream>
#include <fstream>
#include <algorithm>
#include <windows.h>
#include <conio.h>

using namespace std;

void colour(int k)
{
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

void increscent(int *ar, int p, int k){
	sort(ar, ar+k);
	/*
	cout<<"increscent done\n";
	int i=p;
	int j=k;
	long int s=ar[(p+k)/2];
	long int backp;
	
	while(i<=j){
		while(ar[i]<s) i++;
		while(ar[j]>s) j--;
	if(i<=j){
	backp=ar[i];
	ar[i]=ar[j];
	ar[j]=backp;
	
	i++;j++;
		}
	}
	
	if(j>p) increscent(ar, p, j);
	if(i<k) increscent(ar, i, k);
	
	cout<<"increscent_end\n";
	*/
}

void decrescent(int *ar, int p, int k){
	sort(ar, ar+k, greater<int>());
/*
	cout<<"decrescent done\n";
	int i=p;
	int j=k;
	long int s=ar[(p+k)/2];
	long int backp;
	
	while(i<=j){
		while(ar[i]>s) i++;
		while(ar[j]<s) j--;
	if(i<=j){
	backp=ar[i];
	ar[i]=ar[j];
	ar[j]=backp;
	
	i++;j++;
		}
	}
	
	if(j>p) decrescent(ar, p, j);
	if(i<k) decrescent(ar, i, k);
	cout<<"decrescent_end\n";
	*/
}

void wypisz(int *ar, int inputs){
	for(int i=0;i<inputs-1;i++){
		cout<<ar[i]<<" ";
	}
	cout<<'\n';
}

void changeSystem(int *ar,int *choosedAr,int inputs,int system){
	string sValue="";
	int iValue=0;
	int rest=0;
	int multiplier=1;
	
	for(int i=0;i<inputs-1;i++){
		sValue="";
		iValue=0;
		multiplier=1;
		
		iValue=ar[i];
		while(iValue>0){
			sValue=(char)(iValue%system+48)+sValue;
			iValue/=system;
			//cout<<iValue<<" "<<sValue<<"   ";
		}
		//cout<<sValue<<'\n';
		
		for(int j=sValue.length()-1;j>=0;j--){
			iValue+=((int)sValue[j]-48)*multiplier;
			//cout<<(int)sValue[j]-48<<" ";
			multiplier*=10;
		}
		
		choosedAr[i]=iValue;
	}
	//cout<<'\n';
}

void checkIfDivisible(int inputs, int *base, int *arTaken, string divisor){
	int intDivisor=0;
	int multiplier=1;
	
	for(int i=divisor.length()-1;i>=0;i--){
		intDivisor+=((int)divisor[i]-48)*multiplier;
		multiplier*=10;
	}
	
	for(int i=0;i<inputs-1;i++){
		if(base[i]%intDivisor==0){
			cout<<arTaken[i]<<" ";
		}
	}
	//cout<<"i koniec checkIfDivisible\n";
}



void wrongInput(){
	cout<<"blad w poleceniu\n";
}

//------------debug----------
void loopOut(){
	cout<<"poza petla\n";
}

int to10(int value, int system){
	int result=0;
	int multiplier=1;
	
	while(value!=0){
		result+=(value%10)*multiplier;
		value/=10;
		multiplier*=system;
		
		//cout<<result<<" ";
	}
	//cout<<'\n';
	
	return result;
}

bool isInputNumber(string input){
	for(int i=0;i<input.length();i++){
		if((int)input[i]<48 || (int)input[i]>57) return false;
	}
	return true;
}

	//-------------10system---------
	int inputs=1;
	int *ar=new int[inputs];
	
	//-------------originalAr---------
	int *choosedAr=new int[inputs];
	
	//-------------changedSystem----
	//int index=1;
	int *changedAr=new int[inputs];


int main(){
	
	string command;
	string direction="";
	string whichAr="orginalna";
	int system=0;
	string divisor="";
	int color=0;
	long long value=0;
	int multiplier=1;
	bool isClear=true;
	bool isChanged=false;
	int changes=0;
	int commandsAmount=0;
	
	{
  SetConsoleTitle("NightIdea");
	}
	
	
	//-------------menu--------------
	cout<<"Dostepne polecenia:\n";
	cout<<"-uporzadkuj:\n";
	cout<<" -rosnaco\n";
	cout<<" -malejaco\n";
	cout<<"-wypisz\n";
	cout<<" -orginalna\n";
	cout<<" -zmieniona\n";
	cout<<"-system\n";
	cout<<"-podzielne\n";
	cout<<"-wyczysc\n";
	cout<<"-wyjdz\n";
	cout<<"-info\n";
	cout<<"-baza\n";
	cout<<"-kolor\n";
	cout<<'\n';
	
	cout<<"w jakim systemie liczbowym beda wprowadzane wartosci?";
	cout<<"\n-2\n-3\n-4\n-5\n-6\n-7\n-8\n-9\n-10\n";
	
	while(cin>>command){
		
		if(command=="wyjdz" || command=="exit"){
			_Exit(0);
		}
		
		else if(isClear==true){
			
			multiplier=1;
			
			for(int i=command.length()-1;i>=0;i--){
				
				//--------------Is-Input-A-Number-------------
				if(((int)command[i])<48 || ((int)command[i])>57){
					wrongInput();
					system=-1;
					break;
				}
				
				else {
				system+=((int)command[i]-48)*multiplier;
			multiplier*=10;
				}
			}
			if(system>=2 && system<=10)	isClear=0;
		}
		
		else{
		
		if(command=="uporzadkuj" || command=="sortuj"){
			cout<<"rosnaco/malejaco\n";
			
			
			do{
			cin>>direction;
			
			if(direction=="rosnaco"){
				increscent(ar, 0, inputs-1);
				changes++;
			}
			
			else if(direction=="malejaco"){
				decrescent(ar, 0, inputs-1);
				changes++;
			}
			
			else {
				cout<<"powtorz polecenie\n";
			}
			}while(direction!="rosnaco" && direction!="malejaco");
			
			commandsAmount++;
			loopOut();
		}
		
		else if(command=="podzielne"){
			cout<<"sprawdz ktore liczby sa podzielne przez\n";
			
			do{
			cin>>divisor;
			
			if(isInputNumber(divisor)){
				if(!isChanged){
					checkIfDivisible(inputs, ar, choosedAr, divisor);
				}
				else if(isChanged){
					checkIfDivisible(inputs, ar, changedAr, divisor);
				}
				commandsAmount++;
			}
			
			else {
				wrongInput();
			}
			
			}while(!isInputNumber(divisor));
		}
		
		else if(command=="system"){
			
			cout<<"na jaki system liczbowy chcesz zamienic podane wartosci:\n";
			
			do{
			cin>>system;
			
			if((system>1 && system<10)){
				changeSystem(ar,changedAr,inputs,system);
				changes++;
				commandsAmount++;
			}
			
			else {
				wrongInput();
			}
			
			}while(system<2 || system>9);
			
			isChanged=true;
			loopOut();
		}
		
		else if(command=="wypisz"){
			
			
			
			if(inputs<2){
				cout<<"Tablice sa puste\n";
			}
			
			else if(isChanged==false){
				if(system==10) wypisz(ar, inputs);
				else wypisz(choosedAr, inputs);
			}
			
			else{
				cout<<"tablica ktora ma zostac wypisana\n";
				cout<<"baza/orginalna/zmieniona\n";
				
				do{
				cin>>whichAr;
				
				if(whichAr=="baza" || whichAr=="baze"){
					wypisz(ar, inputs);
				}
				
				else if(whichAr=="orginalna"){
					wypisz(choosedAr, inputs);
				}
				
				else if(whichAr=="zmieniona"){
					wypisz(changedAr, inputs);
				}
				
				else{
					wrongInput();
				}
				}while(whichAr!="orginalna" && whichAr!="zmieniona" && whichAr!="baza" && whichAr!="zmieniona");
			}
			commandsAmount++;
		}
		
		else if(command=="baza"){
			wypisz(ar, inputs);
			commandsAmount++;
		}
		
		else if(command=="wyczysc"){
			inputs=1;
			cout<<"w jakim systemie liczbowym beda wprowadzane wartosci?\n";
			isClear=true;
			isChanged=false;
			changes=0;
			commandsAmount++;
		}
		
		else if(command=="info"){
			cout<<"Ilosc wprowadzonych wartosci: "<<inputs-1<<'\n';
			cout<<"Ilosc dokonanych zmian: "<<changes<<'\n';
			cout<<"Ilosc wprowadzonych polecen: "<<commandsAmount<<'\n';
		}
		
		else if(command=="colour" || command=="color" || command=="kolor"){
			
			cout<<"Zmien kolor na:\n";
			cout<<"1-Blue \n2-Green \n3-Agua \n4-Red \n5-Purple \n6-Yellow \n";
			cout<<"7-White \n8-Gray \n9-Light Blue \n0-Black\n";
			cout<<"Wpisz numer:\n";
		
				do{
			//cin>>color;
			color=_getche()-48;
			if(color==1 || color==2 || color==3
				|| color==4 || color==5 || color==6
				|| color==7 || color==8 || color==9
				|| color==0){
					cout<<'\n';
					colour(color);
				}
				
			
			else {
				cout<<'\n';
				wrongInput();
			}
			
			}while(!(color==1 || color==2 || color==3
				|| color==4 || color==5 || color==6
				|| color==7 || color==8 || color==9
				|| color==0));
		}
			
		else{
			
			multiplier=1;
			for(int i=command.length()-1;i>=0;i--){
				
				//--------------Is-Input-A-Number-------------
				if(((int)command[i])<48 || ((int)command[i])>57){
					wrongInput();
					value=-1;
					break;
				}
				
				else {
				value+=((int)command[i]-48)*multiplier;
			multiplier*=10;
				}
			}
			
			if(value!=-1){
				if(system==10){
					ar[inputs-1]=value;
					choosedAr[inputs-1]=value;
					//cout<<"v: "<<value<<" ar[inputs-1]:"<<ar[inputs-1]<<'\n';
					inputs++;
					//cout<<"inputs: "<<inputs<<'\n';
					//cout<<"dodano\n";
				}
				else {
					choosedAr[inputs-1]=value;
					ar[inputs-1]=to10(value, system);
					//cout<<"v: "<<value<<" ar[inputs-1]:"<<ar[inputs-1]<<'\n';
					inputs++;
					//cout<<"inputs: "<<inputs<<'\n';
					//cout<<"dodano"<<to10(value, system)<<"\n";
				}
				
			}
			value=0;
		}
	}
	}
	
	
	delete[] choosedAr;
	delete[] changedAr;
	delete[] ar;
	
	return 0;
}
