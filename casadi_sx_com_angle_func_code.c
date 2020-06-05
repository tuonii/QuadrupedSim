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
  #define CASADI_PREFIX(ID) casadi_sx_com_angle_func_code_ ## ID
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
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_sq CASADI_PREFIX(sq)
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

casadi_real casadi_sq(casadi_real x) { return x*x;}

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

static const casadi_int casadi_s0[5] = {1, 1, 0, 1, 0};
static const casadi_int casadi_s1[1552] = {1548, 1, 0, 1548, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524, 525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576, 577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 588, 589, 590, 591, 592, 593, 594, 595, 596, 597, 598, 599, 600, 601, 602, 603, 604, 605, 606, 607, 608, 609, 610, 611, 612, 613, 614, 615, 616, 617, 618, 619, 620, 621, 622, 623, 624, 625, 626, 627, 628, 629, 630, 631, 632, 633, 634, 635, 636, 637, 638, 639, 640, 641, 642, 643, 644, 645, 646, 647, 648, 649, 650, 651, 652, 653, 654, 655, 656, 657, 658, 659, 660, 661, 662, 663, 664, 665, 666, 667, 668, 669, 670, 671, 672, 673, 674, 675, 676, 677, 678, 679, 680, 681, 682, 683, 684, 685, 686, 687, 688, 689, 690, 691, 692, 693, 694, 695, 696, 697, 698, 699, 700, 701, 702, 703, 704, 705, 706, 707, 708, 709, 710, 711, 712, 713, 714, 715, 716, 717, 718, 719, 720, 721, 722, 723, 724, 725, 726, 727, 728, 729, 730, 731, 732, 733, 734, 735, 736, 737, 738, 739, 740, 741, 742, 743, 744, 745, 746, 747, 748, 749, 750, 751, 752, 753, 754, 755, 756, 757, 758, 759, 760, 761, 762, 763, 764, 765, 766, 767, 768, 769, 770, 771, 772, 773, 774, 775, 776, 777, 778, 779, 780, 781, 782, 783, 784, 785, 786, 787, 788, 789, 790, 791, 792, 793, 794, 795, 796, 797, 798, 799, 800, 801, 802, 803, 804, 805, 806, 807, 808, 809, 810, 811, 812, 813, 814, 815, 816, 817, 818, 819, 820, 821, 822, 823, 824, 825, 826, 827, 828, 829, 830, 831, 832, 833, 834, 835, 836, 837, 838, 839, 840, 841, 842, 843, 844, 845, 846, 847, 848, 849, 850, 851, 852, 853, 854, 855, 856, 857, 858, 859, 860, 861, 862, 863, 864, 865, 866, 867, 868, 869, 870, 871, 872, 873, 874, 875, 876, 877, 878, 879, 880, 881, 882, 883, 884, 885, 886, 887, 888, 889, 890, 891, 892, 893, 894, 895, 896, 897, 898, 899, 900, 901, 902, 903, 904, 905, 906, 907, 908, 909, 910, 911, 912, 913, 914, 915, 916, 917, 918, 919, 920, 921, 922, 923, 924, 925, 926, 927, 928, 929, 930, 931, 932, 933, 934, 935, 936, 937, 938, 939, 940, 941, 942, 943, 944, 945, 946, 947, 948, 949, 950, 951, 952, 953, 954, 955, 956, 957, 958, 959, 960, 961, 962, 963, 964, 965, 966, 967, 968, 969, 970, 971, 972, 973, 974, 975, 976, 977, 978, 979, 980, 981, 982, 983, 984, 985, 986, 987, 988, 989, 990, 991, 992, 993, 994, 995, 996, 997, 998, 999, 1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020, 1021, 1022, 1023, 1024, 1025, 1026, 1027, 1028, 1029, 1030, 1031, 1032, 1033, 1034, 1035, 1036, 1037, 1038, 1039, 1040, 1041, 1042, 1043, 1044, 1045, 1046, 1047, 1048, 1049, 1050, 1051, 1052, 1053, 1054, 1055, 1056, 1057, 1058, 1059, 1060, 1061, 1062, 1063, 1064, 1065, 1066, 1067, 1068, 1069, 1070, 1071, 1072, 1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087, 1088, 1089, 1090, 1091, 1092, 1093, 1094, 1095, 1096, 1097, 1098, 1099, 1100, 1101, 1102, 1103, 1104, 1105, 1106, 1107, 1108, 1109, 1110, 1111, 1112, 1113, 1114, 1115, 1116, 1117, 1118, 1119, 1120, 1121, 1122, 1123, 1124, 1125, 1126, 1127, 1128, 1129, 1130, 1131, 1132, 1133, 1134, 1135, 1136, 1137, 1138, 1139, 1140, 1141, 1142, 1143, 1144, 1145, 1146, 1147, 1148, 1149, 1150, 1151, 1152, 1153, 1154, 1155, 1156, 1157, 1158, 1159, 1160, 1161, 1162, 1163, 1164, 1165, 1166, 1167, 1168, 1169, 1170, 1171, 1172, 1173, 1174, 1175, 1176, 1177, 1178, 1179, 1180, 1181, 1182, 1183, 1184, 1185, 1186, 1187, 1188, 1189, 1190, 1191, 1192, 1193, 1194, 1195, 1196, 1197, 1198, 1199, 1200, 1201, 1202, 1203, 1204, 1205, 1206, 1207, 1208, 1209, 1210, 1211, 1212, 1213, 1214, 1215, 1216, 1217, 1218, 1219, 1220, 1221, 1222, 1223, 1224, 1225, 1226, 1227, 1228, 1229, 1230, 1231, 1232, 1233, 1234, 1235, 1236, 1237, 1238, 1239, 1240, 1241, 1242, 1243, 1244, 1245, 1246, 1247, 1248, 1249, 1250, 1251, 1252, 1253, 1254, 1255, 1256, 1257, 1258, 1259, 1260, 1261, 1262, 1263, 1264, 1265, 1266, 1267, 1268, 1269, 1270, 1271, 1272, 1273, 1274, 1275, 1276, 1277, 1278, 1279, 1280, 1281, 1282, 1283, 1284, 1285, 1286, 1287, 1288, 1289, 1290, 1291, 1292, 1293, 1294, 1295, 1296, 1297, 1298, 1299, 1300, 1301, 1302, 1303, 1304, 1305, 1306, 1307, 1308, 1309, 1310, 1311, 1312, 1313, 1314, 1315, 1316, 1317, 1318, 1319, 1320, 1321, 1322, 1323, 1324, 1325, 1326, 1327, 1328, 1329, 1330, 1331, 1332, 1333, 1334, 1335, 1336, 1337, 1338, 1339, 1340, 1341, 1342, 1343, 1344, 1345, 1346, 1347, 1348, 1349, 1350, 1351, 1352, 1353, 1354, 1355, 1356, 1357, 1358, 1359, 1360, 1361, 1362, 1363, 1364, 1365, 1366, 1367, 1368, 1369, 1370, 1371, 1372, 1373, 1374, 1375, 1376, 1377, 1378, 1379, 1380, 1381, 1382, 1383, 1384, 1385, 1386, 1387, 1388, 1389, 1390, 1391, 1392, 1393, 1394, 1395, 1396, 1397, 1398, 1399, 1400, 1401, 1402, 1403, 1404, 1405, 1406, 1407, 1408, 1409, 1410, 1411, 1412, 1413, 1414, 1415, 1416, 1417, 1418, 1419, 1420, 1421, 1422, 1423, 1424, 1425, 1426, 1427, 1428, 1429, 1430, 1431, 1432, 1433, 1434, 1435, 1436, 1437, 1438, 1439, 1440, 1441, 1442, 1443, 1444, 1445, 1446, 1447, 1448, 1449, 1450, 1451, 1452, 1453, 1454, 1455, 1456, 1457, 1458, 1459, 1460, 1461, 1462, 1463, 1464, 1465, 1466, 1467, 1468, 1469, 1470, 1471, 1472, 1473, 1474, 1475, 1476, 1477, 1478, 1479, 1480, 1481, 1482, 1483, 1484, 1485, 1486, 1487, 1488, 1489, 1490, 1491, 1492, 1493, 1494, 1495, 1496, 1497, 1498, 1499, 1500, 1501, 1502, 1503, 1504, 1505, 1506, 1507, 1508, 1509, 1510, 1511, 1512, 1513, 1514, 1515, 1516, 1517, 1518, 1519, 1520, 1521, 1522, 1523, 1524, 1525, 1526, 1527, 1528, 1529, 1530, 1531, 1532, 1533, 1534, 1535, 1536, 1537, 1538, 1539, 1540, 1541, 1542, 1543, 1544, 1545, 1546, 1547};
static const casadi_int casadi_s2[7] = {3, 1, 0, 3, 0, 1, 2};

/* com_angle:(cur_t,state[1548],com_angle0[3],com_angleT[3])->(com_ang[3]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a2, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a3, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a4, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a5, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a6, a60, a61, a62, a63, a64, a65, a66, a7, a8, a9;
  a0=0.;
  a1=arg[0]? arg[0][0] : 0;
  a0=(a0<=a1);
  a2=arg[1]? arg[1][16] : 0;
  a3=(a1<a2);
  a0=(a0&&a3);
  a3=arg[2]? arg[2][0] : 0;
  a4=2.;
  a5=(a1/a2);
  a6=casadi_sq(a5);
  a6=(a5*a6);
  a6=(a4*a6);
  a7=3.;
  a8=casadi_sq(a5);
  a8=(a7*a8);
  a6=(a6-a8);
  a8=1.;
  a6=(a6+a8);
  a3=(a3*a6);
  a9=arg[1]? arg[1][276] : 0;
  a10=-2.;
  a11=casadi_sq(a5);
  a11=(a5*a11);
  a11=(a10*a11);
  a12=casadi_sq(a5);
  a12=(a7*a12);
  a11=(a11+a12);
  a12=(a9*a11);
  a3=(a3+a12);
  a12=arg[1]? arg[1][279] : 0;
  a13=casadi_sq(a5);
  a13=(a5*a13);
  a5=casadi_sq(a5);
  a13=(a13-a5);
  a5=(a12*a13);
  a5=(a5*a2);
  a3=(a3+a5);
  a3=(a0?a3:0);
  a5=(a2<=a1);
  a14=arg[1]? arg[1][17] : 0;
  a15=(a1<a14);
  a5=(a5&&a15);
  a15=(a1-a2);
  a16=(a14-a2);
  a15=(a15/a16);
  a16=casadi_sq(a15);
  a16=(a15*a16);
  a16=(a4*a16);
  a17=casadi_sq(a15);
  a17=(a7*a17);
  a16=(a16-a17);
  a16=(a16+a8);
  a9=(a9*a16);
  a17=casadi_sq(a15);
  a17=(a15*a17);
  a18=casadi_sq(a15);
  a18=(a4*a18);
  a17=(a17-a18);
  a17=(a17+a15);
  a12=(a12*a17);
  a18=(a14-a2);
  a12=(a12*a18);
  a9=(a9+a12);
  a12=arg[1]? arg[1][282] : 0;
  a19=casadi_sq(a15);
  a19=(a15*a19);
  a19=(a10*a19);
  a20=casadi_sq(a15);
  a20=(a7*a20);
  a19=(a19+a20);
  a20=(a12*a19);
  a9=(a9+a20);
  a20=arg[1]? arg[1][285] : 0;
  a21=casadi_sq(a15);
  a21=(a15*a21);
  a15=casadi_sq(a15);
  a21=(a21-a15);
  a15=(a20*a21);
  a22=(a14-a2);
  a15=(a15*a22);
  a9=(a9+a15);
  a9=(a5?a9:0);
  a3=(a3+a9);
  a9=(a14<=a1);
  a15=arg[1]? arg[1][18] : 0;
  a23=(a1<a15);
  a9=(a9&&a23);
  a23=(a1-a14);
  a24=(a15-a14);
  a23=(a23/a24);
  a24=casadi_sq(a23);
  a24=(a23*a24);
  a24=(a4*a24);
  a25=casadi_sq(a23);
  a25=(a7*a25);
  a24=(a24-a25);
  a24=(a24+a8);
  a12=(a12*a24);
  a25=casadi_sq(a23);
  a25=(a23*a25);
  a26=casadi_sq(a23);
  a26=(a4*a26);
  a25=(a25-a26);
  a25=(a25+a23);
  a20=(a20*a25);
  a26=(a15-a14);
  a20=(a20*a26);
  a12=(a12+a20);
  a20=arg[1]? arg[1][288] : 0;
  a27=casadi_sq(a23);
  a27=(a23*a27);
  a27=(a10*a27);
  a28=casadi_sq(a23);
  a28=(a7*a28);
  a27=(a27+a28);
  a28=(a20*a27);
  a12=(a12+a28);
  a28=arg[1]? arg[1][291] : 0;
  a29=casadi_sq(a23);
  a29=(a23*a29);
  a23=casadi_sq(a23);
  a29=(a29-a23);
  a23=(a28*a29);
  a14=(a15-a14);
  a23=(a23*a14);
  a12=(a12+a23);
  a12=(a9?a12:0);
  a3=(a3+a12);
  a12=(a15<=a1);
  a23=arg[1]? arg[1][19] : 0;
  a30=(a1<a23);
  a12=(a12&&a30);
  a30=(a1-a15);
  a31=(a23-a15);
  a30=(a30/a31);
  a31=casadi_sq(a30);
  a31=(a30*a31);
  a31=(a4*a31);
  a32=casadi_sq(a30);
  a32=(a7*a32);
  a31=(a31-a32);
  a31=(a31+a8);
  a20=(a20*a31);
  a32=casadi_sq(a30);
  a32=(a30*a32);
  a33=casadi_sq(a30);
  a33=(a4*a33);
  a32=(a32-a33);
  a32=(a32+a30);
  a28=(a28*a32);
  a33=(a23-a15);
  a28=(a28*a33);
  a20=(a20+a28);
  a28=arg[1]? arg[1][294] : 0;
  a34=casadi_sq(a30);
  a34=(a30*a34);
  a34=(a10*a34);
  a35=casadi_sq(a30);
  a35=(a7*a35);
  a34=(a34+a35);
  a35=(a28*a34);
  a20=(a20+a35);
  a35=arg[1]? arg[1][297] : 0;
  a36=casadi_sq(a30);
  a36=(a30*a36);
  a30=casadi_sq(a30);
  a36=(a36-a30);
  a30=(a35*a36);
  a15=(a23-a15);
  a30=(a30*a15);
  a20=(a20+a30);
  a20=(a12?a20:0);
  a3=(a3+a20);
  a20=(a23<=a1);
  a30=arg[1]? arg[1][20] : 0;
  a37=(a1<a30);
  a20=(a20&&a37);
  a37=(a1-a23);
  a38=(a30-a23);
  a37=(a37/a38);
  a38=casadi_sq(a37);
  a38=(a37*a38);
  a38=(a4*a38);
  a39=casadi_sq(a37);
  a39=(a7*a39);
  a38=(a38-a39);
  a38=(a38+a8);
  a28=(a28*a38);
  a39=casadi_sq(a37);
  a39=(a37*a39);
  a40=casadi_sq(a37);
  a40=(a4*a40);
  a39=(a39-a40);
  a39=(a39+a37);
  a35=(a35*a39);
  a40=(a30-a23);
  a35=(a35*a40);
  a28=(a28+a35);
  a35=arg[1]? arg[1][300] : 0;
  a41=casadi_sq(a37);
  a41=(a37*a41);
  a41=(a10*a41);
  a42=casadi_sq(a37);
  a42=(a7*a42);
  a41=(a41+a42);
  a42=(a35*a41);
  a28=(a28+a42);
  a42=arg[1]? arg[1][303] : 0;
  a43=casadi_sq(a37);
  a43=(a37*a43);
  a37=casadi_sq(a37);
  a43=(a43-a37);
  a37=(a42*a43);
  a23=(a30-a23);
  a37=(a37*a23);
  a28=(a28+a37);
  a28=(a20?a28:0);
  a3=(a3+a28);
  a28=(a30<=a1);
  a37=arg[1]? arg[1][21] : 0;
  a44=(a1<a37);
  a28=(a28&&a44);
  a44=(a1-a30);
  a45=(a37-a30);
  a44=(a44/a45);
  a45=casadi_sq(a44);
  a45=(a44*a45);
  a45=(a4*a45);
  a46=casadi_sq(a44);
  a46=(a7*a46);
  a45=(a45-a46);
  a45=(a45+a8);
  a35=(a35*a45);
  a46=casadi_sq(a44);
  a46=(a44*a46);
  a47=casadi_sq(a44);
  a47=(a4*a47);
  a46=(a46-a47);
  a46=(a46+a44);
  a42=(a42*a46);
  a47=(a37-a30);
  a42=(a42*a47);
  a35=(a35+a42);
  a42=arg[1]? arg[1][306] : 0;
  a48=casadi_sq(a44);
  a48=(a44*a48);
  a48=(a10*a48);
  a49=casadi_sq(a44);
  a49=(a7*a49);
  a48=(a48+a49);
  a49=(a42*a48);
  a35=(a35+a49);
  a49=arg[1]? arg[1][309] : 0;
  a50=casadi_sq(a44);
  a50=(a44*a50);
  a44=casadi_sq(a44);
  a50=(a50-a44);
  a44=(a49*a50);
  a30=(a37-a30);
  a44=(a44*a30);
  a35=(a35+a44);
  a35=(a28?a35:0);
  a3=(a3+a35);
  a35=(a37<=a1);
  a44=arg[1]? arg[1][22] : 0;
  a51=(a1<a44);
  a35=(a35&&a51);
  a51=(a1-a37);
  a52=(a44-a37);
  a51=(a51/a52);
  a52=casadi_sq(a51);
  a52=(a51*a52);
  a52=(a4*a52);
  a53=casadi_sq(a51);
  a53=(a7*a53);
  a52=(a52-a53);
  a52=(a52+a8);
  a42=(a42*a52);
  a53=casadi_sq(a51);
  a53=(a51*a53);
  a54=casadi_sq(a51);
  a54=(a4*a54);
  a53=(a53-a54);
  a53=(a53+a51);
  a49=(a49*a53);
  a54=(a44-a37);
  a49=(a49*a54);
  a42=(a42+a49);
  a49=arg[1]? arg[1][312] : 0;
  a55=casadi_sq(a51);
  a55=(a51*a55);
  a55=(a10*a55);
  a56=casadi_sq(a51);
  a56=(a7*a56);
  a55=(a55+a56);
  a56=(a49*a55);
  a42=(a42+a56);
  a56=arg[1]? arg[1][315] : 0;
  a57=casadi_sq(a51);
  a57=(a51*a57);
  a51=casadi_sq(a51);
  a57=(a57-a51);
  a51=(a56*a57);
  a37=(a44-a37);
  a51=(a51*a37);
  a42=(a42+a51);
  a42=(a35?a42:0);
  a3=(a3+a42);
  a42=(a44<=a1);
  a51=arg[1]? arg[1][23] : 0;
  a58=(a1<a51);
  a42=(a42&&a58);
  a58=(a1-a44);
  a59=(a51-a44);
  a58=(a58/a59);
  a59=casadi_sq(a58);
  a59=(a58*a59);
  a59=(a4*a59);
  a60=casadi_sq(a58);
  a60=(a7*a60);
  a59=(a59-a60);
  a59=(a59+a8);
  a49=(a49*a59);
  a60=casadi_sq(a58);
  a60=(a58*a60);
  a61=casadi_sq(a58);
  a61=(a4*a61);
  a60=(a60-a61);
  a60=(a60+a58);
  a56=(a56*a60);
  a61=(a51-a44);
  a56=(a56*a61);
  a49=(a49+a56);
  a56=arg[1]? arg[1][318] : 0;
  a62=casadi_sq(a58);
  a62=(a58*a62);
  a62=(a10*a62);
  a63=casadi_sq(a58);
  a63=(a7*a63);
  a62=(a62+a63);
  a63=(a56*a62);
  a49=(a49+a63);
  a63=arg[1]? arg[1][321] : 0;
  a64=casadi_sq(a58);
  a64=(a58*a64);
  a58=casadi_sq(a58);
  a64=(a64-a58);
  a58=(a63*a64);
  a44=(a51-a44);
  a58=(a58*a44);
  a49=(a49+a58);
  a49=(a42?a49:0);
  a3=(a3+a49);
  a49=(a51<=a1);
  a58=4.;
  a65=(a1<=a58);
  a49=(a49&&a65);
  a1=(a1-a51);
  a65=(a58-a51);
  a1=(a1/a65);
  a65=casadi_sq(a1);
  a65=(a1*a65);
  a65=(a4*a65);
  a66=casadi_sq(a1);
  a66=(a7*a66);
  a65=(a65-a66);
  a65=(a65+a8);
  a56=(a56*a65);
  a8=casadi_sq(a1);
  a8=(a1*a8);
  a66=casadi_sq(a1);
  a4=(a4*a66);
  a8=(a8-a4);
  a8=(a8+a1);
  a63=(a63*a8);
  a58=(a58-a51);
  a63=(a63*a58);
  a56=(a56+a63);
  a63=arg[3]? arg[3][0] : 0;
  a51=casadi_sq(a1);
  a51=(a1*a51);
  a10=(a10*a51);
  a1=casadi_sq(a1);
  a7=(a7*a1);
  a10=(a10+a7);
  a63=(a63*a10);
  a56=(a56+a63);
  a56=(a49?a56:0);
  a3=(a3+a56);
  if (res[0]!=0) res[0][0]=a3;
  a3=arg[2]? arg[2][1] : 0;
  a3=(a3*a6);
  a56=arg[1]? arg[1][277] : 0;
  a63=(a56*a11);
  a3=(a3+a63);
  a63=arg[1]? arg[1][280] : 0;
  a7=(a63*a13);
  a7=(a7*a2);
  a3=(a3+a7);
  a3=(a0?a3:0);
  a56=(a56*a16);
  a63=(a63*a17);
  a63=(a63*a18);
  a56=(a56+a63);
  a63=arg[1]? arg[1][283] : 0;
  a7=(a63*a19);
  a56=(a56+a7);
  a7=arg[1]? arg[1][286] : 0;
  a1=(a7*a21);
  a1=(a1*a22);
  a56=(a56+a1);
  a56=(a5?a56:0);
  a3=(a3+a56);
  a63=(a63*a24);
  a7=(a7*a25);
  a7=(a7*a26);
  a63=(a63+a7);
  a7=arg[1]? arg[1][289] : 0;
  a56=(a7*a27);
  a63=(a63+a56);
  a56=arg[1]? arg[1][292] : 0;
  a1=(a56*a29);
  a1=(a1*a14);
  a63=(a63+a1);
  a63=(a9?a63:0);
  a3=(a3+a63);
  a7=(a7*a31);
  a56=(a56*a32);
  a56=(a56*a33);
  a7=(a7+a56);
  a56=arg[1]? arg[1][295] : 0;
  a63=(a56*a34);
  a7=(a7+a63);
  a63=arg[1]? arg[1][298] : 0;
  a1=(a63*a36);
  a1=(a1*a15);
  a7=(a7+a1);
  a7=(a12?a7:0);
  a3=(a3+a7);
  a56=(a56*a38);
  a63=(a63*a39);
  a63=(a63*a40);
  a56=(a56+a63);
  a63=arg[1]? arg[1][301] : 0;
  a7=(a63*a41);
  a56=(a56+a7);
  a7=arg[1]? arg[1][304] : 0;
  a1=(a7*a43);
  a1=(a1*a23);
  a56=(a56+a1);
  a56=(a20?a56:0);
  a3=(a3+a56);
  a63=(a63*a45);
  a7=(a7*a46);
  a7=(a7*a47);
  a63=(a63+a7);
  a7=arg[1]? arg[1][307] : 0;
  a56=(a7*a48);
  a63=(a63+a56);
  a56=arg[1]? arg[1][310] : 0;
  a1=(a56*a50);
  a1=(a1*a30);
  a63=(a63+a1);
  a63=(a28?a63:0);
  a3=(a3+a63);
  a7=(a7*a52);
  a56=(a56*a53);
  a56=(a56*a54);
  a7=(a7+a56);
  a56=arg[1]? arg[1][313] : 0;
  a63=(a56*a55);
  a7=(a7+a63);
  a63=arg[1]? arg[1][316] : 0;
  a1=(a63*a57);
  a1=(a1*a37);
  a7=(a7+a1);
  a7=(a35?a7:0);
  a3=(a3+a7);
  a56=(a56*a59);
  a63=(a63*a60);
  a63=(a63*a61);
  a56=(a56+a63);
  a63=arg[1]? arg[1][319] : 0;
  a7=(a63*a62);
  a56=(a56+a7);
  a7=arg[1]? arg[1][322] : 0;
  a1=(a7*a64);
  a1=(a1*a44);
  a56=(a56+a1);
  a56=(a42?a56:0);
  a3=(a3+a56);
  a63=(a63*a65);
  a7=(a7*a8);
  a7=(a7*a58);
  a63=(a63+a7);
  a7=arg[3]? arg[3][1] : 0;
  a7=(a7*a10);
  a63=(a63+a7);
  a63=(a49?a63:0);
  a3=(a3+a63);
  if (res[0]!=0) res[0][1]=a3;
  a3=arg[2]? arg[2][2] : 0;
  a3=(a3*a6);
  a6=arg[1]? arg[1][278] : 0;
  a11=(a6*a11);
  a3=(a3+a11);
  a11=arg[1]? arg[1][281] : 0;
  a13=(a11*a13);
  a13=(a13*a2);
  a3=(a3+a13);
  a0=(a0?a3:0);
  a6=(a6*a16);
  a11=(a11*a17);
  a11=(a11*a18);
  a6=(a6+a11);
  a11=arg[1]? arg[1][284] : 0;
  a19=(a11*a19);
  a6=(a6+a19);
  a19=arg[1]? arg[1][287] : 0;
  a21=(a19*a21);
  a21=(a21*a22);
  a6=(a6+a21);
  a5=(a5?a6:0);
  a0=(a0+a5);
  a11=(a11*a24);
  a19=(a19*a25);
  a19=(a19*a26);
  a11=(a11+a19);
  a19=arg[1]? arg[1][290] : 0;
  a27=(a19*a27);
  a11=(a11+a27);
  a27=arg[1]? arg[1][293] : 0;
  a29=(a27*a29);
  a29=(a29*a14);
  a11=(a11+a29);
  a9=(a9?a11:0);
  a0=(a0+a9);
  a19=(a19*a31);
  a27=(a27*a32);
  a27=(a27*a33);
  a19=(a19+a27);
  a27=arg[1]? arg[1][296] : 0;
  a34=(a27*a34);
  a19=(a19+a34);
  a34=arg[1]? arg[1][299] : 0;
  a36=(a34*a36);
  a36=(a36*a15);
  a19=(a19+a36);
  a12=(a12?a19:0);
  a0=(a0+a12);
  a27=(a27*a38);
  a34=(a34*a39);
  a34=(a34*a40);
  a27=(a27+a34);
  a34=arg[1]? arg[1][302] : 0;
  a41=(a34*a41);
  a27=(a27+a41);
  a41=arg[1]? arg[1][305] : 0;
  a43=(a41*a43);
  a43=(a43*a23);
  a27=(a27+a43);
  a20=(a20?a27:0);
  a0=(a0+a20);
  a34=(a34*a45);
  a41=(a41*a46);
  a41=(a41*a47);
  a34=(a34+a41);
  a41=arg[1]? arg[1][308] : 0;
  a48=(a41*a48);
  a34=(a34+a48);
  a48=arg[1]? arg[1][311] : 0;
  a50=(a48*a50);
  a50=(a50*a30);
  a34=(a34+a50);
  a28=(a28?a34:0);
  a0=(a0+a28);
  a41=(a41*a52);
  a48=(a48*a53);
  a48=(a48*a54);
  a41=(a41+a48);
  a48=arg[1]? arg[1][314] : 0;
  a55=(a48*a55);
  a41=(a41+a55);
  a55=arg[1]? arg[1][317] : 0;
  a57=(a55*a57);
  a57=(a57*a37);
  a41=(a41+a57);
  a35=(a35?a41:0);
  a0=(a0+a35);
  a48=(a48*a59);
  a55=(a55*a60);
  a55=(a55*a61);
  a48=(a48+a55);
  a55=arg[1]? arg[1][320] : 0;
  a62=(a55*a62);
  a48=(a48+a62);
  a62=arg[1]? arg[1][323] : 0;
  a64=(a62*a64);
  a64=(a64*a44);
  a48=(a48+a64);
  a42=(a42?a48:0);
  a0=(a0+a42);
  a55=(a55*a65);
  a62=(a62*a8);
  a62=(a62*a58);
  a55=(a55+a62);
  a62=arg[3]? arg[3][2] : 0;
  a62=(a62*a10);
  a55=(a55+a62);
  a49=(a49?a55:0);
  a0=(a0+a49);
  if (res[0]!=0) res[0][2]=a0;
  return 0;
}

CASADI_SYMBOL_EXPORT int com_angle(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int com_angle_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int com_angle_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void com_angle_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int com_angle_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void com_angle_release(int mem) {
}

CASADI_SYMBOL_EXPORT void com_angle_incref(void) {
}

CASADI_SYMBOL_EXPORT void com_angle_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int com_angle_n_in(void) { return 4;}

CASADI_SYMBOL_EXPORT casadi_int com_angle_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real com_angle_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* com_angle_name_in(casadi_int i){
  switch (i) {
    case 0: return "cur_t";
    case 1: return "state";
    case 2: return "com_angle0";
    case 3: return "com_angleT";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* com_angle_name_out(casadi_int i){
  switch (i) {
    case 0: return "com_ang";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* com_angle_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    case 2: return casadi_s2;
    case 3: return casadi_s2;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* com_angle_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s2;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int com_angle_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 4;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

#ifdef MATLAB_MEX_FILE
void mex_com_angle(int resc, mxArray *resv[], int argc, const mxArray *argv[]) {
  casadi_int i, j;
  casadi_real w[3106];
  casadi_int *iw = 0;
  const casadi_real* arg[4] = {0};
  casadi_real* res[1] = {0};
  if (argc>4) mexErrMsgIdAndTxt("Casadi:RuntimeError","Evaluation of \"com_angle\" failed. Too many input arguments (%d, max 4)", argc);
  if (resc>1) mexErrMsgIdAndTxt("Casadi:RuntimeError","Evaluation of \"com_angle\" failed. Too many output arguments (%d, max 1)", resc);
  if (--argc>=0) arg[0] = casadi_from_mex(argv[0], w, casadi_s0, w+1558);
  if (--argc>=0) arg[1] = casadi_from_mex(argv[1], w+1, casadi_s1, w+1558);
  if (--argc>=0) arg[2] = casadi_from_mex(argv[2], w+1549, casadi_s2, w+1558);
  if (--argc>=0) arg[3] = casadi_from_mex(argv[3], w+1552, casadi_s2, w+1558);
  --resc;
  res[0] = w+1555;
  i = com_angle(arg, res, iw, w+1558, 0);
  if (i) mexErrMsgIdAndTxt("Casadi:RuntimeError","Evaluation of \"com_angle\" failed.");
  if (res[0]) resv[0] = casadi_to_mex(casadi_s2, res[0]);
}
#endif


#ifdef MATLAB_MEX_FILE
void mexFunction(int resc, mxArray *resv[], int argc, const mxArray *argv[]) {
  char buf[10];
  int buf_ok = --argc >= 0 && !mxGetString(*argv++, buf, sizeof(buf));
  if (!buf_ok) {
    /* name error */
  } else if (strcmp(buf, "com_angle")==0) {
    mex_com_angle(resc, resv, argc, argv);
    return;
  }
  mexErrMsgTxt("First input should be a command string. Possible values: 'com_angle'");
}
#endif
#ifdef __cplusplus
} /* extern "C" */
#endif