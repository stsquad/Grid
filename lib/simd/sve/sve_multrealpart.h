#ifndef SVE_MULTREALPART_H
#define SVE_MULTREALPART_H

#pragma message("include sve_multrealpart.h")

  struct MultRealPart{
    template <typename T>
    inline vec<T> operator()(const vec<T> &a, const vec<T> &b){

      vec<T> out;
      svbool_t pg1 = acle<T>::pg1();
      typename acle<T>::vt a_v  = svld1(pg1, a.v);
      typename acle<T>::vt b_v  = svld1(pg1, b.v);

      // using FCMLA
      typename acle<T>::vt z_v = acle<T>::zero();
      typename acle<T>::vt r_v = svcmla_x(pg1, z_v, a_v, b_v, 0);

/*
      // using instructions for real arithmetics
      typename acle<T>::vt re_v = svtrn1(a_v, a_v);
      typename acle<T>::vt r_v  = svmul_x(pg1, re_v, b_v);
*/
      svst1(pg1, out.v, r_v);

      return out;
    }
  };

#endif
