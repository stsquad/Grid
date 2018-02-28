#ifndef SVE_CONJ_H
#define SVE_CONJ_H

#pragma message("include sve_conj_sls.h using structured load/store")

  struct Conj{
    // Complex
    template <typename T>
    inline vec<T> operator()(const vec<T> &a){

      vec<T> out;
      svbool_t pg2 = acle<T>::pg2();
      typename acle<T>::vt2 a_v = svld2(pg2, a.v);
      a_v.v1 = svneg_x(pg2, a_v.v1);
      svst2(pg2, out.v, a_v);

      return out;
    }
  };

#endif
