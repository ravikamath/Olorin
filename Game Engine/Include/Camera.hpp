#ifndef __OLORIN_CAMERA__
#define __OLORIN_CAMERA__

#include <Component.hpp>
#include <Viewport.hpp>

using namespace Olorin::Framework;

namespace Olorin
{
	namespace GameEngine
	{
		class GAMEENGINE_DLL Camera : public Component
		{
		private:
			float nearClipPlane;
			float farClipPlane;
			float fieldOfView;
			float aspectRatio;
			Viewport viewport;

			float depth; // when this camera should render
		public:
			Camera(GameObject*);

			void setNearClipPlane(const float& value);
			void setFarClipPlane(const float& value);
			void setFieldOfView(const float& value);
			void setAspectRatio(const float& value);
			void setViewport(const Viewport& value);

			const float& getNearClipPlane() const;
			const float& getFarClipPlane() const;
			const float& getFieldOfView() const;
			const float& getAspectRatio() const;
			const Viewport& getViewport() const;

			const Matrix4 getView() const;
			const Matrix4 getProjection() const;
		};
	}
}

#endif