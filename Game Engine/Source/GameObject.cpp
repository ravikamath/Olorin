#include <GameObject.hpp>
#include <Component.hpp>

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

		template <class T> T* GameObject::add()
		{
			Component* component = new T(this);
			components.push_back(component);
			return component;
		}

		template <class T> T* GameObject::get()
		{
			list<Component*>::iterator iterator;
			T* component;
			for (iterator = components.begin(); iterator != components.end(); ++iterator)
				if ((component = dynamic_cast<T*>(*iterator)) != null)
					return component;
			// did not find anything, return null
			return NULL;
		}

		template <class T> void GameObject::remove()
		{
			// warning, will remove all components of type T
			// perhaps, update so it will only remove the first?
			components.remove_if([](Component* c) { return dynamic_cast<T*>(c) != null; });
		}
	}
}