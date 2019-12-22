#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void increscent(int *ar, int p, int k){
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
	
	cout<<"increscent done\n";
}

void decrescent(int *ar, int p, int k){
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
}

void wypisz(int *ar, int inputs){
	for(int i=0;i<inputs-1;i++){
		cout<<ar[i]<<" ";
	}
	cout<<'\n';
}


int main(){
	string command;
	long long value=0;
	
	int inputs=1;
	int *ar=new int[inputs];
	
	//-------------menu--------------
	cout<<"Dostepne polecenia:\n";
	cout<<"-uporzadkuj:\n";
	cout<<"	-rosnaco\n";
	cout<<"	-malejaco\n";
	cout<<"-wypisz\n";
	cout<<"-wyczysc\n";
	cout<<"-wyjdz\n";
	cout<<'\n';
	
	while(cin>>command){

		
		if(command=="uporzadkuj"){
			cout<<"rosnaco/malejaco\n";
			
			string direction="";
			
			do{
			cin>>direction;
			
			if(direction=="rosnaco"){
				increscent(ar, 0, inputs-2);//
			}
			
			else if(direction=="malejaco"){
				decrescent(ar, 0, inputs-2);//
			}
			
			else cout<<"blad w poleceniu\n";
			}while(direction!="rosnaco" && direction!="malejaco");
			
			cout<<"poza petla\n";
		}
		
		else if(command=="wypisz"){
			wypisz(ar, inputs);
		}
		
		else if(command=="wyczysc"){
			inputs=1;
		}
		
		else if(command=="wyjdz" || command=="exit"){
			break;
			_Exit(0);
		}
			
		else{
			int multiplier=1;
			for(int i=command.length()-1;i>=0;i--){
			value+=((int)command[i]-48)*multiplier;
			multiplier*=10;
			}
			ar[inputs-1]=value;
			cout<<"v: "<<value<<" ar[inputs-1]:"<<ar[inputs-1]<<'\n';
			inputs++;
			cout<<"inputs: "<<inputs<<'\n';
			cout<<"sizeof(ar): "<<sizeof(ar)<<'\n';
			value=0;
		}
		
	}
	
	delete[] ar;
	
	return 0;
}
