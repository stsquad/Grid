#ifndef SVE_TIMESMINUSI_H
#define SVE_TIMESMINUSI_H

#pragma message("include sve_timesminusi_ref.h using references")

  struct TimesMinusI{
    // Complex
    template <typename T>
    inline vec<T> operator()(const vec<T> &a, const vec<T> &b){

      vec<T> out;
      svbool_t pg1 = acle<T>::pg1();
      typename acle<T>::vt *a_v = (typename acle<T>::vt*)&a.v;
      typename acle<T>::vt *r_v = (typename acle<T>::vt*)&out.v;
      typename acle<T>::vt re_v = svtrn1(*a_v, *a_v);
      re_v = svneg_x(pg1, re_v);
      *r_v = svtrn2(*a_v, re_v);

      return out;
    }
  };

#endif
