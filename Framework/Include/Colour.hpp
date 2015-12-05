#ifndef __OLORIN_COLOR__
#define __OLORIN_COLOR__

#include <FrameworkDLL.hpp>
#include <Vector3.hpp>
#include <Vector4.hpp>

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
			Colour(const unsigned char& r, const unsigned char& g,
				const unsigned char& b, const unsigned char& a = 255);

			unsigned char& operator [](const int& index);
			const unsigned char& getR() const;
			const unsigned char& getG() const;
			const unsigned char& getB() const;
			const unsigned char& getA() const;

			void setR(const unsigned char& value);
			void setG(const unsigned char& value);
			void setB(const unsigned char& value);
			void setA(const unsigned char& value);

			const Colour& operator =(const Colour& rhs);
			const Colour& operator *=(const Colour& rhs);
			const Colour& operator +=(const Colour& rhs);
			const Colour& operator -=(const Colour& rhs);

			const Vector3 toVector3() const;
			const Vector4 toVector4() const;
		};

		FRAMEWORK_DLL const Colour operator *(const Colour& lhs, const Colour& rhs);
		FRAMEWORK_DLL const Colour operator +(const Colour& lhs, const Colour& rhs);
		FRAMEWORK_DLL const Colour operator -(const Colour& lhs, const Colour& rhs);
	}
}

#endif