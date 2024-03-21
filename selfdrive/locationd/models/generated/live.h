#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_197059200494027966);
void live_err_fun(double *nom_x, double *delta_x, double *out_4389981286306835332);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_2871076421796127612);
void live_H_mod_fun(double *state, double *out_5155217794973921661);
void live_f_fun(double *state, double dt, double *out_5503960962388644187);
void live_F_fun(double *state, double dt, double *out_2076298069187341018);
void live_h_4(double *state, double *unused, double *out_6715684721504435251);
void live_H_4(double *state, double *unused, double *out_7104865494532900345);
void live_h_9(double *state, double *unused, double *out_9081503026275750675);
void live_H_9(double *state, double *unused, double *out_4054659643912203801);
void live_h_10(double *state, double *unused, double *out_5494962244777780694);
void live_H_10(double *state, double *unused, double *out_988134382099698306);
void live_h_12(double *state, double *unused, double *out_2334630861097322167);
void live_H_12(double *state, double *unused, double *out_6322422171144689476);
void live_h_35(double *state, double *unused, double *out_8812005347938789531);
void live_H_35(double *state, double *unused, double *out_3576859138819675767);
void live_h_32(double *state, double *unused, double *out_5009017043479333218);
void live_H_32(double *state, double *unused, double *out_6252828314233598651);
void live_h_13(double *state, double *unused, double *out_4762743962227189082);
void live_H_13(double *state, double *unused, double *out_716872904616565711);
void live_h_14(double *state, double *unused, double *out_9081503026275750675);
void live_H_14(double *state, double *unused, double *out_4054659643912203801);
void live_h_33(double *state, double *unused, double *out_1834506484088595531);
void live_H_33(double *state, double *unused, double *out_4824659517165186291);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}