#include <Vector2.hpp>

namespace Olorin
{
	namespace Framework
	{
		// Constructor
		Vector2::Vector2()
		{
			coords[0] = coords[1] = 0;
		}

		Vector2::Vector2(const float& x, const float& y)
		{
			coords[0] = x;
			coords[1] = y;
		}

		Vector2::Vector2(const float& scalar)
		{
			coords[0] = coords[1] = scalar;
		}

		// Mutators
		void Vector2::setX(const float& x)
		{
			coords[0] = x;
		}

		void Vector2::setY(const float& y)
		{
			coords[1] = y;
		}

		void Vector2::setValue(const int& index, const float& value)
		{
			coords[index] = value;
		}

		// Accessors
		const float& Vector2::getX() const
		{
			return coords[0];
		}

		const float& Vector2::getY() const
		{
			return coords[1];
		}

		const float& Vector2::getValue(const int& index) const
		{
			return coords[index];
		}

		const float& Vector2::operator [](const int& index) const
		{
			return coords[index];
		}

		float& Vector2::operator [](const int& index)
		{
			return coords[index];
		}

		const float Vector2::getLengthSquared() const
		{
			return coords[0] * coords[0] +
				coords[1] * coords[1];
		}

		// Static constant members
		const Vector2 Vector2::Zero(0, 0);
		const Vector2 Vector2::One(1, 1);
		const Vector2 Vector2::UnitX(1, 0);
		const Vector2 Vector2::UnitY(0, 1);
	}
}