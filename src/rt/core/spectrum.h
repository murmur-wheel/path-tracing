//
// Created by murmur-wheel on 2020/10/24.
//

#ifndef RT_CORE_SPECTRUM_H
#define RT_CORE_SPECTRUM_H

#include "common.h"

namespace rt::core {

template <size_t Samples>
struct CoefficientSpectrum {
 public:
  using Self = CoefficientSpectrum<Samples>;

  CoefficientSpectrum() : c_{} {}
  explicit CoefficientSpectrum(Float v) {
    for (int i = 0; i < Samples; ++i) {
      c_[i] = v;
    }
  }

  Float& operator[](int i) { return c_[i]; }
  const Float& operator[](int i) const { return c_[i]; }

  Self operator+(const Self& rhs) const {
    Self res;
    for (int i = 0; i < Samples; ++i) {
      res.c_[i] = c_[i] + rhs.c_[i];
    }
    return res;
  }
  Self& operator+=(const Self& rhs) {
    for (int i = 0; i < Samples; ++i) {
      c_[i] += rhs.c_[i];
    }
    return *this;
  }

  Self operator-(const Self& rhs) const {
    Self res;
    for (int i = 0; i < Samples; ++i) {
      res.c_[i] = c_[i] - rhs.c_[i];
    }
    return res;
  }
  Self& operator-=(const Self& rhs) {
    for (int i = 0; i < Samples; ++i) {
      c_[i] -= rhs.c_[i];
    }
    return *this;
  }

  Self operator*(const Self& rhs) const {
    Self res;
    for (int i = 0; i < Samples; ++i) {
      res.c_[i] = c_[i] * rhs.c_[i];
    }
    return res;
  }
  Self& operator*=(const Self& rhs) {
    for (int i = 0; i < Samples; ++i) {
      c_[i] *= rhs.c_[i];
    }
    return *this;
  }

  Self operator/(const Self& rhs) const {
    Self res;
    for (int i = 0; i < Samples; ++i) {
      res.c_[i] = c_[i] / rhs.c_[i];
    }
    return res;
  }

  bool operator==(const Self& rhs) const {
    for (int i = 0; i < Samples; ++i) {
      if (c_[i] != rhs.c_[i]) {
        return false;
      }
    }
    return true;
  }

  bool operator!=(const Self& rhs) const { return !((*this) == rhs); }

  std::string to_string() const {
    std::string s = "[";
    for (int i = 0; i < Samples; ++i) {
      s += std::to_string(c_[i]);
      if (i + 1 < Samples) {
        s += ", ";
      }
    }
    s += "]";
    return s;
  }

 private:
  Float c_[Samples];
};

struct RGBSpectrum : public CoefficientSpectrum<3> {
  RGBSpectrum() = default;
  explicit RGBSpectrum(Float v) : CoefficientSpectrum<3>(v) {}
};

using Spectrum = RGBSpectrum;
}  // namespace rt::core

#endif