#ifndef __OLORIN_VECTOR3__
#define __OLORIN_VECTOR3__

#include <iostream>
#include <Vector.hpp>

namespace Olorin
{
	namespace Framework
	{
		class FRAMEWORK_DLL Vector2;
		class FRAMEWORK_DLL Vector4;
		class FRAMEWORK_DLL Matrix4;

		class FRAMEWORK_DLL Vector3 : public Vector
		{
		private:
			float coords[3];
		public:
			// Static constant members
			static const Vector3 Zero;		// (0, 0, 0)
			static const Vector3 One;		// (1, 1, 1)
			static const Vector3 UnitX;		// (1, 0, 0)
			static const Vector3 UnitY;		// (0, 1, 0)
			static const Vector3 UnitZ;		// (0, 0, 1)
			static const Vector3 Forward;	// (1, 0, 0)
			static const Vector3 Backward;	// (0, 1, 0)
			static const Vector3 Right;		// (0, 0, 1)
			static const Vector3 Left;		// (1, 0, 0)
			static const Vector3 Up;		// (0, 1, 0)
			static const Vector3 Down;		// (0, 0, 1)


			// Constructors
			Vector3();
			Vector3(const Vector2& source);
			Vector3(const Vector3& source);
			Vector3(const Vector4& source);
			Vector3(const float& x, const float& y, const float& z);
			Vector3(const float& scalar);

			// Mutators
			void setX(const float& x);
			void setY(const float& y);
			void setZ(const float& z);
			void setValue(const int& index, const float& value);

			// Accessors
			const float& getX() const;
			const float& getY() const;
			const float& getZ() const;
			const float& getValue(const int& index) const;

			const float& operator [](const int& index) const;
			float& operator [](const int& index);

			// Operators - Mathematical
			const Vector3 operator -() const;
			const Vector3 operator /(const float& scale) const;
			const Vector3& operator =(const Vector3& rhs);
			const Vector3& operator +=(const Vector3& rhs);
			const Vector3& operator -=(const Vector3& rhs);
			const Vector3& operator *=(const Vector3& rhs);
			const Vector3& operator *=(const float& scale);
			const Vector3& operator /=(const float& scale);

			// Operators - Logical
			const bool operator == (const Vector3& rhs) const;
			const bool operator != (const Vector3& rhs) const;
			const bool operator < (const Vector3& rhs) const;
			const bool operator <= (const Vector3& rhs) const;
			const bool operator > (const Vector3& rhs) const;
			const bool operator >= (const Vector3& rhs) const;

			// Dot product
			const float operator % (const Vector3& rhs) const;
			// Cross product
			const Vector3 operator ^ (const Vector3& rhs) const;

			// Statistical functions
			const float getLengthSquared() const;
			// Does a component-wise min
			void (min)(const Vector3& rhs);
			// Does a component-wise max
			void (max)(const Vector3& rhs);
			const float& (min)() const; // smallest component
			const float& (max)() const; // largest component
			const float avg() const; // average of the component values
			const Vector3 clamp(const Vector3& min, const Vector3& max) const;
			const Vector3& clamp(const Vector3& min, const Vector3& max);

			const Vector3 normalize() const;
			const Vector3& normalize();
			static const Vector3 normalize(const Vector3& vector);
			const Vector3 reflect(const Vector3& normal) const;
			static const Vector3 reflect(const Vector3& vector, const Vector3& normal);
			const Vector3 refract(const Vector3& normal, const float& etaRatio) const;
			static const Vector3 refract(const Vector3& vector, const Vector3& normal, const float& etaRatio);
			const Vector3& transform(const Matrix4& matrix);
			static const Vector3 transform(const Vector3& vector, const Matrix4& matrix);
			const Vector3& transformNormal(const Matrix4& matrix);
			static const Vector3 transformNormal(const Vector3& vector, const Matrix4& matrix);
		};

		// Free operators
		FRAMEWORK_DLL const Vector3 operator +(const Vector3& lhs, const Vector3& rhs);
		FRAMEWORK_DLL const Vector3 operator -(const Vector3& lhs, const Vector3& rhs);
		FRAMEWORK_DLL const Vector3 operator *(const Vector3& lhs, const Vector3& rhs);
		FRAMEWORK_DLL const Vector3 operator *(const Vector3& lhs, const float& rhs);

		// Input/Output
		FRAMEWORK_DLL std::ostream& operator <<(std::ostream& lhs, const Vector3& rhs);
		FRAMEWORK_DLL std::istream& operator >>(std::istream& lhs, Vector3& rhs);
	}
}

#endif
