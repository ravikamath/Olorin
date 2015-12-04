#ifndef __OLORIN_RAY__
#define __OLORIN_RAY__

#include <Vector3.hpp>

namespace Olorin
{
	namespace Framework
	{
		class FRAMEWORK_DLL Ray
		{
		private:
			Vector3 position;
			Vector3 direction;
		public:
			Ray(const Vector3& position, const Vector3& direction);

			const Vector3& getPosition() const;
			const Vector3& getDirection() const;
			const Vector3 getPointAt(const float& parameter) const;

			void setPosition(const Vector3& position);
			void setDirection(const Vector3& direction);

			static const bool intersects(const Ray& lhs, const Ray& rhs, Vector3& result);
		};
	}
}

#endif