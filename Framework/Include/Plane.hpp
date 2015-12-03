#ifndef __OLORIN_PLANE__
#define __OLORIN_PLANE__

#include <Vector3.hpp>
#include <Ray.hpp>

namespace Olorin
{
	namespace Framework
	{
		class FRAMEWORK_DLL Plane
		{
		private:
			Vector3 position;
			Vector3 normal;
		public:
			Plane(const Vector3& position, const Vector3& normal);

			void setPosition(const Vector3& position);
			void setNormal(const Vector3& normal);

			const Vector3& getPosition() const;
			const Vector3& getNormal() const;
			// Find the point on the plane nearest to the argument
			const Vector3 project(const Vector3& point) const;

			// Queries
			const bool contains(const Vector3& point) const;
			const bool intersects(const Ray& ray) const;
			//const bool intersects(const Triangle& triangle) const;
		};
	}
}

#endif