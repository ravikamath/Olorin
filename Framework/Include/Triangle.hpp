#ifndef __OLORIN_TRIANGLE__
#define __OLORIN_TRIANGLE__

#include <Vector3.hpp>
#include <Plane.hpp>

namespace Olorin
{
	namespace Framework
	{
		class FRAMEWORK_DLL Triangle
		{
		private:
			Vector3 vertices[3];
		public:
			Triangle(const Vector3& a, const Vector3& b, const Vector3& c);

			const float getArea() const;
			const Vector3 getNormal() const;
			const Vector3 getCircumCenter() const;
			const Vector3 getInCenter() const;
			const Vector3 getCentroid() const;
			const float getCircumRadius() const;
			const float getInRadius() const;

			const Plane getPlane() const;
			const bool intersects(const Ray&) const;
			//const bool intersects(const Plane&) const;
			//const bool intersects(const Triangle&) const;
			//const bool contains(const Vector3&) const;
		};
	}
}

#endif