//
// Created by Tanmai Niranjan on 21/04/23.
//

#include "/Users/metanmai/Code/C++/stdc++.h"

using namespace std;

#ifndef GRAPH_FUNCTIONALITIES_KATZ_H
#define GRAPH_FUNCTIONALITIES_KATZ_H

double findDeterminant(vector<vector<double>> &mat)
{
	int n = mat.size();

	if(n == 1)
		return mat[0][0];

	double det = 0, sign = 1.0;
	vector<vector<double>> subMatrix(n - 1, vector<double>(n - 1));

	for (int i = 0; i < n; i++)
	{
		int subMatrixRow = 0;
		for (int j = 1; j < n; j++)
		{
			int subMatrixCol = 0;
			for (int k = 0; k < n; k++)
				if (k != i)
					subMatrix[subMatrixRow][subMatrixCol++] = mat[j][k];

			subMatrixRow++;
		}
		det += sign * mat[0][i] * findDeterminant(subMatrix);
		sign = -sign;
	}
	return det;
}

vector<vector<double>> findInverse(vector<vector<double>> &mat)
{
	int n = mat.size();
	vector<vector<double>> inverseMatrix(n, vector<double>(n));
	double det = findDeterminant(mat);

	// If the determinant is 0, it is not possible to find the inverse of matrix.
	assert(det != 0);

	int sign = 1;
	vector<vector<double>> subMatrix(n - 1, vector<double>(n - 1));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int subMatrixRow = 0;
			for (int k = 0; k < n; k++)
			{
				if (k != i)
				{
					int subMatrixCol = 0;
					for (int l = 0; l < n; l++) {

						if (l != j)
							subMatrix[subMatrixRow][subMatrixCol++] = mat[k][l];
					}
					subMatrixRow++;
				}
			}
			inverseMatrix[j][i] = sign * findDeterminant(subMatrix); // Adjoint of the Matrix.
			sign = -sign;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			inverseMatrix[i][j] /= det;

	return inverseMatrix;
}

template <typename T, typename W>
[[maybe_unused]] vector<double> findKatzCentrality(map<T, map<T, W>> &adjList, double alpha, double beta, int n)
{
	vector<double> answer(n);
	vector<vector<double>> adjMat(n, vector<double>(n)), identity(n, vector<double>(n)), inverse(n, vector<double>(n)), temp(n, vector<double>(n));

	for(auto [curr, neighbours] : adjList)
		for(auto [next, weight] : neighbours)
			adjMat[next][curr] = alpha * weight; // Transposed Adjacency matrix.

	for(int i = 0; i < n; i++)
		identity[i][i] = 1;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			temp[i][j] = beta * (identity[i][j] - adjMat[i][j]);

	inverse = findInverse(temp);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			inverse[i][j] *= beta * beta;

	for(int i = 0; i < n; i++)
		answer[i] = accumulate(inverse[i].begin(), inverse[i].end(), 0.0);

	return answer;
}

#endif //GRAPH_FUNCTIONALITIES_KATZ_H
