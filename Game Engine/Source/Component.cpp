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
		GameObject* Component::getGameObject() { return gameObject; }
	}
}