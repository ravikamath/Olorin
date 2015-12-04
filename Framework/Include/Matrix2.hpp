#ifndef __OLORIN_MATRIX2__
#define __OLORIN_MATRIX2__

#include <FrameworkDLL.hpp>

namespace Olorin
	{
	namespace Framework
		{
		class FRAMEWORK_DLL Matrix2
			{
			private:
				float mat[4];
			public:
				Matrix2();
				Matrix2(const Matrix2&);
				Matrix2(const float[]);
				
				// Overloaded operators
				float& operator [](const unsigned int&);
				float& operator ()(const unsigned int&, const unsigned int&);
				const float& operator ()(const unsigned int&, const unsigned int&) const;
				const Matrix2& operator =(const Matrix2&);
				const Matrix2& operator *=(const Matrix2&);
				const Matrix2& operator *=(const float&);
				const Matrix2& operator +=(const Matrix2&);
				const Matrix2& operator -=(const Matrix2&);
				const Matrix2 operator *(const Matrix2&) const;
				
				void transpose();
				void invert();
				const float getConditionNumber() const;
				void getEigenValues(float*) const;
				void loadIdentity();
				const float getDeterminant() const;
				const float getTrace() const;
			};
			
		FRAMEWORK_DLL const Matrix2 operator +(const Matrix2&, const Matrix2&);
		FRAMEWORK_DLL const Matrix2 operator -(const Matrix2&, const Matrix2&);
		FRAMEWORK_DLL const Matrix2 operator *(const Matrix2&, const float&);
		FRAMEWORK_DLL const Matrix2 operator *(const float&, const Matrix2&);
		}
	}

#endif