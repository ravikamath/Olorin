#ifndef __OLORIN_MATRIX4__
#define __OLORIN_MATRIX4__

#include <Quaternion.hpp>
#include <Vector4.hpp>

namespace Olorin
{
	namespace Framework
	{

		class FRAMEWORK_DLL Matrix4
		{
		private:
			// Colum Major!
			float elements[16];
		public:
			// Static constants
			static const Matrix4 Identity;

			// Constructors
			Matrix4();
			Matrix4(const Matrix4& source);
			Matrix4(const float* elements);

			// Accessors
			float* getElements();
			const Vector3 getForward() const;
			const Vector3 getBackward() const;
			const Vector3 getUp() const;
			const Vector3 getDown() const;
			const Vector3 getRight() const;
			const Vector3 getLeft() const;

			// Mutators
			void setElements(const float* elements);

			// Operators
			float& operator [](const int& index);
			const float& operator [](const int& index) const;
			float& operator ()(const int& col, const int& row);
			const float& operator ()(const int& col, const int& row) const;
			const Matrix4& operator =(const Matrix4& rhs);
			const Matrix4& operator +=(const Matrix4& rhs);
			const Matrix4& operator -=(const Matrix4& rhs);
			const Matrix4 operator *(const Matrix4& rhs) const;
			const Matrix4& operator *=(const Matrix4& rhs);
			const Matrix4& operator *=(const float& rhs);
			const Matrix4& operator /=(const float& rhs);
			const Vector4 operator *(const Vector4& rhs) const;

			// Matrix manipulation methods
			void loadIdentity();
			void translate(const Vector3& position);
			void scale(const Vector3& scale);
			void rotateAxisAngle(const Vector3& axis, const float& angle);
			void rotateQuaternion(const Quaternion& rotation);

			// Static functions
			static const Matrix4 createIdentity();
			static const Matrix4 createTranslation(const Vector3& position);
			static const Matrix4 createScale(const Vector3& scale);
			static const Matrix4 createRotationAxisAngle(const Vector3& axis, const float& angle);
			static const Matrix4 createRotationQuaternion(const Quaternion& rotation);

			// Generates a Camera Matrix using the given parameters
			static const Matrix4 createLookAt(const Vector3& position, const Vector3& forward, const Vector3& up);

			// Creates an orthographic projection matrix
			static const Matrix4 createOrtho(const float& left, const float& right,
				const float& bottom, const float& top, const float& nearPlane, const float& farPlane);
			// Creates a view frustum projection matrix
			static const Matrix4 createFrustum(const float& left, const float& right,
				const float& bottom, const float& top, const float& nearPlane, const float& farPlane);
			// Creates a parallel projection matrix
			static const Matrix4 createParallel(const float& fieldOfView, const float& aspectRatio,
				const float& nearPlane, const float& farPlane);
			// Creates a perspective projection matrix
			static const Matrix4 createPerspective(const float& fieldOfView, const float& aspectRatio,
				const float& nearPlane, const float& farPlane);
		};

		FRAMEWORK_DLL const Matrix4 operator +(const Matrix4& lhs, const Matrix4& rhs);
		FRAMEWORK_DLL const Matrix4 operator -(const Matrix4& lhs, const Matrix4& rhs);
		FRAMEWORK_DLL const Matrix4 operator *(const Matrix4& lhs, const float& rhs);
		FRAMEWORK_DLL const Matrix4 operator *(const float& lhs, const Matrix4& rhs);
	}
}

#endif