#ifndef __OLORIN_INTERFACES__
#define __OLORIN_INTERFACES__

#include <GameEngineDLL.hpp>

namespace Olorin
{
	namespace GameEngine
	{
		class GAMEENGINE_DLL IUpdateable
		{
		public:
			virtual void update() = 0;
		};

		class GAMEENGINE_DLL IDrawable
		{
		public:
			virtual void draw() = 0;
		};

		class GAMEENGINE_DLL IRenderable
		{
		public:
			virtual void render() = 0;
		};
	}
}

#endif