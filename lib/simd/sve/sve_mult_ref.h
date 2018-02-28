#ifndef SVE_MULT_H
#define SVE_MULT_H

#pragma message("include sve_mult_ref.h using references")

  struct Mult{
    template <typename T>
    inline vec<T> operator()(const vec<T> &a, const vec<T> &b){

      vec<T> out;
      svbool_t pg1 = acle<T>::pg1();
      typename acle<T>::vt *a_v = (typename acle<T>::vt*)&a.v;
      typename acle<T>::vt *b_v = (typename acle<T>::vt*)&b.v;
      typename acle<T>::vt *r_v = (typename acle<T>::vt*)&out.v;
      *r_v = svmul_x(pg1, *a_v, *b_v);

      return out;

    }
  };

#endif
