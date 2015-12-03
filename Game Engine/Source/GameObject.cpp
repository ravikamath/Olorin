#include <GameObject.hpp>

namespace Olorin
{
	namespace GameEngine
	{
		GameObject::GameObject()
		{
			transform = new Transform();
		}

		GameObject::~GameObject()
		{
			for each (Component *component in components)
				delete component;
			delete transform;
		}

		// Accessor methods
		Transform* GameObject::getTransform() { return transform; }

		template <class T> T GameObject::add()
		{
			Component* component = new T(this);
			components.push_back(component);
		}

		template <class T> void GameObject::remove()
		{
			components.remove_if([](Component* c) { return dynamic_cast<T*>(c) != null; });
		}
	}
}