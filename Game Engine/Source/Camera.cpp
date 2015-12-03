#define _USE_MATH_DEFINES
#include <math.h>
#include <Camera.hpp>

namespace Olorin
{
	namespace GameEngine
	{
		Camera::Camera(GameObject* gameObject)
			: Component(gameObject)
		{
			nearClipPlane = 0.1f;
			farClipPlane = 1000.0f;
			fieldOfView = M_PI_2;
			aspectRatio = 4 / 3.0f;
			//aspectRatio = GraphicsDevice::getViewport().getAspectRatio();

			depth = 0;
		}

		void Camera::setNearClipPlane(const float& value) { nearClipPlane = value; }
		void Camera::setFarClipPlane(const float& value) { farClipPlane = value; }
		void Camera::setFieldOfView(const float& value) { fieldOfView = value; }
		void Camera::setAspectRatio(const float& value) { aspectRatio = value; }
		void Camera::setViewport(const Viewport& value) { viewport = value; }

		const float& Camera::getNearClipPlane() const { return nearClipPlane; }
		const float& Camera::getFarClipPlane() const { return farClipPlane; }
		const float& Camera::getFieldOfView() const { return fieldOfView; }
		const float& Camera::getAspectRatio() const { return aspectRatio; }
		const Viewport& Camera::getViewport() const { return viewport; }
	}
}