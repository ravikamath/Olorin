#include <Transform.hpp>

using namespace Olorin::Framework;
using namespace std;

namespace Olorin
{
	namespace GameEngine
	{
		Transform::Transform()
		{
			localPosition = Vector3::Zero;
			localRotation = Quaternion::Identity;
			localScale = Vector3::One;
			parent = NULL;
			update();
		}

		Transform::~Transform()
		{
			//if I have children remove their parents
			// for
			// child.parent = NULL;
		}


		void Transform::setLocalPosition(const Vector3& localPosition)
		{
			this->localPosition = localPosition;
			update();
		}

		void Transform::setLocalRotation(const Quaternion& localRotation)
		{
			this->localRotation = localRotation;
			update();
		}

		void Transform::setLocalScale(const Vector3& localScale)
		{
			this->localScale = localScale;
			update();
		}

		void Transform::setParent(Transform* parent)
		{
			if (this->parent != NULL)
			{
				//localPosition = getPosition();
				//localRotation = getRotation();
				//localScale = getScale();
				// remove from children list of parent
			}
			this->parent = parent;
			if (this->parent != NULL)
			{
				// add from children list of parent
			}
			update();
		}

		const Vector3& Transform::getLocalPosition() const
		{
			return localPosition;
		}

		const Quaternion& Transform::getLocalRotation() const
		{
			return localRotation;
		}

		const Vector3& Transform::getLocalScale() const
		{
			return localScale;
		}

		void Transform::update()
		{
			world = Matrix4::createTranslation(localPosition) *
				Matrix4::createRotationQuaternion(localRotation) *
				Matrix4::createScale(localScale);
			if (parent != NULL)
				world = parent->world * world;
		}
	}
}
