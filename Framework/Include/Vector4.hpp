#ifndef __OLORIN_VECTOR4__
#define __OLORIN_VECTOR4__

#include <Vector.hpp>

namespace Olorin
{
	namespace Framework
	{
		class DLLAPI Vector3;

		class DLLAPI Vector4 : public Vector
		{
		private:
			float coords[4];
		public:
			// Static constant members
			static const Vector4 Zero;              // (0, 0, 0, 0)
			static const Vector4 One;               // (1, 1, 1, 1)
			static const Vector4 UnitX;             // (1, 0, 0, 0)
			static const Vector4 UnitY;             // (0, 1, 0, 0)
			static const Vector4 UnitZ;             // (0, 0, 1, 0)
			static const Vector4 UnitW;             // (0, 0, 0, 1)

			// Constructors
			Vector4();
			Vector4(const Vector3& source, const float& w = 1);
			Vector4(const Vector4& source);
			Vector4(const float& x, const float& y, const float& z, const float& w);
			Vector4(const float& scalar);

			// Mutators
			void setX(const float& x);
			void setY(const float& y);
			void setZ(const float& z);
			void setW(const float& w);
			void setValue(const int& index, const float& value);

			// Accessors
			const float& getX() const;
			const float& getY() const;
			const float& getZ() const;
			const float& getW() const;
			const float& getValue(const int& index) const;

			const float& operator [](const int& index) const;
			float& operator [](const int& index);
			const Vector4& operator =(const Vector4& rhs);
			const Vector4& operator +=(const Vector4& rhs);
			const Vector4& operator -=(const Vector4& rhs);
			const Vector4& operator *=(const Vector4& rhs);
			const Vector4& operator *=(const float& rhs);
			const Vector4& operator /=(const float& rhs);

			//Statistical function
			const float getLengthSquared() const;
			void (min)(const Vector4& rhs);
			void (max)(const Vector4& rhs);
			const Vector4 clamp(const Vector4& min, const Vector4& max) const;
			const Vector4& clamp(const Vector4& min, const Vector4& max);
			void saturate();
		};

		// Free operators
		DLLAPI const Vector4 operator +(const Vector4& lhs, const Vector4& rhs);
		DLLAPI const Vector4 operator -(const Vector4& lhs, const Vector4& rhs);
		DLLAPI const Vector4 operator *(const Vector4& lhs, const Vector4& rhs);
		DLLAPI const Vector4 operator *(const float& lhs, const Vector4& rhs);
		DLLAPI const Vector4 operator *(const Vector4& lhs, const float& rhs);
	}
}

#endif

