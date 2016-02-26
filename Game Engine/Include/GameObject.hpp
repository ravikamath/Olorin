#ifndef __OLORIN_GAMEOBJECT__
#define __OLORIN_GAMEOBJECT__
#pragma warning(disable: 4251)

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
		class GAMEENGINE_DLL Camera;
		class GAMEENGINE_DLL Light;
		class GAMEENGINE_DLL Renderer;

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
			Camera* getCamera(); // not implemented
			Light* getLight(); // not implemented
			Renderer* getRenderer(); // not implemented

			template<class T> T* add();
			template<class T> T* get();
			template<class T> void remove();
		};
	}
}

#endif