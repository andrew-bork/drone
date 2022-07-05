#include <filter.h>
#include <cmath>


double filter::filter::operator[] (double x0){
    double y0 = b0 * x0 + b1 * x1 + b2 * x2 + a1 * y1 + a2 * y2;
    x2 = x1;
    x1 = x0;
    y2 = y1;
    y1 = y0;
    return y0;
}

filter::filter filter::low_pass(double sample_rate, double w0) {
    filter out;
    double ff = w0 / sample_rate;
    const double ita =1.0/ tan(M_PI*ff);
    const double q=sqrt(2.0);
    out.b0 = 1.0 / (1.0 + q*ita + ita*ita);
    out.b1= 2*b0;
    out.b2= b0;
    out.a1 = 2.0 * (ita*ita - 1.0) * b0;
    out.a2 = -(1.0 - q*ita + ita*ita) * b0;
    return out;
}

filter::filter filter::band_pass(double sample_rate, double wL, double wH){
    // https://github.com/dimtass/DSP-Cpp-filters/blob/master/lib/so_bpf.h
    filter out;
    double w = 2.0 * pi * fc / fs;
    double b = 0.5*((1.0 - tan(w / (2.0*Q))) / (1.0 + tan(w / (2.0*Q))));
    double g = (0.5 + b)*cos(w);
    out.a0 = 0.5 - b;
    out.a1 = 0.0;
    out.a2 = -(0.5 - b);
    out.b1 = -2.0 * g;
    out.b2 = 2.0 * b;
    return out;
}
