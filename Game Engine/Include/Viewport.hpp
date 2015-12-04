#ifndef __OLORIN_VIEWPORT__
#define __OLORIN_VIEWPORT__

#include <GameEngineDLL.hpp>
#include <Vector2.hpp>

using namespace Olorin::Framework;

namespace Olorin
{
	namespace GameEngine
	{
		class GAMEENGINE_DLL Viewport
		{
		private:
			Vector2 position;
			Vector2 size;
		public:
			Viewport();

			const Vector2& getPosition() const;
			const Vector2& getSize() const;
			const float getAspectRatio() const;

			void setPosition(const Vector2& value);
			void setSize(const Vector2& value);
		};
	}
}

#endif