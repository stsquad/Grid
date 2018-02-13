#ifndef SVE_MULTCOMPLEX_H
#define SVE_MULTCOMPLEX_H

#pragma message("include sve_multcomplex_sls.h using structured load/store")


  struct MultComplex{
    // Complex
    template <typename T>
    inline vec<T> operator()(const vec<T> &a, const vec<T> &b){

      vec<T> out;
      svbool_t pg2 = acle<T>::pg2();
      typename acle<T>::vt2 a_v = svld2(pg2, a.v);
      typename acle<T>::vt2 b_v = svld2(pg2, b.v);
      typename acle<T>::vt2 r_v;
      r_v.v0 = svmul_x(pg2, a_v.v0, b_v.v0);
      r_v.v0 = svmls_x(pg2, r_v.v0, a_v.v1, b_v.v1);
      r_v.v1 = svmul_x(pg2, a_v.v0, b_v.v1);
      r_v.v1 = svmla_x(pg2, r_v.v1, a_v.v1, b_v.v0);
      svst2(pg2, out.v, r_v);

      return out;
    }
  };

#endif
