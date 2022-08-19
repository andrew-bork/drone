#ifndef KALMAN_H_GUARD
#define KALMAN_H_GUARD

// #include <math.h>
#include <armadillo>
// namespace kalman {

// }

struct kalman {
    // math::vector x; // x - pos, y - vel, z - acc
    // math::vector x_pred;

    arma::mat state, pred_state;
    arma::mat state_update_mat, state_update_mat_t;
    arma::mat observation_noise, process_noise;
    arma::mat covar_proc_noise, covar_obsrv_noise;
    arma::mat process_covar, pred_process_covar;
    arma::mat observation_model_mat, observation_model_mat_t;
    arma::mat kalman_gain;
    arma::mat observation_uncertainty;
    arma::mat control_update_mat;
    // arma::mat temp1, temp2, temp3;
    arma::mat r;
    arma::mat identity1;

    kalman();
    kalman(int n_measurements, int n_states);

    void predict();
    void predict(arma::mat & control_mat);
    void update(arma::mat & measurements);

    static void kinematic1D_state_update_pva(kalman &k, double dt);
    static void kinematic1D_state_update_pv(kalman &k, double dt);

    static void kinematic1D_control_update_a(kalman &k, double dt);
};

#endif