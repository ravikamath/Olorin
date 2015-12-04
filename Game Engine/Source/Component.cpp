#include <Component.hpp>

namespace Olorin
{
	namespace GameEngine
	{
		Component::Component(GameObject* gameObject)
		{
			this->gameObject = gameObject;
		}

		Component::~Component()
		{

		}

		Transform* Component::getTransform() { return gameObject->getTransform(); }
		const Transform* Component::getTransform() const { return gameObject->getTransform(); }
		GameObject* Component::getGameObject() { return gameObject; }
	}
}