#include <cmath>
#include <cstdlib>
#include <vector>

using Float = float;

struct Vec3 {
  Float x, y, z;

  Vec3() : x(0), y(0), z(0) {}
  explicit Vec3(Float a) : x(a), y(a), z(a) {}
  explicit Vec3(Float _x, Float _y, Float _z) : x(_x), y(_y), z(_z) {}

  Vec3 operator+(const Vec3& rhs) const {
    return Vec3(x + rhs.x, y + rhs.y, z + rhs.z);
  }
  Vec3& operator+=(const Vec3& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
  }

  Vec3 operator-(const Vec3& rhs) const {
    return Vec3(x - rhs.x, y - rhs.y, z - rhs.z);
  }
  Vec3& operator-=(const Vec3& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
  }

  Vec3 operator*(const Vec3& rhs) const {
    return Vec3(x * rhs.x, y * rhs.y, z * rhs.z);
  }
  Vec3 operator*(Float rhs) const { return Vec3(x * rhs, y * rhs, z * rhs); }
  Vec3& operator*=(const Vec3& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    return *this;
  }

  Vec3 operator/(const Vec3& rhs) const {
    return Vec3(x / rhs.x, y * rhs.y, z * rhs.z);
  }
  Vec3& operator/=(const Vec3& rhs) {
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    return *this;
  }
};

Vec3 operator*(Float lhs, const Vec3& rhs) { return rhs * lhs; }

Vec3 cross(const Vec3& v1, const Vec3& v2) {
  Float x = v1.y * v2.z - v1.z * v2.y;
  Float y = v1.z * v2.x - v1.x * v2.z;
  Float z = v1.x * v2.y - v1.y * v2.x;
  return Vec3(x, y, z);
}

Float dot(const Vec3& v1, const Vec3& v2) {
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vec3 sqrt(const Vec3& v) {
  float inv = 1 / std::sqrt(dot(v, v));
  return v * inv;
}

struct Ray {
  Vec3 origin;
  Vec3 direction;
};

struct Material {
  Vec3 emissive;
  Vec3 Kd;  // diffuse factor
  Vec3 ks;  // specular factor
};

struct Sphere {
  Vec3 center;
  Float radius = 0;

  const Material* material = nullptr;

  Sphere() = default;
  explicit Sphere(const Vec3& _center, Float _radus, const Material* _material)
      : center(_center), radius(_radus), material(_material) {}
};

struct Scene {
  std::vector<Sphere*> shapes;
};

struct PerspectiveCamera {
  Vec3 center;
  Vec3 up_dir;
  Vec3 to_dir;
  Float fov_angle = 0;
  Float aspect = 0;

  void generate_ray(float film_u, float film_v, Ray* ray) const {}
};

void setup_camera() {}
void setup_scene() {}
void render() {}
void save_result() {}

int main(int argc, char* argv[]) {
  PerspectiveCamera camera;
  Scene scene;

  setup_camera();
  setup_scene();
  render();
  save_result();
}