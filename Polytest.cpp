#include <iostream>
#include "PolynomQF.h"
#include "PolynomX.h"
#include "PolynomQ.h"

using namespace std;
	void main(){
		Polynom P,S;
		cin>>P;
		cin>>S;
		try{
		cout<<P<<'\n'<<S<<'\n';
		}
		catch(isEmpty){
			cerr<<"Polynom is Empty.";
		}
		P=S;
		if(P==S){
			try{
			cout<<P<<'\n'<<S<<'\n';
			}
			catch(isEmpty){
				cerr<<"Polynom is Empty.\n";
			}
		}
		cout<<P.getValueOn(5.4,7.898,7)<<'\n';
		PolynomX p;
		cin>>p;
		cout<<p.getDerivative()<<'\n';
		PolynomQ PQ;
		cin>>PQ;
		pairOfRoots pairR;
		pairR.first=0;
		pairR.second=0;
		try{
		pairR=PQ.computeRoots();
		cout<<pairR.first<<' '<<pairR.second<<' ';
		}
		catch(badcoeffitients){
			cerr<<"Bad Coeffitients.\n";
		}
		pairOfPolynoms pairP;
		try{
		pairP=PQ.factorization();
		cout<<'\n'<<pairP.first<<' '<<pairP.second<<' ';
		}
		catch(irreducible){
			cerr<<"It's irreducible.\n";
		}
		PolynomQF PQF;
		cin>>PQF;
		if(PQF.isDiagonal()){
			cout<<"It is.\n";
		}
		else{
			cout<<"Is not.\n";
		}
		if(PQF.isSingular()){
			cout<<"It is.\n";
		}
		else{
			cout<<"Is not.\n";
		}
		system("pause");
}