#ifndef __OLORIN_VIEWPORT__
#define __OLORIN_VIEWPORT__

#include <GameEngineDLL.hpp>

namespace Olorin
{
	namespace GameEngine
	{
		class GAMEENGINE_DLL Viewport
		{
		public:
			const float getAspectRatio() const;
		};
	}
}

#endif