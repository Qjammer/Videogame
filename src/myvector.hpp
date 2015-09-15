#ifndef MYVECTOR_H_
#define MYVECTOR_H_

#include <string>
#include <cmath>
#include <istream>


class myVector{
	public:
		double x=0;
		double y=0;
		double scalarProd(const myVector& v) const;
		double vectProd(const myVector& v) const;
		double norm() const;
		double angle(const myVector& v) const;
		myVector proj(const myVector& v) const;
		myVector orth() const;
		myVector reflex(const myVector& normal) const;
		myVector(const double x, const double y);
		myVector();
		myVector(const myVector& v);
		myVector operator*(const double s) const;
		myVector operator/(const double s) const;
		myVector operator+(const myVector& v) const;
		myVector operator+=(const myVector& v);
		myVector operator-(const myVector& v) const;
		myVector& operator=(const myVector v);
		friend std::ostream& operator<<(std::ostream& os,const myVector& v);
		myVector unit() const;//Unit vector
};

std::ostream& operator<<(std::ostream& os,const myVector& v);

extern const double Pi;

#endif