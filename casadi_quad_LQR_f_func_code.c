/* This file was automatically generated by CasADi.
   The CasADi copyright holders make no ownership claim of its contents. */
#ifdef __cplusplus
extern "C" {
#endif

/* How to prefix internal symbols */
#ifdef CASADI_CODEGEN_PREFIX
  #define CASADI_NAMESPACE_CONCAT(NS, ID) _CASADI_NAMESPACE_CONCAT(NS, ID)
  #define _CASADI_NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) CASADI_NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else
  #define CASADI_PREFIX(ID) casadi_quad_LQR_f_func_code_ ## ID
#endif

#include <math.h>
#include <string.h>
#ifdef MATLAB_MEX_FILE
#include <mex.h>
#endif

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int long long int
#endif

/* Add prefix to internal symbols */
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_fill CASADI_PREFIX(fill)
#define casadi_from_mex CASADI_PREFIX(from_mex)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_to_mex CASADI_PREFIX(to_mex)

/* Symbol visibility in DLLs */
#ifndef CASADI_SYMBOL_EXPORT
  #if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    #if defined(STATIC_LINKED)
      #define CASADI_SYMBOL_EXPORT
    #else
      #define CASADI_SYMBOL_EXPORT __declspec(dllexport)
    #endif
  #elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
    #define CASADI_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define CASADI_SYMBOL_EXPORT
  #endif
#endif

void casadi_fill(casadi_real* x, casadi_int n, casadi_real alpha) {
  casadi_int i;
  if (x) {
    for (i=0; i<n; ++i) *x++ = alpha;
  }
}

#ifdef MATLAB_MEX_FILE
casadi_real* casadi_from_mex(const mxArray* p, casadi_real* y, const casadi_int* sp, casadi_real* w) {
  casadi_int nrow, ncol, nnz, is_sparse, c, k;
  const casadi_int *colind, *row;
  size_t p_nrow, p_ncol;
  mwIndex *Jc, *Ir;
  const double* p_data;
  if (!mxIsDouble(p) || mxGetNumberOfDimensions(p)!=2)
    mexErrMsgIdAndTxt("Casadi:RuntimeError",
      "\"from_mex\" failed: Not a two-dimensional matrix of double precision.");
  nrow = *sp++;
  ncol = *sp++;
  nnz = sp[ncol];
  colind = sp;
  row = sp+ncol+1;
  p_nrow = mxGetM(p);
  p_ncol = mxGetN(p);
  is_sparse = mxIsSparse(p);
  if (is_sparse) {
#ifndef CASADI_MEX_NO_SPARSE
    Jc = mxGetJc(p);
    Ir = mxGetIr(p);
#else /* CASADI_MEX_NO_SPARSE */
    mexErrMsgIdAndTxt("Casadi:RuntimeError",
      "\"from_mex\" failed: Sparse inputs disabled.");
#endif /* CASADI_MEX_NO_SPARSE */
  }
  p_data = (const double*)mxGetData(p);
  if (p_nrow==1 && p_ncol==1) {
    double v = is_sparse && Jc[1]==0 ? 0 : *p_data;
    casadi_fill(y, nnz, v);
  } else {
    casadi_int tr = 0;
    if (nrow!=p_nrow || ncol!=p_ncol) {
      tr = nrow==p_ncol && ncol==p_nrow && (nrow==1 || ncol==1);
      if (!tr) mexErrMsgIdAndTxt("Casadi:RuntimeError",
                                 "\"from_mex\" failed: Dimension mismatch.");
    }
    if (is_sparse) {
      if (tr) {
        for (c=0; c<ncol; ++c)
          for (k=colind[c]; k<colind[c+1]; ++k) w[row[k]+c*nrow]=0;
        for (c=0; c<p_ncol; ++c)
          for (k=Jc[c]; k<Jc[c+1]; ++k) w[c+Ir[k]*p_ncol] = p_data[k];
        for (c=0; c<ncol; ++c)
          for (k=colind[c]; k<colind[c+1]; ++k) y[k] = w[row[k]+c*nrow];
      } else {
        for (c=0; c<ncol; ++c) {
          for (k=colind[c]; k<colind[c+1]; ++k) w[row[k]]=0;
          for (k=Jc[c]; k<Jc[c+1]; ++k) w[Ir[k]]=p_data[k];
          for (k=colind[c]; k<colind[c+1]; ++k) y[k]=w[row[k]];
        }
      }
    } else {
      for (c=0; c<ncol; ++c) {
        for (k=colind[c]; k<colind[c+1]; ++k) {
          y[k] = p_data[row[k]+c*nrow];
        }
      }
    }
  }
  return y;
}

#endif

#define casadi_to_double(x) ((double) x)

#ifdef MATLAB_MEX_FILE
mxArray* casadi_to_mex(const casadi_int* sp, const casadi_real* x) {
  casadi_int nrow, ncol, nnz, c, k;
  const casadi_int *colind, *row;
  mxArray *p;
  double *d;
#ifndef CASADI_MEX_NO_SPARSE
  casadi_int i;
  mwIndex *j;
#endif /* CASADI_MEX_NO_SPARSE */
  nrow = *sp++;
  ncol = *sp++;
  nnz = sp[ncol];
  colind = sp;
  row = sp+ncol+1;
#ifndef CASADI_MEX_NO_SPARSE
  if (nnz!=nrow*ncol) {
    p = mxCreateSparse(nrow, ncol, nnz, mxREAL);
    for (i=0, j=mxGetJc(p); i<=ncol; ++i) *j++ = *colind++;
    for (i=0, j=mxGetIr(p); i<nnz; ++i) *j++ = *row++;
    if (x) {
      d = (double*)mxGetData(p);
      for (i=0; i<nnz; ++i) *d++ = casadi_to_double(*x++);
    }
    return p;
  }
#endif /* CASADI_MEX_NO_SPARSE */
  p = mxCreateDoubleMatrix(nrow, ncol, mxREAL);
  if (x) {
    d = (double*)mxGetData(p);
    for (c=0; c<ncol; ++c) {
      for (k=colind[c]; k<colind[c+1]; ++k) {
        d[row[k]+c*nrow] = casadi_to_double(*x++);
      }
    }
  }
  return p;
}

#endif

static const casadi_int casadi_s0[28] = {24, 1, 0, 24, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
static const casadi_int casadi_s1[8] = {4, 1, 0, 4, 0, 1, 2, 3};

/* quad_LQR_f_func:(i0[24],i1[24],i2[4])->(o0[24]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a2, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a3, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a4, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a5, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a6, a60, a61, a62, a63, a7, a8, a9;
  a0=arg[0]? arg[0][6] : 0;
  if (res[0]!=0) res[0][0]=a0;
  a0=arg[0]? arg[0][7] : 0;
  if (res[0]!=0) res[0][1]=a0;
  a0=arg[0]? arg[0][8] : 0;
  if (res[0]!=0) res[0][2]=a0;
  a0=arg[0]? arg[0][9] : 0;
  a1=arg[0]? arg[0][3] : 0;
  a2=sin(a1);
  a3=arg[0]? arg[0][4] : 0;
  a4=tan(a3);
  a2=(a2*a4);
  a4=arg[0]? arg[0][10] : 0;
  a2=(a2*a4);
  a2=(a0+a2);
  a5=cos(a1);
  a6=tan(a3);
  a5=(a5*a6);
  a6=arg[0]? arg[0][11] : 0;
  a5=(a5*a6);
  a2=(a2+a5);
  if (res[0]!=0) res[0][3]=a2;
  a2=cos(a1);
  a2=(a2*a4);
  a5=sin(a1);
  a5=(a5*a6);
  a2=(a2-a5);
  if (res[0]!=0) res[0][4]=a2;
  a2=sin(a1);
  a5=cos(a3);
  a2=(a2/a5);
  a2=(a2*a4);
  a5=cos(a1);
  a7=cos(a3);
  a5=(a5/a7);
  a5=(a5*a6);
  a2=(a2+a5);
  if (res[0]!=0) res[0][5]=a2;
  a2=6.6852248508526335e-02;
  a5=arg[1]? arg[1][0] : 0;
  a7=(a2*a5);
  a8=arg[2]? arg[2][0] : 0;
  a7=(a7*a8);
  a9=arg[1]? arg[1][3] : 0;
  a10=(a2*a9);
  a11=arg[2]? arg[2][1] : 0;
  a10=(a10*a11);
  a7=(a7+a10);
  a10=arg[1]? arg[1][6] : 0;
  a12=(a2*a10);
  a13=arg[2]? arg[2][2] : 0;
  a12=(a12*a13);
  a7=(a7+a12);
  a12=arg[1]? arg[1][9] : 0;
  a14=(a2*a12);
  a15=arg[2]? arg[2][3] : 0;
  a14=(a14*a15);
  a7=(a7+a14);
  if (res[0]!=0) res[0][6]=a7;
  a7=arg[1]? arg[1][1] : 0;
  a14=(a2*a7);
  a14=(a14*a8);
  a16=arg[1]? arg[1][4] : 0;
  a17=(a2*a16);
  a17=(a17*a11);
  a14=(a14+a17);
  a17=arg[1]? arg[1][7] : 0;
  a18=(a2*a17);
  a18=(a18*a13);
  a14=(a14+a18);
  a18=arg[1]? arg[1][10] : 0;
  a19=(a2*a18);
  a19=(a19*a15);
  a14=(a14+a19);
  if (res[0]!=0) res[0][7]=a14;
  a14=-9.8049999999999997e+00;
  a19=arg[1]? arg[1][2] : 0;
  a20=(a2*a19);
  a20=(a20*a8);
  a21=arg[1]? arg[1][5] : 0;
  a22=(a2*a21);
  a22=(a22*a11);
  a20=(a20+a22);
  a22=arg[1]? arg[1][8] : 0;
  a23=(a2*a22);
  a23=(a23*a13);
  a20=(a20+a23);
  a23=arg[1]? arg[1][11] : 0;
  a2=(a2*a23);
  a2=(a2*a15);
  a20=(a20+a2);
  a14=(a14+a20);
  if (res[0]!=0) res[0][8]=a14;
  a14=8.6573059546032525e+00;
  a20=1.6366395000000000e-01;
  a2=(a20*a6);
  a2=(a2*a4);
  a24=2.3296957500000001e-01;
  a25=(a24*a4);
  a25=(a25*a6);
  a2=(a2-a25);
  a25=-4.2451727999999997e+00;
  a26=1.8500000000000000e-01;
  a27=cos(a3);
  a28=cos(a1);
  a29=(a27*a28);
  a30=(a26*a29);
  a30=(a25*a30);
  a31=1.;
  a32=(a31-a8);
  a30=(a30*a32);
  a2=(a2+a30);
  a30=arg[0]? arg[0][5] : 0;
  a33=cos(a30);
  a34=sin(a3);
  a35=(a33*a34);
  a36=sin(a1);
  a37=(a35*a36);
  a38=sin(a30);
  a39=cos(a1);
  a40=(a38*a39);
  a37=(a37-a40);
  a40=arg[0]? arg[0][12] : 0;
  a41=arg[0]? arg[0][0] : 0;
  a40=(a40-a41);
  a42=(a37*a40);
  a43=cos(a30);
  a39=(a43*a39);
  a30=sin(a30);
  a34=(a30*a34);
  a44=(a34*a36);
  a39=(a39+a44);
  a44=arg[0]? arg[0][13] : 0;
  a45=arg[0]? arg[0][1] : 0;
  a44=(a44-a45);
  a46=(a39*a44);
  a42=(a42+a46);
  a27=(a27*a36);
  a36=arg[0]? arg[0][14] : 0;
  a46=arg[0]? arg[0][2] : 0;
  a36=(a36-a46);
  a47=(a27*a36);
  a42=(a42+a47);
  a47=(a8*a42);
  a1=sin(a1);
  a38=(a38*a1);
  a35=(a35*a28);
  a38=(a38+a35);
  a35=(a47*a38);
  a48=(a38*a40);
  a34=(a34*a28);
  a43=(a43*a1);
  a34=(a34-a43);
  a43=(a34*a44);
  a48=(a48+a43);
  a43=(a29*a36);
  a48=(a48+a43);
  a43=(a8*a48);
  a1=(a43*a37);
  a35=(a35-a1);
  a35=(a35*a5);
  a1=(a47*a34);
  a28=(a43*a39);
  a1=(a1-a28);
  a1=(a1*a7);
  a35=(a35+a1);
  a47=(a47*a29);
  a43=(a43*a27);
  a47=(a47-a43);
  a47=(a47*a19);
  a35=(a35+a47);
  a2=(a2+a35);
  a35=-1.8500000000000000e-01;
  a47=(a35*a29);
  a47=(a25*a47);
  a43=(a31-a11);
  a47=(a47*a43);
  a2=(a2+a47);
  a47=arg[0]? arg[0][15] : 0;
  a47=(a47-a41);
  a1=(a37*a47);
  a28=arg[0]? arg[0][16] : 0;
  a28=(a28-a45);
  a49=(a39*a28);
  a1=(a1+a49);
  a49=arg[0]? arg[0][17] : 0;
  a49=(a49-a46);
  a50=(a27*a49);
  a1=(a1+a50);
  a50=(a11*a1);
  a51=(a50*a38);
  a52=(a38*a47);
  a53=(a34*a28);
  a52=(a52+a53);
  a53=(a29*a49);
  a52=(a52+a53);
  a53=(a11*a52);
  a54=(a53*a37);
  a51=(a51-a54);
  a51=(a51*a9);
  a54=(a50*a34);
  a55=(a53*a39);
  a54=(a54-a55);
  a54=(a54*a16);
  a51=(a51+a54);
  a50=(a50*a29);
  a53=(a53*a27);
  a50=(a50-a53);
  a50=(a50*a21);
  a51=(a51+a50);
  a2=(a2+a51);
  a51=(a26*a29);
  a51=(a25*a51);
  a50=(a31-a13);
  a51=(a51*a50);
  a2=(a2+a51);
  a51=arg[0]? arg[0][18] : 0;
  a51=(a51-a41);
  a53=(a37*a51);
  a54=arg[0]? arg[0][19] : 0;
  a54=(a54-a45);
  a55=(a39*a54);
  a53=(a53+a55);
  a55=arg[0]? arg[0][20] : 0;
  a55=(a55-a46);
  a56=(a27*a55);
  a53=(a53+a56);
  a56=(a13*a53);
  a57=(a56*a38);
  a58=(a38*a51);
  a59=(a34*a54);
  a58=(a58+a59);
  a59=(a29*a55);
  a58=(a58+a59);
  a59=(a13*a58);
  a60=(a59*a37);
  a57=(a57-a60);
  a57=(a57*a10);
  a60=(a56*a34);
  a61=(a59*a39);
  a60=(a60-a61);
  a60=(a60*a17);
  a57=(a57+a60);
  a56=(a56*a29);
  a59=(a59*a27);
  a56=(a56-a59);
  a56=(a56*a22);
  a57=(a57+a56);
  a2=(a2+a57);
  a57=(a35*a29);
  a57=(a25*a57);
  a31=(a31-a15);
  a57=(a57*a31);
  a2=(a2+a57);
  a57=arg[0]? arg[0][21] : 0;
  a57=(a57-a41);
  a41=(a37*a57);
  a56=arg[0]? arg[0][22] : 0;
  a56=(a56-a45);
  a45=(a39*a56);
  a41=(a41+a45);
  a45=arg[0]? arg[0][23] : 0;
  a45=(a45-a46);
  a46=(a27*a45);
  a41=(a41+a46);
  a46=(a15*a41);
  a59=(a46*a38);
  a60=(a38*a57);
  a61=(a34*a56);
  a60=(a60+a61);
  a61=(a29*a45);
  a60=(a60+a61);
  a61=(a15*a60);
  a62=(a61*a37);
  a59=(a59-a62);
  a59=(a59*a12);
  a62=(a46*a34);
  a63=(a61*a39);
  a62=(a62-a63);
  a62=(a62*a18);
  a59=(a59+a62);
  a46=(a46*a29);
  a61=(a61*a27);
  a46=(a46-a61);
  a46=(a46*a23);
  a59=(a59+a46);
  a2=(a2+a59);
  a14=(a14*a2);
  if (res[0]!=0) res[0][9]=a14;
  a14=6.1100810532802123e+00;
  a24=(a24*a0);
  a24=(a24*a6);
  a2=1.1550937500000000e-01;
  a6=(a2*a6);
  a6=(a6*a0);
  a24=(a24-a6);
  a6=-1.4999999999999999e-01;
  a59=(a6*a29);
  a59=(a25*a59);
  a59=(a59*a32);
  a24=(a24+a59);
  a48=(a8*a48);
  a59=cos(a3);
  a33=(a33*a59);
  a46=(a48*a33);
  a40=(a33*a40);
  a30=(a30*a59);
  a44=(a30*a44);
  a40=(a40+a44);
  a3=sin(a3);
  a36=(a3*a36);
  a40=(a40-a36);
  a36=(a8*a40);
  a44=(a36*a38);
  a46=(a46-a44);
  a46=(a46*a5);
  a44=(a48*a30);
  a59=(a36*a34);
  a44=(a44-a59);
  a44=(a44*a7);
  a46=(a46+a44);
  a48=(a48*a3);
  a36=(a36*a29);
  a48=(a48+a36);
  a48=(a48*a19);
  a46=(a46-a48);
  a24=(a24+a46);
  a46=(a6*a29);
  a46=(a25*a46);
  a46=(a46*a43);
  a24=(a24+a46);
  a52=(a11*a52);
  a46=(a52*a33);
  a47=(a33*a47);
  a28=(a30*a28);
  a47=(a47+a28);
  a49=(a3*a49);
  a47=(a47-a49);
  a49=(a11*a47);
  a28=(a49*a38);
  a46=(a46-a28);
  a46=(a46*a9);
  a28=(a52*a30);
  a48=(a49*a34);
  a28=(a28-a48);
  a28=(a28*a16);
  a46=(a46+a28);
  a52=(a52*a3);
  a49=(a49*a29);
  a52=(a52+a49);
  a52=(a52*a21);
  a46=(a46-a52);
  a24=(a24+a46);
  a46=1.4999999999999999e-01;
  a52=(a46*a29);
  a52=(a25*a52);
  a52=(a52*a50);
  a24=(a24+a52);
  a58=(a13*a58);
  a52=(a58*a33);
  a51=(a33*a51);
  a54=(a30*a54);
  a51=(a51+a54);
  a55=(a3*a55);
  a51=(a51-a55);
  a55=(a13*a51);
  a54=(a55*a38);
  a52=(a52-a54);
  a52=(a52*a10);
  a54=(a58*a30);
  a49=(a55*a34);
  a54=(a54-a49);
  a54=(a54*a17);
  a52=(a52+a54);
  a58=(a58*a3);
  a55=(a55*a29);
  a58=(a58+a55);
  a58=(a58*a22);
  a52=(a52-a58);
  a24=(a24+a52);
  a52=(a46*a29);
  a52=(a25*a52);
  a52=(a52*a31);
  a24=(a24+a52);
  a60=(a15*a60);
  a52=(a60*a33);
  a57=(a33*a57);
  a56=(a30*a56);
  a57=(a57+a56);
  a45=(a3*a45);
  a57=(a57-a45);
  a45=(a15*a57);
  a38=(a45*a38);
  a52=(a52-a38);
  a52=(a52*a12);
  a38=(a60*a30);
  a34=(a45*a34);
  a38=(a38-a34);
  a38=(a38*a18);
  a52=(a52+a38);
  a60=(a60*a3);
  a45=(a45*a29);
  a60=(a60+a45);
  a60=(a60*a23);
  a52=(a52-a60);
  a24=(a24+a52);
  a14=(a14*a24);
  if (res[0]!=0) res[0][10]=a14;
  a14=4.2924059933577166e+00;
  a2=(a2*a4);
  a2=(a2*a0);
  a20=(a20*a0);
  a20=(a20*a4);
  a2=(a2-a20);
  a20=(a46*a27);
  a4=(a35*a3);
  a20=(a20-a4);
  a20=(a25*a20);
  a20=(a20*a32);
  a2=(a2+a20);
  a40=(a8*a40);
  a20=(a40*a37);
  a8=(a8*a42);
  a42=(a8*a33);
  a20=(a20-a42);
  a20=(a20*a5);
  a5=(a40*a39);
  a42=(a8*a30);
  a5=(a5-a42);
  a5=(a5*a7);
  a20=(a20+a5);
  a8=(a8*a3);
  a40=(a40*a27);
  a8=(a8+a40);
  a8=(a8*a19);
  a20=(a20+a8);
  a2=(a2+a20);
  a46=(a46*a27);
  a20=(a26*a3);
  a46=(a46-a20);
  a46=(a25*a46);
  a46=(a46*a43);
  a2=(a2+a46);
  a47=(a11*a47);
  a46=(a47*a37);
  a11=(a11*a1);
  a1=(a11*a33);
  a46=(a46-a1);
  a46=(a46*a9);
  a9=(a47*a39);
  a1=(a11*a30);
  a9=(a9-a1);
  a9=(a9*a16);
  a46=(a46+a9);
  a11=(a11*a3);
  a47=(a47*a27);
  a11=(a11+a47);
  a11=(a11*a21);
  a46=(a46+a11);
  a2=(a2+a46);
  a46=(a6*a27);
  a35=(a35*a3);
  a46=(a46-a35);
  a46=(a25*a46);
  a46=(a46*a50);
  a2=(a2+a46);
  a51=(a13*a51);
  a46=(a51*a37);
  a13=(a13*a53);
  a53=(a13*a33);
  a46=(a46-a53);
  a46=(a46*a10);
  a10=(a51*a39);
  a53=(a13*a30);
  a10=(a10-a53);
  a10=(a10*a17);
  a46=(a46+a10);
  a13=(a13*a3);
  a51=(a51*a27);
  a13=(a13+a51);
  a13=(a13*a22);
  a46=(a46+a13);
  a2=(a2+a46);
  a6=(a6*a27);
  a26=(a26*a3);
  a6=(a6-a26);
  a25=(a25*a6);
  a25=(a25*a31);
  a2=(a2+a25);
  a57=(a15*a57);
  a37=(a57*a37);
  a15=(a15*a41);
  a33=(a15*a33);
  a37=(a37-a33);
  a37=(a37*a12);
  a39=(a57*a39);
  a30=(a15*a30);
  a39=(a39-a30);
  a39=(a39*a18);
  a37=(a37+a39);
  a15=(a15*a3);
  a57=(a57*a27);
  a15=(a15+a57);
  a15=(a15*a23);
  a37=(a37+a15);
  a2=(a2+a37);
  a14=(a14*a2);
  if (res[0]!=0) res[0][11]=a14;
  a14=arg[1]? arg[1][12] : 0;
  if (res[0]!=0) res[0][12]=a14;
  a14=arg[1]? arg[1][13] : 0;
  if (res[0]!=0) res[0][13]=a14;
  a14=arg[1]? arg[1][14] : 0;
  if (res[0]!=0) res[0][14]=a14;
  a14=arg[1]? arg[1][15] : 0;
  if (res[0]!=0) res[0][15]=a14;
  a14=arg[1]? arg[1][16] : 0;
  if (res[0]!=0) res[0][16]=a14;
  a14=arg[1]? arg[1][17] : 0;
  if (res[0]!=0) res[0][17]=a14;
  a14=arg[1]? arg[1][18] : 0;
  if (res[0]!=0) res[0][18]=a14;
  a14=arg[1]? arg[1][19] : 0;
  if (res[0]!=0) res[0][19]=a14;
  a14=arg[1]? arg[1][20] : 0;
  if (res[0]!=0) res[0][20]=a14;
  a14=arg[1]? arg[1][21] : 0;
  if (res[0]!=0) res[0][21]=a14;
  a14=arg[1]? arg[1][22] : 0;
  if (res[0]!=0) res[0][22]=a14;
  a14=arg[1]? arg[1][23] : 0;
  if (res[0]!=0) res[0][23]=a14;
  return 0;
}

CASADI_SYMBOL_EXPORT int quad_LQR_f_func(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int quad_LQR_f_func_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int quad_LQR_f_func_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void quad_LQR_f_func_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int quad_LQR_f_func_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void quad_LQR_f_func_release(int mem) {
}

CASADI_SYMBOL_EXPORT void quad_LQR_f_func_incref(void) {
}

CASADI_SYMBOL_EXPORT void quad_LQR_f_func_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int quad_LQR_f_func_n_in(void) { return 3;}

CASADI_SYMBOL_EXPORT casadi_int quad_LQR_f_func_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real quad_LQR_f_func_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* quad_LQR_f_func_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* quad_LQR_f_func_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* quad_LQR_f_func_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s0;
    case 2: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* quad_LQR_f_func_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int quad_LQR_f_func_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 3;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

#ifdef MATLAB_MEX_FILE
void mex_quad_LQR_f_func(int resc, mxArray *resv[], int argc, const mxArray *argv[]) {
  casadi_int i, j;
  casadi_real w[140];
  casadi_int *iw = 0;
  const casadi_real* arg[3] = {0};
  casadi_real* res[1] = {0};
  if (argc>3) mexErrMsgIdAndTxt("Casadi:RuntimeError","Evaluation of \"quad_LQR_f_func\" failed. Too many input arguments (%d, max 3)", argc);
  if (resc>1) mexErrMsgIdAndTxt("Casadi:RuntimeError","Evaluation of \"quad_LQR_f_func\" failed. Too many output arguments (%d, max 1)", resc);
  if (--argc>=0) arg[0] = casadi_from_mex(argv[0], w, casadi_s0, w+76);
  if (--argc>=0) arg[1] = casadi_from_mex(argv[1], w+24, casadi_s0, w+76);
  if (--argc>=0) arg[2] = casadi_from_mex(argv[2], w+48, casadi_s1, w+76);
  --resc;
  res[0] = w+52;
  i = quad_LQR_f_func(arg, res, iw, w+76, 0);
  if (i) mexErrMsgIdAndTxt("Casadi:RuntimeError","Evaluation of \"quad_LQR_f_func\" failed.");
  if (res[0]) resv[0] = casadi_to_mex(casadi_s0, res[0]);
}
#endif


#ifdef MATLAB_MEX_FILE
void mexFunction(int resc, mxArray *resv[], int argc, const mxArray *argv[]) {
  char buf[16];
  int buf_ok = --argc >= 0 && !mxGetString(*argv++, buf, sizeof(buf));
  if (!buf_ok) {
    /* name error */
  } else if (strcmp(buf, "quad_LQR_f_func")==0) {
    mex_quad_LQR_f_func(resc, resv, argc, argv);
    return;
  }
  mexErrMsgTxt("First input should be a command string. Possible values: 'quad_LQR_f_func'");
}
#endif
#ifdef __cplusplus
} /* extern "C" */
#endif