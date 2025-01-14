#include <virtual-casing.h>
#include <virtual-casing.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void GenerateVirtualCasingTestDataF(float* Bext, float* Bint, long Nt, long Np, const float* X) {
  std::vector<float> Bext_(3*Nt*Np);
  std::vector<float> Bint_(3*Nt*Np);
  const std::vector<float> X_(X, X+3*Nt*Np);
  VirtualCasingTestData<float>::BFieldData(Bext_, Bint_, Nt, Np, X_);
  for (long i = 0; i < 3*Nt*Np; i++) {
    Bext[i] = Bext_[i];
    Bint[i] = Bint_[i];
  }
}

void GenerateVirtualCasingTestDataD(double* Bext, double* Bint, long Nt, long Np, const double* X) {
  std::vector<double> Bext_(3*Nt*Np);
  std::vector<double> Bint_(3*Nt*Np);
  const std::vector<double> X_(X, X+3*Nt*Np);
  VirtualCasingTestData<double>::BFieldData(Bext_, Bint_, Nt, Np, X_);
  for (long i = 0; i < 3*Nt*Np; i++) {
    Bext[i] = Bext_[i];
    Bint[i] = Bint_[i];
  }
}

void* VirtualCasingCreateContextF() {
  return new VirtualCasing<float>;
}
void* VirtualCasingCreateContextD() {
  return new VirtualCasing<double>;
}

void VirtualCasingDestroyContextF(void** ctx) {
  delete (VirtualCasing<float>*)*ctx;
  ctx[0] = nullptr;
}
void VirtualCasingDestroyContextD(void** ctx) {
  delete (VirtualCasing<double>*)*ctx;
  ctx[0] = nullptr;
}

void VirtualCasingSetSurfaceF(long Nt, long Np, const float* X, void* ctx) {
  VirtualCasing<float>& virtual_casing = *(VirtualCasing<float>*)ctx;
  const std::vector<float> X_(X, X+3*Nt*Np);
  virtual_casing.SetSurface(Nt, Np, X_);
}
void VirtualCasingSetSurfaceD(long Nt, long Np, const double* X, void* ctx) {
  VirtualCasing<double>& virtual_casing = *(VirtualCasing<double>*)ctx;
  const std::vector<double> X_(X, X+3*Nt*Np);
  virtual_casing.SetSurface(Nt, Np, X_);
}

void VirtualCasingSetAccuracyF(int digits, void* ctx) {
  VirtualCasing<float>& virtual_casing = *(VirtualCasing<float>*)ctx;
  virtual_casing.SetAccuracy(digits);
}
void VirtualCasingSetAccuracyD(int digits, void* ctx) {
  VirtualCasing<double>& virtual_casing = *(VirtualCasing<double>*)ctx;
  virtual_casing.SetAccuracy(digits);
}

void VirtualCasingComputeBextF(float* Bext, const float* B, long Nt, long Np, const void* ctx) {
  std::vector<float> Bext_(3*Nt*Np);
  const std::vector<float> B_(B, B+3*Nt*Np);
  const VirtualCasing<float>& virtual_casing = *(VirtualCasing<float>*)ctx;
  virtual_casing.ComputeBext(Bext_, B_);
  for (long i = 0; i < 3*Nt*Np; i++) Bext[i] = Bext_[i];
}
void VirtualCasingComputeBextD(double* Bext, const double* B, long Nt, long Np, const void* ctx) {
  std::vector<double> Bext_(3*Nt*Np);
  const std::vector<double> B_(B, B+3*Nt*Np);
  const VirtualCasing<double>& virtual_casing = *(VirtualCasing<double>*)ctx;
  virtual_casing.ComputeBext(Bext_, B_);
  for (long i = 0; i < 3*Nt*Np; i++) Bext[i] = Bext_[i];
}

#ifdef __cplusplus
}
#endif
