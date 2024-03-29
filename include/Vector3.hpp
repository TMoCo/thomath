/*
* AUTHOR: THOMAS MOENO COOPER
* LAST MODIFIED: 15/12/2021
* COPYRIGHT UNDER THE MIT LICENSE
*/

//
// Vector3 class declaration
//

#ifndef VECTOR3_H
#define VECTOR3_H 1

#include <iostream>
#include <cmath>

#ifdef __x86_64__
  #include <immintrin.h>
#else
  #include <sse2neon.h>
#endif

constexpr size_t SIZE_OF_VEC3 = 0xc;

typedef class Vector3 {
public:
  constexpr Vector3() : _v{} {}

  constexpr Vector3(float value) : _v{ value, value, value } {}

  constexpr Vector3(float X, float Y, float Z) : _v{ X, Y, Z } {}

  constexpr Vector3(const float* values) : _v{ values[0], values[1], values[2] } {}

  constexpr Vector3(const Vector3& other) : _v{ other.x, other.y, other.z } {}

  Vector3& operator =(const Vector3& other);

  bool operator ==(const Vector3& other) const;

  Vector3& operator +=(const Vector3& other);

  Vector3& operator -=(const Vector3& other);

  Vector3& operator /=(const Vector3& other);

  Vector3& operator *=(const Vector3& other);

  Vector3& operator /=(const float& other);

  Vector3& operator *=(const float& factor);

  friend inline Vector3 operator +(Vector3 lhs, const Vector3& rhs) 
  {
    return lhs += rhs;
  }

  friend inline Vector3 operator -(Vector3 lhs, const Vector3& rhs) 
  {
    return lhs -= rhs;
  }

  friend inline Vector3 operator /(Vector3 lhs, const Vector3& rhs) 
  {
    return lhs /= rhs;
  }

  friend inline Vector3 operator *(Vector3 lhs, const Vector3& rhs) 
  {
    return lhs *= rhs;
  }

  Vector3 operator -() const;

  float& operator [](const uint32_t index);

  const float& operator [](const uint32_t index) const;
    
  float dot(const Vector3& other) const;

  Vector3 cross(const Vector3& other) const;

  float length() const;

  float lengthSquared() const;

  Vector3 normalize() const;

  bool isZeroVector() const;

  static Vector3 reflect(const Vector3& v, const Vector3& normal);

  static Vector3 refract(const Vector3& v, const Vector3& normal, const float& iorRatio);

private:
  union {
    float _v[3];
    struct {
      float x, y, z; 
    };
  };

} Vector3;


Vector3 operator /(Vector3 lhs, const float& rhs);

Vector3 operator /(const float lhs, Vector3& rhs);

Vector3 operator *(const float& lhs, Vector3 rhs);

Vector3 operator *(Vector3 lhs, const float& rhs);

std::istream& operator >> (std::istream& inStream, Vector3& vector);

std::ostream& operator << (std::ostream& outStream, const Vector3& vector);

#endif // ! VECTOR3_H
