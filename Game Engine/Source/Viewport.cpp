#include <Viewport.hpp>

using namespace Olorin::Framework;

namespace Olorin
{
	namespace GameEngine
	{
		Viewport::Viewport()
		{
			position = Vector2::Zero;
		}

		const Vector2& Viewport::getPosition() const { return position; }
		const Vector2& Viewport::getSize() const { return size; }
		const float Viewport::getAspectRatio() const { return size.getX() / size.getY(); }

		void Viewport::setPosition(const Vector2& value) { position = value; }
		void Viewport::setSize(const Vector2& value) { size = value; }
	}
}