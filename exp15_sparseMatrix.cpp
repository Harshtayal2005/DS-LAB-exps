#include <iostream>
using namespace std;
// representation
int main(){
	int sparseMatrix[4][5] =
	{
		{0 , 0 , 3 , 0 , 4 },
		{0 , 0 , 5 , 7 , 0 },
		{0 , 0 , 0 , 0 , 0 },
		{0 , 2 , 6 , 0 , 0 }
	};

	int size = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			if (sparseMatrix[i][j] != 0)
				size++;

	int compactMatrix[3][size];

	int k = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			if (sparseMatrix[i][j] != 0)
			{
				compactMatrix[0][k] = i;
				compactMatrix[1][k] = j;
				compactMatrix[2][k] = sparseMatrix[i][j];
				k++;
			} 

	for (int i=0; i<3; i++)
	{
		for (int j=0; j<size; j++)
			cout <<" "<< compactMatrix[i][j];

		cout <<"\n";
	}
	return 0;
}

// operations 

// #include <iostream>
// using namespace std;

// class sparse_matrix
// {

// 	const static int MAX = 100;

// 	int **data;

// 	int row, col;

// 	int len;

// public:
// 	sparse_matrix(int r, int c)
// 	{
// 		row = r;
// 		col = c;
// 		len = 0;
// 		data = new int *[MAX];

// 		for (int i = 0; i < MAX; i++)
// 			data[i] = new int[3];
// 	}
// 	void insert(int r, int c, int val)
// 	{

// 		if (r > row || c > col)
// 		{
// 			cout << "Wrong entry";
// 		}
// 		else
// 		{
// 			data[len][0] = r;

// 			data[len][1] = c;

// 			data[len][2] = val;

// 			len++;
// 		}
// 	}

// 	void add(sparse_matrix b)
// 	{
// 		if (row != b.row || col != b.col)
// 		{
// 			cout << "Matrices can't be added";
// 		}

// 		else
// 		{
// 			int apos = 0, bpos = 0;
// 			sparse_matrix result(row, col);

// 			while (apos < len && bpos < b.len)
// 			{

				
// 				if (data[apos][0] > b.data[bpos][0] ||
// 				(data[apos][0] == b.data[bpos][0] &&
// 					data[apos][1] > b.data[bpos][1]))

// 				{

					
// 					result.insert(b.data[bpos][0],
// 								b.data[bpos][1],
// 								b.data[bpos][2]);

// 					bpos++;
// 				}

			
// 				else if (data[apos][0] < b.data[bpos][0] ||
// 						(data[apos][0] == b.data[bpos][0] &&
// 						data[apos][1] < b.data[bpos][1]))

// 				{

// 					result.insert(data[apos][0],
// 								data[apos][1],
// 								data[apos][2]);

// 					apos++;
// 				}

// 				else
// 				{

					
// 					int addedval = data[apos][2] + 
// 								b.data[bpos][2];

// 					if (addedval != 0)
// 						result.insert(data[apos][0],
// 									data[apos][1],
// 									addedval);
// 					// then insert
// 					apos++;
// 					bpos++;
// 				}
// 			}

// 			// insert remaining elements
// 			while (apos < len)
// 				result.insert(data[apos][0],
// 							data[apos][1],
// 							data[apos++][2]);

// 			while (bpos < b.len)
// 				result.insert(b.data[bpos][0],
// 							b.data[bpos][1],
// 							b.data[bpos++][2]);

			
// 			result.print();
// 		}
// 	}

// 	sparse_matrix transpose()
// 	{

	
// 		sparse_matrix result(col, row);

	
// 		result.len = len;

		
// 		int *count = new int[col + 1];

		
// 		for (int i = 1; i <= col; i++)
// 			count[i] = 0;

// 		for (int i = 0; i < len; i++)
// 			count[data[i][1]]++;

// 		int *index = new int[col + 1];

// 		index[0] = 0;

// 		for (int i = 1; i <= col; i++)

// 			index[i] = index[i - 1] + count[i - 1];

// 		for (int i = 0; i < len; i++)
// 		{

// 			int rpos = index[data[i][1]]++;

		
// 			result.data[rpos][0] = data[i][1];

		
// 			result.data[rpos][1] = data[i][0];

			
// 			result.data[rpos][2] = data[i][2];
// 		}

		
// 		return result;
// 	}

// 	void multiply(sparse_matrix b)
// 	{
// 		if (col != b.row)
// 		{

	
// 			cout << "Can't multiply, Invalid dimensions";
// 			return;
// 		}

		
// 		b = b.transpose();
// 		int apos, bpos;

// 		// result matrix of dimension row X b.col
// 		// however b has been transposed,
// 		// hence row X b.row
// 		sparse_matrix result(row, b.row);

// 		// iterate over all elements of A
// 		for (apos = 0; apos < len;)
// 		{

// 			// current row of result matrix
// 			int r = data[apos][0];

// 			// iterate over all elements of B
// 			for (bpos = 0; bpos < b.len;)
// 			{

// 				// current column of result matrix
// 				// data[,0] used as b is transposed
// 				int c = b.data[bpos][0];

// 				// temporary pointers created to add all
// 				// multiplied values to obtain current
// 				// element of result matrix
// 				int tempa = apos;
// 				int tempb = bpos;

// 				int sum = 0;

// 				// iterate over all elements with
// 				// same row and col value
// 				// to calculate result[r]
// 				while (tempa < len && data[tempa][0] == r &&
// 					tempb < b.len && b.data[tempb][0] == c)
// 				{
// 					if (data[tempa][1] < b.data[tempb][1])

// 						// skip a
// 						tempa++;

// 					else if (data[tempa][1] > b.data[tempb][1])

// 						// skip b
// 						tempb++;
// 					else

// 						// same col, so multiply and increment
// 						sum += data[tempa++][2] * 
// 							b.data[tempb++][2];
// 				}

// 				// insert sum obtained in result[r]
// 				// if its not equal to 0
// 				if (sum != 0)
// 					result.insert(r, c, sum);

// 				while (bpos < b.len && 
// 					b.data[bpos][0] == c)

// 					// jump to next column
// 					bpos++;
// 			}
// 			while (apos < len && data[apos][0] == r)

// 				// jump to next row
// 				apos++;
// 		}
// 		result.print();
// 	}

// 	// printing matrix
// 	void print()
// 	{
// 		cout << "\nDimension: " << row << "x" << col;
// 		cout << "\nSparse Matrix: \nRow\tColumn\tValue\n";

// 		for (int i = 0; i < len; i++)
// 		{
// 			cout << data[i][0] << "\t " << data[i][1] 
// 				<< "\t " << data[i][2] << endl;
// 		}
// 	}
// };

// // Driver Code
// int main()
// {

// 	// create two sparse matrices and insert values
// 	sparse_matrix a(4, 4);
// 	sparse_matrix b(4, 4);

// 	a.insert(1, 2, 10);
// 	a.insert(1, 4, 12);
// 	a.insert(3, 3, 5);
// 	a.insert(4, 1, 15);
// 	a.insert(4, 2, 12);
// 	b.insert(1, 3, 8);
// 	b.insert(2, 4, 23);
// 	b.insert(3, 3, 9);
// 	b.insert(4, 1, 20);
// 	b.insert(4, 2, 25);

// 	// Output result
// 	cout << "Addition: ";
// 	a.add(b);
// 	cout << "\nMultiplication: ";
// 	a.multiply(b);
// 	cout << "\nTranspose: ";
// 	sparse_matrix atranspose = a.transpose();
// 	atranspose.print();
// }