#ifndef SVE_SUB_H
#define SVE_SUB_H

#pragma message("include sve_sub.h")

  struct Sub{
    template <typename T>
    inline vec<T> operator()(const vec<T> &a, const vec<T> &b){

      vec<T> out;
      svbool_t pg1 = acle<T>::pg1();
      typename acle<T>::vt a_v = svld1(pg1, a.v);
      typename acle<T>::vt b_v = svld1(pg1, b.v);
      typename acle<T>::vt r_v = svsub_x(pg1, a_v, b_v);
      svst1(pg1, out.v, r_v);

      return out;
    }
  };

#endif
