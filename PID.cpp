//
// Created by heygears on 23-9-1.
//
#include <string>
#include "PID.h"

PID::PID(double sv, double P, double I, double D) {
    sv_ = sv;
    kp_ = P;
    ki_ = I;
    kd_ = D;
}

PID::~PID() = default;

void PID::setMv(double mv)
{
    mv_ = mv;
}

void PID::setSv(double sv)
{
    sv_ = sv;
}

void PID::setKp(double kp)
{
    kp_ = kp;
}

void PID::setKi(double ki)
{
    ki_ = ki;
}

void PID::setKd(double kd)
{
    kd_ = kd;
}

void PID::setPv(double pv)
{
    pv_ = pv;
}

double PID::update(double new_pv) {
    pv_ = pv_ * filter_ + (1 - filter_) * new_pv;

    auto error = sv_ - pv_;
    auto inc = kp_ * (error - preErr_) + ki_ * error + kd_ * (error - 2 * preErr_ + prePreErr_);
    mv_ += inc;
    prePreErr_ = preErr_;
    preErr_ = error;
    return mv_;
}

std::string PID::getInfo() {
    std::string info ="SV=" + std::to_string(sv_) +
                      ", Kp=" + std::to_string(kp_) +
                      ", Ki=" + std::to_string(ki_) +
                      ", Kd=" + std::to_string(kd_) +
                      ", Filter=" + std::to_string(filter_) +
                      ", pv_=" + std::to_string(pv_) +
                      ", mv_=" + std::to_string(mv_) +
                      ", prePreErr_=" + std::to_string(prePreErr_) +
                      ", preErr_=" + std::to_string(preErr_);

    return info;
}
