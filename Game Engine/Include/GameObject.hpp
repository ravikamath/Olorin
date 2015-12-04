#ifndef __OLORIN_GAMEOBJECT__
#define __OLORIN_GAMEOBJECT__

#include <Transform.hpp>
#include <Matrix4.hpp>
#include <list>

using namespace Olorin::Framework;
using namespace std;

namespace Olorin
{
	namespace GameEngine
	{
		class GAMEENGINE_DLL Component;
		template class GAMEENGINE_DLL list<Component*>;

		class GAMEENGINE_DLL GameObject
		{
		private:
			//String name;
			Transform* transform;
			list<Component*> components;
		public:
			GameObject();
			~GameObject();

			Transform* getTransform();
			//Camera* getCamera();
			//Light* getLight();
			//Renderer* getRenderer();

			template<class T> T add();
			template<class T> T get();
			template<class T> void remove();
		};
	}
}

#endif