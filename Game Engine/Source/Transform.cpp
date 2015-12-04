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
			for each (Transform* child in children)
			{
				child->parent = NULL;
				child->update();
			}
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

		void Transform::setParent(Transform* parent, const bool& global)
		{
			if (this->parent == parent)
				return;
			if (this->parent != NULL)
			{
				if (global)
				{
					localPosition = getPosition();
					//localRotation = getRotation();
					//localScale = getScale();
				}
				parent->children.remove(this);
			}
			if ((this->parent = parent) != NULL)
			{
				if (global)
				{
					// Set the position, rotation, scale
				}
				parent->children.push_back(this);
			}
			update();
		}

		const Vector3& Transform::getLocalPosition() const { return localPosition; }
		const Vector3 Transform::getPosition() const { return Vector3(world[12], world[13], world[14]); }
		const Quaternion& Transform::getLocalRotation() const { return localRotation; }
		const Vector3& Transform::getLocalScale() const { return localScale; }

		const Vector3 Transform::getForward() const { return world.getForward(); }
		const Vector3 Transform::getBackward() const { return world.getBackward(); }
		const Vector3 Transform::getRight() const { return world.getRight(); }
		const Vector3 Transform::getLeft() const { return world.getLeft(); }
		const Vector3 Transform::getUp() const { return world.getUp(); }
		const Vector3 Transform::getDown() const { return world.getDown(); }
		const Matrix4& Transform::getWorld() const { return world; }

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
