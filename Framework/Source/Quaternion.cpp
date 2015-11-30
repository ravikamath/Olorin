#include <math.h>
#include <Quaternion.hpp>

namespace Olorin
{
	namespace Framework
	{
		Quaternion::Quaternion()
		{
			real = 1;
			imaginary = 0;
		}

		Quaternion::Quaternion(const float& real, const Vector3& imaginary)
		{
			this->real = real;
			this->imaginary = imaginary;
		}

		// Mutator
		void Quaternion::setReal(const float& real)
		{
			this->real = real;
		}

		void Quaternion::setImaginary(const Vector3& imaginary)
		{
			this->imaginary = imaginary;
		}

		// Accessor
		const float& Quaternion::getReal() const
		{
			return real;
		}

		const Vector3& Quaternion::getImaginary() const
		{
			return imaginary;
		}

		// Operators - Mathematical
		const Quaternion& Quaternion::operator =(const Quaternion& rhs)
		{
			this->real = rhs.real;
			this->imaginary = rhs.imaginary;
			return *this;
		}

		const Quaternion& Quaternion::operator +=(const Quaternion& rhs)
		{
			this->real += rhs.real;
			this->imaginary + rhs.imaginary;
			return *this;
		}

		const Quaternion& Quaternion::operator -=(const Quaternion& rhs)
		{
			this->real -= rhs.real;
			this->imaginary -= rhs.imaginary;
			return *this;
		}

		const Quaternion& Quaternion::operator *=(const Quaternion& rhs)
		{
			float scalar = real * rhs.real - (imaginary % rhs.imaginary);
			imaginary = real * rhs.imaginary + rhs.real * imaginary + (imaginary ^ rhs.imaginary);
			real = scalar;
			return *this;
		}

		// Static const members
		const Quaternion Quaternion::Identity;

		// Creates a quaternion from axis and angle (in radians)
		const Quaternion Quaternion::createFromAxisAngle(const Vector3& axis, const float& angle)
		{
			return Quaternion(cos(angle * 0.5f), sin(angle * 0.5f) * (axis.normalize()));
		}

		// Free operators
		const Quaternion operator +(const Quaternion& lhs, const Quaternion& rhs)
		{
			return Quaternion(lhs) += rhs;
		}

		const Quaternion operator -(const Quaternion& lhs, const Quaternion& rhs)
		{
			return Quaternion(lhs) -= rhs;
		}

		const Quaternion operator *(const Quaternion& lhs, const Quaternion& rhs)
		{
			return Quaternion(lhs) *= rhs;
		}
	}
}