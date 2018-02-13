#ifndef SVE_MADDREALPART_H
#define SVE_MADDREALPART_H

#pragma message("include sve_maddrealpart_sls.h using structured load/store")

  struct MaddRealPart{
    template <typename T>
    inline vec<T> operator()(const vec<T> &a, const vec<T> &b, const vec<T> &c){

      vec<T> out;
      svbool_t pg2 = acle<T>::pg2();
      typename acle<T>::vt2 a_v = svld2(pg2, a.v);
      typename acle<T>::vt2 b_v = svld2(pg2, b.v);
      typename acle<T>::vt2 c_v = svld2(pg2, c.v);
      typename acle<T>::vt2 r_v;
      r_v.v0 = svmad_x(pg2, a_v.v0, b_v.v0, c_v.v0);
      r_v.v1 = svmad_x(pg2, a_v.v0, b_v.v1, c_v.v1);
      svst2(pg2, out.v, r_v);

      return out;
    }
  };

#endif
