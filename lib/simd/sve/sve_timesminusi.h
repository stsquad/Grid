#ifndef SVE_TIMESMINUSI_H
#define SVE_TIMESMINUSI_H

#pragma message("include sve_timesminusi.h")

  struct TimesMinusI{
    // Complex
    template <typename T>
    inline vec<T> operator()(const vec<T> &a, const vec<T> &b){

      vec<T> out;
      svbool_t pg1 = acle<T>::pg1();
      typename acle<T>::vt a_v = svld1(pg1, a.v);
      typename acle<T>::vt re_v = svtrn1(a_v, a_v);
      re_v = svneg_x(pg1, re_v);
      typename acle<T>::vt r_v = svtrn2(a_v, re_v);
      svst1(pg1, out.v, r_v);

      return out;
    }
  };

#endif
