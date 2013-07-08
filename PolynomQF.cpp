#ifndef PolynomQF_
#define PolynomQF_
#include "PolynomQF.h"

bool PolynomQF::isDiagonal(){
	monom mh;
	mh.x=0;
	mh.y=0;
	mh.z=0;
	mh.constant=0;
	list_.toBegin();
	while(!list_.isAfterEnd()&&(mh.x<2)&&(mh.y<2)&&(mh.z<2)){
		if(list_.getCurrent().x!=2){
			if(list_.getCurrent().y!=2){
				if(list_.getCurrent().z!=2){
					return false;
				}
				else{
					mh.z++;
				}
			}
			else{
				mh.y++;
			}
		}
		else{
			mh.x++;
		}
		list_.toNext();
	}
	return mh.x==1&&mh.y==1&&mh.z==1;
}

bool rowOfNulls(long double* R,int n){
	for(int i=0;i<n;i++){
		if(R[i]!=0)
			return false;
	}
	return true;
}

bool PolynomQF::isSingular(){
	long double** matrix;
	monom mh;
	matrix=new long double*[3];
	for(int i=0;i<3;i++){
		matrix[i]=new long double[3];
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			matrix[i][j]=0;
	}
	int a,b;
	list_.toBegin();
	while(!list_.isAfterEnd()){//Заполняем матрицу
		mh=list_.getCurrent();
		if(mh.x){
			a=0;
			mh.x--;
		}
		else
		{
			if(mh.y){
				a=1;
				mh.y--;
			}
			else{
				if(mh.z){
					a=2;
					mh.z--;
				}
			}
		}
		if(mh.x){
			b=0;
			mh.x--;
		}
		else
		{
			if(mh.y){
				b=1;
				mh.y--;
			}
			else{
				if(mh.z){
					b=2;
					mh.z--;
				}
			}
		}
		matrix[a][b]=mh.constant;
		list_.toNext();
	}
	for(int i=1;i<=2;i++){//				***	***
		for(int j=0;j<i;j++)//				i**	j**
			matrix[i][j]=matrix[j][i];//	i**	jj*
	}//Матрица заполнена
	long double c=0;
	for(int k=0;k<2;k++){
		if(matrix[k][k]==0){
				if(rowOfNulls(matrix[k],3))
					return true;
				for(int i=k+1;i<=2;i++){
					if(matrix[i][k]!=0){
						long double* buf;
						buf=matrix[k];
						matrix[k]=matrix[i];
						matrix[i]=buf;
						break;
					}
				}
			}
		if(matrix[k][k]!=0){
			for(int i=k+1;i<=2;i++){
				c=-(matrix[i][k])/(matrix[k][k]);
				if(c){
					for(int j=k;j<=2;j++){
						matrix[i][j]+=c*matrix[k][j];
					}
				}
				if(rowOfNulls(matrix[i],3))
					return true;
			}
		}
	}
	return false;
}
#endif