//
// Created by heygears on 23-9-1.
//

#ifndef ALL_PID_H
#define ALL_PID_H
class PID{
public:
    PID(double sv, double P, double I, double D);
    ~PID();

    double update(double new_pv);
    void setSv(double sv);
    void setPv(double pv);
    void setMv(double mv);
    void setKp(double kp);
    void setKi(double ki);
    void setKd(double kd);
    std::string getInfo();

private:
    double sv_ = 0.0;
    double pv_ = 0.0;
    double mv_ = 0.0;
    double kp_ = 0.0;
    double ki_ = 0.0;
    double kd_ = 0.0;
    double filter_ = 0.5;
    double preErr_ = 0.0;
    double prePreErr_ = 0.0;
};
#endif //ALL_PID_H
