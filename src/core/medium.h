//
// Created by murmur-wheel on 2020/10/23.
//

#ifndef RT_CORE_MEDIUM_H
#define RT_CORE_MEDIUM_H

namespace rt::core {
class Medium;
struct MediumInterface {
  const Medium* inside;
  const Medium* outside;

  MediumInterface() = default;
  explicit MediumInterface(const Medium* medium)
      : inside(medium), outside(medium) {}
  MediumInterface(const Medium* _inside, const Medium* _outside)
      : inside(_inside), outside(_outside) {}

  bool is_medium_transition() const { return inside != outside; }
};
}  // namespace rt::core

#endif
