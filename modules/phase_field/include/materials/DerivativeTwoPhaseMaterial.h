#ifndef DERIVATIVETWOPHASEMATERIAL_H
#define DERIVATIVETWOPHASEMATERIAL_H

#include "DerivativeBaseMaterial.h"

// Forward Declarations
class DerivativeTwoPhaseMaterial;

template<>
InputParameters validParams<DerivativeTwoPhaseMaterial>();

/**
 * DerivativeMaterial child class to evaluate a parsed function for the
 * free energy and automatically provide all derivatives.
 * This requires the autodiff patch (https://github.com/libMesh/libmesh/pull/238)
 * to Function Parser in libmesh.
 */
class DerivativeTwoPhaseMaterial : public DerivativeBaseMaterial
{
public:
  DerivativeTwoPhaseMaterial(const std::string & name,
                             InputParameters parameters);

protected:
  static InputParameters AddArg(InputParameters params, VariableName var_name);

  virtual unsigned int expectedNumArgs();

  std::string _fa_name;
  std::string _fb_name;

  VariableValue & _phi;

  Real _W;
};

#endif // DERIVATIVETWOPHASEMATERIAL_H
