//
// Created by murmur-wheel on 2020/10/24.
//

#ifndef RT_CORE_SPECTRUM_H
#define RT_CORE_SPECTRUM_H

#include "common.h"
#include "linear_math.h"

namespace rt::core {
inline void RGB_to_XYZ(const Float rgb[3], Float xyz[3]) {
  xyz[0] = 0.412453f * rgb[0] + 0.357580f * rgb[1] + 0.180423f * rgb[2];
  xyz[1] = 0.212671f * rgb[0] + 0.715160f * rgb[1] + 0.072169f * rgb[2];
  xyz[2] = 0.019334f * rgb[0] + 0.119193f * rgb[1] + 0.950227f * rgb[2];
}

inline void XYZ_to_RGB(const Float xyz[3], Float rgb[3]) {
  rgb[0] = 3.240479f * xyz[0] - 1.537150f * xyz[1] - 0.498535f * xyz[2];
  rgb[1] = -0.969256f * xyz[0] + 1.875991f * xyz[1] + 0.041556f * xyz[2];
  rgb[2] = 0.055648f * xyz[0] - 0.204043f * xyz[1] + 1.057311f * xyz[2];
}

template <int SpectrumSamples>
struct CoefficientSpectrum {
 public:
  using Self = CoefficientSpectrum<SpectrumSamples>;

  CoefficientSpectrum() : c_{} {}
  explicit CoefficientSpectrum(Float v) {
    for (int i = 0; i < SpectrumSamples; ++i) {
      c_[i] = v;
    }
  }

  Float& operator[](int i) { return c_[i]; }
  const Float& operator[](int i) const { return c_[i]; }

  Self operator+(const Self& rhs) const {
    Self res;
    for (int i = 0; i < SpectrumSamples; ++i) {
      res.c_[i] = c_[i] + rhs.c_[i];
    }
    return res;
  }
  Self& operator+=(const Self& rhs) {
    for (int i = 0; i < SpectrumSamples; ++i) {
      c_[i] += rhs.c_[i];
    }
    return *this;
  }

  Self operator-(const Self& rhs) const {
    Self res;
    for (int i = 0; i < SpectrumSamples; ++i) {
      res.c_[i] = c_[i] - rhs.c_[i];
    }
    return res;
  }
  Self& operator-=(const Self& rhs) {
    for (int i = 0; i < SpectrumSamples; ++i) {
      c_[i] -= rhs.c_[i];
    }
    return *this;
  }

  Self operator*(const Self& rhs) const {
    Self res;
    for (int i = 0; i < SpectrumSamples; ++i) {
      res.c_[i] = c_[i] * rhs.c_[i];
    }
    return res;
  }
  Self& operator*=(const Self& rhs) {
    for (int i = 0; i < SpectrumSamples; ++i) {
      c_[i] *= rhs.c_[i];
    }
    return *this;
  }
  template <int N>
  friend CoefficientSpectrum<N> operator*(Float lhs,
                                          const CoefficientSpectrum<N>& rhs) {
    CoefficientSpectrum<N> res;
    for (int i = 0; i < N; ++i) {
      res.c_[i] = lhs * rhs.c_[i];
    }
    return res;
  }

  Self operator/(const Self& rhs) const {
    Self res;
    for (int i = 0; i < SpectrumSamples; ++i) {
      res.c_[i] = c_[i] / rhs.c_[i];
    }
    return res;
  }

  bool operator==(const Self& rhs) const {
    for (int i = 0; i < SpectrumSamples; ++i) {
      if (c_[i] != rhs.c_[i]) {
        return false;
      }
    }
    return true;
  }

  bool operator!=(const Self& rhs) const { return !((*this) == rhs); }

  Self operator-() const {
    Self res;
    for (int i = 0; i < SpectrumSamples; ++i) {
      res.c_[i] = -c_[i];
    }
    return res;
  }

  std::string to_string() const {
    std::string s = "[";
    for (int i = 0; i < SpectrumSamples; ++i) {
      s += std::to_string(c_[i]);
      if (i + 1 < SpectrumSamples) {
        s += ", ";
      }
    }
    s += "]";
    return s;
  }

  bool is_black() const {
    for (int i = 0; i < SpectrumSamples; ++i) {
      if (c_[i] != 0) {
        return false;
      }
    }
    return true;
  }

  Self clamp(Float low, Float high = Infinity) const {
    Self res;
    for (int i = 0; i < SpectrumSamples; ++i) {
      res.c_[i] = ::rt::core::clamp(res.c_[i], low, high);
    }
    return res;
  }

  bool has_NaNs() const {
    for (int i = 0; i < SpectrumSamples; ++i) {
      if (std::isnan(c_[i])) {
        return true;
      }
    }
    return false;
  }

  static Self sqrt(const Self& t) {
    Self res;
    for (int i = 0; i < SpectrumSamples; ++i) {
      res.c_[i] = std::sqrt(t.c_[i]);
    }

    DCHECK(!t.has_NaNs());

    return res;
  }

  static Self pow(const Self& s, Float a) {
    Self res;
    for (int i = 0; i < SpectrumSamples; ++i) {
      res.c_[i] = std::pow(s.c_[i], a);
    }
    return res;
  }

  static const int num_samples = SpectrumSamples;

 protected:
  Float c_[SpectrumSamples];
};

struct RGBSpectrum : public CoefficientSpectrum<3> {
  RGBSpectrum() = default;
  explicit RGBSpectrum(Float v) : CoefficientSpectrum<3>(v) {}
  explicit RGBSpectrum(const CoefficientSpectrum<3>& s)
      : CoefficientSpectrum<3>(s) {}

  static RGBSpectrum from_XYZ(const Float xyz[3]) {
    RGBSpectrum res;
    XYZ_to_RGB(xyz, res.c_);
    return res;
  }

  void to_XYZ(Float xyz[3]) const { RGB_to_XYZ(c_, xyz); }

  static RGBSpectrum from_RGB(const Float rgb[3]) {
    RGBSpectrum res;
    res.c_[0] = rgb[0];
    res.c_[1] = rgb[1];
    res.c_[2] = rgb[2];
    return res;
  }

  void to_RGB(Float rgb[3]) const {
    rgb[0] = c_[0];  // r
    rgb[1] = c_[1];  // g
    rgb[2] = c_[2];  // b
  }

  const RGBSpectrum& toRGBSpectrum() const { return *this; }
  static RGBSpectrum form_Sampled(const Float* lamdba, const Float* v, int n) {
    assert(!"no impl");
    RGBSpectrum res;
    return res;
  }

  Float luminance() const {
    assert(!"no impl");
    return 0;
  }
};

template <int N>
CoefficientSpectrum<N> lerp(Float t, const CoefficientSpectrum<N>& s1,
                            const CoefficientSpectrum<N>& s2) {
  return (1 - t) * s1 + t * s2;
}

template <int N>
CoefficientSpectrum<N> sqrt(const CoefficientSpectrum<N>& s) {
  return CoefficientSpectrum<N>::sqrt(s);
}

template <int N>
CoefficientSpectrum<N> pow(const CoefficientSpectrum<N>& s, Float a) {
  return CoefficientSpectrum<N>::pow(s, a);
}

using Spectrum = RGBSpectrum;
}  // namespace rt::core

#endif