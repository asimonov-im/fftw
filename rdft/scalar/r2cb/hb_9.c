/*
 * Copyright (c) 2003, 2007-11 Matteo Frigo
 * Copyright (c) 2003, 2007-11 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Tue Feb 21 19:03:23 EST 2012 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_hc2hc.native -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -sign 1 -n 9 -dif -name hb_9 -include hb.h */

/*
 * This function contains 96 FP additions, 88 FP multiplications,
 * (or, 24 additions, 16 multiplications, 72 fused multiply/add),
 * 69 stack variables, 10 constants, and 36 memory accesses
 */
#include "hb.h"

static void hb_9(R *cr, R *ci, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP954188894, +0.954188894138671133499268364187245676532219158);
     DK(KP852868531, +0.852868531952443209628250963940074071936020296);
     DK(KP492403876, +0.492403876506104029683371512294761506835321626);
     DK(KP984807753, +0.984807753012208059366743024589523013670643252);
     DK(KP777861913, +0.777861913430206160028177977318626690410586096);
     DK(KP839099631, +0.839099631177280011763127298123181364687434283);
     DK(KP363970234, +0.363970234266202361351047882776834043890471784);
     DK(KP176326980, +0.176326980708464973471090386868618986121633062);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 16); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 16, MAKE_VOLATILE_STRIDE(rs)) {
	       E T1X, T1S, T1U, T1P, T1Y, T1T;
	       {
		    E T5, Tl, TQ, T1y, T1b, T1J, Tg, TE, TW, T13, T10, Tz, Tw, TT, T1K;
		    E T1B, T1L, T1E;
		    {
			 E T1, Th, T2, T3, Ti, Tj;
			 T1 = cr[0];
			 Th = ci[WS(rs, 8)];
			 T2 = cr[WS(rs, 3)];
			 T3 = ci[WS(rs, 2)];
			 Ti = ci[WS(rs, 5)];
			 Tj = cr[WS(rs, 6)];
			 {
			      E T12, Tb, TZ, TY, Ta, Tq, T11, Tr, Ts, TS, Te, Tt;
			      {
				   E T6, Tm, Tn, To, T9, Tc, Td, Tp;
				   {
					E T7, T8, T1a, T4;
					T6 = cr[WS(rs, 1)];
					T1a = T2 - T3;
					T4 = T2 + T3;
					{
					     E TP, Tk, TO, T19;
					     TP = Ti + Tj;
					     Tk = Ti - Tj;
					     T7 = cr[WS(rs, 4)];
					     T5 = T1 + T4;
					     TO = FNMS(KP500000000, T4, T1);
					     Tl = Th + Tk;
					     T19 = FNMS(KP500000000, Tk, Th);
					     TQ = FNMS(KP866025403, TP, TO);
					     T1y = FMA(KP866025403, TP, TO);
					     T1b = FMA(KP866025403, T1a, T19);
					     T1J = FNMS(KP866025403, T1a, T19);
					     T8 = ci[WS(rs, 1)];
					}
					Tm = ci[WS(rs, 7)];
					Tn = ci[WS(rs, 4)];
					To = cr[WS(rs, 7)];
					T9 = T7 + T8;
					T12 = T7 - T8;
				   }
				   Tb = cr[WS(rs, 2)];
				   TZ = Tn + To;
				   Tp = Tn - To;
				   TY = FNMS(KP500000000, T9, T6);
				   Ta = T6 + T9;
				   Tc = ci[WS(rs, 3)];
				   Td = ci[0];
				   Tq = Tm + Tp;
				   T11 = FMS(KP500000000, Tp, Tm);
				   Tr = ci[WS(rs, 6)];
				   Ts = cr[WS(rs, 5)];
				   TS = Td - Tc;
				   Te = Tc + Td;
				   Tt = cr[WS(rs, 8)];
			      }
			      {
				   E T1C, Tv, TR, T1D, T1z, T1A;
				   {
					E TU, Tu, TV, Tf;
					TU = FNMS(KP500000000, Te, Tb);
					Tf = Tb + Te;
					Tu = Ts + Tt;
					TV = Ts - Tt;
					Tg = Ta + Tf;
					TE = Ta - Tf;
					TW = FMA(KP866025403, TV, TU);
					T1C = FNMS(KP866025403, TV, TU);
					Tv = Tr - Tu;
					TR = FMA(KP500000000, Tu, Tr);
				   }
				   T1z = FMA(KP866025403, T12, T11);
				   T13 = FNMS(KP866025403, T12, T11);
				   T10 = FNMS(KP866025403, TZ, TY);
				   T1A = FMA(KP866025403, TZ, TY);
				   Tz = Tv - Tq;
				   Tw = Tq + Tv;
				   T1D = FMA(KP866025403, TS, TR);
				   TT = FNMS(KP866025403, TS, TR);
				   T1K = FNMS(KP176326980, T1z, T1A);
				   T1B = FMA(KP176326980, T1A, T1z);
				   T1L = FNMS(KP363970234, T1C, T1D);
				   T1E = FMA(KP363970234, T1D, T1C);
			      }
			 }
		    }
		    {
			 E T1d, T14, T1c, TX;
			 cr[0] = T5 + Tg;
			 T1d = FNMS(KP839099631, T10, T13);
			 T14 = FMA(KP839099631, T13, T10);
			 T1c = FMA(KP176326980, TT, TW);
			 TX = FNMS(KP176326980, TW, TT);
			 ci[0] = Tl + Tw;
			 {
			      E TL, TK, TJ, Ty, TD;
			      Ty = FNMS(KP500000000, Tg, T5);
			      TD = FNMS(KP500000000, Tw, Tl);
			      {
				   E Tx, TC, TA, TI, TF;
				   Tx = W[10];
				   TC = W[11];
				   TA = FNMS(KP866025403, Tz, Ty);
				   TI = FMA(KP866025403, Tz, Ty);
				   TF = FNMS(KP866025403, TE, TD);
				   TL = FMA(KP866025403, TE, TD);
				   {
					E TH, TB, TG, TM;
					TH = W[4];
					TB = Tx * TA;
					TK = W[5];
					TG = Tx * TF;
					TM = TH * TL;
					TJ = TH * TI;
					cr[WS(rs, 6)] = FNMS(TC, TF, TB);
					ci[WS(rs, 6)] = FMA(TC, TA, TG);
					ci[WS(rs, 3)] = FMA(TK, TI, TM);
				   }
			      }
			      cr[WS(rs, 3)] = FNMS(TK, TL, TJ);
			      {
				   E T1k, T1p, T1l, T1q, T1m;
				   {
					E T1e, T1j, T15, T1o;
					T1e = FNMS(KP777861913, T1d, T1c);
					T1j = FMA(KP777861913, T1d, T1c);
					T15 = FNMS(KP777861913, T14, TX);
					T1o = FMA(KP777861913, T14, TX);
					{
					     E TN, T16, T1f, T17, T1s, T1v, T18, T1i, T1n, T1r, T1u;
					     TN = W[0];
					     T16 = FNMS(KP984807753, T15, TQ);
					     T1i = FMA(KP492403876, T15, TQ);
					     T1f = FMA(KP984807753, T1e, T1b);
					     T1n = FNMS(KP492403876, T1e, T1b);
					     T17 = TN * T16;
					     T1s = FMA(KP852868531, T1j, T1i);
					     T1k = FNMS(KP852868531, T1j, T1i);
					     T1v = FMA(KP852868531, T1o, T1n);
					     T1p = FNMS(KP852868531, T1o, T1n);
					     T18 = W[1];
					     T1r = W[6];
					     T1u = W[7];
					     {
						  E T1h, T1g, T1w, T1t;
						  T1h = W[12];
						  cr[WS(rs, 1)] = FNMS(T18, T1f, T17);
						  T1g = T18 * T16;
						  T1w = T1r * T1v;
						  T1t = T1r * T1s;
						  T1l = T1h * T1k;
						  ci[WS(rs, 1)] = FMA(TN, T1f, T1g);
						  ci[WS(rs, 4)] = FMA(T1u, T1s, T1w);
						  cr[WS(rs, 4)] = FNMS(T1u, T1v, T1t);
						  T1q = T1h * T1p;
					     }
					     T1m = W[13];
					}
				   }
				   {
					E T1F, T1W, T1R, T1V, T1N, T1M, T1x, T1I;
					T1F = FNMS(KP954188894, T1E, T1B);
					T1W = FMA(KP954188894, T1E, T1B);
					T1M = FNMS(KP954188894, T1L, T1K);
					T1R = FMA(KP954188894, T1L, T1K);
					ci[WS(rs, 7)] = FMA(T1m, T1k, T1q);
					cr[WS(rs, 7)] = FNMS(T1m, T1p, T1l);
					T1V = FNMS(KP492403876, T1M, T1J);
					T1N = FMA(KP984807753, T1M, T1J);
					T1x = W[2];
					T1I = W[3];
					{
					     E T23, T22, T20, T1Z, T24, T21;
					     T1X = FMA(KP852868531, T1W, T1V);
					     T23 = FNMS(KP852868531, T1W, T1V);
					     {
						  E T1G, T1Q, T1O, T1H;
						  T1G = FMA(KP984807753, T1F, T1y);
						  T1Q = FNMS(KP492403876, T1F, T1y);
						  T1O = T1x * T1N;
						  T22 = W[15];
						  T1H = T1x * T1G;
						  T20 = FMA(KP852868531, T1R, T1Q);
						  T1S = FNMS(KP852868531, T1R, T1Q);
						  ci[WS(rs, 2)] = FMA(T1I, T1G, T1O);
						  cr[WS(rs, 2)] = FNMS(T1I, T1N, T1H);
						  T1Z = W[14];
						  T24 = T22 * T20;
					     }
					     T1U = W[9];
					     T21 = T1Z * T20;
					     ci[WS(rs, 8)] = FMA(T1Z, T23, T24);
					     T1P = W[8];
					     T1Y = T1U * T1S;
					     cr[WS(rs, 8)] = FNMS(T22, T23, T21);
					}
				   }
			      }
			 }
		    }
	       }
	       T1T = T1P * T1S;
	       ci[WS(rs, 5)] = FMA(T1P, T1X, T1Y);
	       cr[WS(rs, 5)] = FNMS(T1U, T1X, T1T);
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_FULL, 1, 9},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 9, "hb_9", twinstr, &GENUS, {24, 16, 72, 0} };

void X(codelet_hb_9) (planner *p) {
     X(khc2hc_register) (p, hb_9, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_hc2hc.native -compact -variables 4 -pipeline-latency 4 -sign 1 -n 9 -dif -name hb_9 -include hb.h */

/*
 * This function contains 96 FP additions, 72 FP multiplications,
 * (or, 60 additions, 36 multiplications, 36 fused multiply/add),
 * 53 stack variables, 8 constants, and 36 memory accesses
 */
#include "hb.h"

static void hb_9(R *cr, R *ci, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP984807753, +0.984807753012208059366743024589523013670643252);
     DK(KP173648177, +0.173648177666930348851716626769314796000375677);
     DK(KP342020143, +0.342020143325668733044099614682259580763083368);
     DK(KP939692620, +0.939692620785908384054109277324731469936208134);
     DK(KP642787609, +0.642787609686539326322643409907263432907559884);
     DK(KP766044443, +0.766044443118978035202392650555416673935832457);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 16); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 16, MAKE_VOLATILE_STRIDE(rs)) {
	       E T5, Tl, TM, T1o, T16, T1y, Ta, Tf, Tg, Tq, Tv, Tw, TT, T17, T1u;
	       E T1A, T1r, T1z, T10, T18;
	       {
		    E T1, Th, T4, T14, Tk, TL, TK, T15;
		    T1 = cr[0];
		    Th = ci[WS(rs, 8)];
		    {
			 E T2, T3, Ti, Tj;
			 T2 = cr[WS(rs, 3)];
			 T3 = ci[WS(rs, 2)];
			 T4 = T2 + T3;
			 T14 = KP866025403 * (T2 - T3);
			 Ti = ci[WS(rs, 5)];
			 Tj = cr[WS(rs, 6)];
			 Tk = Ti - Tj;
			 TL = KP866025403 * (Ti + Tj);
		    }
		    T5 = T1 + T4;
		    Tl = Th + Tk;
		    TK = FNMS(KP500000000, T4, T1);
		    TM = TK - TL;
		    T1o = TK + TL;
		    T15 = FNMS(KP500000000, Tk, Th);
		    T16 = T14 + T15;
		    T1y = T15 - T14;
	       }
	       {
		    E T6, T9, TN, TQ, Tm, Tp, TO, TR, Tb, Te, TU, TX, Tr, Tu, TV;
		    E TY;
		    {
			 E T7, T8, Tn, To;
			 T6 = cr[WS(rs, 1)];
			 T7 = cr[WS(rs, 4)];
			 T8 = ci[WS(rs, 1)];
			 T9 = T7 + T8;
			 TN = FNMS(KP500000000, T9, T6);
			 TQ = KP866025403 * (T7 - T8);
			 Tm = ci[WS(rs, 7)];
			 Tn = ci[WS(rs, 4)];
			 To = cr[WS(rs, 7)];
			 Tp = Tn - To;
			 TO = KP866025403 * (Tn + To);
			 TR = FNMS(KP500000000, Tp, Tm);
		    }
		    {
			 E Tc, Td, Ts, Tt;
			 Tb = cr[WS(rs, 2)];
			 Tc = ci[WS(rs, 3)];
			 Td = ci[0];
			 Te = Tc + Td;
			 TU = FNMS(KP500000000, Te, Tb);
			 TX = KP866025403 * (Tc - Td);
			 Tr = ci[WS(rs, 6)];
			 Ts = cr[WS(rs, 5)];
			 Tt = cr[WS(rs, 8)];
			 Tu = Ts + Tt;
			 TV = KP866025403 * (Ts - Tt);
			 TY = FMA(KP500000000, Tu, Tr);
		    }
		    {
			 E TP, TS, T1s, T1t;
			 Ta = T6 + T9;
			 Tf = Tb + Te;
			 Tg = Ta + Tf;
			 Tq = Tm + Tp;
			 Tv = Tr - Tu;
			 Tw = Tq + Tv;
			 TP = TN - TO;
			 TS = TQ + TR;
			 TT = FNMS(KP642787609, TS, KP766044443 * TP);
			 T17 = FMA(KP766044443, TS, KP642787609 * TP);
			 T1s = TU - TV;
			 T1t = TY - TX;
			 T1u = FMA(KP939692620, T1s, KP342020143 * T1t);
			 T1A = FNMS(KP939692620, T1t, KP342020143 * T1s);
			 {
			      E T1p, T1q, TW, TZ;
			      T1p = TN + TO;
			      T1q = TR - TQ;
			      T1r = FNMS(KP984807753, T1q, KP173648177 * T1p);
			      T1z = FMA(KP173648177, T1q, KP984807753 * T1p);
			      TW = TU + TV;
			      TZ = TX + TY;
			      T10 = FNMS(KP984807753, TZ, KP173648177 * TW);
			      T18 = FMA(KP984807753, TW, KP173648177 * TZ);
			 }
		    }
	       }
	       cr[0] = T5 + Tg;
	       ci[0] = Tl + Tw;
	       {
		    E TA, TG, TE, TI;
		    {
			 E Ty, Tz, TC, TD;
			 Ty = FNMS(KP500000000, Tg, T5);
			 Tz = KP866025403 * (Tv - Tq);
			 TA = Ty - Tz;
			 TG = Ty + Tz;
			 TC = FNMS(KP500000000, Tw, Tl);
			 TD = KP866025403 * (Ta - Tf);
			 TE = TC - TD;
			 TI = TD + TC;
		    }
		    {
			 E Tx, TB, TF, TH;
			 Tx = W[10];
			 TB = W[11];
			 cr[WS(rs, 6)] = FNMS(TB, TE, Tx * TA);
			 ci[WS(rs, 6)] = FMA(Tx, TE, TB * TA);
			 TF = W[4];
			 TH = W[5];
			 cr[WS(rs, 3)] = FNMS(TH, TI, TF * TG);
			 ci[WS(rs, 3)] = FMA(TF, TI, TH * TG);
		    }
	       }
	       {
		    E T1d, T1h, T12, T1c, T1a, T1g, T11, T19, TJ, T13;
		    T1d = KP866025403 * (T18 - T17);
		    T1h = KP866025403 * (TT - T10);
		    T11 = TT + T10;
		    T12 = TM + T11;
		    T1c = FNMS(KP500000000, T11, TM);
		    T19 = T17 + T18;
		    T1a = T16 + T19;
		    T1g = FNMS(KP500000000, T19, T16);
		    TJ = W[0];
		    T13 = W[1];
		    cr[WS(rs, 1)] = FNMS(T13, T1a, TJ * T12);
		    ci[WS(rs, 1)] = FMA(T13, T12, TJ * T1a);
		    {
			 E T1k, T1m, T1j, T1l;
			 T1k = T1c + T1d;
			 T1m = T1h + T1g;
			 T1j = W[6];
			 T1l = W[7];
			 cr[WS(rs, 4)] = FNMS(T1l, T1m, T1j * T1k);
			 ci[WS(rs, 4)] = FMA(T1j, T1m, T1l * T1k);
		    }
		    {
			 E T1e, T1i, T1b, T1f;
			 T1e = T1c - T1d;
			 T1i = T1g - T1h;
			 T1b = W[12];
			 T1f = W[13];
			 cr[WS(rs, 7)] = FNMS(T1f, T1i, T1b * T1e);
			 ci[WS(rs, 7)] = FMA(T1b, T1i, T1f * T1e);
		    }
	       }
	       {
		    E T1F, T1J, T1w, T1E, T1C, T1I, T1v, T1B, T1n, T1x;
		    T1F = KP866025403 * (T1A - T1z);
		    T1J = KP866025403 * (T1r + T1u);
		    T1v = T1r - T1u;
		    T1w = T1o + T1v;
		    T1E = FNMS(KP500000000, T1v, T1o);
		    T1B = T1z + T1A;
		    T1C = T1y + T1B;
		    T1I = FNMS(KP500000000, T1B, T1y);
		    T1n = W[2];
		    T1x = W[3];
		    cr[WS(rs, 2)] = FNMS(T1x, T1C, T1n * T1w);
		    ci[WS(rs, 2)] = FMA(T1n, T1C, T1x * T1w);
		    {
			 E T1M, T1O, T1L, T1N;
			 T1M = T1F + T1E;
			 T1O = T1I + T1J;
			 T1L = W[8];
			 T1N = W[9];
			 cr[WS(rs, 5)] = FNMS(T1N, T1O, T1L * T1M);
			 ci[WS(rs, 5)] = FMA(T1N, T1M, T1L * T1O);
		    }
		    {
			 E T1G, T1K, T1D, T1H;
			 T1G = T1E - T1F;
			 T1K = T1I - T1J;
			 T1D = W[14];
			 T1H = W[15];
			 cr[WS(rs, 8)] = FNMS(T1H, T1K, T1D * T1G);
			 ci[WS(rs, 8)] = FMA(T1H, T1G, T1D * T1K);
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_FULL, 1, 9},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 9, "hb_9", twinstr, &GENUS, {60, 36, 36, 0} };

void X(codelet_hb_9) (planner *p) {
     X(khc2hc_register) (p, hb_9, &desc);
}
#endif				/* HAVE_FMA */
