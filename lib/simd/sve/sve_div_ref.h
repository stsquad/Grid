#ifndef SVE_DIV_H
#define SVE_DIV_H

#pragma message("include sve_div_ref.h using references")

  struct Div{
    // Real
    template <typename T>
    inline vec<T> operator()(const vec<T> &a, const vec<T> &b){

      vec<T> out;
      svbool_t pg1 = acle<T>::pg1();
      typename acle<T>::vt *a_v = (typename acle<T>::vt*)&a.v;
      typename acle<T>::vt *b_v = (typename acle<T>::vt*)&b.v;
      typename acle<T>::vt *r_v = (typename acle<T>::vt*)&out.v;
      *r_v = svdiv_x(pg1, *a_v, *b_v);

      return out;
    }
  };

#endif
