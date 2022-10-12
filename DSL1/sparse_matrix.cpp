#include<iostream>
using namespace std;


int fast_transpose(int mat[10][3]){
	int transpose[10][3];
	int index_arr[mat[0][1]];
	int total_arr[mat[0][1]+1];
	
	for(int i = 0;i<mat[0][1];i++){
		index_arr[i] = 0;
	}
	
}


int main(){
	int sparse_mat[10][3];
	fast_transpose(sparse_mat);
}
