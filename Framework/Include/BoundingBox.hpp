#ifndef __OLORIN_BOUNDINGBOX__
#define __OLORIN_BOUNDINGBOX__

#include <FrameworkDLL.hpp>
#include <Vector3.hpp>
#include <Ray.hpp>

namespace Olorin
{
	namespace Framework
	{
		class FRAMEWORK_DLL BoundingBox
		{
		private:
			Vector3 min;
			Vector3 max;
		public:
			BoundingBox();
			BoundingBox(const Vector3&, const Vector3&);

			void setMin(const Vector3&);
			void setMax(const Vector3&);

			const Vector3& getMin() const;
			const Vector3& getMax() const;

			void include(const Vector3&);
			void include(const BoundingBox&);
			const bool contains(const Vector3&) const;
			const bool contains(const BoundingBox&) const;
			const bool intersects(const BoundingBox&) const; // use the && operator here!
			const bool intersects(const Ray&, const float&, const float&) const;
			const Vector3 getCenter() const;
		};
	}
}

#endif