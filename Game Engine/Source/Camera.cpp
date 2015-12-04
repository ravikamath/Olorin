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
			fieldOfView = float(M_PI_2);
			aspectRatio = 4 / 3.0f;
			//aspectRatio = GraphicsDevice::getViewport().getAspectRatio();

			depth = 0;
		}

		void Camera::setNearClipPlane(const float& value) { nearClipPlane = value; }
		void Camera::setFarClipPlane(const float& value) { farClipPlane = value; }
		void Camera::setFieldOfView(const float& value) { fieldOfView = value; }
		void Camera::setAspectRatio(const float& value) { aspectRatio = value; }
		void Camera::setViewport(const Viewport& value) { viewport = value; }
		void Camera::setDepth(const float& value) { depth = value; }

		const float& Camera::getNearClipPlane() const { return nearClipPlane; }
		const float& Camera::getFarClipPlane() const { return farClipPlane; }
		const float& Camera::getFieldOfView() const { return fieldOfView; }
		const float& Camera::getAspectRatio() const { return aspectRatio; }
		const Viewport& Camera::getViewport() const { return viewport; }
		const float& Camera::getDepth() const { return depth; }

		const Matrix4 Camera::getView() const
		{
			return Matrix4::createLookAt(getTransform()->getPosition(),
				getTransform()->getForward(), getTransform()->getUp());
		}

		const Matrix4 Camera::getProjection() const
		{
			return Matrix4::createPerspective(fieldOfView, aspectRatio, nearClipPlane, farClipPlane);
		}
	}
}