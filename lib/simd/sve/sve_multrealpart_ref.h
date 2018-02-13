#ifndef SVE_MULTREALPART_H
#define SVE_MULTREALPART_H

#pragma message("include sve_multrealpart_ref.h using references")

  struct MultRealPart{
    template <typename T>
    inline vec<T> operator()(const vec<T> &a, const vec<T> &b){

      vec<T> out;
      svbool_t pg1 = acle<T>::pg1();
      typename acle<T>::vt *a_v = (typename acle<T>::vt*)&a.v;
      typename acle<T>::vt *b_v = (typename acle<T>::vt*)&b.v;
      typename acle<T>::vt *r_v = (typename acle<T>::vt*)&out.v;

      // using FCMLA
      typename acle<T>::vt z_v = acle<T>::zero();
      *r_v = svcmla_x(pg1, z_v, *a_v, *b_v, 0);

/*
      // using instructions for real arithmetics
      typename acle<T>::vt re_v = svtrn1(a_v, a_v);
      typename acle<T>::vt r_v  = svmul_x(pg1, re_v, b_v);
*/

      return out;
    }
  };

#endif
