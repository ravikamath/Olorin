#include <Plane.hpp>

namespace Olorin
{
	namespace Framework
	{
		Plane::Plane(const Vector3& position, const Vector3& normal)
		{
			this->position = position;
			this->normal = normal.normalize();
			this->position = project(Vector3::Zero);
		}

		//Mutator Functions
		void Plane::setPosition(const Vector3& position)
		{
			this->position = position;
			this->position = project(Vector3::Zero);
		}

		void Plane::setNormal(const Vector3& normal)
		{
			this->normal = normal.normalize();
			this->position = project(Vector3::Zero);
		}

		// Accessor Functions
		const Vector3& Plane::getPosition() const
		{
			return position;
		}

		const Vector3& Plane::getNormal() const
		{
			return normal;
		}

		const Vector3 Plane::project(const Vector3& point) const
		{
			return point + normal * ((this->position - point) % normal);
		}
	}
}