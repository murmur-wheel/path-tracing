//
// Created by murmur-wheel on 2020/10/22.
//

#ifndef RT_CAMERA_PROJECTIVE_CAMERA_H
#define RT_CAMERA_PROJECTIVE_CAMERA_H

#include "../core/camera.h"

namespace rt::camera {
class ProjectiveCamera : public core::Camera {};

class PerspectiveCamera : public ProjectiveCamera {};

class OrthographicCamera : public ProjectiveCamera {};
}  // namespace rt::camera

#endif