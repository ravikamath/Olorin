#include <Triangle.hpp>

namespace Olorin
{
	namespace Framework
	{
		Triangle::Triangle(const Vector3& a, const Vector3& b, const Vector3& c)
		{
			vertices[0] = a;
			vertices[1] = b;
			vertices[2] = c;
		}

		const Vector3 Triangle::getCentroid() const
		{
			return (vertices[0] + vertices[1] + vertices[2]) / 3;
		}

		const float Triangle::getArea() const
		{
			return ((vertices[1] - vertices[0]) ^ (vertices[2] - vertices[0])).getLength() / 2;
		}

		const Vector3 Triangle::getNormal() const
		{
			return Vector3::normalize((vertices[1] - vertices[0]) ^ (vertices[2] - vertices[0]));
		}

		const Plane Triangle::getPlane() const
		{
			return Plane(vertices[0], (vertices[1] - vertices[0]) ^ (vertices[2] - vertices[0]));
		}
	}
}