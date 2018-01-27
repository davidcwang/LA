/**
 * LA.h
 * Purpose: Linear Algebra library for multiplying and transposing matricies.
 * A matrix is respresented as a vector of vectors<double>.
 *
 * @author David Wang
 */

#ifndef LA_H
#define LA_H

#include <iostream>
#include <vector>

class LA {
  public:
    LA() {};
    ~LA() {};


    /**
     * Takes in two matricies and returns a new matrix 
     * which is the product of the two.
     *
     * @param m1 the first matrix.
     * @param m2 the second matrix.
     * @return result the product of m1 * m2.
     */
    static std::vector<std::vector<double>> multiply(const std::vector<std::vector<double>> &m1, const std::vector<std::vector<double>> &m2);


    /**
     * Takes in a matrix and returns a new matrix that is 
     * the the transpose of the original matrix.
     *
     * @param m an MxN matrix.
     * @return result the transposed of the passed in matrix.
     */
    static std::vector<std::vector<double>> transpose(const std::vector<std::vector<double>> &m);


    /**
     * Takes in a matrix that will then be printed out.
     *
     * @param m an MxN matrix.
     * @return None.
     */
    static void print(std::vector<std::vector<double>> m);


  private:
    /**
     * Takes in an MxN matrix and returns true if the matrix has at least
     * one row and one column.
     *
     * @param m an MxN matrix.
     * @return bool
     */
    static bool checkValidMatrix(const std::vector<std::vector<double>> &m);


    /**
     * Checks if the two matricies each have at least one row and one 
     * column. Also checks if the column length of the first matrix matches
     * the row length of the second matrix.
     *
     * @param m1 an MxN matrix.
     * @param m2 an MxN matrix.
     * @return bool
     */
    static bool checkValidMatricies(const std::vector<std::vector<double>> &m1, const std::vector<std::vector<double>> &m2);
};

#endif /* LA_H */
