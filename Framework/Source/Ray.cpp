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


	}
}