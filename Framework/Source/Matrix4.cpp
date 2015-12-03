#include <Matrix4.hpp>
#define EPSILON 1e-06

namespace Olorin
{
	namespace Framework
	{
		Matrix4::Matrix4()
		{
			loadIdentity();
		}

		Matrix4::Matrix4(const Matrix4& source)
		{
			for (int index = 0; index < 16; index++)
				elements[index] = source.elements[index];
		}

		Matrix4::Matrix4(const float* elements)
		{
			for (int index = 0; index < 16; index++)
				this->elements[index] = elements[index];
		}

		// Accessors
		float* Matrix4::getElements() { return elements; }
		const Vector3 Matrix4::getForward() const { return (*this) * Vector3::Forward; }
		const Vector3 Matrix4::getBackward() const { return (*this) * Vector3::Backward; }
		const Vector3 Matrix4::getRight() const { return (*this) * Vector3::Right; }
		const Vector3 Matrix4::getLeft() const { return (*this) * Vector3::Left; }
		const Vector3 Matrix4::getUp() const { return (*this) * Vector3::Up; }
		const Vector3 Matrix4::getDown() const { return (*this) * Vector3::Down; }

		// Mutators
		void Matrix4::setElements(const float* elements)
		{
			for (int index = 0; index < 16; index++)
				this->elements[index] = elements[index];
		}

		// Operators - Mathematical
		float& Matrix4::operator [](const int& index)
		{
			return elements[index];
		}

		const float& Matrix4::operator [](const int& index) const
		{
			return elements[index];
		}

		float& Matrix4::operator ()(const int& col, const int& row)
		{
			return elements[col * 4 + row];
		}

		const float& Matrix4::operator ()(const int& col, const int& row) const
		{
			return elements[col * 4 + row];
		}

		const Matrix4& Matrix4:: operator =(const Matrix4& rhs)
		{
			for (int index = 0; index < 16; index++)
				elements[index] = rhs.elements[index];
			return *this;
		}

		const Matrix4& Matrix4:: operator +=(const Matrix4& rhs)
		{
			for (int index = 0; index < 16; index++)
				elements[index] += rhs.elements[index];
			return *this;
		}

		const Matrix4& Matrix4:: operator -=(const Matrix4& rhs)
		{
			for (int index = 0; index < 16; index++)
				elements[index] -= rhs.elements[index];
			return *this;
		}

		const Matrix4 Matrix4::operator *(const Matrix4& rhs) const
		{
			Matrix4 result;
			for (unsigned int col = 0; col < 4; ++col)
				for (unsigned int row = 0; row < 4; ++row)
					result(col, row) = (*this)(0, row) * rhs(col, 0) +
					(*this)(1, row) * rhs(col, 1) +
					(*this)(2, row) * rhs(col, 2) +
					(*this)(3, row) * rhs(col, 3);
			return result;
		}

		const Matrix4& Matrix4:: operator *=(const Matrix4& rhs)
		{
			return *this = *this * rhs;
		}

		const Matrix4& Matrix4:: operator *=(const float& rhs)
		{
			for (int index = 0; index < 16; index++)
				elements[index] *= rhs;
			return *this;
		}

		const Matrix4& Matrix4::operator /=(const float& scale)
		{
			return abs(scale) < EPSILON ? *this : *this *= (1.0f / scale);
		}

		const Vector4 Matrix4::operator *(const Vector4& rhs) const
		{
			Vector4 result;
			result[0] = elements[0] * rhs[0] + elements[4] * rhs[1] + elements[8] * rhs[2] + elements[12] * rhs[3];
			result[1] = elements[1] * rhs[0] + elements[5] * rhs[1] + elements[9] * rhs[2] + elements[13] * rhs[3];
			result[2] = elements[2] * rhs[0] + elements[6] * rhs[1] + elements[10] * rhs[2] + elements[14] * rhs[3];
			result[3] = elements[3] * rhs[0] + elements[7] * rhs[1] + elements[11] * rhs[2] + elements[15] * rhs[3];
			return result;
		}

		// Matrix functions
		void Matrix4::loadIdentity()
		{
			for (int index = 0; index < 16; index++)
				elements[index] = 0;
			elements[0] = elements[5] = elements[10] = elements[15] = 1;
		}

		void Matrix4::translate(const Vector3& position)
		{
			elements[12] += elements[15] * position[0];
			elements[13] += elements[15] * position[1];
			elements[14] += elements[15] * position[2];
		}

		void Matrix4::scale(const Vector3& position)
		{
			for (int index = 0; index < 12; index++)
				elements[index] *= position[index / 4];
		}

		void Matrix4::rotateAxisAngle(const Vector3& axis, const float& angle)
		{
		}

		void Matrix4::rotateQuaternion(const Quaternion& rotation)
		{
		}

		// Static methods to create matrices
		const Matrix4 Matrix4::createIdentity()
		{
			return Matrix4();
		}

		const Matrix4 Matrix4::createTranslation(const Vector3& position)
		{
			Matrix4 result;
			result.elements[12] = position[0];
			result.elements[13] = position[1];
			result.elements[14] = position[2];
			return result;
		}

		const Matrix4 Matrix4::createScale(const Vector3& scale)
		{
			Matrix4 result;
			result.elements[0] = scale[0];
			result.elements[5] = scale[1];
			result.elements[10] = scale[2];
			return result;
		}

		const Matrix4 Matrix4::createRotationAxisAngle(const Vector3& axis, const float& angle)
		{
			return Matrix4::createRotationQuaternion(Quaternion::createFromAxisAngle(axis, angle));
		}

		const Matrix4 Matrix4::createRotationQuaternion(const Quaternion& rotation)
		{
			Matrix4 result;
			float s = rotation.getReal();
			float a = rotation.getImaginary().getX();
			float b = rotation.getImaginary().getY();
			float c = rotation.getImaginary().getZ();

			result(0, 0) = 1 - 2 * b*b - 2 * c*c;
			result(1, 0) = 2 * a*b - 2 * s*c;
			result(2, 0) = 2 * a*c + 2 * s*b;

			result(0, 1) = 2 * a*b + 2 * s*c;
			result(1, 1) = 1 - 2 * a*a - 2 * c*c;
			result(2, 1) = 2 * b*c - 2 * s*a;

			result(0, 2) = 2 * a*c - 2 * s*b;
			result(1, 2) = 2 * b*c + 2 * s*a;
			result(2, 2) = 1 - 2 * a*a - 2 * b*b;

			return result;
		}

		const Matrix4 Matrix4::createLookAt(const Vector3& position, const Vector3& forward, const Vector3& up)
		{
			Vector3 n = forward.normalize();
			Vector3 u = (n ^ up).normalize();
			Vector3 v = n ^ u;

			Matrix4 result;
			result(0, 0) = u.getX(); result(1, 0) = u.getY(); result(2, 0) = u.getZ();
			result(0, 1) = v.getX(); result(1, 1) = v.getY(); result(2, 1) = v.getZ();
			result(0, 2) = n.getX(); result(1, 2) = n.getY(); result(2, 2) = n.getZ();
			result(3, 0) = position.getX(); result(3, 1) = position.getY(); result(3, 2) = position.getZ();
			return result;
		}


		// Creates the orthographic matrix - analogous to glOrtho
		// See F. S. Hill, Jr. pg 400
		const Matrix4 Matrix4::createOrtho(const float& left, const float& right, const float& bottom,
			const float& top, const float& nearPlane, const float& farPlane)
		{
			Matrix4 result;
			result(0, 0) = 2.0f / (right - left);
			result(1, 1) = 2.0f / (top - bottom);
			result(2, 2) = 2.0f / (nearPlane - farPlane);
			result(3, 0) = (left + right) / (left - right);
			result(3, 1) = (bottom + top) / (bottom - top);
			result(3, 2) = (nearPlane + farPlane) / (nearPlane - farPlane);
			return result;
		}

		// Creates the frustum matrix - analogous to glFrustum
		// See F. S. Hill, Jr. pg 385
		const Matrix4 Matrix4::createFrustum(const float& left, const float& right, const float& bottom,
			const float& top, const float& nearPlane, const float& farPlane)
		{
			Matrix4 result;
			result(0, 0) = 2 * nearPlane / (right - left);
			result(1, 1) = 2 * nearPlane / (top - bottom);
			result(2, 0) = (right + left) / (right - left);
			result(2, 1) = (top + bottom) / (top - bottom);
			result(2, 2) = (nearPlane + farPlane) / (nearPlane - farPlane);
			result(2, 3) = -1.0f;
			result(3, 2) = farPlane * nearPlane / (nearPlane - farPlane);
			result(3, 3) = 0;
			return result;
		}

		// Creates the parallel matrix using field of view information
		// See F. S. Hill, Jr. pg 400
		const Matrix4 Matrix4::createParallel(const float& fieldOfView, const float& aspectRatio,
			const float& nearPlane, const float& farPlane)
		{
			float top = nearPlane * tan(fieldOfView * 3.14159f / 360.0f);
			float right = top * aspectRatio;
			Matrix4 result;
			result(0, 0) = 1.0f / right;
			result(1, 1) = 1.0f / top;
			result(2, 2) = 2.0f / (nearPlane - farPlane);
			result(3, 2) = (nearPlane + farPlane) / (nearPlane - farPlane);
			return result;
		}

		// Creates the perspective matrix - analogous to gluPerspective
		// See F. S. Hill, Jr. pg 385
		const Matrix4 Matrix4::createPerspective(const float& fieldOfView, const float& aspectRatio,
			const float& nearPlane, const float& farPlane)
		{
			float top = nearPlane * tan(fieldOfView * 3.14159f / 360.0f);
			float right = top * aspectRatio;
			Matrix4 result;
			result(0, 0) = nearPlane / right;
			result(1, 1) = nearPlane / top;
			result(2, 2) = (nearPlane + farPlane) / (nearPlane - farPlane);
			result(2, 3) = -1.0f;
			result(3, 2) = 2 * farPlane * nearPlane / (nearPlane - farPlane);
			result(3, 3) = 0;
			return result;
		}

		// Free overloaded operators    
		const Matrix4 operator +(const Matrix4& lhs, const Matrix4& rhs)
		{
			return Matrix4(lhs) += rhs;
		}

		const Matrix4 operator -(const Matrix4& lhs, const Matrix4& rhs)
		{
			return Matrix4(lhs) -= rhs;
		}

		const Matrix4 operator *(const Matrix4& lhs, const float& rhs)
		{
			return Matrix4(lhs) *= rhs;
		}

		const Matrix4 operator *(const float& lhs, const Matrix4& rhs)
		{
			return Matrix4(rhs) *= lhs;
		}
	}
}