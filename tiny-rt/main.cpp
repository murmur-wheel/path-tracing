#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

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

Vec3 normalize(const Vec3& v) {
  Float l = std::sqrt(dot(v, v));
  Float inv = 1.0 / l;
  return v * inv;
}

Float clamp(Float t, Float low, Float high) {
  if (t < low) return low;
  if (t > high) return high;
  return t;
}

void store(const Vec3& v, uint8_t buf[3]) {
  buf[0] = int32_t(clamp(v.x, 0, 1) * 255.f);
  buf[1] = int32_t(clamp(v.y, 0, 1) * 255.f);
  buf[2] = int32_t(clamp(v.z, 0, 1) * 255.f);
}

struct Ray {
  Vec3 origin;
  Vec3 direction;
};

struct Material {
  Vec3 emissive;
  Vec3 color;  // base color
  Vec3 Kd;     // diffuse factor
  Vec3 ks;     // specular factor
};

struct HitInfo {
  Vec3 position;
  Vec3 normal;
  Material* material = nullptr;
};

class Sphere {
 public:
  Sphere() = default;
  explicit Sphere(const Vec3& _center, Float _radius, Material* _material)
      : center_(_center), radius_(_radius), material(_material) {}

  virtual bool intersects(const Ray& ray, Float* t_hit,
                          HitInfo* hit_info) const {
    auto v = ray.origin - center_;
    Float a = dot(ray.direction, ray.direction);
    Float b = 2 * dot(v, ray.direction);
    Float c = dot(v, v) - radius_ * radius_;
    Float D = b * b - 4 * a * c;
    if (D < 0) {
      return false;
    }

    Float d = std::sqrt(D);
    Float t = (b - d) / (2 * a);
    if (t < 0) {
      t = (b + d) / (2 * a);
    }

    *t_hit = t;
    if (hit_info) {
      hit_info->position = ray.origin + ray.direction * t;
      hit_info->normal = normalize(hit_info->position - center_);
      hit_info->material = material;
    }

    return true;
  }

 private:
  Vec3 center_;
  Float radius_ = 0;
  Material* material = nullptr;
};

struct Scene {
  std::vector<Sphere*> spheres;
};

struct PerspectiveCamera {
  Vec3 center;
  Vec3 up_dir;
  Vec3 to_dir;
  Float fov_angle = 0;
  Float aspect = 0;

  void generate_ray(float film_u, float film_v, Ray* ray) const {}
};

void setup_camera(PerspectiveCamera* camera) {}
void setup_scene(Scene* scene) {}
void render(const PerspectiveCamera* camera, const Scene* scene, int width,
            int height, const std::string& output) {
  uint8_t* buf = new uint8_t[640 * 480 * 3];

  for (int x = 0; x < width; ++x) {
    for (int y = 0; y < height; ++y) {
      Vec3 color;
      int grid_x = x / 32, grid_y = y / 32;
      if ((grid_x + grid_y) % 2) {
        color = Vec3(1);
      }
      store(color, buf + (x + y * width) * 3);
    }
  }

  stbi_write_png(output.c_str(), width, height, 3, buf, width * 3);
  delete[] buf;
}

int main(int argc, char* argv[]) {
  PerspectiveCamera camera;
  setup_camera(&camera);
  Scene scene;
  setup_scene(&scene);
  render(&camera, &scene, 640, 480, "color.png");
}