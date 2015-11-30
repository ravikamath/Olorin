#ifndef __OLORIN_VECTOR2__
#define __OLORIN_VECTOR2__

#include <Vector.hpp>

namespace Olorin
{
	namespace Framework
	{
		class DLLAPI Vector2 : public Vector
		{
		private:
			float coords[2];
		public:
			// Static constant members
			static const Vector2 Zero;              // (0, 0)
			static const Vector2 One;               // (1, 1)
			static const Vector2 UnitX;             // (1, 0)
			static const Vector2 UnitY;             // (0, 1)

			//Constructors
			Vector2();
			Vector2(const Vector2&);
			Vector2(const float&, const float&);
			Vector2(const float&);

			// Mutators
			void setX(const float&);
			void setY(const float&);
			void setValue(const int& index, const float& value);

			// Accessors
			const float& getX() const;
			const float& getY() const;
			const float& getValue(const int& index) const;

			const float& operator [](const int& index) const;
			float& operator [](const int& index);

			const float getLengthSquared() const;
		};
	}
}

#endif