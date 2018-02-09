#ifndef SVE_ACLE_H
#define SVE_ACLE_H

#pragma message("include sve_acle.h")


  /////////////////////////////////////////////////////
  // SVE ACLE
  /////////////////////////////////////////////////////
  template <typename T>
  struct acle{};

  template <>
  struct acle<double>{
    typedef svfloat64_t vt;
    typedef svfloat64x2_t vt2;
    typedef svfloat64x4_t vt4;
    typedef float64_t pt;
    typedef uint64_t uint;
    typedef svuint64_t svuint;
    static inline svfloat64_t zero(){svfloat64_t z_v = __svzero(z_v); return z_v;}
    static inline svbool_t pg1(){return svptrue_b64();}
    static inline svbool_t pg2(){return svuzp1_b64(svptrue_b64(), svpfalse_b());}
    static inline svbool_t pg4(){return svwhilelt_b64((uint64_t)0, (uint64_t)(W<double>::c / 2u));}
    static inline svbool_t pg_even(){return svzip1_b64(svptrue_b64(), svpfalse_b());}
    static inline svbool_t pg_odd() {return svzip1_b64(svpfalse_b(), svptrue_b64());}
  };

  template <>
  struct acle<float>{
    typedef svfloat32_t vt;
    typedef svfloat32x2_t vt2;
    typedef float32_t pt;
    typedef uint32_t uint;
    typedef svuint32_t svuint;
    static inline svfloat32_t zero(){svfloat32_t z_v = __svzero(z_v); return z_v;}
    static inline svbool_t pg1(){return svptrue_b32();}
    static inline svbool_t pg2(){return svuzp1_b32(svptrue_b32(), svpfalse_b());}
    static inline svbool_t pg_even(){return svzip1_b32(svptrue_b32(), svpfalse_b());}
    static inline svbool_t pg_odd() {return svzip1_b32(svpfalse_b(), svptrue_b32());}
  };

  template <>
  struct acle<uint16_t>{
    typedef svfloat16_t vt;
    typedef uint16_t pt;
    typedef uint16_t uint;
    typedef svuint16_t svuint;
    static inline svfloat16_t zero(){svfloat16_t z_v = __svzero(z_v); return z_v;}
    static inline svbool_t pg1(){return svptrue_b16();}
    static inline svbool_t pg2(){return svuzp1_b16(svptrue_b16(), svpfalse_b());}
    static inline svbool_t pg_even(){return svzip1_b16(svptrue_b16(), svpfalse_b());}
    static inline svbool_t pg_odd() {return svzip1_b16(svpfalse_b(), svptrue_b16());}
  };

  template <>
  struct acle<Integer>{
    typedef svuint32_t vt;
    typedef Integer pt;
    // Is Integer guaranteed to be an uint32_t???
    typedef uint32_t uint;
    typedef svuint32_t svuint;
    static inline svbool_t pg1(){return svptrue_b32();}
    static inline svbool_t pg2(){return svuzp1_b32(svptrue_b32(), svpfalse_b());}
    static inline svbool_t pg_even(){return svzip1_b32(svptrue_b32(), svpfalse_b());}
    static inline svbool_t pg_odd() {return svzip1_b32(svpfalse_b(), svptrue_b32());}
  };

#endif
