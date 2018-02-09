#ifndef SVE_DIV_H
#define SVE_DIV_H

#pragma message("include sve_div.h")

  struct Div{
    // Real
    template <typename T>
    inline vec<T> operator()(const vec<T> &a, const vec<T> &b){

      vec<T> out;
      svbool_t pg1 = acle<T>::pg1();
      typename acle<T>::vt a_v = svld1(pg1, a.v);
      typename acle<T>::vt b_v = svld1(pg1, b.v);
      typename acle<T>::vt r_v = svdiv_x(pg1, a_v, b_v);
      svst1(pg1, out.v, r_v);

      return out;
    }
  };

#endif
