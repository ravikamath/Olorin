#include <Matrix2.hpp>
#include <math.h>

namespace Olorin
	{
	namespace Framework
		{
		Matrix2::Matrix2()
			{
			loadIdentity();
			}
		
		Matrix2::Matrix2(const Matrix2& rhs)
			{
			for(unsigned int i = 0; i < 4; ++i)
				mat[i] = rhs.mat[i];
			}
		
		Matrix2::Matrix2(const float rhs[])
			{
			for(unsigned int i = 0; i < 4; ++i)
				mat[i] = rhs[i];
			}
		
		float& Matrix2::operator [](const unsigned int& index)
			{
			if(index < 4)
				return mat[index];
			return mat[3];
			}
		
		float& Matrix2::operator ()(const unsigned int& col, const unsigned int& row)
			{
			if(col < 2 && row < 2)
				return mat[col*2 + row];
			return mat[3];
			}
		
		const float& Matrix2::operator ()(const unsigned int& col, const unsigned int& row) const
			{
			if(col < 2 && row < 2)
				return mat[col*2 + row];
			return mat[3];
			}
		
		const Matrix2& Matrix2::operator = (const Matrix2& rhs)
			{
			for(unsigned int i = 0; i < 4; ++i)
				mat[i] = rhs.mat[i];
			return (*this);
			}
		
		const Matrix2& Matrix2::operator += (const Matrix2& rhs)
			{
			for(unsigned int i = 0; i < 4; ++i)
				mat[i] += rhs.mat[i];
			return (*this);
			}
		
		const Matrix2& Matrix2::operator -= (const Matrix2& rhs)
			{
			for(unsigned int i = 0; i < 4; ++i)
				mat[i] -= rhs.mat[i];
			return (*this);
			}
		
		const Matrix2& Matrix2::operator *= (const float& rhs)
			{
			for(unsigned int i = 0; i < 4; ++i)
				mat[i] *= rhs;
			return (*this);
			}
		
		const Matrix2& Matrix2::operator *= (const Matrix2& rhs)
			{
			*this = *this * rhs;
			return (*this);
			}
		
		const Matrix2 Matrix2::operator *(const Matrix2& rhs) const
			{
			Matrix2 matrix;
			for(unsigned int col = 0; col < 2; ++col)
				for(unsigned int row = 0; row < 2; ++row)
					{
					matrix(col, row) = (*this)(0, row) * rhs(col, 0) + (*this)(1, row) * rhs(col, 1);
					}
			return matrix;
			}
			
		void Matrix2::loadIdentity()
			{
			mat[0] = mat[3] = 1;
			mat[1] = mat[2] = 0;
			}
		
		void Matrix2::transpose()
			{
			float swap = mat[1];
			mat[1] = mat[2];
			mat[2] = swap;
			}
		
		void Matrix2::invert()
			{
			float determinant = getDeterminant();
			if(!determinant)
				return;
			float temp = mat[0];
			mat[0] = mat[3] / determinant;
			mat[1] = -mat[1] / determinant;
			mat[2] = -mat[2] / determinant;
			mat[3] = temp / determinant;
			}
		
		void Matrix2::getEigenValues(float* eigens) const
			{
			float determinant = getDeterminant();
			if(!determinant)
				{
				eigens[0] = eigens[1] = 0;	
				return;
				}
			float trace = getTrace() / 2;
			eigens[0] = float(trace - sqrt(trace * trace - determinant));
			eigens[1] = float(trace + sqrt(trace * trace - determinant));
			}
		
		const float Matrix2::getConditionNumber() const
			{
			if(getDeterminant() == 0)
				return 0;
			Matrix2 mTm(*this);
			mTm.transpose();
			mTm *= *this;
			float eigens[2] = {0, 0};
			mTm.getEigenValues(eigens);
			if(eigens[0] < eigens[1])
				return float(sqrt(eigens[1] / eigens[0]));
			else
				return float(sqrt(eigens[0] / eigens[1]));
			}
		
		const float Matrix2::getDeterminant() const
			{
			return mat[0] * mat[3] - mat[1] * mat[2];
			}
		
		const float Matrix2::getTrace() const
			{
			return mat[0] + mat[3];
			}
		
		// Free overloaded operators	
		const Matrix2 operator +(const Matrix2& lhs, const Matrix2& rhs) { return Matrix2(lhs) += rhs; }
		const Matrix2 operator -(const Matrix2& lhs, const Matrix2& rhs) { return Matrix2(lhs) -= rhs; }
		const Matrix2 operator *(const Matrix2& lhs, const float& rhs) { return Matrix2(lhs) *= rhs; }
		const Matrix2 operator *(const float& lhs, const Matrix2& rhs) { return Matrix2(rhs) *= lhs; }
		}
	}