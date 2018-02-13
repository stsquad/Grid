#ifndef SVE_MULTCOMPLEX_H
#define SVE_MULTCOMPLEX_H

#pragma message("include sve_multcomplex_ref.h using references")

  struct MultComplex{
    // Complex
    template <typename T>
    inline vec<T> operator()(const vec<T> &a, const vec<T> &b){

      vec<T> out;
      svbool_t pg1 = acle<T>::pg1();
      typename acle<T>::vt z_v = acle<T>::zero();
      typename acle<T>::vt *a_v = (typename acle<T>::vt*)&a.v;
      typename acle<T>::vt *b_v = (typename acle<T>::vt*)&b.v;
      typename acle<T>::vt *r_v = (typename acle<T>::vt*)&out.v;
      *r_v = svcmla_x(pg1, z_v, *a_v, *b_v, 90);
      *r_v = svcmla_x(pg1, *r_v, *a_v, *b_v, 0);

      return out;
    }
  };

#endif
