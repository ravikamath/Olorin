#ifndef __OLORIN_COMPONENT__
#define __OLORIN_COMPONENT__

#include <GameEngineDLL.hpp>
#include <GameObject.hpp>

using namespace Olorin::Framework;

namespace Olorin
{
	namespace GameEngine
	{
		class GAMEENGINE_DLL Component
		{
		protected:
			GameObject* gameObject;
		public:
			Component(GameObject* gameObject);
			virtual ~Component();

			Transform* getTransform();
			const Transform* getTransform() const;
			GameObject* getGameObject();
		};
	}
}

#endif