#include <Colour.hpp>

namespace Olorin
{
	namespace Framework
	{
		Colour::Colour()
		{
			channels[0] = channels[1] = channels[2] = channels[3] = 255;
		}

		Colour::Colour(const Colour& source)
		{
			channels[0] = source.channels[0];
			channels[1] = source.channels[1];
			channels[2] = source.channels[2];
			channels[3] = source.channels[3];
		}

		Colour::Colour(const Vector3& source)
		{
			channels[0] = unsigned char(source.getX() * 255);
			channels[1] = unsigned char(source.getY() * 255);
			channels[2] = unsigned char(source.getZ() * 255);
			channels[3] = 1;
		}

		Colour::Colour(const Vector4& source)
		{
			channels[0] = unsigned char(source.getX() * 255);
			channels[1] = unsigned char(source.getY() * 255);
			channels[2] = unsigned char(source.getZ() * 255);
			channels[3] = unsigned char(source.getW() * 255);
		}

		Colour::Colour(const unsigned char& r, const unsigned char& g, 
				const unsigned char& b, const unsigned char& a)
		{
			channels[0] = r; channels[1] = g; channels[2] = b; channels[3] = a;
		}

		unsigned char& Colour::operator [](const int& index) { return channels[index]; }
		const unsigned char& Colour::getR() const { return channels[0]; }
		const unsigned char& Colour::getG() const { return channels[1]; }
		const unsigned char& Colour::getB() const { return channels[2]; }
		const unsigned char& Colour::getA() const { return channels[3]; }

		void Colour::setR(const unsigned char& value) { channels[0] = value; }
		void Colour::setG(const unsigned char& value) { channels[1] = value; }
		void Colour::setB(const unsigned char& value) { channels[2] = value; }
		void Colour::setA(const unsigned char& value) { channels[3] = value; }

		const Colour& Colour::operator =(const Colour& rhs)
		{
			channels[0] = rhs.channels[0];
			channels[1] = rhs.channels[1];
			channels[2] = rhs.channels[2];
			channels[3] = rhs.channels[3];
			return *this;
		}

		const Colour& Colour::operator *=(const Colour& rhs)
		{
			channels[0] = unsigned char((channels[0]/255.0f * rhs.channels[0]/255.0f) * 255);
			channels[0] = unsigned char((channels[1]/255.0f * rhs.channels[1]/255.0f) * 255);
			channels[0] = unsigned char((channels[2]/255.0f * rhs.channels[2]/255.0f) * 255);
			channels[0] = unsigned char((channels[3]/255.0f * rhs.channels[3]/255.0f) * 255);
			return *this;
		}

		const Colour& Colour::operator +=(const Colour& rhs)
		{
			channels[0] = unsigned char((channels[0]/255.0f + rhs.channels[0]/255.0f) * 255);
			channels[0] = unsigned char((channels[1]/255.0f + rhs.channels[1]/255.0f) * 255);
			channels[0] = unsigned char((channels[2]/255.0f + rhs.channels[2]/255.0f) * 255);
			channels[0] = unsigned char((channels[3]/255.0f + rhs.channels[3]/255.0f) * 255);
			return *this;
		}

		const Colour& Colour::operator -=(const Colour& rhs)
		{
			channels[0] = unsigned char((channels[0]/255.0f - rhs.channels[0]/255.0f) * 255);
			channels[0] = unsigned char((channels[1]/255.0f - rhs.channels[1]/255.0f) * 255);
			channels[0] = unsigned char((channels[2]/255.0f - rhs.channels[2]/255.0f) * 255);
			channels[0] = unsigned char((channels[3]/255.0f - rhs.channels[3]/255.0f) * 255);
			return *this;
		}

		const Colour operator *(const Colour& lhs, const Colour& rhs)
		{
			return Colour(lhs) *= rhs;
		}

		const Colour operator +(const Colour& lhs, const Colour& rhs)
		{
			return Colour(lhs) += rhs;
		}

		const Colour operator -(const Colour& lhs, const Colour& rhs)
		{
			return Colour(lhs) -= rhs;
		}
	}
}