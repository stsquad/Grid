#ifndef SVE_TIMESI_H
#define SVE_TIMESI_H

#pragma message("include sve_timesi_sls.h using structured load/store")

  struct TimesI{
    // Complex
    template <typename T>
    inline vec<T> operator()(const vec<T> &a, const vec<T> &b){

      vec<T> out;
      svbool_t pg2 = acle<T>::pg2();
      typename acle<T>::vt2 a_v = svld2(pg2, a.v);
      a_v.v1 = svneg_x(pg2, a_v.v1);
      typename acle<T>::vt2 r_v;
      r_v.v0 = a_v.v1;
      r_v.v1 = a_v.v0;
      svst2(pg2, out.v, r_v);

      return out;
    }
  };

#endif
