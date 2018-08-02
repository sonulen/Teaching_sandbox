#ifndef MATRIX_H_
#define MATRIX_H_

#include <stddef.h>
#include "stdint.h"

//
#include <iostream>

template<size_t rows, size_t columns>
class Matrix {
public:
	// Итератор для реализации Matrix[][]
	class Iterator{
	public:
		float* pRow;
		float& operator[]( size_t j ){
			if (j >= columns)
			std::cout << "iterator[]" << std::endl;
			return pRow[j];
		};
		Iterator( float* pRow ) : pRow(pRow) { };
	};

	friend Iterator;

	Matrix() {
		for (uint32_t i = 0; i < rows; i++) {
			for (uint32_t j = 0; j < columns; j++) {
				this->data[i][j] = 1;
			}
		}
	}

	/**
	 * Конструктор через "объект" двумерного массива
	 */
	Matrix(float _d[rows][columns]) {
		for (uint32_t i = 0; i < rows; i++) {
			for (uint32_t j = 0; j < columns; j++) {
				this->data[i][j] = _d[i][j];
			}
		}
	}



	/**
	 *	Конструктор через одномерный массив
	 *	Пример использования:
	 *		Matrix<2,2> B ( {
	 *		1,2,
	 *		3,4
	 *		} );
	 */
	Matrix(const float (&arr)[rows * columns]) {
		for (uint32_t i = 0; i < rows; i++) {
			for (uint32_t j = 0; j < columns; j++) {
				this->data[i][j] = arr[i * columns + j];
			}
		}
	}

	/** Конструктор перемещения с временного объекта 2-мерного массива
	 * 	Matrix<2,2> B({
	 *		{1,2},
	 *		{3,4}
	 *	});
	 */
	Matrix(float (&&arr)[rows][columns]) {
		(void) arr;
		for (uint32_t i = 0; i < rows; i++) {
			for (uint32_t j = 0; j < columns; j++) {
				this->data[i][j] = arr[i][j];
			}
		}
	}

	//перегрузка []
	Iterator operator[](size_t i)
    {
		std::cout << "operator[]" << std::endl;
		return this->data[i];
    }

	// Геттер на строку
	Matrix<1, columns> operator()(size_t row) {
		Matrix<1, columns> temp;
		if (row < rows) {
			for (size_t j = 0; j < columns; j++) {
				temp(0, j) = this->data[row][j];
			}
		}
		return temp;
	}

	// Геттер на элемент
	inline float& operator()(size_t row, size_t col) {
		if (row >= rows || col >= columns) {
			// TODO: еще раз обсудить
			while (1) {

			}
			return this->data[rows][columns];
		} else {
			return this->data[row][col];
		}
	}


	Matrix<rows, columns> operator+(Matrix<rows, columns> other) {
		Matrix<rows, columns> result_matrix;

		for (uint32_t i = 0; i < rows; i++) {
			for (uint32_t j = 0; j < columns; j++) {
				result_matrix[i][j] = this->data[i][j] + other.data[i][j];
			}
		}
		return result_matrix;
	}


	void operator+=(Matrix<rows, columns> other) {

		*this = *this + other;
	}

	Matrix<rows, columns> operator-(Matrix<rows, columns> other) {
		Matrix<rows, columns> result_matrix;

		for (uint32_t i = 0; i < rows; i++) {
			for (uint32_t j = 0; j < columns; j++) {
				result_matrix[i][j] = this->data[i][j] - other.data[i][j];
			}
		}
		return result_matrix;
	}


	void operator-=(Matrix<rows, columns> other) {

		*this = *this - other;
	}


	template<size_t col_right>
	Matrix<rows, columns> operator*(Matrix<columns, col_right> other) {
		Matrix<rows, col_right> m;
		//внешний цикл перебирает столбцы правой матрицы и столбцы результата
		for (uint32_t i = 0; i < col_right; i++) {
			//средний цикл перебирает строки левой матрицы и строки правой
			for (uint32_t j = 0; j < columns; j++) {
				float elem = 0;
				//внутренний цикл перебирает строки правой матрицы и, соответственно, номер столбца левой
				for (uint32_t k = 0; j < rows; j++) {
					elem += this->data[j][k] * other.data[k][i];
				}
				m[j][i] = elem;
			}
		}
		return m;
	}


	template<size_t col_right>
		void operator*=(Matrix<columns, col_right> other) {
			*this= *this * other;
		}


	Matrix<rows, columns> operator*(float coeff) {
		Matrix<rows, columns> matrix_result;
		for (uint32_t i = 0; i < rows; i++) {
			for (uint32_t j = 0; j < columns; j++) {
				matrix_result = this->data[i][j] * coeff;
			}
		}
		return matrix_result;
	}

	void operator*=(float coeff) {
		*this= *this * coeff;
		}

	void zero() {
		for (uint32_t i = 0; i < rows; i++) {
			for (uint32_t j = 0; j < columns; j++) {
				this->data[i][j] = 0;
			}
		}
	}



private:
	float data[rows][columns];
};

#endif /* MATRIX_H_ */
