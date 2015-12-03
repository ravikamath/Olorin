#ifndef __OLORIN_COMPONENT__
#define __OLORIN_COMPONENT__

#include <DLL.hpp>
#include <GameObject.hpp>

using namespace Olorin::Framework;

namespace Olorin
{
	namespace GameEngine
	{
		class DLLAPI Component
		{
		protected:
			GameObject* gameObject;
		public:
			Component(GameObject*);
			~Component();

			const Transform* getTransform() const;
			const GameObject* getGameObject() const;
		};
	}
}

#endif