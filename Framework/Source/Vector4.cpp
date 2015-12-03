#include <Vector4.hpp>
#include <Vector3.hpp>
#include <math.h>

namespace Olorin
{
	namespace Framework
	{
		// Constructors
		Vector4::Vector4()
		{
			coords[0] = coords[1] = coords[2] = coords[3] = 0;
		}

		Vector4::Vector4(const Vector3& source, const float& w)
		{
			coords[0] = source[0];
			coords[1] = source[1];
			coords[2] = source[2];
			coords[3] = w;
		}

		Vector4::Vector4(const Vector4& source)
		{
			coords[0] = source.coords[0];
			coords[1] = source.coords[1];
			coords[2] = source.coords[2];
			coords[3] = source.coords[3];
		}

		Vector4::Vector4(const float& x, const float& y, const float& z, const float& w)
		{
			coords[0] = x;
			coords[1] = y;
			coords[2] = z;
			coords[3] = w;
		}

		Vector4::Vector4(const float& scalar)
		{
			coords[0] = coords[1] = coords[2] = coords[3] = scalar;
		}

		// Mutators
		void Vector4::setX(const float& x)
		{
			coords[0] = x;
		}

		void Vector4::setY(const float& y)
		{
			coords[1] = y;
		}

		void Vector4::setZ(const float& z)
		{
			coords[2] = z;
		}

		void Vector4::setW(const float& w)
		{
			coords[3] = w;
		}

		void Vector4::setValue(const int& index, const float& value)
		{
			coords[index] = value;
		}

		// Accessors
		const float& Vector4::getX() const
		{
			return coords[0];
		}

		const float& Vector4::getY() const
		{
			return coords[1];
		}

		const float& Vector4::getZ() const
		{
			return coords[2];
		}

		const float& Vector4::getW() const
		{
			return coords[3];
		}

		const float& Vector4::getValue(const int& index) const
		{
			return coords[index];
		}

		const float& Vector4::operator [](const int& index) const
		{
			return coords[index];
		}

		float& Vector4::operator [](const int& index)
		{
			return coords[index];
		}

		// Operators
		const Vector4& Vector4::operator =(const Vector4& rhs)
		{
			coords[0] = rhs.coords[0];
			coords[1] = rhs.coords[1];
			coords[2] = rhs.coords[2];
			coords[3] = rhs.coords[3];
			return *this;
		}

		const Vector4& Vector4::operator +=(const Vector4& rhs)
		{
			coords[0] += rhs.coords[0];
			coords[1] += rhs.coords[1];
			coords[2] += rhs.coords[2];
			coords[3] += rhs.coords[3];
			return *this;
		}

		const Vector4& Vector4::operator -=(const Vector4& rhs)
		{
			coords[0] -= rhs.coords[0];
			coords[1] -= rhs.coords[1];
			coords[2] -= rhs.coords[2];
			coords[3] -= rhs.coords[3];
			return *this;
		}

		const Vector4& Vector4::operator *=(const Vector4& rhs)
		{
			coords[0] *= rhs.coords[0];
			coords[1] *= rhs.coords[1];
			coords[2] *= rhs.coords[2];
			coords[3] *= rhs.coords[3];
			return *this;
		}

		const Vector4& Vector4::operator *=(const float& rhs)
		{
			coords[0] *= rhs;
			coords[1] *= rhs;
			coords[2] *= rhs;
			coords[3] *= rhs;
			return *this;
		}

		const Vector4& Vector4::operator /=(const float& rhs)
		{
			return *this *= (1.0f / rhs);
		}

		// Statistical functions
		const float Vector4::getLengthSquared() const
		{
			return coords[0] * coords[0] +
				coords[1] * coords[1] +
				coords[2] * coords[2] + 
				coords[3] * coords[3];;
		}

		void Vector4::min(const Vector4& rhs)
		{
			if (rhs.coords[0] < coords[0]) coords[0] = rhs.coords[0];
			if (rhs.coords[1] < coords[1]) coords[1] = rhs.coords[1];
			if (rhs.coords[2] < coords[2]) coords[2] = rhs.coords[2];
			if (rhs.coords[3] < coords[3]) coords[3] = rhs.coords[3];
		}

		void Vector4::max(const Vector4& rhs)
		{
			if (rhs.coords[0] > coords[0]) coords[0] = rhs.coords[0];
			if (rhs.coords[1] > coords[1]) coords[1] = rhs.coords[1];
			if (rhs.coords[2] > coords[2]) coords[2] = rhs.coords[2];
			if (rhs.coords[3] > coords[3]) coords[3] = rhs.coords[3];
		}

		const Vector4 Vector4::clamp(const Vector4& min, const Vector4& max) const
		{
			Vector4 result(*this);
			result.min(max);
			result.max(min);
			return result;
		}

		const Vector4& Vector4::clamp(const Vector4& min, const Vector4& max)
		{
			this->min(max);
			this->max(min);
			return *this;
		}

		void Vector4::saturate()
		{
			this->clamp(0, 1);
		}

		// Free operators
		FRAMEWORK_DLL const Vector4 operator +(const Vector4& lhs, const Vector4& rhs)
		{
			return Vector4(lhs) += rhs;
		}

		FRAMEWORK_DLL const Vector4 operator -(const Vector4& lhs, const Vector4& rhs)
		{
			return Vector4(lhs) -= rhs;
		}

		FRAMEWORK_DLL const Vector4 operator *(const Vector4& lhs, const Vector4& rhs)
		{
			return Vector4(lhs) *= rhs;
		}

		FRAMEWORK_DLL const Vector4 operator *(const float& lhs, const Vector4& rhs)
		{
			return Vector4(rhs) *= lhs;
		}

		FRAMEWORK_DLL const Vector4 operator *(const Vector4& lhs, const float& rhs)
		{
			return Vector4(lhs) *= rhs;
		}
	}
}