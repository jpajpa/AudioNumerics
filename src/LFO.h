
// Created by jan aguirre on 11/05/2026.
//

#ifndef AUDIONUMERICS_LFO_H
#define AUDIONUMERICS_LFO_H

#include <chrono>
#include <cmath>
#include <numbers>

class LFO {
public:
  enum class Shape { Sine, Cosine, Tangent };
  LFO() = default;
  LFO(float amplitude_, float frequency_, float phase_, Shape shape_);
  void setAmplitude(float amplitude_);
  void setFrequency(float frequency_);
  void setPhase(float phase_);
  void setShape(Shape shape_);
  void setParameters(float amplitude_, float frequency_, float phase_,
                     Shape shape_);
  [[nodiscard]] float getAmplitude() const;
  [[nodiscard]] float getFrequency() const;
  [[nodiscard]] float getPhase() const;
  [[nodiscard]] Shape getShape() const;
  [[nodiscard]] double getValue() const;

private:
  inline const static auto initTime = std::chrono::steady_clock::now();
  float amplitude{1.0};
  float frequency{1.0};
  float phase{0.0};
  Shape shape{Shape::Sine};
}; // class LFOUtils

inline LFO::LFO(const float amplitude_, const float frequency_,
                const float phase_, const Shape shape_) {
  setParameters(amplitude_, frequency_, phase_, shape_);
}

inline void LFO::setAmplitude(const float amplitude_) {
  amplitude = amplitude_;
}

inline void LFO::setFrequency(const float frequency_) {
  frequency = frequency_;
}

inline void LFO::setPhase(const float phase_) { phase = phase_; }

inline void LFO::setShape(const Shape shape_) { shape = shape_; }

inline void LFO::setParameters(const float amplitude_, const float frequency_,
                               const float phase_, const Shape shape_) {
  amplitude = amplitude_;
  frequency = frequency_;
  phase = phase_;
  shape = shape_;
}

inline float LFO::getAmplitude() const { return amplitude; }

inline float LFO::getFrequency() const { return frequency; }

inline float LFO::getPhase() const { return phase; }

inline LFO::Shape LFO::getShape() const { return shape; }

double LFO::getValue() const {
  const auto now = std::chrono::steady_clock::now();
  const auto elapsed = now - initTime;
  const double seconds = std::chrono::duration<double>(elapsed).count();

  const double formula = 2.0 * std::numbers::pi * seconds * frequency + phase;

  switch (shape) {
  case Shape::Sine:
    return amplitude * std::sin(formula); // A * sin(2*pi*f*t + phi)

  case Shape::Cosine:
    return amplitude * std::cos(formula); // A * sin(2*pi*f*t + phi)

  case Shape::Tangent:
    return amplitude * std::tan(formula); // A * sin(2*pi*f*t + phi)

  default:
    return {0.0};
  }
}

#endif // AUDIONUMERICS_LFO_H
