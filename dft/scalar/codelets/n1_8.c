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
/* Generated on Tue Feb 21 18:59:26 EST 2012 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_notw.native -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -n 8 -name n1_8 -include n.h */

/*
 * This function contains 52 FP additions, 8 FP multiplications,
 * (or, 44 additions, 0 multiplications, 8 fused multiply/add),
 * 36 stack variables, 1 constants, and 32 memory accesses
 */
#include "n.h"

static void n1_8(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, ri = ri + ivs, ii = ii + ivs, ro = ro + ovs, io = io + ovs, MAKE_VOLATILE_STRIDE(is), MAKE_VOLATILE_STRIDE(os)) {
	       E TF, TE, TD, TI;
	       {
		    E Tn, T3, TC, Ti, TB, T6, To, Tl, Td, TN, Tz, TH, Ta, Tq, Tt;
		    E TM;
		    {
			 E T4, T5, Tj, Tk;
			 {
			      E T1, T2, Tg, Th;
			      T1 = ri[0];
			      T2 = ri[WS(is, 4)];
			      Tg = ii[0];
			      Th = ii[WS(is, 4)];
			      T4 = ri[WS(is, 2)];
			      Tn = T1 - T2;
			      T3 = T1 + T2;
			      TC = Tg - Th;
			      Ti = Tg + Th;
			      T5 = ri[WS(is, 6)];
			 }
			 Tj = ii[WS(is, 2)];
			 Tk = ii[WS(is, 6)];
			 {
			      E Tb, Tc, Tw, Tx;
			      Tb = ri[WS(is, 7)];
			      TB = T4 - T5;
			      T6 = T4 + T5;
			      To = Tj - Tk;
			      Tl = Tj + Tk;
			      Tc = ri[WS(is, 3)];
			      Tw = ii[WS(is, 7)];
			      Tx = ii[WS(is, 3)];
			      {
				   E T8, Tv, Ty, T9, Tr, Ts;
				   T8 = ri[WS(is, 1)];
				   Td = Tb + Tc;
				   Tv = Tb - Tc;
				   TN = Tw + Tx;
				   Ty = Tw - Tx;
				   T9 = ri[WS(is, 5)];
				   Tr = ii[WS(is, 1)];
				   Ts = ii[WS(is, 5)];
				   Tz = Tv - Ty;
				   TH = Tv + Ty;
				   Ta = T8 + T9;
				   Tq = T8 - T9;
				   Tt = Tr - Ts;
				   TM = Tr + Ts;
			      }
			 }
		    }
		    {
			 E TL, TG, Tu, Tf, Tm, TO;
			 {
			      E T7, Te, TP, TQ;
			      TL = T3 - T6;
			      T7 = T3 + T6;
			      TG = Tt - Tq;
			      Tu = Tq + Tt;
			      Te = Ta + Td;
			      Tf = Td - Ta;
			      Tm = Ti - Tl;
			      TP = Ti + Tl;
			      TQ = TM + TN;
			      TO = TM - TN;
			      ro[0] = T7 + Te;
			      ro[WS(os, 4)] = T7 - Te;
			      io[0] = TP + TQ;
			      io[WS(os, 4)] = TP - TQ;
			 }
			 {
			      E Tp, TA, TJ, TK;
			      TF = Tn - To;
			      Tp = Tn + To;
			      io[WS(os, 6)] = Tm - Tf;
			      io[WS(os, 2)] = Tf + Tm;
			      ro[WS(os, 2)] = TL + TO;
			      ro[WS(os, 6)] = TL - TO;
			      TA = Tu + Tz;
			      TE = Tz - Tu;
			      TD = TB + TC;
			      TJ = TC - TB;
			      TK = TG + TH;
			      TI = TG - TH;
			      ro[WS(os, 1)] = FMA(KP707106781, TA, Tp);
			      ro[WS(os, 5)] = FNMS(KP707106781, TA, Tp);
			      io[WS(os, 1)] = FMA(KP707106781, TK, TJ);
			      io[WS(os, 5)] = FNMS(KP707106781, TK, TJ);
			 }
		    }
	       }
	       io[WS(os, 3)] = FMA(KP707106781, TE, TD);
	       io[WS(os, 7)] = FNMS(KP707106781, TE, TD);
	       ro[WS(os, 3)] = FMA(KP707106781, TI, TF);
	       ro[WS(os, 7)] = FNMS(KP707106781, TI, TF);
	  }
     }
}

static const kdft_desc desc = { 8, "n1_8", {44, 0, 8, 0}, &GENUS, 0, 0, 0, 0 };

void X(codelet_n1_8) (planner *p) {
     X(kdft_register) (p, n1_8, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_notw.native -compact -variables 4 -pipeline-latency 4 -n 8 -name n1_8 -include n.h */

/*
 * This function contains 52 FP additions, 4 FP multiplications,
 * (or, 52 additions, 4 multiplications, 0 fused multiply/add),
 * 28 stack variables, 1 constants, and 32 memory accesses
 */
#include "n.h"

static void n1_8(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, ri = ri + ivs, ii = ii + ivs, ro = ro + ovs, io = io + ovs, MAKE_VOLATILE_STRIDE(is), MAKE_VOLATILE_STRIDE(os)) {
	       E T3, Tn, Ti, TC, T6, TB, Tl, To, Td, TN, Tz, TH, Ta, TM, Tu;
	       E TG;
	       {
		    E T1, T2, Tj, Tk;
		    T1 = ri[0];
		    T2 = ri[WS(is, 4)];
		    T3 = T1 + T2;
		    Tn = T1 - T2;
		    {
			 E Tg, Th, T4, T5;
			 Tg = ii[0];
			 Th = ii[WS(is, 4)];
			 Ti = Tg + Th;
			 TC = Tg - Th;
			 T4 = ri[WS(is, 2)];
			 T5 = ri[WS(is, 6)];
			 T6 = T4 + T5;
			 TB = T4 - T5;
		    }
		    Tj = ii[WS(is, 2)];
		    Tk = ii[WS(is, 6)];
		    Tl = Tj + Tk;
		    To = Tj - Tk;
		    {
			 E Tb, Tc, Tv, Tw, Tx, Ty;
			 Tb = ri[WS(is, 7)];
			 Tc = ri[WS(is, 3)];
			 Tv = Tb - Tc;
			 Tw = ii[WS(is, 7)];
			 Tx = ii[WS(is, 3)];
			 Ty = Tw - Tx;
			 Td = Tb + Tc;
			 TN = Tw + Tx;
			 Tz = Tv - Ty;
			 TH = Tv + Ty;
		    }
		    {
			 E T8, T9, Tq, Tr, Ts, Tt;
			 T8 = ri[WS(is, 1)];
			 T9 = ri[WS(is, 5)];
			 Tq = T8 - T9;
			 Tr = ii[WS(is, 1)];
			 Ts = ii[WS(is, 5)];
			 Tt = Tr - Ts;
			 Ta = T8 + T9;
			 TM = Tr + Ts;
			 Tu = Tq + Tt;
			 TG = Tt - Tq;
		    }
	       }
	       {
		    E T7, Te, TP, TQ;
		    T7 = T3 + T6;
		    Te = Ta + Td;
		    ro[WS(os, 4)] = T7 - Te;
		    ro[0] = T7 + Te;
		    TP = Ti + Tl;
		    TQ = TM + TN;
		    io[WS(os, 4)] = TP - TQ;
		    io[0] = TP + TQ;
	       }
	       {
		    E Tf, Tm, TL, TO;
		    Tf = Td - Ta;
		    Tm = Ti - Tl;
		    io[WS(os, 2)] = Tf + Tm;
		    io[WS(os, 6)] = Tm - Tf;
		    TL = T3 - T6;
		    TO = TM - TN;
		    ro[WS(os, 6)] = TL - TO;
		    ro[WS(os, 2)] = TL + TO;
	       }
	       {
		    E Tp, TA, TJ, TK;
		    Tp = Tn + To;
		    TA = KP707106781 * (Tu + Tz);
		    ro[WS(os, 5)] = Tp - TA;
		    ro[WS(os, 1)] = Tp + TA;
		    TJ = TC - TB;
		    TK = KP707106781 * (TG + TH);
		    io[WS(os, 5)] = TJ - TK;
		    io[WS(os, 1)] = TJ + TK;
	       }
	       {
		    E TD, TE, TF, TI;
		    TD = TB + TC;
		    TE = KP707106781 * (Tz - Tu);
		    io[WS(os, 7)] = TD - TE;
		    io[WS(os, 3)] = TD + TE;
		    TF = Tn - To;
		    TI = KP707106781 * (TG - TH);
		    ro[WS(os, 7)] = TF - TI;
		    ro[WS(os, 3)] = TF + TI;
	       }
	  }
     }
}

static const kdft_desc desc = { 8, "n1_8", {52, 4, 0, 0}, &GENUS, 0, 0, 0, 0 };

void X(codelet_n1_8) (planner *p) {
     X(kdft_register) (p, n1_8, &desc);
}

#endif				/* HAVE_FMA */
