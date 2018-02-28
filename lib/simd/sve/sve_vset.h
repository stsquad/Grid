#ifndef SVE_VSET_H
#define SVE_VSET_H

#pragma message("include sve_vset.h")

  struct Vset{
    // Complex
    template <typename T>
    inline vec<T> operator()(const std::complex<T> *a){

      vec<T> out;
      svbool_t pg1 = acle<T>::pg1();
      typename acle<T>::vt a_v = svld1(pg1, (T*)a);
      svst1(pg1, out.v, a_v);

      return out;
    }

    // Real
    template <typename T>
    inline vec<T> operator()(T * a){

      vec<T> out;
      svbool_t pg1 = acle<T>::pg1();
      typename acle<T>::vt a_v = svld1(pg1, a);
      svst1(pg1, out.v, a_v);

      return out;
    }
  };

#endif
