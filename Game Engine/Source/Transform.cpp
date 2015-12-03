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
					//localPosition = getPosition();
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

		const Matrix4& Transform::getWorld() const
		{
			return world;
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
