#include <Plane.hpp>

namespace Olorin
{
	namespace Framework
	{


		// Accessor Functions
		const Vector3& Plane::getPoint() const
		{
			return point;
		}

		const Vector3& Plane::getNormal() const
		{
			return normal;
		}

		const Vector3 Plane::project(const Vector3& point) const
		{
			return point + normal * ((this->point - point) % normal);
		}
	}
}