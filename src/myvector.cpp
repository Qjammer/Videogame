#include "myvector.hpp"

double myVector::scalarProd(const myVector& v) const{
	return (this->x*v.x+this->y*v.y);
}

double myVector::vectProd(const myVector& v) const{
	return (this->x*v.y-this->y*v.x);
}

double myVector::norm() const{
	return sqrt(pow(this->x,2)+pow(this->y,2));
}

double myVector::angle(const myVector& v) const{
	if(this->vectProd(v)>0){
		return acos(this->scalarProd(v)/(this->norm()*v.norm()));
	} else {
		return 2*Pi-acos(this->scalarProd(v)/(this->norm()*v.norm()));
	}
}

myVector myVector::proj(const myVector& v) const{
	return (v*(this->norm()*cos(this->angle(v))/v.norm()));
}

myVector myVector::orth() const{
	return myVector(this->y,-this->x);
}

myVector myVector::reflex(const myVector& normal) const{
	return *this-this->proj(normal.orth())*2;
}

myVector::myVector(const double _x=0.0, const double _y=0.0) : x(_x),y(_y){}

myVector::myVector() : x(0), y(0) {}

myVector::myVector(const myVector& v) : x(v.x), y(v.y){}

myVector myVector::unit() const{
	float n=this->norm();
	if(n==0){return *this;}
	return *this/this->norm();
}

myVector myVector::operator*(const double s) const{
	return myVector(this->x*s,this->y*s);
}

myVector myVector::operator/(const double s) const{
	return myVector(this->x/s,this->y/s);
}

myVector myVector::operator+(const myVector& v) const{
	return myVector(this->x+v.x,this->y+v.y);
}

myVector myVector::operator+=(const myVector& v){
	return *this=*this+v;
}

myVector myVector::operator-(const myVector& v) const{
	return myVector(this->x-v.x,this->y-v.y);
}

myVector& myVector::operator=(const myVector v){
	this->x=v.x;
	this->y=v.y;
	return *this;
}

std::ostream& operator<<(std::ostream& os,const myVector& v){
	os<<"["<<v.x<<","<<v.y<<"]";
	return os;
}
