#include <iostream>
using namespace std;
#define max 17

void dispaly(int mat[max][3], int r, int c)
{
	cout << "Row Col Elmt" << endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void fast_transpose(int mat[max][3], int transpose[max][3])
{
	int index_arr[mat[0][1]];
	int total_arr[mat[0][1] + 1];

	total_arr[0] = 1;
	for (int i = 0; i < mat[0][1]; i++)
	{
		index_arr[i] = 0;
		total_arr[i + 1] = 0;
	}

	for (int i = 1; i < mat[0][2]; i++)
	{
		index_arr[mat[i][1]] += 1;
	}
	for (int i = 0; i < mat[0][2]; i++)
	{
		total_arr[i + 1] = total_arr[i] + index_arr[i];
	}

	int col_no, loc;
	transpose[0][0] = mat[0][1];
	transpose[0][1] = mat[0][0];
	transpose[0][2] = mat[0][2];

	for (int k = 1; k < mat[0][2]; k++)
	{
		col_no = mat[k][1];
		loc = total_arr[col_no];
		transpose[loc][0] = mat[k][1];
		transpose[loc][1] = mat[k][0];
		transpose[loc][2] = mat[k][2];
		total_arr[col_no]++;
	}
}

int main()
{
	int transpose[max][3], sparse_mat[max][3], num;
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sparse_mat[i][j] = 0;
			transpose[i][j] = 0;
		}
	}
	cout << "Enter number of elements";
	cin >> num;
	cout << "Enter sparse matrix" << endl;
	for (int i = 0; i < num + 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> sparse_mat[i][j];
		}
	}

	// cout << sparse_mat;
	// dispaly(sparse_mat, num + 1, 3);
	fast_transpose(sparse_mat,transpose);
	dispaly(sparse_mat,num+1,3);
	dispaly(transpose,num+1,3);
}
/*
8
4 4 8
0 0 7
0 3 1
1 1 2
1 2 1
2 1 1
2 3 4
3 0 9
3 2 6

*/
