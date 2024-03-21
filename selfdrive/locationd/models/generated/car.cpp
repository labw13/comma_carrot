#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1193960547558833252) {
   out_1193960547558833252[0] = delta_x[0] + nom_x[0];
   out_1193960547558833252[1] = delta_x[1] + nom_x[1];
   out_1193960547558833252[2] = delta_x[2] + nom_x[2];
   out_1193960547558833252[3] = delta_x[3] + nom_x[3];
   out_1193960547558833252[4] = delta_x[4] + nom_x[4];
   out_1193960547558833252[5] = delta_x[5] + nom_x[5];
   out_1193960547558833252[6] = delta_x[6] + nom_x[6];
   out_1193960547558833252[7] = delta_x[7] + nom_x[7];
   out_1193960547558833252[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4543449835478093159) {
   out_4543449835478093159[0] = -nom_x[0] + true_x[0];
   out_4543449835478093159[1] = -nom_x[1] + true_x[1];
   out_4543449835478093159[2] = -nom_x[2] + true_x[2];
   out_4543449835478093159[3] = -nom_x[3] + true_x[3];
   out_4543449835478093159[4] = -nom_x[4] + true_x[4];
   out_4543449835478093159[5] = -nom_x[5] + true_x[5];
   out_4543449835478093159[6] = -nom_x[6] + true_x[6];
   out_4543449835478093159[7] = -nom_x[7] + true_x[7];
   out_4543449835478093159[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_7232390223739026194) {
   out_7232390223739026194[0] = 1.0;
   out_7232390223739026194[1] = 0;
   out_7232390223739026194[2] = 0;
   out_7232390223739026194[3] = 0;
   out_7232390223739026194[4] = 0;
   out_7232390223739026194[5] = 0;
   out_7232390223739026194[6] = 0;
   out_7232390223739026194[7] = 0;
   out_7232390223739026194[8] = 0;
   out_7232390223739026194[9] = 0;
   out_7232390223739026194[10] = 1.0;
   out_7232390223739026194[11] = 0;
   out_7232390223739026194[12] = 0;
   out_7232390223739026194[13] = 0;
   out_7232390223739026194[14] = 0;
   out_7232390223739026194[15] = 0;
   out_7232390223739026194[16] = 0;
   out_7232390223739026194[17] = 0;
   out_7232390223739026194[18] = 0;
   out_7232390223739026194[19] = 0;
   out_7232390223739026194[20] = 1.0;
   out_7232390223739026194[21] = 0;
   out_7232390223739026194[22] = 0;
   out_7232390223739026194[23] = 0;
   out_7232390223739026194[24] = 0;
   out_7232390223739026194[25] = 0;
   out_7232390223739026194[26] = 0;
   out_7232390223739026194[27] = 0;
   out_7232390223739026194[28] = 0;
   out_7232390223739026194[29] = 0;
   out_7232390223739026194[30] = 1.0;
   out_7232390223739026194[31] = 0;
   out_7232390223739026194[32] = 0;
   out_7232390223739026194[33] = 0;
   out_7232390223739026194[34] = 0;
   out_7232390223739026194[35] = 0;
   out_7232390223739026194[36] = 0;
   out_7232390223739026194[37] = 0;
   out_7232390223739026194[38] = 0;
   out_7232390223739026194[39] = 0;
   out_7232390223739026194[40] = 1.0;
   out_7232390223739026194[41] = 0;
   out_7232390223739026194[42] = 0;
   out_7232390223739026194[43] = 0;
   out_7232390223739026194[44] = 0;
   out_7232390223739026194[45] = 0;
   out_7232390223739026194[46] = 0;
   out_7232390223739026194[47] = 0;
   out_7232390223739026194[48] = 0;
   out_7232390223739026194[49] = 0;
   out_7232390223739026194[50] = 1.0;
   out_7232390223739026194[51] = 0;
   out_7232390223739026194[52] = 0;
   out_7232390223739026194[53] = 0;
   out_7232390223739026194[54] = 0;
   out_7232390223739026194[55] = 0;
   out_7232390223739026194[56] = 0;
   out_7232390223739026194[57] = 0;
   out_7232390223739026194[58] = 0;
   out_7232390223739026194[59] = 0;
   out_7232390223739026194[60] = 1.0;
   out_7232390223739026194[61] = 0;
   out_7232390223739026194[62] = 0;
   out_7232390223739026194[63] = 0;
   out_7232390223739026194[64] = 0;
   out_7232390223739026194[65] = 0;
   out_7232390223739026194[66] = 0;
   out_7232390223739026194[67] = 0;
   out_7232390223739026194[68] = 0;
   out_7232390223739026194[69] = 0;
   out_7232390223739026194[70] = 1.0;
   out_7232390223739026194[71] = 0;
   out_7232390223739026194[72] = 0;
   out_7232390223739026194[73] = 0;
   out_7232390223739026194[74] = 0;
   out_7232390223739026194[75] = 0;
   out_7232390223739026194[76] = 0;
   out_7232390223739026194[77] = 0;
   out_7232390223739026194[78] = 0;
   out_7232390223739026194[79] = 0;
   out_7232390223739026194[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4151564110835034874) {
   out_4151564110835034874[0] = state[0];
   out_4151564110835034874[1] = state[1];
   out_4151564110835034874[2] = state[2];
   out_4151564110835034874[3] = state[3];
   out_4151564110835034874[4] = state[4];
   out_4151564110835034874[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4151564110835034874[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4151564110835034874[7] = state[7];
   out_4151564110835034874[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8639931614123605899) {
   out_8639931614123605899[0] = 1;
   out_8639931614123605899[1] = 0;
   out_8639931614123605899[2] = 0;
   out_8639931614123605899[3] = 0;
   out_8639931614123605899[4] = 0;
   out_8639931614123605899[5] = 0;
   out_8639931614123605899[6] = 0;
   out_8639931614123605899[7] = 0;
   out_8639931614123605899[8] = 0;
   out_8639931614123605899[9] = 0;
   out_8639931614123605899[10] = 1;
   out_8639931614123605899[11] = 0;
   out_8639931614123605899[12] = 0;
   out_8639931614123605899[13] = 0;
   out_8639931614123605899[14] = 0;
   out_8639931614123605899[15] = 0;
   out_8639931614123605899[16] = 0;
   out_8639931614123605899[17] = 0;
   out_8639931614123605899[18] = 0;
   out_8639931614123605899[19] = 0;
   out_8639931614123605899[20] = 1;
   out_8639931614123605899[21] = 0;
   out_8639931614123605899[22] = 0;
   out_8639931614123605899[23] = 0;
   out_8639931614123605899[24] = 0;
   out_8639931614123605899[25] = 0;
   out_8639931614123605899[26] = 0;
   out_8639931614123605899[27] = 0;
   out_8639931614123605899[28] = 0;
   out_8639931614123605899[29] = 0;
   out_8639931614123605899[30] = 1;
   out_8639931614123605899[31] = 0;
   out_8639931614123605899[32] = 0;
   out_8639931614123605899[33] = 0;
   out_8639931614123605899[34] = 0;
   out_8639931614123605899[35] = 0;
   out_8639931614123605899[36] = 0;
   out_8639931614123605899[37] = 0;
   out_8639931614123605899[38] = 0;
   out_8639931614123605899[39] = 0;
   out_8639931614123605899[40] = 1;
   out_8639931614123605899[41] = 0;
   out_8639931614123605899[42] = 0;
   out_8639931614123605899[43] = 0;
   out_8639931614123605899[44] = 0;
   out_8639931614123605899[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8639931614123605899[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8639931614123605899[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8639931614123605899[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8639931614123605899[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8639931614123605899[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8639931614123605899[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8639931614123605899[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8639931614123605899[53] = -9.8000000000000007*dt;
   out_8639931614123605899[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8639931614123605899[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8639931614123605899[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8639931614123605899[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8639931614123605899[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8639931614123605899[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8639931614123605899[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8639931614123605899[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8639931614123605899[62] = 0;
   out_8639931614123605899[63] = 0;
   out_8639931614123605899[64] = 0;
   out_8639931614123605899[65] = 0;
   out_8639931614123605899[66] = 0;
   out_8639931614123605899[67] = 0;
   out_8639931614123605899[68] = 0;
   out_8639931614123605899[69] = 0;
   out_8639931614123605899[70] = 1;
   out_8639931614123605899[71] = 0;
   out_8639931614123605899[72] = 0;
   out_8639931614123605899[73] = 0;
   out_8639931614123605899[74] = 0;
   out_8639931614123605899[75] = 0;
   out_8639931614123605899[76] = 0;
   out_8639931614123605899[77] = 0;
   out_8639931614123605899[78] = 0;
   out_8639931614123605899[79] = 0;
   out_8639931614123605899[80] = 1;
}
void h_25(double *state, double *unused, double *out_8123692409857042420) {
   out_8123692409857042420[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7263354347084809474) {
   out_7263354347084809474[0] = 0;
   out_7263354347084809474[1] = 0;
   out_7263354347084809474[2] = 0;
   out_7263354347084809474[3] = 0;
   out_7263354347084809474[4] = 0;
   out_7263354347084809474[5] = 0;
   out_7263354347084809474[6] = 1;
   out_7263354347084809474[7] = 0;
   out_7263354347084809474[8] = 0;
}
void h_24(double *state, double *unused, double *out_280100904029904765) {
   out_280100904029904765[0] = state[4];
   out_280100904029904765[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5090704748079309908) {
   out_5090704748079309908[0] = 0;
   out_5090704748079309908[1] = 0;
   out_5090704748079309908[2] = 0;
   out_5090704748079309908[3] = 0;
   out_5090704748079309908[4] = 1;
   out_5090704748079309908[5] = 0;
   out_5090704748079309908[6] = 0;
   out_5090704748079309908[7] = 0;
   out_5090704748079309908[8] = 0;
   out_5090704748079309908[9] = 0;
   out_5090704748079309908[10] = 0;
   out_5090704748079309908[11] = 0;
   out_5090704748079309908[12] = 0;
   out_5090704748079309908[13] = 0;
   out_5090704748079309908[14] = 1;
   out_5090704748079309908[15] = 0;
   out_5090704748079309908[16] = 0;
   out_5090704748079309908[17] = 0;
}
void h_30(double *state, double *unused, double *out_8280879078208171565) {
   out_8280879078208171565[0] = state[4];
}
void H_30(double *state, double *unused, double *out_4266699385133125387) {
   out_4266699385133125387[0] = 0;
   out_4266699385133125387[1] = 0;
   out_4266699385133125387[2] = 0;
   out_4266699385133125387[3] = 0;
   out_4266699385133125387[4] = 1;
   out_4266699385133125387[5] = 0;
   out_4266699385133125387[6] = 0;
   out_4266699385133125387[7] = 0;
   out_4266699385133125387[8] = 0;
}
void h_26(double *state, double *unused, double *out_9108428911059128384) {
   out_9108428911059128384[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3521851028210753250) {
   out_3521851028210753250[0] = 0;
   out_3521851028210753250[1] = 0;
   out_3521851028210753250[2] = 0;
   out_3521851028210753250[3] = 0;
   out_3521851028210753250[4] = 0;
   out_3521851028210753250[5] = 0;
   out_3521851028210753250[6] = 0;
   out_3521851028210753250[7] = 1;
   out_3521851028210753250[8] = 0;
}
void h_27(double *state, double *unused, double *out_7286265612408176511) {
   out_7286265612408176511[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4959252088141144493) {
   out_4959252088141144493[0] = 0;
   out_4959252088141144493[1] = 0;
   out_4959252088141144493[2] = 0;
   out_4959252088141144493[3] = 1;
   out_4959252088141144493[4] = 0;
   out_4959252088141144493[5] = 0;
   out_4959252088141144493[6] = 0;
   out_4959252088141144493[7] = 0;
   out_4959252088141144493[8] = 0;
}
void h_29(double *state, double *unused, double *out_3279205810547325920) {
   out_3279205810547325920[0] = state[1];
}
void H_29(double *state, double *unused, double *out_3245889361271593460) {
   out_3245889361271593460[0] = 0;
   out_3245889361271593460[1] = 1;
   out_3245889361271593460[2] = 0;
   out_3245889361271593460[3] = 0;
   out_3245889361271593460[4] = 0;
   out_3245889361271593460[5] = 0;
   out_3245889361271593460[6] = 0;
   out_3245889361271593460[7] = 0;
   out_3245889361271593460[8] = 0;
}
void h_28(double *state, double *unused, double *out_6342755759506514076) {
   out_6342755759506514076[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5209519632836919711) {
   out_5209519632836919711[0] = 1;
   out_5209519632836919711[1] = 0;
   out_5209519632836919711[2] = 0;
   out_5209519632836919711[3] = 0;
   out_5209519632836919711[4] = 0;
   out_5209519632836919711[5] = 0;
   out_5209519632836919711[6] = 0;
   out_5209519632836919711[7] = 0;
   out_5209519632836919711[8] = 0;
}
void h_31(double *state, double *unused, double *out_3735223737376214033) {
   out_3735223737376214033[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7294000308961769902) {
   out_7294000308961769902[0] = 0;
   out_7294000308961769902[1] = 0;
   out_7294000308961769902[2] = 0;
   out_7294000308961769902[3] = 0;
   out_7294000308961769902[4] = 0;
   out_7294000308961769902[5] = 0;
   out_7294000308961769902[6] = 0;
   out_7294000308961769902[7] = 0;
   out_7294000308961769902[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_1193960547558833252) {
  err_fun(nom_x, delta_x, out_1193960547558833252);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4543449835478093159) {
  inv_err_fun(nom_x, true_x, out_4543449835478093159);
}
void car_H_mod_fun(double *state, double *out_7232390223739026194) {
  H_mod_fun(state, out_7232390223739026194);
}
void car_f_fun(double *state, double dt, double *out_4151564110835034874) {
  f_fun(state,  dt, out_4151564110835034874);
}
void car_F_fun(double *state, double dt, double *out_8639931614123605899) {
  F_fun(state,  dt, out_8639931614123605899);
}
void car_h_25(double *state, double *unused, double *out_8123692409857042420) {
  h_25(state, unused, out_8123692409857042420);
}
void car_H_25(double *state, double *unused, double *out_7263354347084809474) {
  H_25(state, unused, out_7263354347084809474);
}
void car_h_24(double *state, double *unused, double *out_280100904029904765) {
  h_24(state, unused, out_280100904029904765);
}
void car_H_24(double *state, double *unused, double *out_5090704748079309908) {
  H_24(state, unused, out_5090704748079309908);
}
void car_h_30(double *state, double *unused, double *out_8280879078208171565) {
  h_30(state, unused, out_8280879078208171565);
}
void car_H_30(double *state, double *unused, double *out_4266699385133125387) {
  H_30(state, unused, out_4266699385133125387);
}
void car_h_26(double *state, double *unused, double *out_9108428911059128384) {
  h_26(state, unused, out_9108428911059128384);
}
void car_H_26(double *state, double *unused, double *out_3521851028210753250) {
  H_26(state, unused, out_3521851028210753250);
}
void car_h_27(double *state, double *unused, double *out_7286265612408176511) {
  h_27(state, unused, out_7286265612408176511);
}
void car_H_27(double *state, double *unused, double *out_4959252088141144493) {
  H_27(state, unused, out_4959252088141144493);
}
void car_h_29(double *state, double *unused, double *out_3279205810547325920) {
  h_29(state, unused, out_3279205810547325920);
}
void car_H_29(double *state, double *unused, double *out_3245889361271593460) {
  H_29(state, unused, out_3245889361271593460);
}
void car_h_28(double *state, double *unused, double *out_6342755759506514076) {
  h_28(state, unused, out_6342755759506514076);
}
void car_H_28(double *state, double *unused, double *out_5209519632836919711) {
  H_28(state, unused, out_5209519632836919711);
}
void car_h_31(double *state, double *unused, double *out_3735223737376214033) {
  h_31(state, unused, out_3735223737376214033);
}
void car_H_31(double *state, double *unused, double *out_7294000308961769902) {
  H_31(state, unused, out_7294000308961769902);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
