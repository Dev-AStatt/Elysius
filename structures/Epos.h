#include <cmath>
#include <string>
template <class T>
struct Epos2d_generic
{
    T x = 0;
    T y = 0;
    Epos2d_generic() : x(0), y(0) {}
    Epos2d_generic(T _x, T _y) : x(_x), y(_y) {}
    Epos2d_generic(const Epos2d_generic& v) : x(v.x), y(v.y) {}
    Epos2d_generic& operator=(const Epos2d_generic& v) = default;
    T mag() const { return T(std::sqrt(x * x + y * y)); }
    T mag2() const { return x * x + y * y; }
    Epos2d_generic  norm() const { T r = 1 / mag(); return Epos2d_generic(x * r, y * r); }
    Epos2d_generic  perp() const { return Epos2d_generic(-y, x); }
    Epos2d_generic  floor() const { return Epos2d_generic(std::floor(x), std::floor(y)); }
    Epos2d_generic  ceil() const { return Epos2d_generic(std::ceil(x), std::ceil(y)); }
    Epos2d_generic  max(const Epos2d_generic& v) const { return Epos2d_generic(std::max(x, v.x), std::max(y, v.y)); }
    Epos2d_generic  min(const Epos2d_generic& v) const { return Epos2d_generic(std::min(x, v.x), std::min(y, v.y)); }
    Epos2d_generic  cart() { return { std::cos(y) * x, std::sin(y) * x }; }
    Epos2d_generic  polar() { return { mag(), std::atan2(y, x) }; }
    T dot(const Epos2d_generic& rhs) const { return this->x * rhs.x + this->y * rhs.y; }
    T cross(const Epos2d_generic& rhs) const { return this->x * rhs.y - this->y * rhs.x; }
    Epos2d_generic  operator +  (const Epos2d_generic& rhs) const { return Epos2d_generic(this->x + rhs.x, this->y + rhs.y); }
    Epos2d_generic  operator -  (const Epos2d_generic& rhs) const { return Epos2d_generic(this->x - rhs.x, this->y - rhs.y); }
    Epos2d_generic  operator *  (const T& rhs)           const { return Epos2d_generic(this->x * rhs, this->y * rhs); }
    Epos2d_generic  operator *  (const Epos2d_generic& rhs) const { return Epos2d_generic(this->x * rhs.x, this->y * rhs.y); }
    Epos2d_generic  operator /  (const T& rhs)           const { return Epos2d_generic(this->x / rhs, this->y / rhs); }
    Epos2d_generic  operator /  (const Epos2d_generic& rhs) const { return Epos2d_generic(this->x / rhs.x, this->y / rhs.y); }
    Epos2d_generic& operator += (const Epos2d_generic& rhs) { this->x += rhs.x; this->y += rhs.y; return *this; }
    Epos2d_generic& operator -= (const Epos2d_generic& rhs) { this->x -= rhs.x; this->y -= rhs.y; return *this; }
    Epos2d_generic& operator *= (const T& rhs) { this->x *= rhs; this->y *= rhs; return *this; }
    Epos2d_generic& operator /= (const T& rhs) { this->x /= rhs; this->y /= rhs; return *this; }
    Epos2d_generic& operator *= (const Epos2d_generic& rhs) { this->x *= rhs.x; this->y *= rhs.y; return *this; }
    Epos2d_generic& operator /= (const Epos2d_generic& rhs) { this->x /= rhs.x; this->y /= rhs.y; return *this; }
    Epos2d_generic  operator +  () const { return { +x, +y }; }
    Epos2d_generic  operator -  () const { return { -x, -y }; }
    bool operator == (const Epos2d_generic& rhs) const { return (this->x == rhs.x && this->y == rhs.y); }
    bool operator != (const Epos2d_generic& rhs) const { return (this->x != rhs.x || this->y != rhs.y); }
    const std::string str() const { return std::string("(") + std::to_string(this->x) + "," + std::to_string(this->y) + ")"; }
    friend std::ostream& operator << (std::ostream& os, const Epos2d_generic& rhs) { os << rhs.str(); return os; }
    operator Epos2d_generic<int32_t>() const { return { static_cast<int32_t>(this->x), static_cast<int32_t>(this->y) }; }
    operator Epos2d_generic<float>() const { return { static_cast<float>(this->x), static_cast<float>(this->y) }; }
    operator Epos2d_generic<double>() const { return { static_cast<double>(this->x), static_cast<double>(this->y) }; }
};

// Note: joshinils has some good suggestions here, but they are complicated to implement at this moment,
// however they will appear in a future version of PGE
template<class T> inline Epos2d_generic<T> operator * (const float& lhs, const Epos2d_generic<T>& rhs)
{ return Epos2d_generic<T>((T)(lhs * (float)rhs.x), (T)(lhs * (float)rhs.y)); }
template<class T> inline Epos2d_generic<T> operator * (const double& lhs, const Epos2d_generic<T>& rhs)
{ return Epos2d_generic<T>((T)(lhs * (double)rhs.x), (T)(lhs * (double)rhs.y)); }
template<class T> inline Epos2d_generic<T> operator * (const int& lhs, const Epos2d_generic<T>& rhs)
{ return Epos2d_generic<T>((T)(lhs * (int)rhs.x), (T)(lhs * (int)rhs.y)); }
template<class T> inline Epos2d_generic<T> operator / (const float& lhs, const Epos2d_generic<T>& rhs)
{ return Epos2d_generic<T>((T)(lhs / (float)rhs.x), (T)(lhs / (float)rhs.y)); }
template<class T> inline Epos2d_generic<T> operator / (const double& lhs, const Epos2d_generic<T>& rhs)
{ return Epos2d_generic<T>((T)(lhs / (double)rhs.x), (T)(lhs / (double)rhs.y)); }
template<class T> inline Epos2d_generic<T> operator / (const int& lhs, const Epos2d_generic<T>& rhs)
{ return Epos2d_generic<T>((T)(lhs / (int)rhs.x), (T)(lhs / (int)rhs.y)); }

// To stop dandistine crying...
template<class T, class U> inline bool operator < (const Epos2d_generic<T>& lhs, const Epos2d_generic<U>& rhs)
{ return lhs.y < rhs.y || (lhs.y == rhs.y && lhs.x < rhs.x); }
template<class T, class U> inline bool operator > (const Epos2d_generic<T>& lhs, const Epos2d_generic<U>& rhs)
{ return lhs.y > rhs.y || (lhs.y == rhs.y && lhs.x > rhs.x); }

typedef Epos2d_generic<int32_t> Ei2d;
typedef Epos2d_generic<uint32_t> Eu2d;
typedef Epos2d_generic<float> Ef2d;
typedef Epos2d_generic<double> Ed2d;
