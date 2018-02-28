#ifndef SVE_PREC_H
#define SVE_PREC_H

#pragma message("include sve_prec.h")

  struct PrecisionChange {
    static inline vech StoH (const vecf &sa,const vecf &sb) {

      vech ret;
      svbool_t pg1s = acle<float>::pg1();
      svbool_t pg1h = acle<uint16_t>::pg1();
      typename acle<float>::vt sa_v = svld1(pg1s, sa.v);
      typename acle<float>::vt sb_v = svld1(pg1s, sb.v);
      typename acle<uint16_t>::vt ha_v = svcvt_f16_x(pg1s, sa_v);
      typename acle<uint16_t>::vt hb_v = svcvt_f16_x(pg1s, sb_v);
      typename acle<uint16_t>::vt r_v = svuzp1(ha_v, hb_v);
      svst1(pg1h, (typename acle<uint16_t>::pt*)&ret.v, r_v);
      return ret;
    }
    static inline void HtoS (const vech &h,vecf &sa,vecf &sb) {

      svbool_t pg1h = acle<uint16_t>::pg1();
      svbool_t pg1s = acle<float>::pg1();
      typename acle<uint16_t>::vt h_v = svld1(pg1h, (typename acle<uint16_t>::pt*)&h.v);
      typename acle<uint16_t>::vt ha_v = svzip1(h_v, h_v);
      typename acle<uint16_t>::vt hb_v = svzip2(h_v, h_v);
      typename acle<float>::vt sa_v = svcvt_f32_x(pg1s, ha_v);
      typename acle<float>::vt sb_v = svcvt_f32_x(pg1s, hb_v);
      svst1(pg1s, sa.v, sa_v);
      svst1(pg1s, sb.v, sb_v);
    }
    static inline vecf DtoS (const vecd &a, const vecd &b) {

      vecf ret;
      svbool_t pg1d = acle<double>::pg1();
      svbool_t pg1s = acle<float>::pg1();
      typename acle<double>::vt a_v = svld1(pg1d, a.v);
      typename acle<double>::vt b_v = svld1(pg1d, b.v);
      typename acle<float>::vt sa_v = svcvt_f32_x(pg1d, a_v);
      typename acle<float>::vt sb_v = svcvt_f32_x(pg1d, b_v);
      typename acle<float>::vt r_v = svuzp1(sa_v, sb_v);
      svst1(pg1s, ret.v, r_v);
      return ret;
    }
    static inline void StoD (const vecf &s,vecd &a,vecd &b) {

      svbool_t pg1s = acle<float>::pg1();
      svbool_t pg1d = acle<double>::pg1();
      typename acle<float>::vt s_v = svld1(pg1s, s.v);
      typename acle<float>::vt sa_v = svzip1(s_v, s_v);
      typename acle<float>::vt sb_v = svzip2(s_v, s_v);
      typename acle<double>::vt a_v = svcvt_f64_x(pg1d, sa_v);
      typename acle<double>::vt b_v = svcvt_f64_x(pg1d, sb_v);
      svst1(pg1d, a.v, a_v);
      svst1(pg1d, b.v, b_v);
    }
    static inline vech DtoH (const vecd &a, const vecd &b, const vecd &c, const vecd &d) {

      vech ret;
      svbool_t pg1d = acle<double>::pg1();
      svbool_t pg1h = acle<uint16_t>::pg1();
      typename acle<double>::vt a_v = svld1(pg1d, a.v);
      typename acle<double>::vt b_v = svld1(pg1d, b.v);
      typename acle<double>::vt c_v = svld1(pg1d, c.v);
      typename acle<double>::vt d_v = svld1(pg1d, d.v);
      typename acle<uint16_t>::vt ha_v = svcvt_f16_x(pg1d, a_v);
      typename acle<uint16_t>::vt hb_v = svcvt_f16_x(pg1d, b_v);
      typename acle<uint16_t>::vt hc_v = svcvt_f16_x(pg1d, c_v);
      typename acle<uint16_t>::vt hd_v = svcvt_f16_x(pg1d, d_v);
      typename acle<uint16_t>::vt hab_v = svuzp1(ha_v, hb_v);
      typename acle<uint16_t>::vt hcd_v = svuzp1(hc_v, hd_v);
      typename acle<uint16_t>::vt r_v = svuzp1(hab_v, hcd_v);
      svst1(pg1h, (typename acle<uint16_t>::pt*)&ret.v, r_v);

      return ret;
/*
      vecf sa,sb;
      sa = DtoS(a,b);
      sb = DtoS(c,d);
      return StoH(sa,sb);
*/
    }
    static inline void HtoD (const vech &h, vecd &a, vecd &b, vecd &c, vecd &d) {

      svbool_t pg1h = acle<uint16_t>::pg1();
      svbool_t pg1d = acle<double>::pg1();
      typename acle<uint16_t>::vt h_v = svld1(pg1h, (typename acle<uint16_t>::pt*)&h.v);
      typename acle<uint16_t>::vt sa_v = svzip1(h_v, h_v);
      typename acle<uint16_t>::vt sb_v = svzip2(h_v, h_v);
      typename acle<uint16_t>::vt da_v = svzip1(sa_v, sa_v);
      typename acle<uint16_t>::vt db_v = svzip2(sa_v, sa_v);
      typename acle<uint16_t>::vt dc_v = svzip1(sb_v, sb_v);
      typename acle<uint16_t>::vt dd_v = svzip2(sb_v, sb_v);
      typename acle<double>::vt a_v = svcvt_f64_x(pg1d, da_v);
      typename acle<double>::vt b_v = svcvt_f64_x(pg1d, db_v);
      typename acle<double>::vt c_v = svcvt_f64_x(pg1d, dc_v);
      typename acle<double>::vt d_v = svcvt_f64_x(pg1d, dd_v);
      svst1(pg1d, a.v, a_v);
      svst1(pg1d, b.v, b_v);
      svst1(pg1d, c.v, c_v);
      svst1(pg1d, d.v, d_v);
/*
      vecf sa,sb;
      HtoS(h,sa,sb);
      StoD(sa,a,b);
      StoD(sb,c,d);
*/
    }
  };

#endif
