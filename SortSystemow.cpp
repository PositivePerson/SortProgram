#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

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
			cout<<iValue<<" "<<sValue<<"   ";
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

void wrongInput(){
	cout<<"blad w poleceniu\n";
}

//------------debug----------
void loopOut(){
	cout<<"poza petla\n";
}

	//-------------10system---------
	int inputs=1;
	int *ar=new int[inputs];
	
	
	//-------------choosedsystem----
	//int index=1;
	int *choosedAr=new int[inputs];


int main(){
	string command;
	string direction="";
	string whichAr="orginalna";
	int system=0;
	long long value=0;
	
	
	
	
	//-------------menu--------------
	cout<<"Dostepne polecenia:\n";
	cout<<"-uporzadkuj:\n";
	cout<<" -rosnaco\n";
	cout<<" -malejaco\n";
	cout<<"-wypisz\n";
	cout<<" -orginalna\n";
	cout<<" -zmieniona\n";
	cout<<"-system\n";
	cout<<"-wyczysc\n";
	cout<<"-wyjdz\n";
	cout<<'\n';
	
	while(cin>>command){

		
		if(command=="uporzadkuj" || command=="sortuj"){
			cout<<"rosnaco/malejaco\n";
			
			
			do{
			cin>>direction;
			
			if(direction=="rosnaco"){
				increscent(ar, 0, inputs-1);//
			}
			
			else if(direction=="malejaco"){
				decrescent(ar, 0, inputs-1);//
			}
			
			else {
				wrongInput();
			}
			}while(direction!="rosnaco" && direction!="malejaco");
			
			loopOut();
		}
		
		else if(command=="system"){
			
			cout<<"na jaki system liczbowy chcesz zamienic podane wartosci:\n";
			
			do{
			cin>>system;
			
			if((system>1 && system<10)){
				changeSystem(ar,choosedAr,inputs,system);
			}
			
			else {
				wrongInput();
			}
			
			}while(system<2 || system>9);
			
			loopOut();
		}
		
		else if(command=="wypisz"){
			
			cout<<"tablica ktora ma zostac wypisana\n";
			cout<<"orginalna/zmieniona\n";
			
			do{
			cin>>whichAr;
			
			if(whichAr=="orginalna"){
				wypisz(ar, inputs);
			}
			
			else if(whichAr=="zmieniona"){
				wypisz(choosedAr, inputs);
			}
			
			else{
				wrongInput();
			}
			}while(whichAr!="orginalna" && whichAr!="zmieniona");
			
		}
		
		else if(command=="wyczysc"){
			inputs=1;
		}
		
		else if(command=="wyjdz" || command=="exit"){
			_Exit(0);
		}
			
		else{
			int multiplier=1;
			for(int i=command.length()-1;i>=0;i--){
			value+=((int)command[i]-48)*multiplier;
			multiplier*=10;
			}
			ar[inputs-1]=value;
			choosedAr[inputs-1]=value;
			cout<<"v: "<<value<<" ar[inputs-1]:"<<ar[inputs-1]<<'\n';
			inputs++;
			cout<<"inputs: "<<inputs<<'\n';
			//cout<<"sizeof(ar): "<<sizeof(ar)<<'\n';
			value=0;
		}
		
	}
	
	delete[] ar;
	
	return 0;
}
