/**
 * LA.cpp
 * Purpose: Linear Algebra library for multiplying and transposing matricies.
 * A matrix is respresented as a vector of vectors<double>.
 *
 * @author David Wang
 */
#include "LA.h"


/* Takes the product of two matricies and returns the new matrix */
std::vector<std::vector<double>> LA::multiply(const std::vector<std::vector<double>> &m1, const std::vector<std::vector<double>> &m2) {

    // Makes sure the two matricies have rows and columns greater than 0.
    // Allows makes sure that the number of columns of m1 matches the number
    // of rows of m2.
    if (!checkValidMatricies(m1, m2)) {
        throw "Error with input matricies, "
            "can't perform multiplication operation";
    }

    int M = m1.size();
    int N = m2[0].size();

    std::vector<std::vector<double>> result(M, std::vector<double>(N));

    // The outer loop will iterate over the columns of the first matrix so that
    // we can get more cache hits.
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            int value = 0;
            for (int k = 0; k < m2.size(); k++) {
                value += m1[i][k] * m2[k][j];
            }
            result[i][j] = value; 
        }
    }
    return result;
}


/* Takes the transpose of a matrix */
std::vector<std::vector<double>> LA::transpose(const std::vector<std::vector<double>> &m) {

    int M = m.size();
    int N = m[0].size();

    // check if rows and columns are greater than 0.
    if (!checkValidMatrix(m)) {
        throw "Error with input matrix, "
            "can't perform transpose operation";
    }

    std::vector<std::vector<double>> result(N, std::vector<double>(M));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result[j][i] = m[i][j];
        }
    }

    return result;
}


/** 
 * Prints out each value of the matrix seperating columns with a space and
 * seperating rows with a newline.
 */
 void LA::print(const std::vector<std::vector<double>> m) {
    for (auto it1 = m.begin(); it1 != m.end(); it1++) {
        for (auto it2 = it1->begin(); it2 != it1->end(); it2++) {
            std::cout << *it2 << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}


/* Check if the demenions and values of the matricix are valid. */
 bool LA::checkValidMatrix(const std::vector<std::vector<double>> &m) {
     if (m.size() == 0) {
        std::cerr << "ValueError: Matrix must have at least one row.";
        return false; 

     } else if (m[0].size() == 0) {
        std::cerr << "ValueError Matrix must have at least one column.";
        return false; 

    }
    return true;
}


/* Check if the demenions and values of the matricies are valid. */
 bool LA::checkValidMatricies(const std::vector<std::vector<double>> &m1,
         const std::vector<std::vector<double>> &m2) {
     if (m1.size() == 0 || m2.size() == 0) {
        std::cerr << "ValueError: Matricies must have at least one row." 
            << std::endl;
        return false; 

     } else if (m1[0].size() == 0|| m2[0].size() == 0) {
        std::cerr << "ValueError Matricies must have at least one column." 
            << std::endl;
        return false; 

    } else {
        if (m1[0].size() != m2.size()) {
            std::cerr << "MatrixDimensionError: Number of rows of first matrix must match number of columns of second matrix." << std::endl;
            return false;
        }

    }
    return true;
}
