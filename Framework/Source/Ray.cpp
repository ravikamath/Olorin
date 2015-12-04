#include <Ray.hpp>

namespace Olorin
{
	namespace Framework
	{
		Ray::Ray(const Vector3& position, const Vector3& direction)
		{
			this->position = position;
			this->direction = direction;
		}

		//Accessor functions
		const Vector3& Ray::getPosition() const
		{
			return position;
		}

		const Vector3& Ray::getDirection() const
		{
			return direction;
		}

		const Vector3 Ray::getPointAt(const float& parameter) const
		{
			return position + direction * parameter;
		}

		//Mutator functions
		void Ray::setPosition(const Vector3& position)
		{
			this->position = position;
		}

		void Ray::setDirection(const Vector3& direction)
		{
			this->direction = direction;
		}

		const bool Ray::intersects(const Ray& lhs, const Ray& rhs, Vector3& result)
		{
			Vector3 normal = lhs.getDirection() ^ rhs.getDirection();
			float determinant = normal.getLengthSquared();
			if (determinant == 0)
				return false;
			Vector3 location = rhs.getPosition() - lhs.getPosition();
			result.setX((rhs.getDirection() ^ normal) % location / determinant);
			result.setY((lhs.getDirection() ^ normal) % location / determinant);
			result.setZ(0);
			return true;
		}

	}
}