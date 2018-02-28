#ifndef SVE_CONJ_H
#define SVE_CONJ_H

#pragma message("include sve_conj_ref.h using references")

  struct Conj{
    // Complex
    template <typename T>
    inline vec<T> operator()(const vec<T> &a){

      vec<T> out;
      svbool_t pg1 = acle<T>::pg1();
      typename acle<T>::vt *a_v = (typename acle<T>::vt*)&a.v;
      typename acle<T>::vt *r_v = (typename acle<T>::vt*)&out.v;
      typename acle<T>::vt im_v = svtrn2(*a_v, *a_v);
      im_v = svneg_x(pg1, im_v);
      *r_v = svtrn1(*a_v, im_v);

      return out;
    }
  };

#endif
