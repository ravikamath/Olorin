#ifndef __OLORIN_TRANSFORM__
#define __OLORIN_TRANSFORM__

#include <Vector3.hpp>
#include <Quaternion.hpp>
#include <Matrix4.hpp>
#include <list>

using namespace Olorin::Framework;
using namespace std;

namespace Olorin
{
	namespace GameEngine
	{
		class DLLAPI Transform;
		template class DLLAPI list<Transform*>;

		class DLLAPI Transform
		{
		private:
			Vector3 localPosition;
			Quaternion localRotation;
			Vector3 localScale;
			Matrix4 world;
			Transform* parent;
			list<Transform*> children;

			void update();
		public:
			Transform();
			~Transform();

			void setLocalPosition(const Vector3& localPosition);
			void setLocalRotation(const Quaternion& localRotation);
			void setLocalScale(const Vector3& localScale);
			void setParent(Transform* parent, const bool& global = false);

			const Vector3& getLocalPosition() const;
			const Quaternion& getLocalRotation() const;
			const Vector3& getLocalScale() const;
			const Vector3 getPosition() const;
			const Quaternion getRotation() const;
			const Vector3 getScale() const;
			Transform* getParent() const;
			const Matrix4& getWorld() const;

			const Vector3 getForward() const;
			const Vector3 getBackward() const;
			const Vector3 getUp() const;
			const Vector3 getDown() const;
			const Vector3 getRight() const;
			const Vector3 getLeft() const;
		};
	}
}

#endif
