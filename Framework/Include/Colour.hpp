#ifndef __OLORIN_COLOR__
#define __OLORIN_COLOR__

#include <FrameworkDLL.hpp>
#include <Vector3.hpp>

namespace Olorin
{
	namespace Framework
	{
		class FRAMEWORK_DLL Colour
		{
		private:
			unsigned char channels[4];
		public:
			Colour();
			Colour(const Colour& source);
			Colour(const Vector3& source);
			Colour(const Vector4& source);
			Colour(const unsigned char& r, const unsigned char& g, const unsigned char& b, const unsigned char& a);

			unsigned char& operator [](const int& index);

			const Colour& operator *=(const Colour& rhs);
			const Colour& operator +=(const Colour& rhs);
			const Colour& operator -=(const Colour& rhs);
		};

		const Colour operator +(const Colour& lhs, const Colour& rhs);
		const Colour operator -(const Colour& lhs, const Colour& rhs);
		const Colour operator *(const Colour& lhs, const Colour& rhs);
	}
}

#endif