#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_1193960547558833252);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4543449835478093159);
void car_H_mod_fun(double *state, double *out_7232390223739026194);
void car_f_fun(double *state, double dt, double *out_4151564110835034874);
void car_F_fun(double *state, double dt, double *out_8639931614123605899);
void car_h_25(double *state, double *unused, double *out_8123692409857042420);
void car_H_25(double *state, double *unused, double *out_7263354347084809474);
void car_h_24(double *state, double *unused, double *out_280100904029904765);
void car_H_24(double *state, double *unused, double *out_5090704748079309908);
void car_h_30(double *state, double *unused, double *out_8280879078208171565);
void car_H_30(double *state, double *unused, double *out_4266699385133125387);
void car_h_26(double *state, double *unused, double *out_9108428911059128384);
void car_H_26(double *state, double *unused, double *out_3521851028210753250);
void car_h_27(double *state, double *unused, double *out_7286265612408176511);
void car_H_27(double *state, double *unused, double *out_4959252088141144493);
void car_h_29(double *state, double *unused, double *out_3279205810547325920);
void car_H_29(double *state, double *unused, double *out_3245889361271593460);
void car_h_28(double *state, double *unused, double *out_6342755759506514076);
void car_H_28(double *state, double *unused, double *out_5209519632836919711);
void car_h_31(double *state, double *unused, double *out_3735223737376214033);
void car_H_31(double *state, double *unused, double *out_7294000308961769902);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}