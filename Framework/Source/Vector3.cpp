#include <Vector2.hpp>
#include <Vector3.hpp>
#include <Vector4.hpp>
#include <Matrix4.hpp>
#define EPSILON 1e-10

namespace Olorin
{
	namespace Framework
	{
		Vector3::Vector3()
		{
			coords[0] = coords[1] = coords[2] = 0;
		}

		Vector3::Vector3(const Vector2& source)
		{
			coords[0] = source.getValue(0);
			coords[1] = source.getValue(1);
			coords[2] = 0;
		}

		Vector3::Vector3(const Vector3& source)
		{
			coords[0] = source.coords[0];
			coords[1] = source.coords[1];
			coords[2] = source.coords[2];
		}

		Vector3::Vector3(const Vector4& source)
		{
			coords[0] = source[0];
			coords[1] = source[1];
			coords[2] = source[2];
		}

		Vector3::Vector3(const float& scalar)
		{
			coords[0] = coords[1] = coords[2] = scalar;
		}

		Vector3::Vector3(const float& x, const float& y, const float& z)
		{
			coords[0] = x;
			coords[1] = y;
			coords[2] = z;
		}

		// Mutators

		void Vector3::setX(const float& x)
		{
			coords[0] = x;
		}

		void Vector3::setY(const float& y)
		{
			coords[1] = y;
		}

		void Vector3::setZ(const float& z)
		{
			coords[2] = z;
		}

		void Vector3::setValue(const int& index, const float& value)
		{
			coords[index] = value;
		}

		// Accessors
		const float& Vector3::getX() const
		{
			return coords[0];
		}

		const float& Vector3::getY() const
		{
			return coords[1];
		}

		const float& Vector3::getZ() const
		{
			return coords[2];
		}

		const float& Vector3::getValue(const int& index) const
		{
			return coords[index];
		}

		const float& Vector3::operator [](const int& index) const
		{
			return coords[index];
		}

		float& Vector3::operator [](const int& index)
		{
			return coords[index];
		}

		// Operators - Mathematical
		const Vector3 Vector3::operator -() const
		{
			return Vector3(-coords[0], -coords[1], -coords[2]);
		}

		const Vector3 Vector3::operator /(const float& scale) const
		{
			return abs(scale) < EPSILON ? *this : *this * (1.0f / scale);
		}

		const Vector3& Vector3::operator =(const Vector3& rhs)
		{
			coords[0] = rhs.coords[0];
			coords[1] = rhs.coords[1];
			coords[2] = rhs.coords[2];
			return *this;
		}

		const Vector3& Vector3::operator +=(const Vector3& rhs)
		{
			coords[0] += rhs.coords[0];
			coords[1] += rhs.coords[1];
			coords[2] += rhs.coords[2];
			return *this;
		}

		const Vector3& Vector3::operator -=(const Vector3& rhs)
		{
			coords[0] -= rhs.coords[0];
			coords[1] -= rhs.coords[1];
			coords[2] -= rhs.coords[2];
			return *this;
		}

		const Vector3& Vector3::operator *=(const Vector3& rhs)
		{
			coords[0] *= rhs.coords[0];
			coords[1] *= rhs.coords[1];
			coords[2] *= rhs.coords[2];
			return *this;
		}

		const Vector3& Vector3::operator *=(const float& scale)
		{
			coords[0] *= scale;
			coords[1] *= scale;
			coords[2] *= scale;
			return *this;
		}

		const Vector3& Vector3::operator /=(const float& scale)
		{
			if (abs(scale) > EPSILON)
				*this *= 1.0f / scale;
			return *this;
		}

		// Operators - Logical

		const bool Vector3::operator ==(const Vector3& rhs) const
		{
			return abs(coords[0] - rhs.coords[0]) < EPSILON &&
				abs(coords[1] - rhs.coords[1]) < EPSILON &&
				abs(coords[2] - rhs.coords[2]) < EPSILON;
		}

		const bool Vector3::operator !=(const Vector3& rhs) const
		{
			return abs(coords[0] - rhs.coords[0]) > EPSILON ||
				abs(coords[1] - rhs.coords[1]) > EPSILON ||
				abs(coords[2] - rhs.coords[2]) > EPSILON;
		}

		const bool Vector3::operator <(const Vector3& rhs) const
		{
			return coords[0] < rhs.coords[0] &&
				coords[1] < rhs.coords[1] &&
				coords[2] < rhs.coords[2];
		}

		const bool Vector3::operator <=(const Vector3& rhs) const
		{
			return coords[0] - rhs.coords[0] < EPSILON &&
				coords[1] - rhs.coords[1] < EPSILON &&
				coords[2] - rhs.coords[2] < EPSILON;
		}

		const bool Vector3::operator >(const Vector3& rhs) const
		{
			return coords[0] > rhs.coords[0] &&
				coords[1] > rhs.coords[1] &&
				coords[2] > rhs.coords[2];
		}

		const bool Vector3::operator >=(const Vector3& rhs) const
		{
			return rhs.coords[0] - coords[0] < EPSILON &&
				rhs.coords[1] - coords[1] < EPSILON &&
				rhs.coords[2] - coords[2] < EPSILON;
		}

		// Dot Product
		const float Vector3::operator %(const Vector3& rhs) const
		{
			return coords[0] * rhs.coords[0] + coords[1] * rhs.coords[1] + coords[2] * rhs.coords[2];
		}

		// Cross Product
		const Vector3 Vector3::operator ^(const Vector3& rhs) const
		{
			return Vector3(coords[1] * rhs.coords[2] - coords[2] * rhs.coords[1],
				coords[2] * rhs.coords[0] - coords[0] * rhs.coords[2],
				coords[0] * rhs.coords[1] - coords[1] * rhs.coords[0]);
		}

		// Statistical
		const float Vector3::getLengthSquared() const
		{
			return coords[0] * coords[0] +
				coords[1] * coords[1] +
				coords[2] * coords[2];
		}

		void Vector3::min(const Vector3& rhs)
		{
			if (rhs.coords[0] < coords[0]) coords[0] = rhs.coords[0];
			if (rhs.coords[1] < coords[1]) coords[1] = rhs.coords[1];
			if (rhs.coords[2] < coords[2]) coords[2] = rhs.coords[2];
		}

		void Vector3::max(const Vector3& rhs)
		{
			if (rhs.coords[0] > coords[0]) coords[0] = rhs.coords[0];
			if (rhs.coords[1] > coords[1]) coords[1] = rhs.coords[1];
			if (rhs.coords[2] > coords[2]) coords[2] = rhs.coords[2];
		}

		const float& Vector3::min() const
		{
			unsigned int index = 0;
			if (coords[1] < coords[0]) index = 1;
			if (coords[2] < coords[index]) index = 2;
			return coords[index];
		}

		const float& Vector3::max() const
		{
			unsigned int index = 0;
			if (coords[1] > coords[0]) index = 1;
			if (coords[2] > coords[index]) index = 2;
			return coords[index];
		}

		const float Vector3::avg() const
		{
			return (coords[0] + coords[1] + coords[2]) / 3;
		}

		const Vector3 Vector3::clamp(const Vector3& min, const Vector3& max) const
		{
			Vector3 vector = *this;
			vector.min(max);
			vector.max(min);
			return vector;
		}

		const Vector3& Vector3::clamp(const Vector3& min, const Vector3& max)
		{
			this->max(min);
			this->min(max);
			return *this;
		}

		const Vector3 Vector3::normalize() const
		{
			return *this / getLength();
		}

		const Vector3& Vector3::normalize()
		{
			*this /= getLength();
			return *this;
		}

		const Vector3 Vector3::normalize(const Vector3& vector)
		{
			return vector / vector.getLength();
		}

		const Vector3 Vector3::reflect(const Vector3& normal) const
		{
			return *this - normal * (*this % normalize(normal) * 2);
		}

		const Vector3 Vector3::reflect(const Vector3& vector, const Vector3& normal)
		{
			return vector.reflect(normal);
		}

		const Vector3 Vector3::refract(const Vector3& normal, const float& etaRatio) const
		{
			float cosTheta = *this % -normal;
			float discriminant = 1 - etaRatio * etaRatio * (1 - cosTheta * cosTheta);
			if (discriminant < 0)
				return 0;
			return *this * etaRatio + normal * (cosTheta * etaRatio - sqrt(discriminant));
		}

		const Vector3 Vector3::refract(const Vector3& vector, const Vector3& normal, const float& etaRatio)
		{
			return vector.refract(normal, etaRatio);
		}

		const Vector3& Vector3::transform(const Matrix4& matrix)
		{
			return *this = matrix * Vector4(coords[0], coords[1], coords[2], 1);
		}

		const Vector3& Vector3::transformNormal(const Matrix4& matrix)
		{
			return *this = matrix * Vector4(coords[0], coords[1], coords[2], 0);
		}

		const Vector3 Vector3::transform(const Vector3& vector, const Matrix4& matrix)
		{
			return matrix * Vector4(vector.coords[0], vector.coords[1], vector.coords[2], 1);
		}

		const Vector3 Vector3::transformNormal(const Vector3& vector, const Matrix4& matrix)
		{
			return matrix * Vector4(vector.coords[0], vector.coords[1], vector.coords[2], 0);
		}

		// Definition of static constants
		const Vector3 Vector3::Zero(0, 0, 0);
		const Vector3 Vector3::UnitX(1, 0, 0);
		const Vector3 Vector3::UnitY(0, 1, 0);
		const Vector3 Vector3::UnitZ(0, 0, 1);
		const Vector3 Vector3::One(1, 1, 1);
		const Vector3 Vector3::Forward(0, 0, 1);
		const Vector3 Vector3::Backward(0, 0, -1);
		const Vector3 Vector3::Right(1, 0, 0);
		const Vector3 Vector3::Left(-1, 0, 0);
		const Vector3 Vector3::Up(0, 1, 0);
		const Vector3 Vector3::Down(0, -1, 0);

		// Free Mathematical operators
		const Vector3 operator +(const Vector3& lhs, const Vector3& rhs)
		{
			return Vector3(lhs) += rhs;
		}

		const Vector3 operator -(const Vector3& lhs, const Vector3& rhs)
		{
			return Vector3(lhs) -= rhs;
		}

		const Vector3 operator *(const Vector3& lhs, const Vector3& rhs)
		{
			return Vector3(lhs) *= rhs;
		}

		const Vector3 operator *(const Vector3& lhs, const float& rhs)
		{
			return Vector3(lhs) *= rhs;
		}

		const Vector3 operator *(const float& lhs, const Vector3& rhs)
		{
			return Vector3(rhs) *= lhs;
		}

		std::ostream& operator <<(std::ostream& lhs, const Vector3& rhs)
		{
			lhs << "(" << rhs.getX() << "," << rhs.getY() << "," << rhs.getZ() << ")";
			return lhs;
		}

		std::istream& operator >>(std::istream& lhs, Vector3& rhs)
		{
			lhs >> rhs[0] >> rhs[1] >> rhs[2];
			return lhs;
		}
	}
}