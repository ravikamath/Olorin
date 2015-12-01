#ifndef __OLORIN_QUATERNION__
#define __OLORIN_QUATERNION__

#include <Vector3.hpp>

namespace Olorin
{
	namespace Framework
	{
		class DLLAPI Quaternion
		{
		private:
			float real;		// The real part
			Vector3 imaginary;	// The imaginary part
		public:
			static const Quaternion Identity;

			// Constructor
			Quaternion();
			Quaternion(const float& real, const Vector3& imaginary);

			// Mutators
			void setReal(const float& real);
			void setImaginary(const Vector3& imaginary);

			// Accessors
			const float& getReal() const;
			const Vector3& getImaginary() const;

			const Quaternion& operator =(const Quaternion& rhs);
			const Quaternion& operator += (const Quaternion& rhs);
			const Quaternion& operator -= (const Quaternion& rhs);
			const Quaternion& operator *= (const Quaternion& rhs);

			// Creates a rotation quaternion using axis and angle (radians)
			static const Quaternion createFromAxisAngle(const Vector3& axis, const float& angle);
		};

		DLLAPI const Quaternion operator +(const Quaternion& lhs, const Quaternion& rhs);
		DLLAPI const Quaternion operator -(const Quaternion& lhs, const Quaternion& rhs);
		DLLAPI const Quaternion operator *(const Quaternion& lhs, const Quaternion& rhs);
	}
}

#endif